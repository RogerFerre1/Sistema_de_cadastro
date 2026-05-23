#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Pessoa engloba todas as variáveis declaradas em um mesmo padrão
struct Pessoa{
    char nome[50];
    char cpf[20];
    char telefone[20];
    char email[100];
};

// Definindo a quatidade de cadastros suportados
struct Pessoa pessoas[100];

int opcao = 0, opcao_cadastro = 0, opcao_listar = 0;
int total_pessoas = 0;

// Declarando as funções
int cadastrar_cliente();
int listar_cliente();

int main(){
    printf("############### Sistema de Cadastro ###############");
    printf("\nSelecione a operacao desejada: \n 1 - Cadastrar cliente \n 2 - Verificar cadastro \n 3 - Sair \n");
    scanf("%d", &opcao);
    getchar();

    // Chamando as funções de acordo com a opção selecionada
    switch(opcao){
        case 1: 
            cadastrar_cliente();
            return 0;
        case 2: 
            listar_cliente();
            return 0;
        default:
            printf("Encerrando programa");
            break;
    }
}

// Função cadastrar cliente
int cadastrar_cliente(){
    
    while(opcao_cadastro != 2){

        // Cria um ponteiro para a variavel file
        FILE *file;
    
        // Cria ou abre o arquivo "clientes.txt"
        // O "a" define a ação a ser realizada no arquivo, no caso append adiciona novos registros
        file = fopen("clientes.txt", "a");

        // Verifica se o arquivo foi aberto
        if(file == NULL){
            printf("Erro ao abrir o arquivo");
            system("pause");
            exit(0);
        }

        printf("Digite o nome do cliente: ");
        // Fgets substitui o scanf, ideal para armazenar mais de 1 palavra por variável
        fgets(pessoas[total_pessoas].nome, sizeof(pessoas[total_pessoas].nome), stdin);
        //Fprintf "imprime" o dado em um arquivo txt em vez da tela
        fprintf(file, "Nome: %s", pessoas[total_pessoas].nome);

        printf("Digite o CPF do cliente: ");
        fgets(pessoas[total_pessoas].cpf, sizeof(pessoas[total_pessoas].cpf), stdin);
        fprintf(file, "CPF: %s", pessoas[total_pessoas].cpf);

        printf("Digite o telefone do cliente: ");
        fgets(pessoas[total_pessoas].telefone, sizeof(pessoas[total_pessoas].telefone), stdin);
        fprintf(file, "Telefone: %s", pessoas[total_pessoas].telefone);

        printf("Digite o E-mail do cliente: ");
        fgets(pessoas[total_pessoas].email, sizeof(pessoas[total_pessoas].email), stdin);
        fprintf(file, "E-mail: %s \n", pessoas[total_pessoas].email);
        
        // Fecha o arquivo clientes.txt
        fclose(file);
        // Incrementa o vetor de pessoas cadastradas
        total_pessoas++;

        printf("Voce deseja cadastrar outro cliente ? \n 1 - Sim \n 2 - Nao \n");
        scanf("%d", &opcao_cadastro);
        getchar();
    }
}

int listar_cliente(){  
    FILE *file;
    
    // Variável para armazenar cada linha
    char linha[200];

    // Abre o arquivo em modo leitura
    file = fopen("clientes.txt", "r");

    if(file == NULL){
        printf("Nenhum cliente cadastrado. \n");
        return 0;
    }

    printf("############# CLIENTES CADASTRADOS ##############\n");

    while(fgets(linha, sizeof(linha), file) != NULL){
        printf("%s", linha);
    }

    fclose(file);

    return 0;
}