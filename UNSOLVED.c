#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void title()
{
    printf("\n\n\
\t\t\t██╗   ██╗███╗   ██╗███████╗ ██████╗ ██╗    ██╗   ██╗███████╗██████╗ \n\
\t\t\t██║   ██║████╗  ██║██╔════╝██╔═══██╗██║    ██║   ██║██╔════╝██╔══██╗\n\
\t\t\t██║   ██║██╔██╗ ██║███████╗██║   ██║██║    ██║   ██║█████╗  ██║  ██║\n\
\t\t\t██║   ██║██║╚██╗██║╚════██║██║   ██║██║    ╚██╗ ██╔╝██╔══╝  ██║  ██║\n\
\t\t\t╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗╚████╔╝ ███████╗██████╔╝\n\
\t\t\t ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝ ╚═══╝  ╚══════╝╚═════╝ \n\n");
}
void pause()
{
    printf("\n\t\t\t\t\t[APERTE QUALQUER TECLA PARA CONTINUAR]\n");
    system("pause > NUL");
}
void map(int v1, int v2)
{
    int i,i2,x=v1/2,y=v2/2;
    char mapa[v1][v2],movimento;
    for (i = 0; i < v1; i++)
    {
        for ( i2 = 0; i2 < v2; i2++)
        {
            if (i==0 || i==v1-1 || i2==0 || i2==v2-1)
            {
                mapa[i][i2]='#';
            }
            else
            {
                mapa[i][i2]=' ';
            }
        }
        
    }
    mapa[1][2]='@';
    mapa[x][y]='&';
    while (i!=-1)
    {
        system("cls");
        for (i = 0; i < v1; i++)
        {
            printf("\n\t\t\t\t");
            for (i2 = 0; i2 < v2; i2++)
            {
                printf("%c",mapa[i][i2]);   
            }
            
        }
        movimento=getch();
        mapa[x][y]=' ';
        if (movimento=='w')
        {
            if (mapa[x-1][y]!='#')
            {
                x--;
            }   
        }
        else if (movimento=='a')
        {
            if (mapa[x][y-1]!='#')
            {
                y--;
            }   
        }
        else if (movimento=='s')
        {
            if (mapa[x+1][y]!='#')
            {
                x++;
            }   
        }
        else if (movimento=='d')
        {
            if (mapa[x][y+1]!='#')
            {
                y++;
            }   
        }
        else if (movimento=='i')
        {
            if (mapa[x-1][y]=='@')
            {
                printf("interagiu");
                pause();
            }
            
        }
        
        mapa[x][y]='&';
    }
}

int main()
{
    char nome[20];
    int escolha=0;

    UINT portugues = 65001;
    SetConsoleOutputCP(portugues);

    title();
    pause();

    while (escolha==0)
    {
        system("cls");
        title();
        printf("\t\t\t\t\t\t[ESCOLHA UMA DAS OPÇÕES]\n\n\t\t\t\t\t\t[1] - JORNADA\n\t\t\t\t\t\t[2] - CRÉDITOS\n\t\t\t\t\t\t[3] - SAIR DE UNSOLVED\n\t\t\t\t\t\t ");
        escolha=getch();

        
        if (escolha=='1')
        {
            system("cls");
            printf("\t\t\t\tApós anos de investigação, o departamento da verdade encerrou\n\t\t\t\t o caso o qual você tentou encontrar as respostas.\n\n\t\t\t\tVocê acreditava que estava cada vez mais perto de uma solução,\n\t\t\t\t sendo assim, decidiu fazer isso por conta própria.\n\n");
            Sleep(2500);
            pause();
            system("cls");
            escolha++;
        }
        else if (escolha=='2')
        {
            system("cls");
            printf("\t\t\t\t\t\t\tCRÉDITOS:\n\n\t\t\t\t\t\tLUAN PIEDADE DE OLIVEIRA\n");
            pause();
            escolha=0;

        }
        else if (escolha=='3')
        {
            printf("\n\n\t\t\t\t\t\tOBRIGADO POR JOGAR!\n\n\n\n\n\n\n\n");
            goto fim;
        }
        else
        {
            system("cls");
            printf("Opcao invalida");
            Sleep(1000);
            system("cls");
            escolha=0;
            
        }
    }

    escolha=0;
    printf("\n\n\t\t\t\t\tTODO MUNDO TEM UM NOME, QUAL O SEU?");
    while (escolha==0)
    {
        printf("\n\n\t\t\t\t\tDIGITE SEU NOME: ");
        scanf("%s", nome);
        system("cls");
        printf("\t\t\t\t\tVOCÊ TEM CERTEZA DA SUA ESCOLHA?\n\t\t\t\t\t(1)-SIM\n\t\t\t\t\t(2)-NÃO\n\t\t\t\t\t");
        scanf("%i",&escolha);

        if (escolha==1)
        {
            system("cls");
            escolha++;
        }
        else if (escolha==2)
        {
            system("cls");
            escolha=0;
        }
        else
        {
            system("cls");
            printf("OPÇÃO INVÁLIDA");
            Sleep(1500);
            system("cls");
            escolha=0;
        }
        
        
    }
    
    printf("%s",nome);
    Sleep(1500);
    system("cls");
    printf("\t\t\t\tO ano é 1946, o mundo se mostra perdido em meio a\n\t\t\t\tascenção de grandes potências. Aconteça o que acontecer,....");
    Sleep(3000);
    printf("\n\n\t\t\t\tNUNCA\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tDIGA\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tSEU\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tNOME\n\t\t\t\t");
    Sleep(2500);
    pause();
    system("cls");

    map(10,20);
    
    fim:
    return 0;
}
