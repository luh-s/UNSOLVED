#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char nome[20];
    int escolha=0,mapa[20][20];

    UINT portugues = 65001;
    SetConsoleOutputCP(portugues);

    int i,i2;
    for ( i = 0; i < 20; i++)
    {
        for ( i2 = 0; i2 < 20; i2++)
        {
            mapa[i][i2]=0;
        }
        
    }

    printf("\n\n\t\t\t.---------------------------------------------------------------------------.\n\t\t\
        |##     ## ##    ##  ######   #######  ##       ##     ## ######## ######## |\n\t\t\
        |##     ## ###   ## ##    ## ##     ## ##       ##     ## ##       ##     ##|\n\t\t\
        |##     ## ####  ## ##       ##     ## ##       ##     ## ##       ##     ##|\n\t\t\
        |##     ## ## ## ##  ######  ##     ## ##       ##     ## ######   ##     ##|\n\t\t\
        |##     ## ##  ####       ## ##     ## ##        ##   ##  ##       ##     ##|\n\t\t\
        |##     ## ##   ### ##    ## ##     ## ##         ## ##   ##       ##     ##|\n\t\t\
        | #######  ##    ##  ######   #######  ########    ###    ######## ######## |\n\t\t\
        '---------------------------------------------------------------------------'\n\n");

    printf("\t\t\t\t\t  [APERTE QUALQUER TECLA PARA CONTINUAR]\n");
    system("pause > NUL");

    while (escolha==0)
    {
        system("cls");
        printf("\n\n\t\t\t.---------------------------------------------------------------------------.\n\t\t\
        |##     ## ##    ##  ######   #######  ##       ##     ## ######## ######## |\n\t\t\
        |##     ## ###   ## ##    ## ##     ## ##       ##     ## ##       ##     ##|\n\t\t\
        |##     ## ####  ## ##       ##     ## ##       ##     ## ##       ##     ##|\n\t\t\
        |##     ## ## ## ##  ######  ##     ## ##       ##     ## ######   ##     ##|\n\t\t\
        |##     ## ##  ####       ## ##     ## ##        ##   ##  ##       ##     ##|\n\t\t\
        |##     ## ##   ### ##    ## ##     ## ##         ## ##   ##       ##     ##|\n\t\t\
        | #######  ##    ##  ######   #######  ########    ###    ######## ######## |\n\t\t\
        '---------------------------------------------------------------------------'\n\n");
        printf("\t\t\t\t\t\t[ESCOLHA UMA DAS OPÇÕES]\n\n\t\t\t\t\t\t(1) - JORNADA\n\t\t\t\t\t\t(2) - CRÉDITOS\n\t\t\t\t\t\t(3) - SAIR DE UNSOLVED\n\t\t\t\t\t\t ");
        scanf("%i",&escolha);

        
        if (escolha==1)
        {
            system("cls");
            printf("\t\t\t\tApós anos de investigação, o departamento da verdade encerrou\n\t\t\t\t o caso o qual você tentou encontrar as respostas.\n\n\t\t\t\tVocê acreditava que estava cada vez mais perto de uma solução,\n\t\t\t\t sendo assim, decidiu fazer isso por conta própria.\n\n");
            Sleep(2500);
            printf("\n\t\t\t\t\t[APERTE QUALQUER TECLA PARA CONTINUAR]");
            system("pause > NUL");
            system("cls");
            escolha++;
        }
        else if (escolha==2)
        {
            system("cls");
            printf("\t\t\t\t\t\t\tCRÉDITOS:\n\n\t\t\t\t\t\tLUAN PIEDADE DE OLIVEIRA\n");
            printf("\n\t\t\t\t\t[APERTE QUALQUER TECLA PARA CONTINUAR]");
            system("pause > NUL");
            escolha=0;

        }
        else if (escolha==3)
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
        gets(nome);
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
    printf("\n\t\t\t\t\t[APERTE QUALQUER TECLA PARA CONTINUAR]");
    system("pause > NUL");
    system("cls");

    for ( i = 0; i < 20; i++)
    {
        printf("\n\t\t\t\t");

        for ( i2 = 0; i2 < 20; i2++)
        {
            if (mapa[i][i2]==0)
        {
            printf("-");
        }
        else
        {
            printf("*");
        }

        }
        
    }
    


    fim:
    return 0;
}
