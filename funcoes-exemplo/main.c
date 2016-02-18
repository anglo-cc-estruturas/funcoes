#include <stdio.h>
#include <stdlib.h>

#define SIZE_NOME 32
#define QTD_PESSOAS 5


typedef struct pessoa {
    char nome[SIZE_NOME];
    int idade;
    char sexo;
}tpPessoa;


void limpa_buffer(){
        // Limpeza do buffer do teclado para Linux/Mac
        __fpurge(stdin);
        // Limpeza do buffer do teclado para Windows
        //fflush(stdin);
}


void ler_pessoa(tpPessoa *pessoa){
    printf("Informe o nome da pessoa: ");
    limpa_buffer();
    scanf("%s",pessoa->nome);

    printf("Informe a idade da pessoa: ");
    limpa_buffer();
    scanf("%d",&pessoa->idade);

    printf("Informe o sexo da pessoa [M/F]: ");
    limpa_buffer();
    scanf("%c",&pessoa->sexo);
}

void imprimir_pessoa(tpPessoa pessoa){
    printf("Nome: %s\n",pessoa.nome);
    printf("Idade: %d\n",pessoa.idade);
    printf("Sexo: %c\n\n",pessoa.sexo);
}

void gravar_pessoa(tpPessoa pessoas[], tpPessoa pessoa, int posicao){
    pessoas[posicao] = pessoa;
}

int busca_posicao_livre(int posicoes[]){
    int i, pos;

    pos = -1;

    for(i = 0; i < sizeof(posicoes); i++){
        if (posicoes[i] == 0)
            return pos;
    }

    return pos;
}

int menu(){
    int opc;

    system("clear");

    printf("\n\n###### MENU #######\n\n");
    printf("1 - Castrar Pessoa\n");
    printf("2 - Listar todas as Pessoas\n\n");
    printf("0 - Sair\n");

    printf("Opcao: ");
    scanf("%d",&opc);

    return opc;
}

void msgs_erro(int cod_erro){
    switch (cod_erro){
        case 1:{
            printf("\nNao ha posicoes livres para gravar essa pessoa\n");
            break;
        }
        default:{
            printf("\nErro desconhecido\n");
            break;
        }

    }
}

int main()
{
    int opc=-1;
    int i;
    tpPessoa pessoas[QTD_PESSOAS], pessoa;
    int posicoes[QTD_PESSOAS];

    // Coloca zero em todas as posicoes do vetor
    for(i = 0; i < sizeof(posicoes); i++)
        posicoes[i] = 0;



    while(opc != 0){
        opc = menu();

        switch (opc){
            case 1: {
                ler_pessoa(&pessoa);
                i = busca_posicao_livre(posicoes);

                if ( i != -1)
                    gravar_pessoa(pessoas,pessoa,i);
                else
                    msgs_erro(1);
                break;
            }
            case 2: {

            }

        }
    }


    ler_pessoa(&pessoa);

    imprimir_pessoa(pessoa);

    return 0;
}
