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
            cadastrar_cliente();
            return 0;
        case 2: 
            buscar_cliente();
            return 0;
        case 3:
            remover_cadastro();
            return 0;
        default:
            printf("Encerrando programa");
            break;
    }
}

int cadastrar_cliente(){
    while(opcao_cadastro != 2){

        printf("Digite o nome do cliente: ");
        fgets(pessoas[0].nome, sizeof(pessoas[0].nome), stdin);
        printf("%s", pessoas[0].nome);

        printf("Digite o CPF do cliente: ");
        //se o cpf existir msg de erro, implementar dps
        if(pessoas[0].cpf != NULL){
            printf("[ERRO] O CPF já existe");
        } else{
            fgets(pessoas[0].cpf, sizeof(pessoas[0].cpf), stdin);
            printf("%s", pessoas[0].cpf);
        }

        printf("Digite o telefone do cliente: ");
        fgets(pessoas[0].telefone, sizeof(pessoas[0].telefone), stdin);

        printf("Digite o E-mail do cliente: ");
        fgets(pessoas[0].email, sizeof(pessoas[0].email), stdin);

        // abrir o TXT
        // salvar os dados no TXT
        // fechar o TXT

        printf("Voce deseja cadastrar outro cliente ? \n 1 - Sim \n 2 - Não");
        scanf("%d", &opcao_cadastro);
    }
}

int buscar_cliente(){
    while(opcao_busca != 2){

        printf("Digite o CPF do cliente desejado: ");
        scanf("%s", pessoas[0].cpf);

        if(pessoas[0].cpf == NULL){
            printf("Cliente não cadastrado");
        } else{
            // abrir txt, mostrar os dados
            //fechar o txt
        }

        printf("Voce deseja realizar outra busca ? \n 1 - Sim \n 2 - Não");
        scanf("%d", &opcao_busca);
    }
}

int remover_cliente(){
    while(opcao_excluir != 2){

        printf("Digite o CPF que deseja remover do cadastro");
        fgets(pessoas[0].cpf, sizeof(pessoas[0].cpf), stdin);

        if(pessoas[0]. cpf == NULL){
            printf("Cliente não cadastrado");
        } else{
            // abrir o txt
            // buscar o cpf
            // excluir os dados do cliente
            // fechar o txt
        }

        printf("Voce deseja excluir outro cadastro ? \n 1 - Sim \n 2 - Não");
        scanf("%d", &opcao_excluir);
    }
}