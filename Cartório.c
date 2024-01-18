#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() //Função responsável por cadastar os usuários no sistema
{
	//Inicio da criação de variáveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
		strcpy(arquivo, cpf); // responsavel por criar os valores das strings
	
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da variavel
		fprintf(file,", ");
		fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o nome do usuário cadastrado
		fprintf(file,nome);
		fprintf(file,", ");
		fclose(file);

	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o sobrenome do usuário cadastrado
		fprintf(file,sobrenome);
		fprintf(file,", ");
		fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o cargo do usuário cadastrado
		fprintf(file,cargo);
		fclose(file);
	
	printf("\nCPF cadastrado com sucesso!\n");
	system("pause");
}

int consultar() //Função consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
	
		FILE *file;
		file = fopen(cpf,"r"); //Faz a leitura do arquivo
	
	
	if(file == NULL) //Condição da variável
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Funão deletar
{
	char cpf[40];
	
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
	
		remove(cpf);
	
		FILE *file;
		file = fopen(cpf, "r");
	
	if(file == NULL) //Condição da variável
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Estrutura de repetição
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCartório da EBAC    \n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); 
		
		
		switch(opcao) //Início da seleção
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;	
		}	
	}
}
