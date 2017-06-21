
/*Menu para o jogo Mr Do.
Octavio Arruda e Lucas Flores. */
#include <stdio.h>
#include <stdlib.h> // biblioteca que contem a funcao exit(0) que sai do programa.
#include <conio.h>
#include "conio2.h"
#include<ctype.h>

#define TAMLIN 23
#define TAMCOL 60

/*typedef struct //struct pra usar nos ghosts;
{
    int posx;
    int posy;
    int vivo;
} FANTASMA;*/

typedef struct //struct do tiro
{
    char direcao;
    int posx, posy;
} TIRO;

TIRO atira (int position_do[], char lado)
{
    TIRO tiro_do;

    tiro_do.posx = position_do[0];
    tiro_do.posy = position_do[1];
    tiro_do.direcao = lado;

    return tiro_do;
}

TIRO move_tiro (TIRO papapa) //recebe o tiro e faz ele se mover na matrixx
{

    switch(papapa.direcao)
    {
        case 1:
        case 2:
        case 3:
        case 4:
    }

}


void menu_do() // função do menu do Mr do.
{
    int end=0, option=0,i=0;
    char opmenu=0;
    char opcao_selecionada=1;
    char matriz[TAMLIN][TAMCOL]= {"ppppppppppppppppppppvvvivvvvvvvvvvvvvvvvvvvvvvvvvvvvvppppppp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppvvvvpppp", "pffppppppppppppppppppppvpppppppppppppppppppppppppppppppvvvpp", "pffppppppppppppppppppppvpppppppppppppppppppppppppppppppppvvp", "pffppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pffppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvpppppppffpppppppppppppppppppppppppvp", "pppppppppppppppppppppppvpppppppffppppppppppppppppppppppppvvp", "pppppppppppppppppppppppippppppppffppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppffppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppffppppppppppppvpppppppppppppppppffpppppppppppppppvp", "ppppppppppffpppppppppppvpppppppppppppppppffpppppppppppppppvp", "pppppppppppffppppppppppnpppppppppppppppppffpppppppppppppppvp", "pppppppppppppffppppppppvpppppppppppppppppffpppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "vvvvvvvvpppppppppppppppvpppppppppppppppppppppppppppppppppvvp", "vvppppvvppppppppppppppptpppppppppppppppppppppppppppppppvvvpp", "vvppppvvpppppppppppppppvppppppppppppppppppppppppppppvvivpppp", "vvppppvvpppppppppppppppvppppppppppppppppppppppppppvvvppppppp", "vvvvvvvvvvvvvvvvvvvvvvvdvvvvvvvvvvivvvvvvvvvvvvvvvvppppppppp"};

    do
    {
        textcolor(15);
        gotoxy(1,5);
        for(i=0; i<80; i++) //os for's são para printar os caracteres que fazem as barras do menu.
        {
            printf("%c", 	220);
        }
        gotoxy(8,6);
        textcolor(11);
        printf("\n  Mr. Do!\n");
        textcolor(15);
        for(i=0; i<80; i++)
        {
            printf("%c", 	220);
        }
        gotoxy(5,12);
        textcolor(15);
        printf("\n  New Game");
        textcolor(7);
        printf("\n  Load Game");
        textcolor(15);
        printf("\n  High Scores");
        textcolor(7);
        printf("\n  Exit");

        gotoxy(1,opcao_selecionada + 12);
        printf(">");
        while(opmenu != 'w' && opmenu != 's')
        {
            opmenu = getch();
            switch(opmenu)
            {
            case 'w' :
                opcao_selecionada--;
                break;
            case 's' :
                opcao_selecionada++;
                break;
            case 13 : //13 = enter. Chama a função selecionada.
                // um if pra cada opcao, chamando a funcao correspondente.
                if(opcao_selecionada==4)
                {
                    exit(0);
                }
                if(opcao_selecionada==1)
                {
                    clrscr();
                    jogo(matriz);
                }
            }
            if (opcao_selecionada==5) // limitando os acessos do menu.
            {
                opcao_selecionada=1;
            }
            else if(opcao_selecionada==0)
            {
                opcao_selecionada=4;
            }
        }
        opmenu = 0;


    }
    while(1);

}



void imprime_matrix(char matrix[TAMLIN][TAMCOL], int score)
{

    int j,i; // contadores
    int position_do[2];// variável para saber o lugar que o Mr.Do está.

    for(j=0; j<TAMLIN; j++)
    {
        for(i=0; i<TAMCOL; i++) // for aninhado para impressão da matriz.
        {
            switch(matrix[j][i]) //Switch para os chars da matriz para fazer o cenário
            {
            case 'p' :
            {
                textcolor(10);
                printf ("%c", 176);
                break;
            }
            case 'i':
            {
                textcolor(15);
                printf ("%c", 153);
                break;
            }
            case 'f':
            {
                textcolor(12);
                printf ("%c", 229);
                break;
            }
            case 'd':
            {
                position_do[0] = j;
                position_do[1] = i;
                textcolor(9);
                printf ("%c", 227);
                break;
            }
            case 't':
            {
                printf ("%c", 250);
                break;
            }
            case 'n':
            {
                textcolor(8);
                printf ("%c", 206);
                break;
            }
            case 'v':
            {
                textcolor(10);
                printf ("%c", 32);
                break;
            }
            }

        }
        printf ("\n");

    }
}


void jogo(char matrix[TAMLIN][TAMCOL])
{
    int x=24, y=23, fim_jogo=1;
    int postion_do[2];
    char lado;
    int cont_score=0;

    imprime_matrix(matrix, cont_score);
    do
    {

        gotoxy(65,4);
        textcolor(14);
        printf("SCORE %d", cont_score);
        kbhit();//Essa função, junto com getch recebe os dados do teclado
        lado = getch();//tu precisa ter uma variavel que receba esse dado, pra poder jusar no switch, nesse caso foi "lado"
        lado = toupper(lado);//aqui é para, caso o capslock esteja ligado ou desligado não ter problema


        switch(lado)
        {
        case 'D':
            if(x<=(TAMCOL-1))//aqui ele testa a posição do mr. do, caso ele não esteja na posição certa, ele não faz nada, pois está atingindo uma parede.
            {
                gotoxy(x, y);//aqui ele coloca um espaço onde o mr do estava

                /* como usar o gotoxy: tu escreve a posição onde tu quer algo, e embaixo do gotoxy
                tu imprime o que tu quer nesse lugar*/

                printf("%c", 32);//aqui ele printa o espaço pela tabela ascii
                x++;//aqui ele incrementa o x, pois ao apertar D, tu tá indo pro lado

                textcolor(9);//aqui é uma cor teste, pode mudar a vontade
                gotoxy(x, y);//aqui a gente vai mudar a posição do mr. do, vamos mandar ele pra outro lugar, já que o X foi incrementado
                printf("%c", 227);//printa o do pela tabela ascii

            }
            break;
        case 'A':
            if(x>=2)
            {
                gotoxy(x, y);
                printf("%c", 32);
                x--;//nesse caso a gente decremetna o x, por ele ir para o outro lado
                textcolor(9);
                gotoxy(x, y);
                printf("%c", 227);

            }
            break;
        case 'W':
            if(y>=2)
            {
                gotoxy(x, y);
                printf("%c", 32);
                y--;// nesse caso a gente descrementa o y, pois ele vai pra cima: pelo gotoxy, o terminal começa na posição (1,1)
                textcolor(9);
                gotoxy(x, y);
                printf("%c", 227);

            }
            break;
        case 'S':
            if(y<=(TAMLIN-1))
            {
                gotoxy(x, y);
                printf("%c", 32);
                y++;// nesse caso a gente incrementa o y, pois ele vai pra baixo
                textcolor(9);
                gotoxy(x, y);
                printf("%c", 227);

            }
            break;

        }
        if(matrix[y-1][x-1]=='f')
        {
            cont_score+=50;
            matrix[y-1][x-1]='v';
        }
    }
    while(fim_jogo != 0);
}
int main ()
{

    char matriz[TAMLIN][TAMCOL] = {"ppppppppppppppppppppvvvivvvvvvvvvvvvvvvvvvvvvvvvvvvvvppppppp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppvvvvpppp", "pffppppppppppppppppppppvpppppppppppppppppppppppppppppppvvvpp", "pffppppppppppppppppppppvpppppppppppppppppppppppppppppppppvvp", "pffppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pffppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvpppppppffpppppppppppppppppppppppppvp", "pppppppppppppppppppppppvpppppppffppppppppppppppppppppppppvvp", "pppppppppppppppppppppppippppppppffppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppffppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppffppppppppppppvpppppppppppppppppffpppppppppppppppvp", "ppppppppppffpppppppppppvpppppppppppppppppffpppppppppppppppvp", "pppppppppppffppppppppppnpppppppppppppppppffpppppppppppppppvp", "pppppppppppppffppppppppvpppppppppppppppppffpppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "pppppppppppppppppppppppvppppppppppppppppppppppppppppppppppvp", "vvvvvvvvpppppppppppppppvpppppppppppppppppppppppppppppppppvvp", "vvppppvvppppppppppppppptpppppppppppppppppppppppppppppppvvvpp", "vvppppvvpppppppppppppppvppppppppppppppppppppppppppppvvivpppp", "vvppppvvpppppppppppppppvppppppppppppppppppppppppppvvvppppppp", "vvvvvvvvvvvvvvvvvvvvvvvdvvvvvvvvvvivvvvvvvvvvvvvvvvppppppppp"};

    menu_do();


    return 0;

}




