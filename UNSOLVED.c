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
void map(int v1, int v2,int numap,int yjogador,int xjogador, int chavem)
{
    srand(time(0));
    int i,i2,x=xjogador,y=yjogador,chave=chavem;
    char mapa[v1][v2],movimento;

    for (i = 0; i < v1; i++)
    {
        for ( i2 = 0; i2 < v2; i2++)
        {
            if (i==0 || i==v1-1 || i2==0 || i2==v2-1)
                mapa[i][i2]='#';
            else
                mapa[i][i2]=' ';
        }
    } 
    if (numap==1)
    {
        mapa[y][x]='&';
        mapa[4][6]='P';
        for (i = 1; i < 5; i++)
        {
            for (i2 = 1; i2 < 5; i2++)
            {
                if (i==4 || i2==4)
                    mapa[i][i2]='#';
                else
                    mapa[i][i2]='*';
            }
        }
        for (i = 7; i < 10; i++)
        {
            for (i2 = 20; i2 < 29; i2++)
            {
                if (i==7 || i2==20)
                    mapa[i][i2]='#';
                else
                    mapa[i][i2]='_';
            }
        }
        mapa[4][2]='-';
        if (chave==0)
            mapa[5][29]='[';
        else
            mapa[5][29]=']';
    }
    else if (numap==2)
    {
        mapa[y][x]='&';
        mapa[5][0]=']';
        mapa[8][29]='[';
        for (i = 1; i < 7; i++)
        {
            for (i2 = 23; i2 < 29; i2++)
            {
                if (i==6 || i2==23)
                    mapa[i][i2]='#';
                else
                    mapa[i][i2]='*';
            }
        }
        mapa[2][23]='|';
    }
    else if (numap==3)
    {

    }
    else if (numap==4)
    {

    }
    
    else if (numap==5)
    {
        mapa[y][x]='&';
        mapa[9][5]='-';
        if (chave==0)
            mapa[1][1]='@';
    }
    else if (numap==6)
    {
        mapa[y][x]='&';
        mapa[5][2]='-';
    }
    

    while (i!=-1)
    {
        system("cls");
        if (numap==1)
        {
            printf("\n\t\t\t\t\t[-=- VILA -=-]\n\n");
        }
        else if (numap==2)
        {
            printf("\n\t\t\t\t   [-=- PRÉDIO ABANDONADO-=-]\n\n");
        }
        else if (numap==5)
        {
            printf("\n\t\t\t [-=- CASA DESCONHECIDA -=-]\n\n");
        }
        
        for (i = 0; i < v1; i++)
        {
            printf("\n\t\t\t\t");
            for (i2 = 0; i2 < v2; i2++)
            {
                printf("%c",mapa[i][i2]);   
            }
        }
        movimento=getch();
        mapa[y][x]=' ';
        if (movimento=='w')
        {
            if (mapa[y-1][x]==' ')
            {
                y--;
            }
            else if (numap==1 && mapa[y-1][x]=='-')
            {
                system("cls");
                if (chave==0)
                {
                    map(10,11,5,8,5,0);
                }
                else
                {
                    map(10,11,5,8,5,1);
                }
                
                system("pause");
            }
               
        }
        else if (movimento=='a')
        {
            if (mapa[y][x-1]==' ')
            {
                x--;
            }   
        }
        else if (movimento=='s')
        {
            if (mapa[y+1][x]==' ')
            {
                y++;
            }
            else if (mapa[y+1][x]=='-')
            {
                system("cls");
                if (numap==5)
                {
                    if (chave==0)
                    {
                        map(11,30,1,5,2,0);
                    }
                    else
                    {
                        map(11,30,1,5,2,1);
                    }
                }
                else if (numap==6)
                {
                    if (chave==0)
                    {
                        map(10,30,2,2,22,0);
                    }
                    else
                    {
                        map(10,30,2,2,22,1);
                    }
                }
                
            }
        }
        else if (movimento=='d')
        {
            if (mapa[y][x+1]==' ')
            {
                x++;
            }
            else if (mapa[y][x+1]==']')
            {
                if (numap==1)
                {
                    system("cls");
                    printf("\n\n\tLogo após destrancar o portão, o senhor empurra você e diz.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Desculpe camarada, não posso arriscar que aquela coisa saia dai.");
                    Sleep(1200);
                    printf("\n\n\tO portão foi barrado.");
                    Sleep(1200);
                    printf("\n\n\tPessoa: -Desgraçado");
                    Sleep(1200);
                    pause();
                    chave=0;
                    map(10,30,2,5,1,0);
                }
                else if (numap==2)
                {

                }
            }
            else if (mapa[y][x+1]=='|')
            {
                system("cls");
                if (numap==2)
                {
                    if (chave==0)
                    {
                        map(6,15,6,4,2,0);
                    }
                    else
                    {
                        map(6,15,6,4,2,1);
                    }
                }
            }
        }
        else if (movimento=='e')
        {
            if (mapa[y-1][x]=='@')
            {
                if (numap==5)
                {
                    printf("\n\n\t\t\t[-=- VOCÊ ENCONTROU UMA CHAVE -=-]\n");
                    pause();
                    chave=1;
                    mapa[1][1]=' ';

                }
            }
            else if (mapa[y-1][x]=='P')
            {
                if (chave==0)
                {
                    system("cls");
                    printf("\n\n\tSenhor desconhecido: -Olá camarada, faz muito tempo que não vejo um jovem por aqui, deseja algo?");
                    Sleep(1200);
                    printf("\n\n\tPessoa: -Procuro respostas.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Todos procuram...Siga em direção ao leste, você deve encontrar algo naqueles prédios.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Já ia me esquecendo, pegue a chave em minha casa (@), você precisará dela para abrir o portão\n");
                    pause();
                }
                else
                {
                    system("cls");
                    printf("\n\n\tSenhor desconhecido: -Olá camarada, vejo que já encontrou a chave, lembre-se de ter cuidado,\n\t\t\to leste não anda sendo muito piedoso com novos aventureiros!\n");
                    Sleep(1200);
                    pause();
                }
            }
        }
        mapa[y][x]='&';
    }
}
void erro()
{
    system("cls");
    printf("Opcao invalida");
    Sleep(1000);
    system("cls");
}

int main()
{
    char nome[20];
    int escolha=0,i,i2;

    system("echo -e \e[?25l");
    system("cls");
    UINT portugues = 65001;
    SetConsoleOutputCP(portugues);

    title();
    pause();

    while (escolha==0)
    {
        system("cls");
        title();
        printf("\t\t\t\t\t    [ESCOLHA UMA DAS OPÇÕES]\n\n\t\t\t\t\t\t[1] - JORNADA\n\t\t\t\t\t\t[2] - CRÉDITOS\n\t\t\t\t\t\t[3] - COMO JOGAR\n\t\t\t\t\t\t[4] - SAIR DE UNSOLVED\n\t\t\t\t\t\t ");
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
            while (escolha=='3')
            {
            system("cls");
            printf("\n\t\t\t\t\t\t[-=- COMO JOGAR -=-]\n\n\t\t\t\t\t\t [1] - CONTROLES\n\t\t\t\t\t\t [2] - OBJETIVO\n\t\t\t\t\t\t [3] - SAIR\n");
            escolha=getch();

            if (escolha=='1')
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- CONTROLES -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\n\n\tW: CIMA \t\t\t\tEsc: MENU RÁPIDO\n\tA: ESQUERDA\t\t\t\tE: INTERAGIR\n\tS: BAIXO\n\tD: DIREITA\n\n");
                escolha='3';
                pause();
            }
            else if (escolha=='2')
            {
                /* code */
            }
            else if (escolha=='3')
            {
                /* code */
            }
            else if (escolha=='4')
            {
                escolha=0;
            }
            
            else
            {
                erro();
                escolha='3';
            }

            }
        }
        
        else if (escolha=='4')
        {
            for (i = 0; i < 3; i++)
            {
                system("cls");
                printf("\n\n\t\tObrigado por jogar UNSOLVED, espero que você volte logo!\n\n\t\t");
                printf("Saindo do jogo");
                for (i2 = 0; i2 < 3; i2++)
                {
                    printf(".");
                    Sleep(500);
                }
                
            }
            printf("\n\n");
            goto fim;
        }
        else
        {
            erro();
            escolha=0;
        }
    }

    escolha=0;
    system("echo -e \e[?25h");
    system("cls");
    printf("\n\n\t\t\t\t\tTODO MUNDO TEM UM NOME, QUAL O SEU?");

    while (escolha==0)
    {
        
        printf("\n\n\t\t\t\t\tDIGITE SEU NOME: ");
        gets(nome);
        system("cls");
        printf("\t\t\t\t\tVOCÊ TEM CERTEZA DA SUA ESCOLHA?\n\t\t\t\t\t(1)-SIM\n\t\t\t\t\t(2)-NÃO\n\t\t\t\t\t");
        escolha=getch();

        if (escolha=='1')
        {
            system("cls");
            escolha++;
        }
        else if (escolha=='2')
        {
            system("cls");
            escolha=0;
        }
        else
        {
            erro();
            escolha=0;
        }
        
        
    }
    system("echo -e \e[?25l");
    system("cls");
    
    puts(nome);
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


    map(11,30,1,6,15,0);

    fim:
    
    return 0;
}
