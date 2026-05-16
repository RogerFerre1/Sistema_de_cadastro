#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[50];
    char cpf[12];
    char telefone[9];
    char email[100];
};

struct Pessoa pessoas[100];

int opcao, opcao_cadastro, opcao_busca, opcao_excluir;


int main(){
    printf("############### Sistema de Cadastro ###############");
    printf("\nSelecione a operacao desejada: \n 1 - Cadastrar cliente \n 2 - Buscar cliente \n 3 - Remover cadastro \n 4 - Sair \n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1: 
            //cadastrar_cliente();
            printf("Vc escolheu cadastrar cliente");
            return 0;
        case 2: 
            //buscar_cliente();
            printf("Vc escolheu buscar cliente");
            return 0;
        case 3:
            //remover_cadastro();
            printf("Vc escolheu remover cadastro");
            return 0;
        default:
            printf("Encerrando programa");
            break;
    }
}

int cadastrar_cliente(){
    printf("Digite o nome do cliente: ");
    fgets(pessoas[0].nome, sizeof(pessoas[0].nome), stdin);
    printf("%s", pessoas[0].nome);

    printf("Digite o CPF do cliente: ");
    //se o cpf existir
    if(pessoas[0].cpf == ){
        printf("[ERRO] O CPF já existe");
    } else{
        fgets(pessoas[0].cpf, sizeof(pessoas[0].cpf), stdin);
        printf("%s", pessoas[0].cpf);
    }

    printf("Digite o telefone do cliente: ");
    fgets(pessoas[0].telefone, sizeof(pessoas[0].telefone), stdin);

    printf("Digite o E-mail do cliente: ");
    fgets(pessoas[0].email, sizeof(pessoas[0].email), stdin);

    // salvar os dados no TXT
}

