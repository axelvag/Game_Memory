#include <Grapic.h>
#include<string.h>
#include <iostream>
using namespace grapic;
using namespace std;

const int DIMW = 500;
const int MAXCHAR = 100;
const int MAX_X = 10;
const int MAX_Y = 10;
const int MAX_IMAGES = 18;

struct CaseGrille
{
    Image ImCase;
    char nom_image[MAXCHAR];
    bool visible;
};

struct Memory
{
    int TGX=4;
    int TGY=4;
    struct CaseGrille jeu[MAX_X][MAX_Y];
    int t_indice_image[MAX_IMAGES];
    Image vide;

};

void Creer_Nom_Fichier (Memory &m,char nom_fichier[MAXCHAR])
{
    int num_image;
    char numero[3];
    do
    {
        num_image=rand() % MAX_IMAGES + 1;
    }
    while (m.t_indice_image[num_image-1]!=0);
    m.t_indice_image[num_image-1]=1;

    strcpy(nom_fichier,"data/memory/Image_Memory_");
    if (num_image<10)
    {
        strcat(nom_fichier,"0");
        numero[0]='0'+num_image;
        numero[1]='\0';
    }
    else
    {
        numero[0]='1';
        numero[1]=num_image % 10 + '0';
        numero[2]='\0';
    }
    strcat(nom_fichier,numero);
    strcat(nom_fichier,".jpg");

}


void init_images(Memory& m)
{
    int i,j;
    int ind_ligne,ind_colonne;
    char nom_image[MAXCHAR];

    for (i=0; i<(m.TGX*m.TGY)/2; i++)
    {
        Creer_Nom_Fichier(m,nom_image);
        for (j=0; j<2; j++)
        {
            do
            {
                ind_ligne=rand()%m.TGX ;
                ind_colonne=rand()%m.TGY ;
            }
            while (strcmp(m.jeu[ind_ligne][ind_colonne].nom_image,"data/memory/vide.jpg")!=0);
            strcpy(m.jeu[ind_ligne][ind_colonne].nom_image,nom_image);
            m.jeu[ind_ligne][ind_colonne].ImCase=image(nom_image);
            //
image_draw(m.jeu[ind_ligne][ind_colonne].ImCase,ind_ligne*DIMW/m.TGX,ind_colonne*DIMW/m.TGY,DIMW/m.TGX,DIMW/m.TGY);
        }
    }
    m.vide = image("data/memory/vide.jpg");
}


void init(Memory& m)
{
    int i,j;
    for (i=0; i<MAX_IMAGES; i++)
    {
        m.t_indice_image[i]=0;
    }
    for (i=0; i<m.TGX; i++)
    {
        for (j=0; j<m.TGY; j++)
        {
            m.jeu[i][j].ImCase=image("data/memory/vide.jpg");
            strcpy(m.jeu[i][j].nom_image,"data/memory/vide.jpg");
            //image_draw(m.jeu[i][j].ImCase,i*DIMW/m.TGX,j*DIMW/m.TGY,DIMW/m.TGX,DIMW/m.TGY);
            m.jeu[i][j].visible=false;
        }
    }
    init_images(m);
}


void choix_case (Memory m, int &l1, int &c1)
{
    int l,c;
    bool b;
    l1 = -1;
    while  ( l1==-1 )
    {
        if (isMousePressed(SDL_BUTTON_LEFT))
        {
            int x,y;
            mousePos(x, y);
            l=x/(DIMW/m.TGX);
            c=y/(DIMW/m.TGY);
            if (!m.jeu[l][c].visible)
            {
                l1=l;
                c1=c;
            }
        }
        winDisplay();
    }
}


void Affiche_Grille(Memory &m)
{
    int i,j;
    Image Im;
    for (i=0; i<m.TGX; i++)
    {
        for (j=0; j<m.TGY; j++)
        {
            if (m.jeu[i][j].visible==false)
            {
                image_draw( m.vide,i*DIMW/m.TGX,j*DIMW/m.TGY,DIMW/m.TGX,DIMW/m.TGY);
            }
            else

image_draw(m.jeu[i][j].ImCase,i*DIMW/m.TGX,j*DIMW/m.TGY,DIMW/m.TGX,DIMW/m.TGY);

        }
    }

}

int VerifiePaire(Memory &m)
{
    int l1,c1,l2,c2;
    choix_case(m,l1,c1);
    m.jeu[l1][c1].visible=true;
    Affiche_Grille(m);
    winDisplay();

    choix_case(m,l2,c2);
    m.jeu[l2][c2].visible=true;
    Affiche_Grille(m);
    winDisplay();
    //pressSpace();
    if ( strcmp(m.jeu[l1][c1].nom_image,m.jeu[l2][c2].nom_image)==0)
    {
        return 1;
    }
    else
    {
        delay(2000);
        m.jeu[l2][c2].visible=false;
        m.jeu[l1][c1].visible=false;
        return 0;
    }

}

int main(int , char** )
{
    Memory m;
    int score = 0 , echec=0;
    int l1,c1,l2,c2;
    bool stop=false;
    srand(time(NULL));
    winInit("MEMORY", DIMW, DIMW);
    winClear();
    init(m);
    Affiche_Grille(m);
    stop=winDisplay();

    while ((!stop)&&(score!=(m.TGX*m.TGY)/2))
    {
        if (VerifiePaire(m))
        {
            score+=1;
        }
        else
        {
            echec++;
        }
        Affiche_Grille(m);
        stop = winDisplay();
    }
    color(255,0,0);
    fontSize(48);
    print(150,250,"GAGNE!!!");
    fontSize(28);
    print(200,150,echec);
    print(250,150,"erreurs");
    color(0,0,0);
    fontSize(12);
    pressSpace();
    winQuit();
    return 0;
}
