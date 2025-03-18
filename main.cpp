#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winbgim.h>
#include <graphics.h>
#include <algorithm>
#include <time.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <stdio.h>
using namespace std;
ifstream in("inputmatriceA");
ifstream in2("inputmatriceAordin2");
ifstream inB("inputmatriceB");
ofstream out("outputmatrici");
#define MAX 20
#define latura 60

int vector_citire[10000],vector_citireB[1000],contor_cit=0,contor_citB=0,nr_lin_tast,nr_col_tast,nr_lin_fisier,nr_col_fisier,nr_lin_tastB,nr_col_tastB,nr_lin_fisierB,nr_col_fisierB;
int vector_citire_Vector[100],contor_vector=0,nr_valori_tast,nr_valori_fisier,scalar;
struct matrice
{
    int x,y; // coordonate sytanga sus
    int nrLinii, nrColoane;
    int elem[MAX][MAX];
};

struct matrice_float
{
    int x,y;
    int nrLinii, nrColoane;
    float elem[MAX][MAX];
};



void fisier_in_vector_A()
{
    FILE
    *fisier=fopen("inputmatriceA","r");
    int x;
    fscanf(fisier,"%d",&x);
    nr_lin_fisier=x;
    fscanf(fisier,"%d",&x);
    nr_col_fisier=x;
    contor_cit=0;
    for (int i=1; i<=nr_lin_fisier; i++)
        for (int j=1; j<=nr_col_fisier; j++)
        {
            fscanf(fisier,"%d",&x);
            contor_cit++;
            vector_citire[contor_cit]=x;;
        }

    fclose(fisier);

}

void fisier_in_vector_Vector()
{
    FILE
    *fisier=fopen("inputvector","r");
    int x;
    fscanf(fisier,"%d",&x);
    nr_valori_fisier=x;

    contor_vector=0;

    for (int j=1; j<=nr_valori_fisier; j++)
    {
        fscanf(fisier,"%d",&x);
        contor_vector++;
        vector_citire_Vector[contor_vector]=x;;
    }
    fscanf(fisier,"%d",&x);
    scalar=x;
    fclose(fisier);
}
void fisier_in_vector_A_ordin2()
{
    FILE
    *fisier=fopen("inputmatriceAordin2","r");
    int x;
    fscanf(fisier,"%d",&x);
    nr_lin_fisier=x;
    fscanf(fisier,"%d",&x);
    nr_col_fisier=x;
    contor_cit=0;
    for (int i=1; i<=nr_lin_fisier; i++)
        for (int j=1; j<=nr_col_fisier; j++)
        {
            fscanf(fisier,"%d",&x);
            contor_cit++;
            vector_citire[contor_cit]=x;;
        }

    fclose(fisier);
}

void fisier_in_vector_B()
{
    FILE
    *fisier=fopen("inputmatriceB","r");
    int x;
    fscanf(fisier,"%d",&x);
    nr_lin_fisierB=x;
    fscanf(fisier,"%d",&x);
    nr_col_fisierB=x;
    contor_citB=0;
    for (int i=1; i<=nr_lin_fisierB; i++)
        for (int j=1; j<=nr_col_fisierB; j++)
        {
            fscanf(fisier,"%d",&x);
            contor_citB++;
            vector_citireB[contor_citB]=x;;
        }

    fclose(fisier);
}

void afisare_in_fisier_matrice(matrice A,int numar_linii, int numar_coloane)
{
  FILE
    *fisier=fopen("outputmatrici","w");

for (int j=1; j<=numar_coloane+1; j++)
          {fprintf(fisier,"%c",'-');
          fprintf(fisier,"%c",' ');}
fprintf(fisier,"%c\n",' ');

 for (int i=1; i<=numar_linii; i++)
        {fprintf(fisier,"%c",'|');
            for (int j=1; j<=numar_coloane; j++)
            {fprintf(fisier,"%d",A.elem[i][j]);
             fprintf(fisier,"%c",'|');
            }
          fprintf(fisier,"%c\n",' ');
         for (int j=1; j<=numar_coloane+1; j++)
          {fprintf(fisier,"%c",'-');
          fprintf(fisier,"%c",' ');
          }
          fprintf(fisier,"%c\n",' ');

        }
fclose(fisier);

}

void afisare_in_fisier_matrice_float(matrice_float A,int numar_linii, int numar_coloane)
{
  FILE
    *fisier=fopen("outputmatrici","w");

for (int j=1; j<=numar_coloane+1; j++)
          {fprintf(fisier,"%c",'-');
          fprintf(fisier,"%c",' ');}
fprintf(fisier,"%c\n",' ');

 for (int i=1; i<=numar_linii; i++)
        {fprintf(fisier,"%c",'|');
            for (int j=1; j<=numar_coloane; j++)
            {fprintf(fisier,"%.2f",A.elem[i][j]);
             fprintf(fisier,"%c",'|');
            }
          fprintf(fisier,"%c\n",' ');
         for (int j=1; j<=numar_coloane+1; j++)
          {fprintf(fisier,"%c",'-');
          fprintf(fisier,"%c",' ');
          }
          fprintf(fisier,"%c\n",' ');

        }
fclose(fisier);

}




void afisare_in_fisier_rezultat(int x)
{
  FILE
    *fisier=fopen("outputmatrici","w");


            fprintf(fisier,"%d",x);

fclose(fisier);

}
void afisare_in_fisier_vector(matrice A,int nr_elemente)
{
  FILE
    *fisier=fopen("outputmatrici","w");


            for (int j=1; j<=nr_elemente; j++)
            {fprintf(fisier,"%d",A.elem[1][j]);
            fprintf(fisier,"%c",' ');
            }
fclose(fisier);

}





void initializeazaVector(matrice& M, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    int cnt=1;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=vector_citire_Vector[cnt];
            cnt++;
        }
}


void initializeazaMatrice(matrice& M, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    int cnt=1;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=vector_citire[cnt];
            cnt++;
        }
}


void initializeazaMatriceB(matrice& M, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    int cnt=1;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=vector_citireB[cnt];
            cnt++;
        }
}
void initializeazaMatrice_pentruAdjuncta(matrice& M,matrice T, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=T.elem[i][j];
        }
}

void initializeazaMatrice_pentruAdjuncta_float(matrice_float& M,matrice_float T, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=T.elem[i][j];
        }
}
void drawButton(int x, int y, int width, int height)
{
    setcolor(WHITE);
    rectangle(x, y, x + width, y + height);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x + 10, y + height / 2 - 5, "Pasul urmator");
}


void drawButtonContinuare(int x, int y, int width, int height)
{
    setcolor(WHITE);
    rectangle(x, y, x + width, y + height);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x + 10, y + height / 2 - 5, "Continua");
}

bool isMouseOverButton(int x, int y, int width, int height)
{
    int mouseX, mouseY;
    getmouseclick(WM_MOUSEMOVE, mouseX, mouseY);
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

bool isMouseClick()
{

    return (ismouseclick(WM_LBUTTONDOWN));
}
bool isEnterPressed()
{
    return (_kbhit() && _getch() == 13); // 13 is the ASCII code for ENTER
}

void pasul_urmator()
{
    int buttonX = 800;
    int buttonY = 300;
    int buttonWidth = 150;
    int buttonHeight = 50;

    bool buttonClicked = false;

    while (!buttonClicked)
    {


        drawButton(buttonX, buttonY, buttonWidth, buttonHeight);

        if (isMouseOverButton(buttonX, buttonY, buttonWidth, buttonHeight))
        {
            setcolor(RED);
            rectangle(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);
        }

        if (isEnterPressed() || (isMouseOverButton(buttonX, buttonY, buttonWidth, buttonHeight) && isMouseClick()))
        {
            buttonClicked = true;
            clearmouseclick(WM_LBUTTONDOWN);
        }



    }

    closegraph();

}

void continuare()
{
    int buttonX = 800;
    int buttonY = 500;
    int buttonWidth = 150;
    int buttonHeight = 50;

    bool buttonClicked = false;

    while (!buttonClicked)
    {


        drawButtonContinuare(buttonX, buttonY, buttonWidth, buttonHeight);

        if (isMouseOverButton(buttonX, buttonY, buttonWidth, buttonHeight))
        {
            setcolor(RED);
            rectangle(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);
        }

        if (isEnterPressed() || (isMouseOverButton(buttonX, buttonY, buttonWidth, buttonHeight) && isMouseClick()))
        {
            buttonClicked = true;
            clearmouseclick(WM_LBUTTONDOWN);
        }



    }

    closegraph();

}

void deseneazaMatrice(matrice M, bool aleatoriu)
{
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
            if (aleatoriu)
            {
                char sir[10];
                // itoa(M.elem[i][j],sir,10);
                snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
                outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
            }
        }

}


void initializeazaMatrice_float(matrice_float& M, int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[i][j]=aleatoriu ? rand()%100-rand()%100 : 0;
        }
}

void deseneazaMatrice_float(matrice_float M, bool aleatoriu)
{
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            rectangle(M.x+(j-1)*latura,M.y+(i-1)*latura,M.x+j*latura,M.y+i*latura);
            if (aleatoriu)
            {
                char sir[10];
                // itoa(M.elem[i][j],sir,10);
                snprintf(sir, sizeof(sir), "%.2f", M.elem[i][j]);
                outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
            }
        }

}

void afisare_matrice(matrice M,int numar_linii,int numar_coloane)
{
    initializeazaMatrice(M,numar_linii,numar_coloane,50,50,true);
    deseneazaMatrice(M,true);
}

void aprinde(matrice M, int i, int j, int culoare)
{
    char sir[10];
    snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
    // itoa(M.elem[i][j],sir,10);
    for (int k=1; k<=3; k++)
    {
        setcolor(culoare);

        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(150);
        setcolor(WHITE);
        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(150);
    }
}

void aprinde_float(matrice_float M, int i, int j, int culoare)
{
    char sir[10];
    snprintf(sir, sizeof(sir), "%.2f", M.elem[i][j]);

    // itoa(M.elem[i][j],sir,10);
    for (int k=1; k<=5; k++)
    {
        setcolor(culoare);

        outtextxy(-5+M.x+(j-1)*latura+latura/2-5,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(250);
        setcolor(WHITE);
        outtextxy(-5+M.x+(j-1)*latura+latura/2-5,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(150);
    }
}

void schimbare_culoare(matrice M,int i,int j, int culoare)
{
    char sir[10];
    snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
    setcolor(culoare);

    outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
    //delay(1000);
    //setcolor(WHITE);
    //outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);

}
void aprindeC_inmultire(matrice M, int i, int j, int culoare)
{
    char sir[10];
    snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
    // itoa(M.elem[i][j],sir,10);
    for (int k=1; k<=2; k++)
    {
        setcolor(culoare);

        outtextxy(-5+M.x+(j-1)*latura+latura/2-9,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(150);
        setcolor(WHITE);
        outtextxy(-5+M.x+(j-1)*latura+latura/2-9,-5+M.y+(i-1)*latura+latura/2,sir);
        delay(150);
    }
}

void aprinde_linie(matrice M,int i,int culoare)
{

    // itoa(M.elem[i][j],sir,10);
    for (int k=1; k<=5; k++)
    {
        char sir[10];
        for(int j=1; j<=M.nrColoane; j++)
        {
            snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
            setcolor(culoare);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(250);

        for (int j=1; j<=M.nrColoane; j++)
        {
            snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
            setcolor(WHITE);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(150);
    }

}

aprindelinie2(matrice M,int i,int j,int culoare)
{
    for(int j=1; j<=M.nrColoane; j++)
    {
        char sir[10];
        snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
        setcolor(culoare);
        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
    }

    for (int i=1; i<=M.nrLinii; i++)
    {
        char sir[10];
        snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
        setcolor(culoare);
        outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
    }
    //delay(250);

    /*for (int j=1; j<=M.nrColoane; j++)
     {snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
    setcolor(WHITE);
     outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
     }
     delay(150);} */

}


void aprinde_col(matrice M,int j,int culoare)
{
    for (int k=1; k<=5; k++)
    {
        char sir[10];
        for (int i=1; i<=M.nrLinii; i++)
        {
            snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
            setcolor(culoare);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(250);

        for (int i=1; i<=M.nrLinii; i++)
        {
            snprintf(sir, sizeof(sir), "%d", M.elem[i][j]);
            setcolor(WHITE);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(150);
    }

}

void aprinde_col_float(matrice_float M,int j,int culoare)
{
    for (int k=1; k<=5; k++)
    {
        char sir[10];
        for (int i=1; i<=M.nrLinii; i++)
        {
            snprintf(sir, sizeof(sir), "%.2f", M.elem[i][j]);
            setcolor(culoare);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(250);

        for (int i=1; i<=M.nrLinii; i++)
        {
            snprintf(sir, sizeof(sir), "%.2f", M.elem[i][j]);
            setcolor(WHITE);
            outtextxy(-5+M.x+(j-1)*latura+latura/2,-5+M.y+(i-1)*latura+latura/2,sir);
        }
        delay(150);
    }

}

void aprinde_elem_det3(matrice M,int i,int j,int culoare,int k)
{
    char s[10];
    aprinde(M,i,j,culoare);
    snprintf(s, sizeof(s), "%d", M.elem[i][j]);
    outtextxy(50+latura*M.nrColoane+25+15+k,50+latura*M.nrLinii/2,s);
}


int calculeazaDeterminant3(matrice A)
{


    return A.elem[1][1] * (A.elem[2][2] * A.elem[3][3] - A.elem[3][2] * A.elem[2][3])
           - A.elem[1][2] * (A.elem[2][1] * A.elem[3][3] - A.elem[3][1] * A.elem[2][3])
           + A.elem[1][3] * (A.elem[2][1] * A.elem[3][2] - A.elem[3][1] * A.elem[2][2]);
}




void adunare_matrici(matrice A,matrice B,matrice &C,int numar_linii, int numar_coloane)
{

    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaMatriceB(B, A.nrLinii, A.nrColoane,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(B,true);

    initializeazaMatrice(C,numar_linii, numar_coloane, 50+(A.nrColoane+B.nrColoane)*latura+100,50,false);
    deseneazaMatrice(C,false);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"+");
    outtextxy(50+latura*(A.nrColoane+B.nrColoane)+50+25,50+latura*A.nrLinii/2,"=");
    for (int i=1; i<=A.nrLinii; i++)
        for (int j=1; j<=A.nrColoane; j++)
        {
            aprinde(A,i,j,LIGHTRED);
            aprinde(B,i,j,LIGHTCYAN);
            C.elem[i][j]=A.elem[i][j]+B.elem[i][j];
            aprinde(C,i,j,LIGHTGREEN);
        }
        afisare_in_fisier_matrice(C,C.nrLinii,C.nrColoane);
}


void scadere_matrici(matrice A,matrice B,matrice &C, int numar_linii, int numar_coloane)
{

    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaMatriceB(B, A.nrLinii, A.nrLinii,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(B,true);

    initializeazaMatrice(C,numar_linii, numar_coloane, 50+(A.nrColoane+B.nrColoane)*latura+100,50,false);
    deseneazaMatrice(C,false);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"-");
    outtextxy(50+latura*(A.nrColoane+B.nrColoane)+50+25,50+latura*A.nrLinii/2,"=");
    for (int i=1; i<=A.nrLinii; i++)
        for (int j=1; j<=A.nrColoane; j++)
        {
            aprinde(A,i,j,LIGHTRED);
            aprinde(B,i,j,LIGHTCYAN);
            C.elem[i][j]=A.elem[i][j]-B.elem[i][j];
            aprinde(C,i,j,LIGHTGREEN);
        }
        afisare_in_fisier_matrice(C,C.nrLinii,C.nrColoane);
}

void impartire_matrici(matrice A,matrice B, int numar_linii, int numar_coloane)
{

    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaMatriceB(B, A.nrLinii, A.nrLinii,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(B,true);

    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,":");


}


void transpusa(matrice A,matrice &T,int numar_linii, int numar_coloane )
{
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    initializeazaMatrice(T, A.nrColoane, A.nrLinii,70+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(T,false);


    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"-->");
    for (int i = 1; i <= T.nrColoane; i++)
        for (int j = 1; j <=T.nrLinii; j++)
        {
            T.elem[i][j] = A.elem[j][i];
            aprinde(A,j,i,LIGHTRED);
            aprinde(T,i,j,LIGHTCYAN);
        }
        afisare_in_fisier_matrice(T,T.nrLinii,T.nrColoane);

}


void transpusaB(matrice A,matrice &T,int numar_linii, int numar_coloane )
{
    initializeazaMatriceB(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    initializeazaMatrice(T, A.nrColoane, A.nrLinii,70+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(T,false);


    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"-->");
    for (int i = 1; i <= T.nrColoane; i++)
        for (int j = 1; j <=T.nrLinii; j++)
        {
            T.elem[i][j] = A.elem[j][i];
            aprinde(A,j,i,LIGHTRED);
            aprinde(T,i,j,LIGHTCYAN);
        }

}

void determinant_ordin2(matrice A,int numar_linii,int numar_coloane)
{
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    char s1[10],s2[10],s3[10],s4[10];
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");

    aprinde(A,1,1,LIGHTRED);
    snprintf(s1, sizeof(s1), "%d", A.elem[1][1]);
    outtextxy(50+latura*A.nrColoane+25+15,50+latura*A.nrLinii/2,s1);


    outtextxy(50+latura*A.nrColoane+25+40,50+latura*A.nrLinii/2,"*");

    aprinde (A,2,2,LIGHTRED);
    snprintf(s2, sizeof(s2), "%d", A.elem[2][2]);
    outtextxy(50+latura*A.nrColoane+25+50,50+latura*A.nrLinii/2,s2);

    outtextxy(50+latura*A.nrColoane+25+75,50+latura*A.nrLinii/2,"-");


    aprinde (A,1,2,LIGHTGREEN);
    snprintf(s3, sizeof(s3), "%d", A.elem[1][2]);
    outtextxy(50+latura*A.nrColoane+25+90,50+latura*A.nrLinii/2,s3);

    outtextxy(50+latura*A.nrColoane+25+125,50+latura*A.nrLinii/2,"*");

    aprinde (A,2,1,LIGHTGREEN);

    snprintf(s4, sizeof(s4), "%d", A.elem[2][1]);
    outtextxy(50+latura*A.nrColoane+25+135,50+latura*A.nrLinii/2,s4);

    outtextxy(50+latura*A.nrColoane+25+160,50+latura*A.nrLinii/2," = ");

    int det=A.elem[1][1]*A.elem[2][2]- A.elem[1][2]*A.elem[2][1];

    snprintf(s1, sizeof(s1), "%d", det);

    outtextxy(50+latura*A.nrColoane+25+175,50+latura*A.nrLinii/2,s1);


afisare_in_fisier_rezultat(det);
}


void determinant_ordin3(matrice A,int numar_linii,int numar_coloane,int &det)
{
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    int k=0,semn_det=0;
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,i,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][i]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"+");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,1,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"+");
    k=k+20;

    aprinde_elem_det3(A,2,1,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,1,3,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    semn_det=0;
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,A.nrLinii-i+1,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][A.nrLinii-i+1]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"-");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    aprinde_elem_det3(A,1,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
    det=calculeazaDeterminant3(A);
    char s[10];

    snprintf(s, sizeof(s), "%d", det);
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
    afisare_in_fisier_rezultat(det);
}





void determinant_ordin3_inversa(matrice A,int numar_linii,int numar_coloane,int &det)
{
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    int k=0,semn_det=0;
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,i,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][i]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"+");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,1,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"+");
    k=k+20;

    aprinde_elem_det3(A,2,1,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,1,3,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    semn_det=0;
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,A.nrLinii-i+1,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][A.nrLinii-i+1]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"-");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    aprinde_elem_det3(A,1,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
    det=calculeazaDeterminant3(A);
    char s[10];

    snprintf(s, sizeof(s), "%d", det);
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
    if(det==0)
        outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este egal cu 0, nu se poate calcula inversa");
    else
        outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este diferit de 0, se poate calcula inversa si se poate trece la pasul urmator");



}

void determinant_ordin3_inversaB(matrice A,int numar_linii,int numar_coloane,int &det)
{
    initializeazaMatriceB(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    int k=0,semn_det=0;
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,i,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][i]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"+");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,1,LIGHTBLUE,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"+");
    k=k+20;

    aprinde_elem_det3(A,2,1,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,1,3,YELLOW,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    semn_det=0;
    for( int i=1; i<=A.nrLinii; i++)
    {
        char s[10];
        aprinde(A,i,A.nrLinii-i+1,LIGHTRED);
        snprintf(s, sizeof(s), "%d", A.elem[i][A.nrLinii-i+1]);
        outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
        if (semn_det<=1)
        {
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"*");
            semn_det++;
        }
        else
            outtextxy(50+latura*A.nrColoane+25+15+k+30,50+latura*A.nrLinii/2,"-");
        k=k+45;
    }

    aprinde_elem_det3(A,1,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"-");
    k=k+20;

    aprinde_elem_det3(A,1,1,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,2,3,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"*");
    k=k+20;
    aprinde_elem_det3(A,3,2,LIGHTMAGENTA,k);
    k=k+35;
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
    det=calculeazaDeterminant3(A);
    char s[10];

    snprintf(s, sizeof(s), "%d", det);
    outtextxy(50+latura*A.nrColoane+25+15+k,50+latura*A.nrLinii/2,s);
    if(det==0)
        outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este egal cu 0, nu se poate calcula inversa");
    else
        outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este diferit de 0, se poate calcula inversa si se poate trece la pasul urmator");



}

void minori( matrice M,matrice T,int numar_linii,int numar_coloane, matrice &C,int k1,int k2)
{
    initializeazaMatrice_pentruAdjuncta(M,T, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(M,true);
    initializeazaMatrice(C, M.nrColoane, M.nrLinii,70+M.nrColoane*latura+50,50,true);
    deseneazaMatrice(C,false);



    outtextxy(50+latura*M.nrColoane+25,50+latura*M.nrLinii/2,"-->");

    int vector[10] = { 0 };
    float nr = 0;
    for (int i = 1; i <= M.nrLinii; i++)
        for (int j = 1; j <= M.nrColoane; j++)
        {
            int nr = 0;
            char s1[10],s2[10],s3[10],s4[10];
            aprindelinie2(M,i,j,LIGHTRED);

            for (int k = 1; k <=M.nrLinii; k++)
                for (int l = 1; l <=M.nrColoane; l++)
                    if (k != i && l != j)
                    {
                        //cout << M[k][l]<<" ";
                        vector[nr] = M.elem[k][l];
                        schimbare_culoare(M,k,l,LIGHTCYAN);
                        nr++;
                    }
            C.elem[i][j]=vector[0] *vector[1] - vector[2]* vector[3];
            snprintf(s1, sizeof(s1), "%d",vector[0]);
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,s1);
            k1=k1+25;
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,"*");
            k1=k1+25;
            snprintf(s2, sizeof(s2), "%d",vector[1]);
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,s2);
            k1=k1+25;
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,"-");
            k1=k1+25;
            snprintf(s3, sizeof(s3), "%d",vector[2]);
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,s3);
            k1=k1+25;
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,"*");
            k1=k1+25;
            snprintf(s4, sizeof(s4), "%d",vector[3]);
            outtextxy(20+k1,50+latura*M.nrColoane+25+15+k2,s4);
            k2=k2+40;
            k1=0;

            if ((i + j ) % 2 == 1)
                C.elem[i][j] *= -1;
            aprindeC_inmultire(C,i,j,LIGHTRED);
            aprindelinie2(M,i,j,WHITE);

        }
    schimbare_culoare(M,1,1,WHITE);
    schimbare_culoare(M,1,2,WHITE);
    schimbare_culoare(M,2,1,WHITE);
    schimbare_culoare(M,2,2,WHITE);


}
void afisare_operatie_inmultire(int v[],int a,int k1,int k2,matrice M,matrice N)
{
    for(int i=1; i<=a; i++)
    {

        char s[10];
        snprintf(s, sizeof(s), "%d",v[i]);
        outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,s);
        k1=k1+25;
        if (i!=a)
        {
            if (i%2==1)
                outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,"*");
            else
                outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,"+");
            k1=k1+25;
        }

    }

}
void afisare_operatie_inmultire_float(float v[],int a,int k1,int k2,matrice M,matrice_float N)
{
    for(int i=1; i<=a; i++)
    {

        char s[10];
        snprintf(s, sizeof(s), "%.2f",v[i]);
        outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+27+25+k2,s);
        k1=k1+30;
        if (i!=a)
        {
            if (i%2==1)
                outtextxy(20+k1+17,50+latura*max(M.nrColoane,N.nrColoane)+27+25+k2,"*");
            else
                outtextxy(20+k1+17,50+latura*max(M.nrColoane,N.nrColoane)+27+25+k2,"+");
            k1=k1+40;
        }

    }

}

/*void afisare_operatie_inmultire_float(int v[],int a,int k1,int k2,matrice M,matrice_float N)
{
for(int i=1;i<=a;i++)
{



    if (i!=a)
        {if (i%2==1)
          {
          char s[10];
           snprintf(s, sizeof(s), "%d",v[i]);
           outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,s);
           k1=k1+30;
           outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,"*");
           }

        else
           {
            char s[10];
           snprintf(s, sizeof(s), "%.2f",v[i]);
           outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,s);
           k1=k1+30;
           outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,"*");
            outtextxy(20+k1,50+latura*max(M.nrColoane,N.nrColoane)+25+25+k2,"+");

           }

        k1=k1+30;
        }

}

}*/


void inmultirematrici2(matrice A,matrice B,int Alin,int Acol,int Blin,int Bcol,matrice &C)
{
    initializeazaMatrice(A, Alin, Acol,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaMatriceB(B, Blin, Bcol,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(B,true);

    initializeazaMatrice(C,Alin, Bcol, 50+(A.nrColoane+B.nrColoane)*latura+100,50,false);
    deseneazaMatrice(C,false);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"*");
    outtextxy(50+latura*(A.nrColoane+B.nrColoane)+50+25,50+latura*A.nrLinii/2,"=");
    if (A.nrColoane != B.nrLinii)
        outtextxy(20,50+latura*A.nrColoane+25,"Nu se poate efectua operatia");

    else

    {
        int v[100],a=0,k2=-30;
        C.nrLinii = A.nrLinii;
        C.nrColoane = B.nrColoane;

        for (int i = 1; i <= C.nrLinii; ++i)
        {
            for (int j = 1; j <= C.nrColoane; ++j)
            {
                C.elem[i][j] = 0;
                aprinde_linie(A,i,LIGHTRED);
                aprinde_col(B,j,LIGHTRED);
                for (int k = 1; k <= A.nrColoane; ++k)

                {
                    C.elem[i][j] += A.elem[i][k] * B.elem[k][j];

                    a++;
                    v[a]=A.elem[i][k];
                    a++;
                    v[a]=B.elem[k][j];
                }
                aprindeC_inmultire(C,i,j,LIGHTBLUE);
                afisare_operatie_inmultire(v,a,0,k2,A,B);
                a=0;
                k2=k2+30;

            }

        }

    }
    afisare_in_fisier_matrice(C,C.nrLinii,C.nrColoane);
}

void inmultirematrici_inversa(matrice A,matrice_float B,matrice_float I,int Alin,int Acol,matrice_float C)
{
    initializeazaMatrice(A, Alin, Acol,50,50,true);
    deseneazaMatrice(A,true);
    initializeazaMatrice_pentruAdjuncta_float(B,I,Alin,Acol,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice_float(B,true);

    initializeazaMatrice_float(C,Alin, Acol, 50+(A.nrColoane+B.nrColoane)*latura+100,50,false);
    deseneazaMatrice_float(C,false);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"*");
    outtextxy(50+latura*(A.nrColoane+B.nrColoane)+50+25,50+latura*A.nrLinii/2,"=");
    if (A.nrColoane != B.nrLinii)
        outtextxy(20,50+latura*A.nrColoane+25,"Nu se poate efectua operatia");

    else

    {
        int a=0,k2=-30;
        float v[1000];
        C.nrLinii = A.nrLinii;
        C.nrColoane = B.nrColoane;

        for (int i = 1; i <= C.nrLinii; ++i)
        {
            for (int j = 1; j <= C.nrColoane; ++j)
            {
                C.elem[i][j] = 0;
                aprinde_linie(A,i,LIGHTRED);
                aprinde_col_float(B,j,LIGHTRED);
                for (int k = 1; k <= A.nrColoane; ++k)

                {
                    C.elem[i][j] += A.elem[i][k] * B.elem[k][j];

                    a++;
                    v[a]= float(A.elem[i][k]);
                    a++;
                    v[a]=B.elem[k][j];
                }
                //aprindeC_inmultire(C,i,j,LIGHTBLUE);
                aprinde_float(C,i,j,LIGHTBLUE);
                afisare_operatie_inmultire_float(v,a,0,k2,A,B);
                a=0;
                k2=k2+30;

            }

        }
afisare_in_fisier_matrice_float(C,C.nrLinii,C.nrColoane);
    }

}


void impartiredeterminant(matrice M,matrice Adj,matrice_float &N,int numar_linii,int numar_coloane,float det)
{
    initializeazaMatrice_pentruAdjuncta(M,Adj, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(M,true);
    outtextxy(50+latura*M.nrColoane+25,50+latura*M.nrLinii/2,"*");
    outtextxy(50+latura*M.nrColoane+40,50+latura*M.nrLinii/2,"------");
    outtextxy(56+latura*M.nrColoane+40,40+latura*M.nrLinii/2,"1");
    char s[10];
    snprintf(s, sizeof(s), "%d",int(det));
    outtextxy(53+latura*M.nrColoane+40,60+latura*M.nrLinii/2,s);
    outtextxy(100+latura*M.nrColoane+40,50+latura*M.nrLinii/2,"=");
    initializeazaMatrice_float(N, M.nrColoane, M.nrLinii,110+M.nrColoane*latura+50,50,false);
    deseneazaMatrice_float(N,false);
    for (int i=1; i<=M.nrLinii; i++)
        for (int j=1; j<=M.nrColoane; j++)
        {
            aprinde(M,i,j,LIGHTRED);

            N.elem[i][j]= M.elem[i][j]/det;
            //char s1[10];
            //snprintf(s1, sizeof(s1), "%d",M.elem[i][j]);
            //outtextxy(700+latura*M.nrColoane+40,50+latura*M.nrLinii/2,s1);

            aprinde_float(N,i,j,LIGHTGREEN);
        }
        afisare_in_fisier_matrice_float(N,N.nrLinii,N.nrColoane);

}

void Inversa(matrice A, int numar_linii, int numar_coloane, matrice T,matrice Adj,matrice_float I)
{
    outtextxy(20,20,"Pas 1: verificare determinant matrice diferit de 0");

    //initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    //deseneazaMatrice(A,true);
    int det=0,determinant;
    determinant_ordin3_inversa(A,numar_linii,numar_coloane,det);
    /*determinant=calculeazaDeterminant3(A);
    if(determinant==0)
    outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este egal cu 0, nu se poate calcula inversa");
    else
     outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este diferit de 0, se poate calcula inversa si se poate trece la pasul urmator");*/



}

void InversaB(matrice A, int numar_linii, int numar_coloane, matrice T,matrice Adj,matrice_float I)
{
    outtextxy(20,20,"Pas 1: verificare determinant matrice diferit de 0");

    //initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    //deseneazaMatrice(A,true);
    int det=0,determinant;
    determinant_ordin3_inversaB(A,numar_linii,numar_coloane,det);
    /*determinant=calculeazaDeterminant3(A);
    if(determinant==0)
    outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este egal cu 0, nu se poate calcula inversa");
    else
     outtextxy(20,50+latura*A.nrColoane+25+25,"Determinatul este diferit de 0, se poate calcula inversa si se poate trece la pasul urmator");*/



}

void ridicare_putere2(matrice A,matrice B, int numar_linii,int numar_coloane,matrice C)
{
    initializeazaMatrice(A,numar_linii,numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaMatrice(B,numar_linii,numar_coloane,50+A.nrColoane*latura+50,50,true);
    deseneazaMatrice(B,true);

    initializeazaMatrice(C,A.nrLinii, B.nrColoane, 50+(A.nrColoane+B.nrColoane)*latura+100,50,false);
    deseneazaMatrice(C,false);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"*");
    outtextxy(50+latura*(A.nrColoane+B.nrColoane)+50+25,50+latura*A.nrLinii/2,"=");
    if (A.nrColoane != B.nrLinii)
        outtextxy(20,50+latura*A.nrColoane+25,"Nu se poate efectua operatia");

    else

    {
        int v[100],a=0,k2=-30;
        C.nrLinii = A.nrLinii;
        C.nrColoane = B.nrColoane;

        for (int i = 1; i <= C.nrLinii; ++i)
        {
            for (int j = 1; j <= C.nrColoane; ++j)
            {
                C.elem[i][j] = 0;
                aprinde_linie(A,i,LIGHTRED);
                aprinde_col(B,j,LIGHTRED);
                for (int k = 1; k <= A.nrColoane; ++k)

                {
                    C.elem[i][j] += A.elem[i][k] * B.elem[k][j];

                    a++;
                    v[a]=A.elem[i][k];
                    a++;
                    v[a]=B.elem[k][j];
                }
                aprindeC_inmultire(C,i,j,LIGHTBLUE);
                afisare_operatie_inmultire(v,a,0,k2,A,B);
                a=0;
                k2=k2+30;

            }

        }

    }
    afisare_in_fisier_matrice(C,C.nrLinii,C.nrColoane);
}
void suma_diagonala_principala(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
    {
        aprinde(A,i,i,LIGHTMAGENTA);
        suma=suma+A.elem[i][i];

        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][i]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }
//k=k+15;
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        for(int i=1;i<=A.nrLinii;i++)
            schimbare_culoare(A,i,i,LIGHTMAGENTA);
            afisare_in_fisier_rezultat(suma);

}

void suma_deasupra_diagonala_principala(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
            schimbare_culoare(A,i,i,LIGHTRED);
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {
        if(i < j)
        {aprinde(A,i,j,LIGHTMAGENTA);
        suma=suma+A.elem[i][j];

        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;}

    }
//k=k+15;
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);

        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
        if(i < j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
afisare_in_fisier_rezultat(suma);
}
void suma_sub_diagonala_principala(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
            schimbare_culoare(A,i,i,LIGHTRED);
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {
        if(i > j)
        {aprinde(A,i,j,LIGHTMAGENTA);
        suma=suma+A.elem[i][j];

        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        //if(j!=A.nrLinii-1 && i==A.nrLinii)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;}

    }
//k=k+15;
setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
        if(i > j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
afisare_in_fisier_rezultat(suma);
}
void suma_diagonala_secundara(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j==A.nrLinii+1)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);

        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
        if(i+j==A.nrLinii+1)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
afisare_in_fisier_rezultat(suma);
}


void suma_deasupra_diagonala_secundara(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");

    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
          if(i+j==A.nrLinii+1)
            schimbare_culoare(A,i,j,LIGHTRED);




    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j<A.nrLinii+1)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);

        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
        if(i+j<A.nrLinii+1)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
afisare_in_fisier_rezultat(suma);
}

void suma_sub_diagonala_secundara(matrice A,int numar_linii,int numar_coloane)
{  int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
          if(i+j==A.nrLinii+1)
            schimbare_culoare(A,i,j,LIGHTRED);
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j>A.nrLinii+1)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        //if(A.elem[i][j]!=A.elem[A.nrLinii][A.nrLinii])
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;
setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);
    outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;

            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
 for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
        if(i+j>A.nrLinii+1)
          schimbare_culoare(A,i,j,LIGHTMAGENTA);
afisare_in_fisier_rezultat(suma);
}

void suma_zonaNord(matrice A,int numar_linii,int numar_coloane)
{
    int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
             if(!(i+j<A.nrLinii+1 && i<j))
                {  if(i==j || i+j==A.nrLinii+1)
                    schimbare_culoare(A,i,j,LIGHTCYAN);
                    else
                        schimbare_culoare(A,i,j,LIGHTGRAY);
                }
    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j<A.nrLinii+1 && i<j)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;

setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);
 if(A.nrLinii>3)
    {outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);}

         for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
            if(i+j<A.nrLinii+1 && i<j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
            afisare_in_fisier_rezultat(suma);
}

void suma_zonaSud(matrice A,int numar_linii,int numar_coloane)
{
    int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");

    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
             if(!(i+j>A.nrLinii+1 && i>j))
                {  if(i==j || i+j==A.nrLinii+1)
                    schimbare_culoare(A,i,j,LIGHTCYAN);
                    else
                        schimbare_culoare(A,i,j,LIGHTGRAY);
                }


    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j>A.nrLinii+1 && i>j)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;

setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);
 if(A.nrLinii>3)
    {outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);}
        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
            if(i+j>A.nrLinii+1 && i>j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
            afisare_in_fisier_rezultat(suma);
}

void suma_zonaVest(matrice A,int numar_linii,int numar_coloane)
{
    int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
     for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
             if(!(i+j<A.nrLinii+1 && i>j))
                {  if(i==j || i+j==A.nrLinii+1)
                    schimbare_culoare(A,i,j,LIGHTCYAN);
                    else
                        schimbare_culoare(A,i,j,LIGHTGRAY);
                }

    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j<A.nrLinii+1 && i>j)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }}
//k=k+15;

setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);
 if(A.nrLinii>3)
    {outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);}
        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
            if(i+j<A.nrLinii+1 && i>j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
            afisare_in_fisier_rezultat(suma);

}

void suma_zonaEest(matrice A,int numar_linii,int numar_coloane)
{
    int suma=0,k=20;
    initializeazaMatrice(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");

    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
             if(!(i+j>A.nrLinii+1 && i<j))
                {  if(i==j || i+j==A.nrLinii+1)
                    schimbare_culoare(A,i,j,LIGHTCYAN);
                    else
                        schimbare_culoare(A,i,j,LIGHTGRAY);
                }


    for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
    {

    if(i+j>A.nrLinii+1 && i<j)
        {suma=suma+A.elem[i][j];
        aprinde(A,i,j,LIGHTMAGENTA);
        char s[10];
        snprintf(s, sizeof(s), "%d", A.elem[i][j]);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);
        k=k+35;
        if(i!=A.nrLinii-1)
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"+");
        k=k+20;

    }


    }
//k=k+15;

setcolor(BLACK);
outtextxy(50+latura*A.nrColoane+25+k-20,50+latura*A.nrLinii/2,"+");
 setcolor(WHITE);

 if(A.nrLinii>3)
    {outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,"=");
    k=k+20;
            char s[10];
        snprintf(s, sizeof(s), "%d", suma);
        outtextxy(50+latura*A.nrColoane+25+k,50+latura*A.nrLinii/2,s);}

        for(int i=1;i<=A.nrLinii;i++)
        for(int j=1;j<=A.nrColoane;j++)
            if(i+j>A.nrLinii+1 && i<j)
            schimbare_culoare(A,i,j,LIGHTMAGENTA);
            afisare_in_fisier_rezultat(suma);
}

void ZonaNord_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_zonaNord(A,nr_lin_fisier,nr_col_fisier);



}
void CitesteSir(int x, int y, char mesaj[200], char S[200])
{

    char Enter = 13, BackSpace = 8, Escape = 27;
    char MultimeDeCaractereAcceptabile[200] = "0123456789-";
    char Sinitial[200], tasta;
    char Ss[200], mesajs[200];

    strcpy(Sinitial,S);
    settextstyle(DEFAULT_FONT, 0, 3);
    setcolor(WHITE);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    strcpy(mesajs,mesaj);
    strcat(mesajs,":");
    outtextxy(x,y,mesajs);
    x=x+textwidth(mesajs);
    strcpy(S,"");
    do
    {
        tasta=getch();
        if (tasta==0)
        {
            tasta=getch();
            Beep(200,200);
        }
        else if (strchr(MultimeDeCaractereAcceptabile,tasta))
        {
            // stergem fostul sir
            strcpy(Ss,S);
            strcat(Ss,"_ ");
            setcolor(BLACK);
            outtextxy(x,y,Ss);
            char tt2[2];
            tt2[0]=tasta;
            tt2[1]=0;
            strcat(S,tt2);
            // afisam pe cel nou }
            strcpy(Ss,S);
            strcat(Ss,"_ ");
            setcolor(WHITE);
            outtextxy(x,y,Ss);
        }
        else if (tasta == BackSpace)
        {
            if (!strcmp(S,""))
                Beep(200,200);
            else
            {
                strcpy(Ss,S);
                strcat(Ss,"_");
                setcolor(BLACK);
                outtextxy(x,y,Ss);
                setcolor(WHITE);
                S[strlen(S)-1]=0;
                strcpy(Ss,S);
                strcat(Ss,"_ ");
                outtextxy(x,y,Ss);
            }
        }
        else if (tasta!=Enter && tasta!=Escape)
            Beep(200,200);
    }
    while (tasta!=Enter && tasta!=Escape);
    if (tasta == Escape)
        strcpy(S,Sinitial);
    setcolor(BLACK);
    strcpy(Ss,S);
    strcat(Ss," ");
    outtextxy(x,y,Ss);
    setcolor(WHITE);
    //cnt++;
    outtextxy(x,y,S);


}

void citire_matriceA()
{
    //contor_cit=0;
char S[200];
int k=0,k2=80;
    CitesteSir(100, 50+k, "Numar linii", S);
    nr_lin_tast=atoi(S);
    k=k+25;

    CitesteSir(100,50+k,"Numar coloane",S);
    nr_col_tast=atoi(S);
    k=k+25;

   for(int i=1;i<=nr_lin_tast;i++)
    for(int j=1;j<=nr_col_tast;j++)
   {

     outtextxy(100,50+k,"Elementul" );

     char si[10],sj[10];

     snprintf(si, sizeof(si), "%d",i);
     outtextxy(100+200,50+k,si);

      snprintf(sj, sizeof(sj), "%d",j);
      outtextxy(100+218,50+k,sj);

     CitesteSir(100+250,50+k,"",S);
     contor_cit++;
     vector_citire[contor_cit]=atoi(S);


     k=k+25;
   }

}

void ZonaNord_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    suma_zonaNord(A,nr_lin_tast,nr_col_tast);

}

void ZonaSud_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_zonaSud(A,nr_lin_fisier,nr_col_fisier);



}

void ZonaSud_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    suma_zonaSud(A,nr_lin_tast,nr_col_tast);

}



void ZonaEst_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_zonaEest(A,nr_lin_fisier,nr_col_fisier);



}

void ZonaEst_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    suma_zonaEest(A,nr_lin_tast,nr_col_tast);

}


void ZonaVest_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_zonaVest(A,nr_lin_fisier,nr_col_fisier);



}


void ZonaVest_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    suma_zonaVest(A,nr_lin_tast,nr_col_tast);

}








void citire_matriceAB()
{
    //contor_cit=0;
    char S[200];
    int k=0,k2=80;
    outtextxy(100,25,"Matricea A" );
    CitesteSir(100, 50+k, "Numar linii", S);
    nr_lin_tast=atoi(S);
    k=k+20;

    CitesteSir(100,50+k,"Numar coloane",S);
    nr_col_tast=atoi(S);
    k=k+20;

    for(int i=1; i<=nr_lin_tast; i++)
        for(int j=1; j<=nr_col_tast; j++)
        {

            outtextxy(100,50+k,"Elementul" );

            char si[10],sj[10];

            snprintf(si, sizeof(si), "%d",i);
            outtextxy(100+200,50+k,si);

            snprintf(sj, sizeof(sj), "%d",j);
            outtextxy(100+218,50+k,sj);

            CitesteSir(100+250,50+k,"",S);
            contor_cit++;
            vector_citire[contor_cit]=atoi(S);


            k=k+20;
        }

    k=k+10;
    outtextxy(100,50+k,"Matricea B" );
    k=k+20;
    CitesteSir(100, 50+k, "Numar linii", S);
    nr_lin_tastB=atoi(S);
    k=k+20;

    CitesteSir(100,50+k,"Numar coloane",S);
    nr_col_tastB=atoi(S);
    k=k+20;

    for(int i=1; i<=nr_lin_tastB; i++)
        for(int j=1; j<=nr_col_tastB; j++)
        {

            outtextxy(100,50+k,"Elementul" );

            char si[10],sj[10];

            snprintf(si, sizeof(si), "%d",i);
            outtextxy(100+200,50+k,si);

            snprintf(sj, sizeof(sj), "%d",j);
            outtextxy(100+218,50+k,sj);

            CitesteSir(100+250,50+k,"",S);
            contor_citB++;
            vector_citireB[contor_citB]=atoi(S);


            k=k+20;
        }





}

void citeste_vector()
{
    char S[200];
    int k=0;
    CitesteSir(100, 50+k, "Numar elemente", S);
    nr_valori_tast=atoi(S);
    k=k+25;



    for(int j=1; j<=nr_valori_tast; j++)
    {

        outtextxy(100,50+k,"Elementul" );

        char s[10];

        snprintf(s, sizeof(s), "%d",j);
        outtextxy(100+200,50+k,s);

        CitesteSir(100+230,50+k,"",S);
        contor_vector++;
        vector_citire_Vector[contor_vector]=atoi(S);


        k=k+25;
    }

}

void citeste_vector_scalar()
{
    char S[200];
    int k=0;
    CitesteSir(100, 50+k, "Numar elemente", S);
    nr_valori_tast=atoi(S);
    k=k+25;



    for(int j=1; j<=nr_valori_tast; j++)
    {

        outtextxy(100,50+k,"Elementul" );

        char s[10];

        snprintf(s, sizeof(s), "%d",j);
        outtextxy(100+200,50+k,s);

        CitesteSir(100+230,50+k,"",S);
        contor_vector++;
        vector_citire_Vector[contor_vector]=atoi(S);


        k=k+25;
    }
    CitesteSir(100,50+k,"Alege un scalar",S);
    scalar=atoi(S);
}
void suma_elemente_vector(matrice A,int numar_linii,int numar_coloane)
{
    initializeazaVector(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);


    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"--->");
    int k=0,suma=0;
    for (int i=1; i<=A.nrLinii; i++)
        for (int j=1; j<=A.nrColoane; j++)
        {
            aprinde(A,i,j,LIGHTRED);
            char sir[10];
            suma=suma+A.elem[i][j];
            snprintf(sir, sizeof(sir), "%d", A.elem[i][j]);
            outtextxy(100+k+latura*A.nrColoane+25,50+latura*A.nrLinii/2,sir);
            if(j!=A.nrColoane)
                outtextxy(100+k+latura*A.nrColoane+25+20,50+latura*A.nrLinii/2," + ");
            k+=35+strlen(sir);

        }


    char s1[256];
    snprintf(s1, sizeof(s1), "%d",suma);
    outtextxy(100+k+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    outtextxy(100+k+latura*A.nrColoane+35,50+latura*A.nrLinii/2,s1);
    afisare_in_fisier_rezultat(suma);

}
void produs_elemente_vector(matrice A,int numar_linii,int numar_coloane)
{
    initializeazaVector(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);
    outtextxy(50+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"--->");
    int k=0,produs=1;
    for (int i=1; i<=A.nrLinii; i++)
        for (int j=1; j<=A.nrColoane; j++)
        {
            aprinde(A,i,j,LIGHTRED);
            char sir[10];
            produs=produs*A.elem[i][j];
            snprintf(sir, sizeof(sir), "%d", A.elem[i][j]);
            outtextxy(100+k+latura*A.nrColoane+25,50+latura*A.nrLinii/2,sir);
            if(j!=A.nrColoane)
                outtextxy(100+k+latura*A.nrColoane+25+20,50+latura*A.nrLinii/2," * ");
            k+=35+strlen(sir);

        }


    char s1[256];
    snprintf(s1, sizeof(s1), "%d",produs);
    outtextxy(100+k+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"=");
    outtextxy(100+k+latura*A.nrColoane+35,50+latura*A.nrLinii/2,s1);
    afisare_in_fisier_rezultat(produs);

}


void inmultire_cu_scalar(matrice A,matrice C,int numar_linii,int numar_coloane,int scalar)
{

    initializeazaVector(A, numar_linii, numar_coloane,50,50,true);
    deseneazaMatrice(A,true);

    initializeazaVector(C,numar_linii, numar_coloane,100+A.nrColoane*latura+50,50,false);
    deseneazaMatrice(C,false);
    char s1[256];
    snprintf(s1, sizeof(s1), "%d",scalar);
    outtextxy(50+latura*A.nrColoane+25-3,50+latura*A.nrLinii/2,"*");
    //settextstyle(8 , 0, 3);
    outtextxy(55+latura*A.nrColoane+25,47+latura*A.nrLinii/2,s1);
    //settextstyle(10,0,0);
    outtextxy(85+latura*A.nrColoane+25,50+latura*A.nrLinii/2,"--->");
    for (int i=1; i<=A.nrLinii; i++)
        for (int j=1; j<=A.nrColoane; j++)
        {
            aprinde(A,i,j,LIGHTRED);
            C.elem[i][j]=A.elem[i][j] *scalar;
            aprinde(C,i,j,LIGHTGREEN);
        }

afisare_in_fisier_vector(C,C.nrColoane);
}

void fisier_in_vector_Vector_natural()
{
    FILE
    *fisier=fopen("inputvector","r");
    int x;
    fscanf(fisier,"%d",&x);
    nr_valori_fisier=x;

    contor_vector=0;

    for (int j=1; j<=nr_valori_fisier; j++)
    {
        fscanf(fisier,"%d",&x);
        contor_vector++;
        vector_citire_Vector[contor_vector]=x;;
    }
    fscanf(fisier,"%d",&x);
    scalar=x;
    fclose(fisier);
}

void initializare_matrice_frecventa(matrice &M,int nrLin, int nrCol, int xx, int yy, bool aleatoriu)
{
    M.nrLinii=nrLin;
    M.nrColoane=nrCol;
    M.x=xx;
    M.y=yy;
    int cnt=1;
        for (int j=1; j<=M.nrColoane; j++)
        {
            M.elem[1][j]=vector_citire_Vector[cnt];
            cnt++;
        }
    for (int j=1; j<=M.nrColoane; j++)
     M.elem[2][j]=0;
}

void sortare_frecventa_cresc(matrice A,matrice C,int numar_linii,int numar_coloane)
{
 initializare_matrice_frecventa(A,numar_linii,numar_coloane,50,50,true);
 deseneazaMatrice(A,true);

 initializeazaVector(C,1, numar_coloane,50,A.nrLinii*latura+150,false);
    deseneazaMatrice(C,false);

outtextxy(A.nrColoane*latura+100,65,"Valoarea maxima din vector este: ");

outtextxy(A.nrColoane*latura+100,130,"Frecventa numerelor din vector ");

   int frq[100000] = { 0 }, MAXI = A.elem[1][1];;
	for (int i = 1; i <= A.nrColoane; i++)
	{   int x=frq[A.elem[1][i]];
		frq[A.elem[1][i]]++;
		A.elem[2][i]=frq[A.elem[1][i]];
		aprinde(A,2,i,LIGHTGREEN);

		if(frq[A.elem[1][i]]>x && frq[A.elem[1][i]]>1 )
        for(int j = 1; j <i; j++)
        {
            A.elem[2][j]=frq[A.elem[1][j]];
            if(A.elem[1][j]==A.elem[1][i])
		aprinde(A,2,j,LIGHTGREEN);
        }
		if (A.elem[1][i] > MAXI)
			MAXI =A.elem[1][i] ;


    char s1[256];
           snprintf(s1, sizeof(s1), "%d",MAXI);
       outtextxy(A.nrColoane*latura+340,65,s1);

	}
setcolor(LIGHTRED);
outtextxy(A.nrColoane*latura+100,130,"Frecventa numerelor din vector ");
for(int i=1;i<=A.nrColoane;i++)
    schimbare_culoare(A,2,i,LIGHTRED);
setcolor(WHITE);
outtextxy(A.nrColoane*latura+80,A.nrLinii*latura+150+25," Afisarea numerelor ce au frecventa diferita de 0, prin parcurgerea vectorului de frecventa de la 0 la valoarea maxima din vector");
	int k = 1;
	for (int i = 0; i <= MAXI; i++)
        if(frq[i]!=0)
		while (frq[i]--)
		{
			C.elem[1][k] = i;
			aprinde(C,1,k,LIGHTMAGENTA);
			k++;
		}
		afisare_in_fisier_vector(C,C.nrColoane);

}

void sortare_frecventa_descrescator(matrice A,matrice C,int numar_linii,int numar_coloane)
{
 initializare_matrice_frecventa(A,numar_linii,numar_coloane,50,50,true);
 deseneazaMatrice(A,true);

 initializeazaVector(C,1, numar_coloane,50,A.nrLinii*latura+150,false);
    deseneazaMatrice(C,false);

outtextxy(A.nrColoane*latura+100,65,"Valoarea maxima din vector este: ");

outtextxy(A.nrColoane*latura+100,130,"Frecventa numerelor din vector ");

   int frq[100000] = { 0 }, MAXI = A.elem[1][1];;
	for (int i = 1; i <= A.nrColoane; i++)
	{   int x=frq[A.elem[1][i]];
		frq[A.elem[1][i]]++;
		A.elem[2][i]=frq[A.elem[1][i]];
		aprinde(A,2,i,LIGHTGREEN);

		if(frq[A.elem[1][i]]>x && frq[A.elem[1][i]]>1 )
        for(int j = 1; j <i; j++)
        {
            A.elem[2][j]=frq[A.elem[1][j]];
            if(A.elem[1][j]==A.elem[1][i])
		aprinde(A,2,j,LIGHTGREEN);
        }
		if (A.elem[1][i] > MAXI)
			MAXI =A.elem[1][i] ;


    char s1[256];
           snprintf(s1, sizeof(s1), "%d",MAXI);
       outtextxy(A.nrColoane*latura+340,65,s1);

	}
setcolor(LIGHTRED);
outtextxy(A.nrColoane*latura+100,130,"Frecventa numerelor din vector ");
for(int i=1;i<=A.nrColoane;i++)
    schimbare_culoare(A,2,i,LIGHTRED);
setcolor(WHITE);
outtextxy(A.nrColoane*latura+80,A.nrLinii*latura+150+25," Afisarea numerelor ce au frecventa diferita de 0, prin parcurgerea vectorului de frecventa de la valoarea maxima din vector la 0 ");
	int k = 1;
	for (int i = MAXI; i >=0; i--)
        if(frq[i]!=0)
		while (frq[i]--)
		{
			C.elem[1][k] = i;
			aprinde(C,1,k,LIGHTMAGENTA);
			k++;
		}
afisare_in_fisier_vector(C,C.nrColoane);



}


void impartire_matrici_tast()
{  matrice A,B,C,D,T,Adj,Adun,Scad;
matrice_float I,Rez,B1;

    int numar_linii=3;
int numar_coloane;
numar_coloane=numar_linii;
 citire_matriceAB();
continuare();
   initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

outtextxy(50,25,"Impartirea a doua matrici se face prin inmultirea primei matrici cu inversa celei de-a doua");

impartire_matrici(A,B,nr_lin_tast,nr_col_tast);

initializeazaMatriceB(B,nr_lin_tastB,nr_col_tastB,50+A.nrColoane*latura+50,50,true);
float determinant;
   determinant=B.elem[1][1] * (B.elem[2][2] * B.elem[3][3] - B.elem[3][2] * B.elem[2][3])
        - B.elem[1][2] * (B.elem[2][1] * B.elem[3][3] - B.elem[3][1] * B.elem[2][3])
        + B.elem[1][3] * (B.elem[2][1] * B.elem[3][2] - B.elem[3][1] * B.elem[2][2]);
        //determinant=calculeazaDeterminant3(B);
//cout<<determinant;

   pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   InversaB(B,3,3,T,Adj,I);

   if(determinant!=0)
  {
      pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");//
    outtextxy(20,20,"Pas 2: creare transpusa matricei");
    transpusaB(B,T,3,3);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 3: creare matricea adjuncta");
    minori(C,T,3,3,Adj,0,0);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 4: Impartirea elementelor prin determinant");
    impartiredeterminant(D,Adj,I,3,3,determinant);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 5: Inmultirea primei matrici cu inversa celei de-a doua");
    inmultirematrici_inversa(A,B1,I,nr_lin_tast,nr_col_tast,Rez);

    }


}


void inversa_tast()
{
  int numar_linii=3;
   // int numar_coloane=2+rand()%5;
int numar_coloane;
numar_coloane=numar_linii;
matrice A,B,C,D,T,Adj,Adun,Scad;
matrice_float I,Rez,B1;

citire_matriceA();
    initializeazaMatrice(A,nr_lin_tast,nr_col_tast,50,50,true);
    float determinant;
   determinant=A.elem[1][1] * (A.elem[2][2] * A.elem[3][3] - A.elem[3][2] * A.elem[2][3])
        - A.elem[1][2] * (A.elem[2][1] * A.elem[3][3] - A.elem[3][1] * A.elem[2][3])
        + A.elem[1][3] * (A.elem[2][1] * A.elem[3][2] - A.elem[3][1] * A.elem[2][2]);
    continuare();
   initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   Inversa(A,3,3,T,Adj,I);

   if(determinant!=0)
  {
      pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");//
    outtextxy(20,20,"Pas 2: creare transpusa matricei");
    transpusa(A,T,3,3);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 3: creare matricea adjuncta");
    minori(B,T,3,3,Adj,0,0);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 4: Impartirea elementelor prin determinant");
    impartiredeterminant(D,Adj,I,3,3,determinant);


}}


void inversa_fisier()
{  int numar_linii=3;
   // int numar_coloane=2+rand()%5;
int numar_coloane;
numar_coloane=numar_linii;
matrice A,B,C,D,T,Adj,Adun,Scad;
matrice_float I,Rez,B1;
    fisier_in_vector_A();
    initializeazaMatrice(A,nr_lin_fisier,nr_col_fisier,50,50,true);
   float determinant;
   determinant=A.elem[1][1] * (A.elem[2][2] * A.elem[3][3] - A.elem[3][2] * A.elem[2][3])
        - A.elem[1][2] * (A.elem[2][1] * A.elem[3][3] - A.elem[3][1] * A.elem[2][3])
        + A.elem[1][3] * (A.elem[2][1] * A.elem[3][2] - A.elem[3][1] * A.elem[2][2]);

        //cout<<A.elem[1][1];
   Inversa(A,3,3,T,Adj,I);

   if(determinant!=0)
  {
      pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");//
    outtextxy(20,20,"Pas 2: creare transpusa matricei");
    transpusa(A,T,3,3);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 3: creare matricea adjuncta");
    minori(B,T,3,3,Adj,0,0);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 4: Impartirea elementelor prin determinant");
    impartiredeterminant(D,Adj,I,3,3,determinant);

    }
}


void impartire_matrici_fisier()
{

    int numar_linii=3;
   // int numar_coloane=2+rand()%5;
int numar_coloane;
numar_coloane=numar_linii;
matrice A,B,C,D,T,Adj,Adun,Scad;
matrice_float I,Rez,B1;
outtextxy(50,25,"Impartirea a doua matrici se face prin inmultirea primei matrici cu inversa celei de-a doua");
fisier_in_vector_A();
fisier_in_vector_B();
impartire_matrici(A,B,nr_lin_fisier,nr_col_fisier);

initializeazaMatriceB(B,nr_lin_fisierB,nr_col_fisierB,50+A.nrColoane*latura+50,50,true);
float determinant;
   determinant=B.elem[1][1] * (B.elem[2][2] * B.elem[3][3] - B.elem[3][2] * B.elem[2][3])
        - B.elem[1][2] * (B.elem[2][1] * B.elem[3][3] - B.elem[3][1] * B.elem[2][3])
        + B.elem[1][3] * (B.elem[2][1] * B.elem[3][2] - B.elem[3][1] * B.elem[2][2]);
        //determinant=calculeazaDeterminant3(B);
//cout<<determinant;

   pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   InversaB(B,3,3,T,Adj,I);

   if(determinant!=0)
  {
      pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");//
    outtextxy(20,20,"Pas 2: creare transpusa matricei");
    transpusaB(B,T,3,3);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 3: creare matricea adjuncta");
    minori(C,T,3,3,Adj,0,0);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 4: Impartirea elementelor prin determinant");
    impartiredeterminant(D,Adj,I,3,3,determinant);

    pasul_urmator();
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    outtextxy(20,20,"Pas 5: Inmultirea primei matrici cu inversa celei de-a doua");
    inmultirematrici_inversa(A,B1,I,nr_lin_fisier,nr_col_fisier,Rez);

    }

}

void suma_vector_fisier()
{ int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;

fisier_in_vector_Vector();
//initializeazaVector(X,1,nr_valori_fisier,50,50,true);
suma_elemente_vector(X,1,nr_valori_fisier);

}

void produs_vector_fisier()
{ int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;

fisier_in_vector_Vector();
produs_elemente_vector(X,1,nr_valori_fisier);

}

void suma_vector_tast()
{
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
citeste_vector();
continuare();
initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
suma_elemente_vector(X,1,nr_valori_tast);


}

void produs_vector_tast()
{
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
citeste_vector();
continuare();
initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
produs_elemente_vector(X,1,nr_valori_tast);
}

void vector_scalar_fisier()
{
  int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
fisier_in_vector_Vector();
inmultire_cu_scalar(X,Y,1,nr_valori_fisier,scalar);

}

void vector_scalar_tast()
{
  int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
citeste_vector_scalar();
continuare();
initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
inmultire_cu_scalar(X,Y,1,nr_valori_tast,scalar);
}

void adunare_matrici_fisier()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
  fisier_in_vector_A();
  fisier_in_vector_B();
  adunare_matrici(A,B,C,nr_lin_fisier,nr_col_fisier);

}

void scadere_matrici_fisier()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
  fisier_in_vector_A();
  fisier_in_vector_B();
  scadere_matrici(A,B,C,nr_lin_fisier,nr_col_fisier);


}

void adunare_matrici_tast()
{ matrice A,B,C,D,T,Adj,Adun,Scad;
    citire_matriceAB();
    continuare();
    int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    adunare_matrici(A,B,C,nr_lin_tast,nr_col_tast);

}
void scadere_matrici_tast()
{ matrice A,B,C,D,T,Adj,Adun,Scad;
    citire_matriceAB();
    continuare();
    int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    scadere_matrici(A,B,C,nr_lin_tast,nr_col_tast);

}

void transpusa_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
  fisier_in_vector_A();
  transpusa(A,T,nr_lin_fisier,nr_col_fisier);
}

void transpusa_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    transpusa(A,T,nr_lin_tast,nr_col_tast);;

}

void inmultire_matrici_fisier()
{
 matrice A,B,C,D,T,Adj,Adun,Scad;
matrice_float I,Rez,B1;
fisier_in_vector_A();
fisier_in_vector_B();

inmultirematrici2(A,B,nr_lin_fisier,nr_col_fisier,nr_lin_fisierB,nr_col_fisierB,C);
}

void inmultire_matrici_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceAB();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    inmultirematrici2(A,B,nr_lin_tast,nr_col_tast,nr_lin_tastB,nr_col_tastB,C);
}
void determinant_fisier()
{
 int det;
    matrice A,B,C,D,T,Adj,Adun,Scad;
    fisier_in_vector_A();
    if(nr_lin_fisier==2)
        determinant_ordin2(A,nr_lin_fisier,nr_col_fisier);
    else
        if(nr_lin_fisier==3)
       determinant_ordin3(A,nr_lin_fisier,nr_col_fisier,det);

}
void determinant_tast()
{ int det;
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

    if(nr_lin_tast==3)
     determinant_ordin3(A,nr_lin_tast,nr_col_tast,det);

    else
     determinant_ordin2(A,nr_lin_tast,nr_col_tast);

}

void determinant_ordin3_fisier()
{ int det;
    matrice A,B,C,D,T,Adj,Adun,Scad;
    fisier_in_vector_A();
    determinant_ordin3(A,nr_lin_fisier,nr_col_fisier,det);
}

void determinant_ordin2_fisier()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A_ordin2();
   determinant_ordin2(A,nr_lin_fisier,nr_col_fisier);
}

void determinant_ordin3_tast()
{ int det;
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    determinant_ordin3(A,nr_lin_tast,nr_col_tast,det);

}
void determinant_ordin2_tast()
{
   matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    determinant_ordin2(A,nr_lin_tast,nr_col_tast);

}

void ridicare_putere2_fisier()
{
matrice A,B,C,D,T,Adj,Putere,Adun,Scad;
fisier_in_vector_A();
ridicare_putere2(A,A,nr_lin_fisier,nr_col_fisier,Putere);
}

void ridicare_putere2_tast()
{
   matrice A,B,C,D,T,Adj,Putere,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    ridicare_putere2(A,A,nr_lin_tast,nr_col_tast,Putere);
}




void sortare_frecventa_cresc_fisier()
{

matrice X,Y;
fisier_in_vector_Vector_natural();
sortare_frecventa_cresc(X,Y,2,nr_valori_fisier);
}



void sortare_frecventa_descrescator_fisier()
{

matrice X,Y;
fisier_in_vector_Vector_natural();
sortare_frecventa_descrescator(X,Y,2,nr_valori_fisier);
}
void CitesteSir_natural(int x, int y, char mesaj[200], char S[200])
{

    char Enter = 13, BackSpace = 8, Escape = 27;
    char MultimeDeCaractereAcceptabile[200] = "0123456789";
    char Sinitial[200], tasta;
    char Ss[200], mesajs[200];

    strcpy(Sinitial,S);
    settextstyle(DEFAULT_FONT, 0, 3);
    setcolor(WHITE);
    settextjustify(LEFT_TEXT,TOP_TEXT);
    strcpy(mesajs,mesaj);
    strcat(mesajs,":");
    outtextxy(x,y,mesajs);
    x=x+textwidth(mesajs);
    strcpy(S,"");
    do
    {
        tasta=getch();
        if (tasta==0)
        {
            tasta=getch();
            Beep(200,200);
        }
        else if (strchr(MultimeDeCaractereAcceptabile,tasta))
        {
            // stergem fostul sir
            strcpy(Ss,S);
            strcat(Ss,"_ ");
            setcolor(BLACK);
            outtextxy(x,y,Ss);
            char tt2[2];
            tt2[0]=tasta;
            tt2[1]=0;
            strcat(S,tt2);
            // afisam pe cel nou }
            strcpy(Ss,S);
            strcat(Ss,"_ ");
            setcolor(WHITE);
            outtextxy(x,y,Ss);
        }
        else if (tasta == BackSpace)
        {
            if (!strcmp(S,""))
                Beep(200,200);
            else
            {
                strcpy(Ss,S);
                strcat(Ss,"_");
                setcolor(BLACK);
                outtextxy(x,y,Ss);
                setcolor(WHITE);
                S[strlen(S)-1]=0;
                strcpy(Ss,S);
                strcat(Ss,"_ ");
                outtextxy(x,y,Ss);
            }
        }
        else if (tasta!=Enter && tasta!=Escape)
            Beep(200,200);
    }
    while (tasta!=Enter && tasta!=Escape);
    if (tasta == Escape)
        strcpy(S,Sinitial);
    setcolor(BLACK);
    strcpy(Ss,S);
    strcat(Ss," ");
    outtextxy(x,y,Ss);
    setcolor(WHITE);
    //cnt++;
    outtextxy(x,y,S);


}
void citeste_vector_natural()
{
  char S[200];
int k=0;
    CitesteSir_natural(100, 50+k, "Numar elemente", S);
    nr_valori_tast=atoi(S);
    k=k+25;



    for(int j=1;j<=nr_valori_tast;j++)
   {

     outtextxy(100,50+k,"Elementul" );

     char s[10];

     snprintf(s, sizeof(s), "%d",j);
     outtextxy(100+200,50+k,s);

     CitesteSir_natural(100+230,50+k,"",S);
     contor_vector++;
     vector_citire_Vector[contor_vector]=atoi(S);


     k=k+25;
   }

}

void sortare_frecventa_cresc_tast()
{
    citeste_vector_natural();
    continuare();
  int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
sortare_frecventa_cresc(X,Y,2,nr_valori_tast);

}


void sortare_frecventa_descrescator_tast()
{
    citeste_vector_natural();
    continuare();
  int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
matrice X,Y;
sortare_frecventa_descrescator(X,Y,2,nr_valori_tast);

}


void sub_diag_pricipala_fisier()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_sub_diagonala_principala(A,nr_lin_fisier,nr_col_fisier);
}

void deasupra_diag_pricipala_fisier()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_deasupra_diagonala_principala(A,nr_lin_fisier,nr_col_fisier);
}

void diag_pricipala_fisier()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_diagonala_principala(A,nr_lin_fisier,nr_col_fisier);
}

void diag_secundara_fisier()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_diagonala_secundara(A,nr_lin_fisier,nr_col_fisier);
}
void sub_diag_secundara_fisier()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_sub_diagonala_secundara(A,nr_lin_fisier,nr_col_fisier);
}

void deasupra_diag_secundara_fisier()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   fisier_in_vector_A();
   suma_deasupra_diagonala_secundara(A,nr_lin_fisier,nr_col_fisier);
}


void sub_diag_pricipala_tast()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_sub_diagonala_principala(A,nr_lin_tast,nr_col_tast);
}

void deasupra_diag_pricipala_tast()
{
matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_deasupra_diagonala_principala(A,nr_lin_tast,nr_col_tast);
}

void diag_pricipala_tast()
{
  matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_diagonala_principala(A,nr_lin_tast,nr_col_tast);
}

void diag_secundara_tast()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_diagonala_secundara(A,nr_lin_tast,nr_col_tast);
}
void sub_diag_secundara_tast()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_sub_diagonala_secundara(A,nr_lin_tast,nr_col_tast);
}

void deasupra_diag_secundara_tast()
{
    matrice A,B,C,D,T,Adj,Adun,Scad;
   citire_matriceA();
   continuare();
   int numar_linii=3;
    int numar_coloane;
numar_coloane=numar_linii;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
   suma_deasupra_diagonala_secundara(A,nr_lin_tast,nr_col_tast);
}


///BUBBLE CRESC
void printMatrixbubblec(int matrix[], int sizee) {
    for (int i = 0; i < sizee; ++i) {
        std::cout << matrix[i] << " ";
    }
    std::cout << std::endl;
}

void drawMatrixbubblec(int matrix[], int sizee, int highlightIndex1, int highlightIndex2) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < sizee; ++i) {
        // Colorăm un dreptunghi în funcție de indicele elementului
        if (i == highlightIndex1 || i == highlightIndex2) {
            setcolor(i == highlightIndex1 ? GREEN : RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        // Utilizăm const_cast pentru a elimina constanța în cadrul funcției outtextxy
        const char* str = std::to_string(matrix[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 1 secundă
}

void bubbleSort(int matrix[], int sizee) {
    for (int i = 0; i < sizee - 1; ++i) {
        for (int j = 0; j < sizee - i - 1; ++j) {
            drawMatrixbubblec(matrix, sizee, j, j + 1);

            // Comparăm și schimbăm dacă este cazul
            if (matrix[j] > matrix[j + 1]) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}

///QUICK CRESC

const int arraySize = 7;  // Dimensiunea matricei
void printMatrixqc(int matrix[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i] << " ";
    }
    std::cout << std::endl;
}

void drawMatrixqc(int matrix[], int size, int highlightIndex1, int highlightIndex2, int pivotIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        // Culori pentru pivot și elemente
        if (i == pivotIndex) {
            setcolor(YELLOW);
            rectangle(x, y - 20, x + 30, y + 20);
        } else if (i == highlightIndex1 || i == highlightIndex2) {
            setcolor(i == highlightIndex1 ? GREEN : RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        // Utilizăm const_cast pentru a elimina constanța în cadrul funcției outtextxy
        const char* str = std::to_string(matrix[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 1 secundă
}

int partition1(int matrix[], int low, int high) {
    int pivot = matrix[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (matrix[j] <= pivot) {
            ++i;
            std::swap(matrix[i], matrix[j]);
        }
    }

    std::swap(matrix[i + 1], matrix[high]);
    return i + 1;
}

void animateSortqc(int matrix[], int low, int high) {
    if (low < high) {
        int pi = partition1(matrix, low, high);

        drawMatrixqc(matrix, arraySize, low, high, pi);

        animateSortqc(matrix, low, pi - 1);
        animateSortqc(matrix, pi + 1, high);
    }
}

///Sortare SELECTIE CRESC


void printArray1(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void drawArray1(int arr[], int size, int currentIndex, int minIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        if (i == currentIndex) {
            setcolor(RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else if (i == minIndex) {
            setcolor(GREEN);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 0.5 secunde
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
        drawArray1(arr, arraySize, i, minIndex);
    }
}

///Sortare Insertie
void printArray2(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void drawArray2(int arr[], int size, int currentIndex, int keyIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        if (i == currentIndex || i == keyIndex) {
            setcolor(i == currentIndex ? GREEN : RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 1 secunda
}

void insertionSortAscending(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        drawArray2(arr, arraySize, i, j + 1);
    }
}

///Bubble desc
void printMatrix2(int matrix[], int sizee) {
    for (int i = 0; i < sizee; ++i) {
        std::cout << matrix[i] << " ";
    }
    std::cout << std::endl;
}

void drawMatrix2(int matrix[], int sizee, int highlightIndex1, int highlightIndex2) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < sizee; ++i) {
        // Colorăm un dreptunghi în funcție de indicele elementului
        if (i == highlightIndex1 || i == highlightIndex2) {
            setcolor(i == highlightIndex1 ? GREEN : RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        // Utilizăm const_cast pentru a elimina constanța în cadrul funcției outtextxy
        const char* str = std::to_string(matrix[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 1 secundă
}

void bubbleSort2(int matrix[], int sizee) {
    for (int i = 0; i < sizee - 1; ++i) {
        for (int j = 0; j < sizee - i - 1; ++j) {
            drawMatrix2(matrix, sizee, j, j + 1);

            // Comparăm și schimbăm dacă este cazul
            if (matrix[j] < matrix[j + 1]) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}

///Quick desc
void printMatrixqd(int matrix[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i] << " ";
    }
    std::cout << std::endl;
}

void drawMatrixqd(int matrix[], int size, int highlightIndex1, int highlightIndex2, int pivotIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        // Culori pentru pivot și elemente
        if (i == pivotIndex) {
            setcolor(YELLOW);
            rectangle(x, y - 20, x + 30, y + 20);
        } else if (i == highlightIndex1 || i == highlightIndex2) {
            setcolor(i == highlightIndex1 ? GREEN : RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        // Utilizăm const_cast pentru a elimina constanța în cadrul funcției outtextxy
        const char* str = std::to_string(matrix[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 1 secundă
}

int partitionqd(int matrix[], int low, int high) {
    int pivot = matrix[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (matrix[j] >= pivot) {
            ++i;
            std::swap(matrix[i], matrix[j]);
        }
    }

    std::swap(matrix[i + 1], matrix[high]);
    return i + 1;
}

void animateSortqd(int matrix[], int low, int high) {
    if (low < high) {
        int pi = partitionqd(matrix, low, high);

        drawMatrixqd(matrix, arraySize, low, high, pi);

        animateSortqd(matrix, low, pi - 1);
        animateSortqd(matrix, pi + 1, high);
    }
}

///Sortare prin Selectie
void printArrays(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void drawArrays(int arr[], int size, int currentIndex, int minIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        if (i == currentIndex) {
            setcolor(RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else if (i == minIndex) {
            setcolor(GREEN);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 0.5 secunde
}

void selectionSorts(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
        drawArrays(arr, arraySize, i, minIndex);
    }
}

///SORTARE PRIN SELSCTIE DESCRESCATOARE
void printArray3(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void drawArray3(int arr[], int size, int currentIndex, int maxIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;

    for (int i = 0; i < size; ++i) {
        if (i == currentIndex) {
            setcolor(RED);
            rectangle(x, y - 20, x + 30, y + 20);
        } else if (i == maxIndex) {
            setcolor(GREEN);
            rectangle(x, y - 20, x + 30, y + 20);
        } else {
            setcolor(WHITE);
            rectangle(x, y - 20, x + 30, y + 20);
        }

        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + 10, y, const_cast<char*>(str));

        x += spacing;
    }

    delay(600); // Întârziere de 0.5 secunde
}

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        std::swap(arr[i], arr[maxIndex]);
        drawArray3(arr, arraySize, i, maxIndex);
    }
}




int partition(int matrix[], int low, int high)
{
    int pivot = matrix[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (matrix[j] >= pivot)
        {
            ++i;
            swap(matrix[i], matrix[j]);
        }
    }

    swap(matrix[i + 1], matrix[high]);
    return i + 1;
}

void printMatrix(int matrix[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

void drawSnowflake(int x, int y)
{
    setcolor(WHITE);
    line(x, y - 5, x, y + 5);
    line(x - 5, y, x + 5, y);
    line(x - 4, y - 4, x + 4, y + 4);
    line(x - 4, y + 4, x + 4, y - 4);
}

void updateSnowflakes(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    for (int i = 0; i < numSnowflakes; ++i)
    {
        snowflakesY[i] = (snowflakesY[i] + 1) % getmaxy();

        if (snowflakesY[i] == getmaxy() - 1)
        {
            snowflakesX[i] = rand() % getmaxx();
        }
    }
}

void drawMenu(const char* title, const char* options[], int numOptions, int currentOption, int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    cleardevice();

    for (int i = 0; i < numSnowflakes; ++i)
    {
        drawSnowflake(snowflakesX[i], snowflakesY[i]);
    }
    setcolor(WHITE);

    outtextxy(getmaxx() / 2 - textwidth(const_cast<char*>(title)) / 2, 50, const_cast<char*>(title));

    int totalHeight = numOptions * textheight(const_cast<char*>(options[0])) + 70;
    int optionHeight = textheight(const_cast<char*>(options[0]));

    setcolor(GREEN);
    int topMargin = 30;
    rectangle(getmaxx() / 4, getmaxy() / 2 - totalHeight / 2 - topMargin, 3 * getmaxx() / 4, getmaxy() / 2 + totalHeight / 2);

    setcolor(WHITE);
    for (int i = 0; i < numOptions; ++i)
    {
        char* optionCopy = strdup(options[i]);

        if (optionCopy != NULL)
        {
            int optionX = getmaxx() / 2 - textwidth(optionCopy) / 2;
            int optionY = getmaxy() / 2 - totalHeight / 2 + i * optionHeight + i * 10;

            outtextxy(optionX, optionY, optionCopy);

            if (i == currentOption)
            {
                setcolor(WHITE);
                int circleY = optionY + optionHeight / 2;
                circle(getmaxx() / 4 + 10, circleY, 5);
            }

            free(optionCopy);
        }
    }
}

matrice A, B, C;
int numar_linii=3, numar_coloane=3;

void Adunare1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Adunare Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Adunare Matrici");
                adunare_matrici_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Adunare Matrici");
                adunare_matrici_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Scadere1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Scadere Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Scadere Matrici");
                scadere_matrici_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Scadere Matrici");
                scadere_matrici_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Inmultire1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Inmultire Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Inmultire Matrici");
                inmultire_matrici_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Inmultire Matrici");
                inmultire_matrici_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Impartire1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Impartire Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Impartire Matrici");
                impartire_matrici_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Impartire Matrici");
                impartire_matrici_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Ridicareputere1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Ridicare la putere la Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Ridicare la putere la Matrici");
                ridicare_putere2_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Ridicare la putere la Matrici");
                ridicare_putere2_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}


void matrixOperationsMenu(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char *matrixMenuOptions[] =
    {
        "1. Adunare",
        "2. Scadere",
        "3. Inmultire",
        "4. Impartire",
        "5. Ridicare la putere",
        "6. Inapoi"
    };

    int matrixChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Matrici - Submeniu", matrixMenuOptions, 6, matrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (matrixChoice > 0)
                matrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (matrixChoice < 5)
                matrixChoice++;
            break;
        case 13: // ENTER key
            switch (matrixChoice)
            {
            case 0:
            {
                // Adunare
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                outtextxy(50,25,"Adunare Matrici");
                // Implementează logica pentru adunare
                Adunare1(snowflakesX,snowflakesY,numSnowflakes);

                // Așteaptă o tastă înainte de a închide fereastra grafică pentru adunare

                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Scadere1(snowflakesX,snowflakesY,numSnowflakes);


                break;
            }
            case 2:
            {
                // Inmultire
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Inmultire1(snowflakesX,snowflakesY,numSnowflakes);

                break;
            }
            case 3:
            {
                // Impartire
                // Implementează logica pentru impartire
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Impartire1(snowflakesX,snowflakesY,numSnowflakes);
                break;
            }
            case 4:
            {
                // Ridicare la putere

                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Ridicareputere1(snowflakesX,snowflakesY,numSnowflakes);
                break;
            }
            case 5:
                // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Obtinereatranspusei1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Scadere Matrici", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea transpusei");
                transpusa_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea transpusei");
                transpusa_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Determinant1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Obtinerea determinantului", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea determinantului");
                //determinant_ordin3_tast();
                determinant_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea determinantului");
                //determinant_ordin3_fisier();
                determinant_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Inversa1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Obtinerea inversei", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea inversei");
                inversa_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Obtinerea inversei");
                inversa_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void otherMatrixOperationsMenu(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. Obtinerea transpusei",
        "2. Obtinerea determinantului",
        "3. Obtinerea inversei",
        "4. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Alte operatii cu Matrici - Submeniu", otherMatrixMenuOptions, 4, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 3) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0: // Obtinerea transpusei
                // Implementează logica pentru obținerea transpusei
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Obtinereatranspusei1(snowflakesX,snowflakesY,numSnowflakes);

                getch();
                break;
            }
            case 1: // Obtinerea determinantului
                // Implementează logica pentru obținerea determinantului
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Determinant1(snowflakesX,snowflakesY,numSnowflakes);
                getch();
                break;
            }
            case 2: // Obtinerea inversei
                // Implementează logica pentru obținerea inversei
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Inversa1(snowflakesX,snowflakesY,numSnowflakes);
                getch();
                break;
            }
            case 3: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

///shiftare dreapta
void Afiseaza(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void deseneaza(int arr[], int size, int highlightIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;
    int squareSize = 35;

    for (int i = 0; i < size; ++i) {
        // Desenăm marginile colorate ale pătratului
        setcolor(i == highlightIndex ? RED : WHITE);
        rectangle(x, y - squareSize, x + squareSize, y);
        floodfill(x + 1, y - squareSize + 1, i == highlightIndex ? RED : WHITE);

        // Desenăm numărul în interiorul pătratului cu fundal negru
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BLACK);
        bar(x + 1, y - squareSize + 1, x + squareSize - 1, y - 1);  // Umplem cu negru
        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + squareSize / 2 - 5, y - squareSize / 2, const_cast<char*>(str));

        x += spacing;
    }

    delay(500);
}

void shiftLeft(int arr[], int marime) {
    int temp = arr[0];
    for (int i = 1; i < marime; ++i) {
        arr[i - 1] = arr[i];
    }
    arr[marime - 1] = temp;
}

///shiftare stanga

void desen(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void deseneazastanga(int arr[], int size, int highlightIndex) {
    cleardevice();

    int x = 50;
    int y = getmaxy() / 2;
    int spacing = 40;
    int squareSize = 35;

    for (int i = 0; i < size; ++i) {
        // Desenăm marginile colorate ale pătratului
        setcolor(i == highlightIndex ? RED : WHITE);
        rectangle(x, y - squareSize, x + squareSize, y);
        floodfill(x + 1, y - squareSize + 1, i == highlightIndex ? RED : WHITE);

        // Desenăm numărul în interiorul pătratului cu fundal negru
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BLACK);
        bar(x + 1, y - squareSize + 1, x + squareSize - 1, y - 1);  // Umplem cu negru
        const char* str = std::to_string(arr[i]).c_str();
        outtextxy(x + squareSize / 2 - 5, y - squareSize / 2, const_cast<char*>(str));

        x += spacing;
    }

    delay(500);
}

void shiftRight(int arr[], int marime) {
    int temp = arr[marime - 1];
    for (int i = marime - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void otherMatrixOperationsMenu2(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. Dreapta",
        "2. Stanga",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Shiftare Vectori", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                const int arraySize = 10;
                int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                for (int i = 0; i < arraySize; ++i) {
                    shiftLeft(arr, arraySize);
                    deseneaza(arr, arraySize, i == arraySize - 1 ? 0 : i + 1);
                    // Verificăm dacă primul număr a ajuns primul din dreapta
                    if (i != arraySize - 1 && arr[0] == arraySize) {
                    break;
            }
        }
                std::cout << "Vectorul dupa shiftare la dreapta: ";
                Afiseaza(arr, arraySize);
                getch();


                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                const int arraySize = 10;
                int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < arraySize; ++i) {
        shiftRight(arr, arraySize);
        deseneazastanga(arr, arraySize, i == arraySize - 1 ? 0 : i + 1);

        // Verificăm dacă primul număr a ajuns primul din dreapta
        if (i != arraySize - 1 && arr[arraySize - 1] == 1) {
            break;
        }
    }

    std::cout << "Vectorul dupa shiftare la stanga: ";
    desen(arr, arraySize);
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}
//////////////////////////////////////////////////////////////

void Sortarefrec2(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Sortare Prin Frecventa (Doar nr. nat.)", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Frecventa (Doar nr. nat.)");
                sortare_frecventa_cresc_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Frecventa (Doar nr. nat.)");
                sortare_frecventa_cresc_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void vectorOperationsMenu2(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* vectorMenuOptions[] =
    {
        "1. Quick Sort",
        "2. Bubble Sort",
        "3. Sortare Prin Selectie",
        "4. Sortare Insertie",
        "5. Sortare Prin Frecventa (Doar nr. nat.)",
        "6. Inapoi"
    };

    int vectorChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Vectori - Submeniu", vectorMenuOptions, 6, vectorChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (vectorChoice > 0) vectorChoice--;
            break;
        case 80: // DOWN arrow key
            if (vectorChoice < 5) vectorChoice++;
            break;
        case 13: // ENTER key
            switch (vectorChoice)
            {
            case 0: // Suma elementelor din vector
                // Implementează logica pentru suma elementelor din vector

            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                int matrix[] = {30, 80, 25, 12, 22, 11, 90};
                outtextxy(50,25,"Quick Sort");
                animateSortqc(matrix, 0, arraySize - 1);
                getch();
                break;

            }
            case 1: // Produsul elementelor din vector
                // Implementează logica pentru produsul elementelor din vector

            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Bubble Sort");
                int matrix[] = {64, 34, 25, 12, 22, 11, 90};
                int sizee = sizeof(matrix) / sizeof(matrix[0]);
                bubbleSort(matrix, sizee);
                getch();
                break;

            }
            case 2: // Sortare vector crescator
                // Implementează logica pentru sortarea vectorului crescător
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Selectie");
                const int arraySize = 10;  // Dimensiunea matricei
                int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 8};
                selectionSort(arr, arraySize);
                getch();
                break;
            }
            break;
            case 3:  {int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Insertie");
                const int arraySize = 10;  // Dimensiunea matricei
                int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 8};
                insertionSortAscending(arr, arraySize);
                getch();
                break;}
            case 4:  {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Sortarefrec2(snowflakesX,snowflakesY,numSnowflakes);


                break;
                }
            case 5: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sortarefrec1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Sortare Prin Frecventa (Doar nr. nat.)", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Frecventa (Doar nr. nat.)");
                sortare_frecventa_descrescator_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Frecventa (Doar nr. nat.)");
                sortare_frecventa_descrescator_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void vectorOperationsMenu3(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* vectorMenuOptions[] =
    {
        "1. Quick Sort",
        "2. Bubble Sort",
        "3. Sortare Prin Selectie",
        "4. Sortare Insertie",
        "5. Sortare Prin Frecventa (Doar nr. nat.)",
        "6. Inapoi"
    };

    int vectorChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Vectori - Submeniu", vectorMenuOptions, 6, vectorChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (vectorChoice > 0) vectorChoice--;
            break;
        case 80: // DOWN arrow key
            if (vectorChoice < 5) vectorChoice++;
            break;
        case 13: // ENTER key
            switch (vectorChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                int matrix[] = {64, 34, 25, 12, 22, 11, 90};
                int sizee = sizeof(matrix) / sizeof(matrix[0]);
                bubbleSort2(matrix, sizee);
                getch();
                break;

            }
            case 1:

            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                const int arraySize = 7;  // Dimensiunea matricei
                int matrix[] = {30, 80, 25, 12, 22, 11, 90};
                animateSortqd(matrix, 0, arraySize - 1);
                getch();
                break;

            }
            case 2:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                const int arraySize = 10;  // Dimensiunea matricei
                int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 8};
                selectionSorts(arr, arraySize);
                getch();
                break;
            }
            break;
            case 3:
                {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                const int arraySize = 10;  // Dimensiunea matricei
                int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 8};
                selectionSortDescending(arr, arraySize);
                break;
                }
            case 4:{// Shiftare vectori
                // Implementează logica pentru shiftarea vectorilor
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Sortare Prin Frecventa (Doar nr. nat.)");
                Sortarefrec1(snowflakesX,snowflakesY,numSnowflakes);

                break;
            }
            case 5: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumaelementelordinvector1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma elementelor din vector", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma elementelor din vector");
                suma_vector_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma elementelor din vector");
                suma_vector_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Produselementelordinvector1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Produsul elementelor din vector", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Produsul elementelor din vector");
                produs_vector_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Produsul elementelor din vector");
                produs_vector_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Inmultirescalar(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma elementelor din vector", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma elementelor din vector");
                vector_scalar_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma elementelor din vector");
                vector_scalar_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void vectorOperationsMenu(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* vectorMenuOptions[] =
    {
        "1. Suma elementelor din vector",
        "2. Produsul elementelor din vector",
        "3. Sortare vector crescator",
        "4. Sortare vector descrescator",
        "5. Shiftare vectori",
        "6. Inmultire cu un scalar",
        "7. Inapoi"
    };

    int vectorChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Vectori - Submeniu", vectorMenuOptions, 7, vectorChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (vectorChoice > 0) vectorChoice--;
            break;
        case 80: // DOWN arrow key
            if (vectorChoice < 6) vectorChoice++;
            break;
        case 13: // ENTER key
            switch (vectorChoice)
            {
            case 0: // Suma elementelor din vector
                // Implementează logica pentru suma elementelor din vector



            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Sumaelementelordinvector1(snowflakesX,snowflakesY,numSnowflakes);


                break;

            }
            case 1: // Produsul elementelor din vector
                // Implementează logica pentru produsul elementelor din vector

            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                Produselementelordinvector1(snowflakesX,snowflakesY,numSnowflakes);

                break;

            }
            case 2: // Sortare vector crescator
                // Implementează logica pentru sortarea vectorului crescător
                vectorOperationsMenu2(snowflakesX, snowflakesY, numSnowflakes);
                break;

            break;
            case 3: // Sortare vector descrescator
                // Implementează logica pentru sortarea vectorului descrescător
               vectorOperationsMenu3(snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 4: // Shiftare vectori
                // Implementează logica pentru shiftarea vectorilor
                otherMatrixOperationsMenu2( snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 5:
            {
                    Inmultirescalar(snowflakesX,snowflakesY,numSnowflakes);
            }
            case 6: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumadiagprin1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma diagonala principala", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma diagonala principala");
                diag_pricipala_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma diagonala principala");
                diag_pricipala_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumadiagsec1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma diagonala secundara", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma diagonala secundara");
                diag_secundara_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma diagonala secundara");
                diag_secundara_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumasubprin1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma sub diag. principala", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma sub diag. principala");
                sub_diag_pricipala_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma sub diag. principala");
                sub_diag_pricipala_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumasubsec1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma sub diag. secundara", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma sub diag. secundara");
                sub_diag_secundara_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma sub diag. secundara");
                sub_diag_secundara_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumdeasupraprin1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma deasupra diag. principala", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma deasupra diag. principala");
                deasupra_diag_pricipala_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma deasupra diag. principala");
                deasupra_diag_pricipala_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Sumdeasuprasec1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Suma deasupra diag. secundara", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma deasupra diag. secundara");
                deasupra_diag_secundara_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Suma deasupra diag. secundara");
                deasupra_diag_secundara_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void matrixOperationsMenu2(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char *matrixMenuOptions[] =
    {
        "1. Suma diagonala principala",
        "2. Suma diagonala secundara",
        "3. Suma sub diag. principala",
        "4. Suma sub diag. secundara",
        "5. Suma deasupra diag. principala",
        "6. Suma deasupra diag. secundara",
        "7. Inapoi"
    };

    int matrixChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Matrici - Submeniu", matrixMenuOptions, 7, matrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (matrixChoice > 0)
                matrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (matrixChoice < 6)
                matrixChoice++;
            break;
        case 13: // ENTER key
            switch (matrixChoice)
            {
            case 0:
            {

                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Sumadiagprin1(snowflakesX,snowflakesY,numSnowflakes);

                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Sumadiagsec1(snowflakesX,snowflakesY,numSnowflakes);


                break;
            }
            case 2:
            {
                // Inmultire
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                // Implementează logica pentru adunare

                Sumasubprin1(snowflakesX,snowflakesY,numSnowflakes);
                break;
            }
            case 3:
            {
                // Impartire
                // Implementează logica pentru impartire
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                //IMPARTIRE MATRICI

                Sumasubsec1(snowflakesX,snowflakesY,numSnowflakes);

                break;
            }
            case 4:
            {
                // Ridicare la putere
                // Implementează logica pentru ridicare la putere
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Sumdeasupraprin1(snowflakesX,snowflakesY,numSnowflakes);
                // Așteaptă o tastă înainte de a închide fereastra grafică pentru adunare

                break;
            }
            case 5:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");

                Sumdeasuprasec1(snowflakesX,snowflakesY,numSnowflakes);
            }
            case 6:
                // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void ZonaNord1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Zona Nord", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Nord");
                ZonaNord_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Nord");
                ZonaNord_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}


void ZonaSud1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Zona Sud", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Sud");
                ZonaSud_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Sud");
                ZonaSud_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void ZonaEst1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Zona Est", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Est");
                ZonaEst_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Est");
                ZonaEst_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void ZonaVest1(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* otherMatrixMenuOptions[] =
    {
        "1. De la tastatura",
        "2. Din fisier",
        "3. Inapoi"
    };

    int otherMatrixChoice = 0;

    while (true)
    {
        drawMenu("Zona Vest", otherMatrixMenuOptions, 3, otherMatrixChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (otherMatrixChoice > 0) otherMatrixChoice--;
            break;
        case 80: // DOWN arrow key
            if (otherMatrixChoice < 2) otherMatrixChoice++;
            break;
        case 13: // ENTER key
            switch (otherMatrixChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Vest");
                ZonaEst_tast();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }
            case 1:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                outtextxy(50,25,"Zona Vest");
                ZonaVest_fisier();
                outtextxy(1000,500,"Apasa pe una dintre sageti pentru a te intoarce la meniu");
                getch();
                break;
            }

            case 2: // Iesire
                return;
                break;
            }
            break;
        }
    }
}

void Zonemeniu(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* vectorMenuOptions[] =
    {
        "1. Zona Nord",
        "2. Zona Sud",
        "3. Zona Est",
        "4. Zona Vest",
        "5. Inapoi"

    };

    int vectorChoice = 0;

    while (true)
    {
        drawMenu("Operatii cu Vectori - Submeniu", vectorMenuOptions, 5, vectorChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (vectorChoice > 0) vectorChoice--;
            break;
        case 80: // DOWN arrow key
            if (vectorChoice < 4) vectorChoice++;
            break;
        case 13: // ENTER key
            switch (vectorChoice)
            {
            case 0:
            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                ZonaNord1(snowflakesX, snowflakesY, numSnowflakes);

                break;

            }
            case 1: // Produsul elementelor din vector
                // Implementează logica pentru produsul elementelor din vector

            {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                ZonaSud1(snowflakesX, snowflakesY, numSnowflakes);

                break;

            }
            case 2: {// Sortare vector crescator
                // Implementează logica pentru sortarea vectorului crescător
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                ZonaEst1(snowflakesX, snowflakesY, numSnowflakes);
                break;

            break;}
            case 3: {
                int gd_matrice = DETECT, gm_matrice;
                initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
                ZonaVest1(snowflakesX, snowflakesY, numSnowflakes);
                break;
            }
            case 4:
                return;
                break;

        }
    }
}
}
void mainMenu(int snowflakesX[], int snowflakesY[], int numSnowflakes)
{
    const char* mainMenuOptions[] =
    {
        "1. Operatii cu Matrici",
        "2. Alte operatii cu Matrici",
        "3. Operatii cu Vectori",
        "4. Sume in functie de Diagonale",
        "5. Sume pe zone in matrice",
        "6. Iesire"
    };

    int mainChoice = 0;

    while (true)
    {
        drawMenu("Meniu Principal", mainMenuOptions, 6, mainChoice, snowflakesX, snowflakesY, numSnowflakes);

        char key = getch();
        switch (key)
        {
        case 72: // UP arrow key
            if (mainChoice > 0) mainChoice--;
            break;
        case 80: // DOWN arrow key
            if (mainChoice < 5) mainChoice++;
            break;
        case 13: // ENTER key
            switch (mainChoice)
            {
            case 0: // Operatii cu Matrici
                matrixOperationsMenu(snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 1: // Alte operatii cu Matrici
                otherMatrixOperationsMenu(snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 2: // Operatii cu Vectori
                vectorOperationsMenu(snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 3: // Operatii cu Matrice
                matrixOperationsMenu2(snowflakesX, snowflakesY, numSnowflakes);
                break;
            case 4:
                {
                    Zonemeniu(snowflakesX,snowflakesY,numSnowflakes);
                    break;
                }
            case 5: // Iesire
                closegraph();
                exit(0);
                break;
            }
            break;
        }
    }
}



int main()
{
    int det;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Setăm numărul de fulgi și inițializăm coordonatele lor
    const int numSnowflakes = 15;
    int snowflakesX[numSnowflakes];
    int snowflakesY[numSnowflakes];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numSnowflakes; ++i)
    {
        snowflakesX[i] = rand() % getmaxx();
        snowflakesY[i] = rand() % getmaxy();
    }

    srand(time(NULL));
    numar_linii=3;
    // int numar_coloane=2+rand()%5;
    numar_coloane=numar_linii;
    matrice A,B,C,D,T,Adj;
    matrice_float I,Rez,B1;
    initwindow(latura*numar_coloane*7+200,latura*numar_linii+10*latura,"BibMat");
    matrice X,Y;
    // Setăm dimensiunea ferestrei


    mainMenu(snowflakesX, snowflakesY, numSnowflakes);

    closegraph();
    return 0;

}
