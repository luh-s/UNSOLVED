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
    int yenim,xenim,enimc=0,primeira=0;
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
                    if (i==16 || i==14 || i2==11 ||i2==15 || i==9)
                    {
                        mapa[i][i2]='^';
                    }
                }
            }
            for (i = 12; i < 15; i++)
            {
                mapa[16][i]=' ';
                mapa[14][i]=' ';
            }
            for (i = 6; i < 19; i++)
            {
                mapa[9][i]='^';
            }
            for (i = 1; i < 6; i++)
            {
                for (i2 = 1; i2 < 6; i2++)
                {
                    if (i==5 || i2==5)
                    {
                        mapa[i][i2]='^';
                    }
                }
            }
            
            yenim=10;
            xenim=2;
            mapa[yenim][xenim]='X';
        }
    }
    else if (numap==4)
    {
        mapa[20][0]=']';
        mapa[20][39]='[';
        mapa[2][38]='#';
        if (botao==0)
        {
            mapa[20][1]='&';
            yenim=3;
            xenim=30;
            mapa[yenim][xenim]='X';
            for (i = 7; i < 33; i++)
            {
                for (i2 = 8; i2 < 9; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
        }
        else if (botao==1)
        {
            mapa[1][37]='&';
            yenim=20;
            xenim=17;
            mapa[yenim][xenim]='V';
            for (i = 29; i < 30; i++)
            {
                for (i2 = 1; i2 < 34; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
            for (i = 25; i < 26; i++)
            {
                for (i2 = 6; i2 < 39; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
            for (i = 12; i < 25; i++)
            {
                for (i2 = 6; i2 < 7; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
            for (i = 12; i < 13; i++)
            {
                for (i2 = 6; i2 < 34; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
            for (i = 19; i < 20; i++)
            {
                for (i2 = 34; i2 < 39; i2++)
                {
                    mapa[i][i2]='^';
                }
            }
        }
        for (i = 1; i < 4; i++)
        {
            for (i2 = 8; i2 < 17; i2++)
            {
                if (i2==8 || i2==16)
                {
                    mapa[i][i2]='^';
                }
            }
        }
        for (i = 3; i < 6; i++)
        {
            for (i2 = 12; i2 < 21; i2++)
            {
                if (i2==12 || i2==20)
                {
                    mapa[i][i2]='^';
                }
            }
        }
        for (i = 1; i < 39; i++)
        {
            mapa[6][i]='#';
            mapa[33][i]='#';
            if (i<6)
            {
                mapa[33][i]=' ';
            }
        }
        for (i = 1; i < 4; i++)
        {
            mapa[2][i]='#';
            mapa[4][i]='#';
        }
        for (i = 36; i < 39; i++)
        {
            mapa[35][i]='#';
            mapa[37][i]='#';
        }
        mapa[3][1]='<';
        mapa[36][38]='>';
        if (chave==0)
        {
            mapa[20][35]='@';
        }
        else
        {
            mapa[20][35]=' ';
        }
        mapa[1][38]='O';
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
    else if (numap==7)
    {
        mapa[2][0]=']';
        if (chave==0)
        {
            mapa[12][1]='@';
            mapa[12][12]='[';
            mapa[2][1]='&';
        }
        else
        {
            mapa[12][1]=' ';
            mapa[12][12]=']';
            mapa[13][1]='&';
        }
        
        for (i = 1; i < 10; i++)
        {
            mapa[4][i]='^';
            mapa[10][i]='^';
        }
        for (i = 3; i < 12; i++)
        {
            mapa[7][i]='^';
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
            printf("\n\t\t\t\t\t   [-=- BANDAS -=-]\n\n");
        }
        else if (numap==3)
        {
            printf("\n\t\t\t\t[-=- VASTO CAMPO -=-]\n\n");
        }
        else if (numap==4)
        {
            printf("\n\t\t\t\t\t[-=- O GRANDE QUINTAL -=-]\n\n");
        }
        else if (numap==5)
        {
            printf("\n\t\t\t [-=- CASA DESCONHECIDA -=-]\n\n");
        }
        else if (numap==6)
        {
            printf("\n\t\t\t   [-=- CASA ACOCHEGANTE -=-]\n\n");
        }
        else if (numap==7)
        {
            printf("\n\t\t\t   [-=- BARRACO GRANDE -=-]\n\n");
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
            if (numap==4&&botao==1)
            {
                if (mapa[yenim+1][xenim]==' '||mapa[yenim+1][xenim]=='&')
                {
                    mapa[yenim][xenim]=' ';
                    yenim++;
                    mapa[yenim][xenim]='V';
                }
                if (mapa[y][x]==mapa[yenim][xenim])
                {
                    morte=morte+1;
                    death(morte,numap,1);
                }
                
            }
            
            if (mapa[y-1][x]=='O'&& botao==0)
            {
                botao=1;
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tO cenário muda novamente.");
                Sleep(1200);
                printf("\n\n\tA criatura proxima morrer na sua frete, o alívio dura pouco.");
                Sleep(1200);
                printf("\n\n\tUma criatura ainda mais poderosa aparece.");
                Sleep(1200);
                printf("\n\n\tVocê respira fundo.\n\n\n\t\t\t\t      ");
                Sleep(1200);
                pause();
                map(40,40,4,2,38,0,1,morte);
            }
            if (mapa[y-1][x]==' ' || mapa[y-1][x]=='X')
            {
                if (mapa[y-1][x]=='X')
                {
                    morte=morte+1;
                    death(morte,numap,0);
                }
                y--;
                if (numap==3 && mapa[y+1][x]==mapa[18][1])
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
                if (numap==4 && botao==0)
                {
                    death(morte,numap,0);
                }
                else
                {
                    death(morte,numap,1);
                }
            }
        }
        else if (movimento=='a')
        {
            if (numap==4&&botao==1)
            {
                if (mapa[yenim][xenim-1]==' '||mapa[yenim][xenim-1]=='&')
                {
                    mapa[yenim][xenim]=' ';
                    xenim--;
                    mapa[yenim][xenim]='V';
                }
                if (mapa[y][x]==mapa[yenim][xenim])
                {
                    morte=morte+1;
                    death(morte,numap,1);
                }
            }
            if (numap==4 && mapa[y][x+1]==mapa[1][38])
            {
                    mapa[1][38]='O';
            }
            if (mapa[y][x-1]==' ' || mapa[y][x-1]=='O' || mapa[y][x-1]=='X')
            {
                if (mapa[y][x-1]=='O' && botao==0)
                {
                    botao=1;
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tLogo após apertar o botão, espinhos saem do chão.");
                    Sleep(1200);
                    printf("\n\n\tUma criatura emerge de um vão.");
                    Sleep(1200);
                    printf("\n\n\tAo fundo, você consegue ve a porta do barraco se abrindo.");
                    Sleep(1200);
                    printf("\n\n\tVocê mal consegue mexer o pé do chão.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,18,1,0,1,0);
                }
                if (mapa[y][x-1]=='X')
                {
                    morte=morte+1;
                    death(morte,numap,0);
                }
                x--;
            }   
            else if (mapa[y][x-1]=='^')
            {
                morte=morte+1;
                if (numap==4&&botao==0)
                {
                    death(morte,numap,0);
                }
                else
                {
                    death(morte,numap,1);
                }
            }
            else if (mapa[y][x-1]=='<')
            {
                mapa[36][37]='&';
                mapa[3][2]=' ';
                y=36;
                x=37;
            }
        }
        else if (movimento=='s')
        {
            if (numap==4&&botao==1)
            {
                if (mapa[yenim-1][xenim]==' '||mapa[yenim-1][xenim]=='&')
                {
                    mapa[yenim][xenim]=' ';
                    yenim--;
                    mapa[yenim][xenim]='V';
                }
                if (mapa[y][x]==mapa[yenim][xenim])
                {
                    morte=morte+1;
                    death(morte,numap,1);
                }
            }
            if (numap==4 && mapa[y-1][x]==mapa[1][38])
            {
                mapa[1][38]='O';
            }
            if (mapa[y+1][x]==' ' || mapa[y+1][x]=='O' || mapa[y+1][x]=='X')
            {
                if (mapa[y+1][x]=='O' && botao==0)
                {
                    botao=1;
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tLogo após apertar o botão, espinhos saem do chão.");
                    Sleep(1200);
                    printf("\n\n\tUma criatura emerge de um vão.");
                    Sleep(1200);
                    printf("\n\n\tAo fundo, você consegue ve a porta do barraco se abrindo.");
                    Sleep(1200);
                    printf("\n\n\tVocê mal consegue mexer o pé do chão.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,18,1,0,1,0);
                }
                if (mapa[y+1][x]=='X')
                {
                    morte=morte+1;
                    death(morte,numap,0);
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
                if (numap==4&&botao==0)
                {
                    death(morte,numap,0);
                }
                else
                {
                    death(morte,numap,1);
                }
            }
        }
        else if (movimento=='d'|| movimento=='D')
        {
            if (numap==4&&botao==1)
            {
                if (mapa[yenim][xenim+1]==' '||mapa[yenim][xenim+1]=='&')
                {
                    mapa[yenim][xenim]=' ';
                    xenim++;
                    mapa[yenim][xenim]='V';
                }
                if (mapa[y][x]==mapa[yenim][xenim])
                {
                    morte=morte+1;
                    death(morte,numap,1);
                }
            }
            if (numap==4)
            {
                if (mapa[y][x+1]=='O'&&botao==0)
                {
                    botao=1;
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tO cenário muda novamente.");
                    Sleep(1200);
                    printf("\n\n\tA criatura proxima morrer na sua frete, o alívio dura pouco.");
                    Sleep(1200);
                    printf("\n\n\tUma criatura ainda mais poderosa aparece.");
                    Sleep(1200);
                    printf("\n\n\tVocê respira fundo.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(40,40,4,1,37,0,1,morte);
                }
            }
            if (mapa[y][x+1]==' ' || mapa[y][x+1]=='X')
            {
                if (mapa[y][x+1]=='X')
                {
                    morte=morte+1;
                    death(morte,numap,0);
                }
                x++;
                if (numap==3 && mapa[y][x-1]==mapa[18][1])
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
                    printf("\n\n\tVocê: -Desgraçado...Que coisa?\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(10,30,2,5,1,0,0,0);
                }
                else if (numap==2)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tVocê: Que estranho, quem fechou esse portão?");
                    Sleep(1200);
                    printf("\n\n\tVocê: Que lugar vazio...vejo apenas um botão e um barraco.");
                    Sleep(1200);
                    printf("\n\n\tO vento canta uma leve canção.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(20,20,3,2,1,0,0,0);
                }
                else if (numap==3)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tDesesperado, você entra no barraco e tranca a porta.");
                    Sleep(1200);
                    printf("\n\n\tVocê: -Droga, quase que aquela coisa me pega.");
                    Sleep(1200);
                    printf("\n\n\tVocê escuta batidas na porta.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(15,13,7,2,1,0,1,0);
                }
                else if (numap==4)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tDepois de muito correr, você para para respirar.");
                    Sleep(1200);
                    printf("\n\n\tVocê: -Nem consegui provas, pelo menos agora entendo do por que cancelar minha investigação.");
                    Sleep(1200);
                    printf("\n\n\tVocê volta para casa a salvo.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- PARABÉNS -=-]\n\n\t\t\tVOCÊ TERMINOU O JOGO! OBRIGADO POR JOGAR UNSOLVED :).\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    main();
                }
                else if (numap==7)
                {
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]\n\n\tVocê se esforça para sair dentre as brechas do barraco.");
                    Sleep(1200);
                    printf("\n\n\tQuando finalmente consegue, os pedeços de madeira que antes pareciam um vão, agora parecem uma parede.");
                    Sleep(1200);
                    printf("\n\n\tVocê se depara com um grande quintal, com algumas máquinas velhas espalhadas.");
                    Sleep(1200);
                    printf("\n\n\t(AVISO!, NECESSÁRIO O USO DE TELA CHEIA!)\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    pause();
                    map(40,40,4,20,1,0,0,0);
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
                if (numap==4&&botao==0)
                {
                    death(morte,numap,0);
                }
                else
                {
                    death(morte,numap,1);
                }
            }
            else if (mapa[y][x+1]=='>')
            {
                mapa[36][37]=' ';
                mapa[3][2]='&';
                y=3;
                x=2;
                if (primeira==0&&botao==0)
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t[-=- DIÁLOGO -=-]");
                    printf("\n\n\tVocê: -O que acabou de acontecer?...égua.\n\n\n\t\t\t\t      ");
                    Sleep(1200);
                    primeira=1;
                    pause();
                }
                
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
                else if (numap==7)
                {
                    map(15,13,7,13,1,1,1,morte);
                }
                else if (numap==4)
                {
                    mapa[yenim][xenim]=' ';
                    yenim=1;
                    xenim=1;
                    mapa[20][35]=' ';
                    mapa[y][x]=' ';
                    y=20;
                    x=33;
                    mapa[y][x]='&';
                    mapa[20][39]=']';
                    
                }
                
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
                    printf("\n\n\tVocê: -Procuro respostas.");
                    Sleep(1200);
                    printf("\n\n\tSenhor desconhecido: -Todos procuram...Siga em direção ao leste, você deve encontrar algo naquelas bandas.");
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
        if ((numap==3 && botao==1) || (numap==4 && botao==0))
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
                death(morte,numap,0);
            }
        }
    }
}
void death(int morte, int numap,int botao)
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
        if (botao==0)
        {
            if (morte!=5)
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu!");
                Sleep(1200);
                printf("\n\n\tVocê morreu %i/5 vezes!\n\n\n\t\t\t\t      ",morte);
                Sleep(1200);
                pause();
                map(40,40,4,20,1,0,0,morte);
            }
            else
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu 5/5 vezes!");
                Sleep(1200);
                printf("\n\n\tVocê morreu muitas vezes, volte para o inicio!\n\n\n\t\t\t\t      ");
                Sleep(1200);
                pause();
                main();
            }
        }
        else
        {
            if (morte!=5)
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu!");
                Sleep(1200);
                printf("\n\n\tVocê morreu %i/5 vezes!\n\n\n\t\t\t\t      ",morte);
                Sleep(1200);
                pause();
                map(40,40,4,1,37,0,1,morte);
            }
            else
            {
                system("cls");
                printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu 5/5 vezes!");
                Sleep(1200);
                printf("\n\n\tVocê morreu muitas vezes, volte para o inicio!\n\n\n\t\t\t\t      ");
                Sleep(1200);
                pause();
                main();
            }
        }
        
        
        
    }
    else if (numap==7)
    {
        if (morte!=3)
        {
            system("cls");
            printf("\n\t\t\t\t\t\t[-=- MORTE -=-]\n\n\tVocê morreu!");
            Sleep(1200);
            printf("\n\n\tVocê morreu %i/3 vezes!\n\n\n\t\t\t\t      ",morte);
            Sleep(1200);
            pause();
            map(15,13,7,2,1,0,1,morte);
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
            printf("\t\t\t\t\t\t   [-=- CRÉDITOS -=-]\n\n\n\t\t\t\t\t        [-=- PROJETADO POR -=- ]\n\n\t\t\t\t\t\tLUAN PIEDADE DE OLIVEIRA\n\n\t\t\t\t\t\t   LUCAS SOUSA JATENE\n\n\n\n\t\t\t\t\t         [-=- ESCRITO POR -=- ]\n\n\t\t\t\t\t\tLUAN PIEDADE DE OLIVEIRA\n\n\n\t\t\t\t\t  ");
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
                printf("\n\t\t\t\t\t\t[-=- ELEMENTOS -=-]\n\n\n\t[-=- MOVIMENTAÇÃO -=-]\t\t\t[-=- INTERAÇÃO -=-]\t\t\t[-=- PERIGOS -=-]\n\n\t| e -:PORTAS LIVRES\t\t\t@: CHAVE\t\t\t\t^: ESPINHO\n\t[: PORTA TRANCADA\t\t\tP: NPC\t\t\t\t\tX: INIMIGO LEVEL 1\n\t]: PORTA ABERTA\t\t\t\t\t\t\t\t\tV: INIMIGO LEVEL 2\n\t#: PAREDES\n\n\n\t\t\t\t\t");
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

    //[-=- DIÁLOGO/LORE -=-]
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

