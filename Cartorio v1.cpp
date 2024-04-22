#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() //fun��o respons�vel por cadastrar os usuarios no sistema
{	
	//inicio de cria��o de vari�veis		
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s",cpf );
 
	strcpy(arquivo, cpf);
	
	FILE *file; 
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); 
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s,", sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usu�rio a der deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main ()

{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("####CART�RIO DA EBAC#### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n ");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do Sistema \n\n");
		printf("Escolha uma Op��o:"); //fim do menu
		
		scanf("%d" , &opcao); //armazenando a escolha do usuario
	
		system("cls"); //respons�vel por deletar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
		
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema \n");
		    return 0;
		    break;
		
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
		} //fim da sele��o
	}		
}
