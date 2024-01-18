#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
		strcpy(arquivo, cpf); // responsavel por criar os valores das strings
	
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da variavel
		fprintf(file,", ");
		fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o nome do usu�rio cadastrado
		fprintf(file,nome);
		fprintf(file,", ");
		fclose(file);

	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o sobrenome do usu�rio cadastrado
		fprintf(file,sobrenome);
		fprintf(file,", ");
		fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a"); //Atualiza o arquivo incluindo o cargo do usu�rio cadastrado
		fprintf(file,cargo);
		fclose(file);
	
	printf("\nCPF cadastrado com sucesso!\n");
	system("pause");
}

int consultar() //Fun��o consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
	
		FILE *file;
		file = fopen(cpf,"r"); //Faz a leitura do arquivo
	
	
	if(file == NULL) //Condi��o da vari�vel
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun�o deletar
{
	char cpf[40];
	
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
	
		remove(cpf);
	
		FILE *file;
		file = fopen(cpf, "r");
	
	if(file == NULL) //Condi��o da vari�vel
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //Estrutura de repeti��o
	{
		
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCart�rio da EBAC    \n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); 
		
		
		switch(opcao) //In�cio da sele��o
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;	
		}	
	}
}
