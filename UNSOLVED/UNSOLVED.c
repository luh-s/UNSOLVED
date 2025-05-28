#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void erro()
{
    //[-=- SISTEMA PARA EVITAR OPÇÕES INVÁLIDAS -=-]
    system("cls");
    printf("\n\n\t\t\t\t\t\t[-=- OPÇÃO INVÁLIDA -=-]");
    Sleep(1000);
    system("cls");
}
void title()
{
    //[-=- PRINT DA LOGO -=-]
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
    //[-=- SISTEMA DE PAUSE -=-]
    printf("[APERTE QUALQUER TECLA PARA CONTINUAR]\n");
    system("pause > NUL");
}
void map(int v1, int v2,int numap,int yjogador,int xjogador, int chavem,int botaom,int mortem)
{
    //[-=- SISTEMA DO JOGO -=-]
    srand(time(0));
    int i,i2,x=xjogador,y=yjogador,chave=chavem,botao=botaom,morte=mortem;
    int yenim,xenim,enimc=0;
    char mapa[v1][v2],movimento;

    //[-=- MODELAGEM DOS MAPAS -=-]
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
        if (chave==0)
            mapa[8][29]='[';
        else
            mapa[8][29]=']';
            
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
        mapa[2][0]=']';
        mapa[2][1]='&';
        mapa[18][1]='O';
        for (i = 1; i < 8; i++)
        {
            for (i2 = 12; i2 < 19; i2++)
            {
                if (i==7 || i2==12)
                    mapa[i][i2]='#';
                else
                    mapa[i][i2]='*';
            }
            mapa[2][12]='[';
        }
        if (botao==1)
        {
            mapa[2][1]=' ';
            mapa[18][1]='&';
            mapa[2][12]=']';

            for (i = 14; i < 17; i++)
            {
                for (i2 = 1; i2 < 19; i2++)
                {
                    if (i==16 || i==14 || i2==11 ||i2==15)
                    {
                        mapa[i][i2]='^';
                    }
                }
            }
            for (i = 12; i < 15; i++)
            {
                mapa[16][i]=' ';
            }
            for (i = 12; i < 15; i++)
            {
                mapa[14][i]=' ';
            }
            yenim=10;
            xenim=2;
            mapa[yenim][xenim]='X';
        }
    }
    else if (numap==4)
    {

    }
    
    else if (numap==5)
    {
        mapa[y][x]='&';
        mapa[9][5]='-';
        if (chave==0)
            mapa[1][5]='@';
        for (i = 4; i < 9; i++)
        {
            for (i2 = 0; i2 < 10; i2++)
            {
                if (i2==1 || i2==9)
                {
                    if (i==4)
                    {
                        mapa[i][i2]='T';
                    }
                    else
                    {
                        mapa[i][i2]='I';
                    }
                }
            }
        }
    }
    else if (numap==6)
    {
        mapa[y][x]='&';
        mapa[5][2]='-';
        if (chave==0)
        {
            mapa[1][13]='@';
        }
    }

    //[-=- MOVIMENTAÇÃO, INTERAÇÃO E DIÁLOGOS -=-]
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
        
        //[-=- PRINT DA MODELAGEM DO MAPA -=-]
        for (i = 0; i < v1; i++)
        {
            printf("\n\t\t\t\t");
            for (i2 = 0; i2 < v2; i2++)
            {
                printf("%c",mapa[i][i2]);   
            }
        }

        //[-=- MOVIMENTAÇÃO -=-]
        movimento=getch();
        mapa[y][x]=' ';
        if (movimento=='w')
        {
            if (mapa[y-1][x]==' ')
            {
                y--;
                if (mapa[y+1][x]==mapa[18][1])
                {
                    mapa[18][1]='O';
                }
                
            }
            else if (numap==1 && mapa[y-1][x]=='-')
            {
                system("cls");
                if (chave==0)
                {
                    map(10,11,5,8,5,0,0,0);
                }
                else
                {
                    map(10,11,5,8,5,1,0,0);
                }
                
                system("pause");
            }
            else if (mapa[y-1][x]=='^')
            {
                morte=morte+1;
                death(morte,numap);
            }
        }
        else if (movimento=='a')
        {
            if (mapa[y][x-1]==' ' || mapa[y][x-1]=='O')
            {
                if (mapa[y][x-1]=='O'&& botao==0)
                {
                    botao=1;
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tLogo após apertar o botão, espinhos saem do chão.");
                    Sleep(1200);
                    printf("\n\n\tUma criatura emerge de um vão.");
                    Sleep(1200);
                    printf("\n\n\tVocê mal consegue mexer o pé do chão.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,18,1,0,1,0);
                }
                x--;
            }   
            else if (mapa[y][x-1]=='^')
            {
                morte=morte+1;
                death(morte,numap);
            }
        }
        else if (movimento=='s')
        {
            if (mapa[y+1][x]==' ' || mapa[y+1][x]=='O')
            {
                if (mapa[y+1][x]=='O'&& botao==0)
                {
                    botao=1;
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tLogo após apertar o botão, espinhos saem do chão.");
                    Sleep(1200);
                    printf("\n\n\tUma criatura emerge de um vão.");
                    Sleep(1200);
                    printf("\n\n\tVocê mal consegue mexer o pé do chão.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,18,1,0,1,0);
                }
                y++;
            }
            else if (mapa[y+1][x]=='-')
            {
                system("cls");
                if (numap==5)
                {
                    if (chave==0)
                    {
                        map(11,30,1,5,2,0,0,0);
                    }
                    else
                    {
                        map(11,30,1,5,2,1,0,0);
                    }
                }
                else if (numap==6)
                {
                    if (chave==0)
                    {
                        map(10,30,2,2,22,0,0,0);
                    }
                    else
                    {
                        map(10,30,2,2,22,1,0,0);
                    }
                }
                
            }
            else if (mapa[y+1][x]=='^')
            {
                morte=morte+1;
                death(morte,numap);
            }
        }
        else if (movimento=='d')
        {
            if (mapa[y][x+1]==' ')
            {
                x++;
                if (mapa[y][x-1]==mapa[18][1])
                {
                    mapa[18][1]='O';
                }
            }
            else if (mapa[y][x+1]==']')
            {
                system("cls");
                if (numap==1)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tLogo após destrancar o portão, o senhor empurra você e diz.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Desculpe camarada, não posso arriscar que aquela coisa saia dai.");
                    Sleep(1200);
                    printf("\n\n\tO portão foi barrado.");
                    Sleep(1200);
                    printf("\n\n\tPessoa: -Desgraçado...Que coisa?\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(10,30,2,5,1,0,0,0);
                }
                else if (numap==2)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tPESSOA: Que estranho, quem fechou esse portão?");
                    Sleep(1200);
                    printf("\n\n\tPessoa: Que lugar vazio...vejo apenas um botão.");
                    Sleep(1200);
                    printf("\n\n\tO vento canta uma leve canção.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,2,1,0,0,0);
                }
            }
            else if (mapa[y][x+1]=='|')
            {
                system("cls");
                if (numap==2)
                {
                    if (chave==0)
                    {
                        map(6,15,6,4,2,0,0,0);
                    }
                    else
                    {
                        map(6,15,6,4,2,1,0,0);
                    }
                }
            }
            else if (mapa[y][x+1]=='^')
            {
                morte=morte+1;
                death(morte,numap);
            }
        }
        else if (movimento=='e')
        {
            if (mapa[y-1][x]=='@')
            {
                printf("\n\n\t\t\t[-=- VOCÊ ENCONTROU UMA CHAVE -=-]\n\n\t\t      ");
                pause();
                chave=1;
                if (numap==5)
                    mapa[1][5]=' ';
                else
                    mapa[1][13]=' ';
            }
            else if (mapa[y-1][x]=='P')
            {
                if (chave==0)
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tSenhor desconhecido: -Olá camarada, faz muito tempo que não vejo um jovem por aqui, deseja algo?");
                    Sleep(1200);
                    printf("\n\n\tPessoa: -Procuro respostas.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Todos procuram...Siga em direção ao leste, você deve encontrar algo naqueles prédios.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Já ia me esquecendo, pegue a chave em minha casa (@),\n\t\t\t       você precisará dela para abrir o portão.\n\n\n\t\t\t\t      ");
                    pause();
                }
                else
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tSenhor desconhecido: -Olá camarada, vejo que já encontrou a chave, lembre-se de ter cuidado,\n\t\t\t       o leste não anda sendo muito piedoso com novos aventureiros!\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                }
            }
        }
        else if (movimento=='t')
        {
            movimento='1';
            while (movimento=='1')
            {
                system("cls");
                title();
                printf("\n\t\t\t\t\t\t[-=- MENU RÁPIDO -=-]\n\n\t\t\t\t\t\t[1] - VOLTAR AO JOGO\n\t\t\t\t\t\t[2] - COMO JOGAR\n\t\t\t\t\t\t[3] - VOLTAR AO MENU\n");
                movimento=getch();
                if (movimento=='1')
                {
                    movimento=0;
                }
                else if (movimento=='2')
                {
                    movimento='5';
                    while(movimento=='5')
                    {
                        system("cls");
                        title();
                        printf("\t\t\t\t\t\t[-=- COMO JOGAR -=-]\n\n\t\t\t\t\t\t [1] - CONTROLES\n\t\t\t\t\t\t [2] - ELEMENTOS\n\t\t\t\t\t\t [3] - SAIR\n");
                        movimento=getch();

                        if (movimento=='1')
                        {
                            system("cls");
                            printf("\n\t\t\t\t\t\t[-=- CONTROLES -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\n\n\tW: CIMA \t\t\t\tT: MENU RÁPIDO\n\tA: ESQUERDA\t\t\t\tE: INTERAGIR\n\tS: BAIXO\n\tD: DIREITA\n\n\n\t\t\t\t\t");
                            movimento='5';
                            pause();
                        }
                        else if (movimento=='2')
                        {
                            system("cls");
                            printf("\n\t\t\t\t\t\t[-=- ELEMENTOS -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\n\n\t| e -:PORTAS LIVRES\t\t\t@: CHAVE\n\t[: PORTA TRANCADA\t\t\tP: NPC\n\t]: PORTA ABERTA\n\t#: PAREDES\n\n\n\t\t\t\t\t");
                            movimento='5';
                            pause();
                        }
                        else if (movimento=='3')
                        {
                            movimento='1';
                        }
                        else
                        {
                            erro();
                            movimento='5';
                        }
                    }
                }
                else if (movimento=='3')
                {
                    main();
                }
                else
                {
                    erro();
                    movimento='1';
                }
                
            }
        }
        if (numap==3 && botao==1)
        {
            //[-=- SISTEMA DE MOVIMENTAÇÃO INIMIGO -=-]
            mapa[yenim][xenim]=' ';
            enimc=rand()%2;
            if (enimc==0)
            {
                enimc=rand()%2;
                if (enimc==0)
                {
                    if (mapa[yenim-1][xenim]==' ')
                    {
                        yenim--;
                    }
                }
                else
                {
                    if (mapa[yenim+1][xenim]==' ')
                    {
                        yenim++;
                    }
                }
            }
            else if (enimc==1)
            {
                enimc=rand()%2;
                if (enimc==0)
                {
                    if (mapa[yenim][xenim-1]==' ')
                    {
                        xenim--;
                    }
                }
                else
                {
                    if (mapa[yenim][xenim+1]==' ')
                    {
                        xenim++;
                    }
                }
            }
            mapa[yenim][xenim]='X';
        }
        mapa[y][x]='&';
        if (numap==3  && botao==1)
        {
            if (mapa[y][x]==mapa[yenim][xenim])
            {
                morte=morte+1;
                death(morte,numap);
            }
        }
    }
}
void death(int morte, int numap)
{
    //[-=- SISTEMA DE CONTABILIDADE DE MORTES -=-]
    if (numap==3)
    {
        if (morte!=3)
        {
            system("cls");
            printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu!");
            Sleep(1200);
            printf("\n\n\tVocê morreu %i/3 vezes!\n\n\n\t\t\t\t      ",morte);
            Sleep(1200);
            pause();
            map(20,20,3,18,1,0,1,morte);
        }
        else
        {
            system("cls");
            printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu 3/3 vezes!");
            Sleep(1200);
            printf("\n\n\tVocê morreu muitas vezes, volte para o inicio!\n\n\n\t\t\t\t      ");
            Sleep(1200);
            pause();
            main();
        }
    }
    else if (numap==4)
    {
        printf("s");
    }
}

int main()
{
    //[-=- INICIO PROGRAMA -=-]
    char nome[20];
    int escolha=0,i,i2;

    //[-=- DEFINIÇÕES PARA USO DE PT-BR E SIMBOLOS -=-]
    system("\e[?25l");
    system("cls");
    UINT portugues = 65001;
    SetConsoleOutputCP(portugues);

    title();
    printf("\n\t\t\t\t\t");
    pause();

    //[-=- MENU -=-]
    while (escolha==0)
    {
        system("cls");
        title();
        printf("\t\t\t\t\t     [ESCOLHA UMA DAS OPÇÕES]\n\n\t\t\t\t\t\t[1] - JORNADA\n\t\t\t\t\t\t[2] - CRÉDITOS\n\t\t\t\t\t\t[3] - COMO JOGAR\n\t\t\t\t\t\t[4] - SAIR DE UNSOLVED\n\n\t\t\t\t\t ");
        escolha=getch();

        
        if (escolha=='1')
        {
            system("cls");
            printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-] \n\n\t\t\t\tApós anos de investigação, o departamento da verdade encerrou\n\t\t\t\t o caso o qual você tentou encontrar as respostas.\n\n\t\t\t\tVocê acreditava que estava cada vez mais perto de uma solução,\n\t\t\t\t sendo assim, decidiu fazer isso por conta própria.\n\n\n\t\t\t\t       ");
            Sleep(2500);
            pause();
            system("cls");
            escolha++;
        }
        else if (escolha=='2')
        {
            system("cls");
            printf("\t\t\t\t\t\t   [-=- CRÉDITOS -=-]\n\n\n\t\t\t\t\t    [-=- PROJETADO E ESCRITO POR -=- ]\n\n\t\t\t\t\t\tLUAN PIEDADE DE OLIVEIRA\n\n\n\t\t\t\t\t  ");
            pause();
            escolha=0;

        }
        else if (escolha=='3')
        {
            while (escolha=='3')
            {
            system("cls");
            title();
            printf("\t\t\t\t\t\t[-=- COMO JOGAR -=-]\n\n\t\t\t\t\t\t [1] - CONTROLES\n\t\t\t\t\t\t [2] - ELEMENTOS\n\t\t\t\t\t\t [3] - SAIR\n");
            escolha=getch();

            if (escolha=='1')
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- CONTROLES -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\n\n\tW: CIMA \t\t\t\tT: MENU RÁPIDO\n\tA: ESQUERDA\t\t\t\tE: INTERAGIR\n\tS: BAIXO\n\tD: DIREITA\n\n\n\t\t\t\t\t");
                escolha='3';
                pause();
            }
            else if (escolha=='2')
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- ELEMENTOS -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\n\n\t| e -:PORTAS LIVRES\t\t\t@: CHAVE\n\t[: PORTA TRANCADA\t\t\tP: NPC\n\t]: PORTA ABERTA\n\t#: PAREDES\n\n\n\t\t\t\t\t");
                escolha='3';
                pause();
            }
            else if (escolha=='3')
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
                printf("\n\n\t\tObrigado por jogar UNSOLVED, espero que volte logo!\n\n\t\t");
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
    system("\e[?25h");
    system("cls");
    printf("\n\t\t\t\t\t\t[-=- NOME -=-]\n\n\n\t\t\t\t\tTODO MUNDO TEM UM NOME, QUAL O SEU?");

    //[-=- ARMAZENAMENTO DO NOME DO PLAYER -=-]
    while (escolha==0)
    {
        
        printf("\n\n\t\t\t\t\tDIGITE SEU NOME: ");
        gets(nome);
        system("cls");
        printf("\n\t\t\t\t\t\t[-=- NOME -=-]\n\n\n\t\t\t\t\tVOCÊ TEM CERTEZA DA SUA ESCOLHA?\n\n\t\t\t\t\t\t[1] - SIM\n\t\t\t\t\t\t[2] - NÃO\n\t\t\t\t\t\t");
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
    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\t\t\t\tO ano é 1946, o mundo se mostra perdido em meio a\n\t\t\t\tascenção de grandes potências. Aconteça o que acontecer,....");
    Sleep(3000);
    printf("\n\n\t\t\t\tNUNCA\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tDIGA\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tSEU\n\t\t\t\t");
    Sleep(1000);
    printf("\n\t\t\t\tNOME\n\n\t\t\t\t\t");
    Sleep(2500);
    pause();
    system("cls");

    //[-=- VOID PARA GERAR AS FUNÇÕES DO JOGO -=-]
    map(11,30,1,6,15,0,0,0);

    fim:
    
    return 0;
}

