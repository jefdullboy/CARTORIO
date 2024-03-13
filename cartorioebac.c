#include <stdio.h>  //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o 
#include <string.h>  //biblioteca repons�vel por cuidar das string

int registro() //  Responsavel por cadastrar os os usuarios no sistema
{
	// Inicio da cria��o de variaveis/strings  
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     // Final da cria��o de variaveis/strings  

     
     printf("Digite o CPF a ser cadastrado: "); // Coletando infotma��o do us�ario 
     scanf("%s", cpf); // %s refere-se as strings 
     
     strcpy(arquivo, cpf);  //  Responsavel por copiar os valores das string
	 
	 FILE *file;  // cria o arquivo
	 file = fopen(arquivo, "w");  // cria  o arquivo e o "w" significa escrever
	  fprintf(file," \nCPF: ");	 // salva o valor da variavel 
	 fprintf(file,cpf); // salva o valor da variavel 
	 fclose(file);  // fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // cria um arquivo
	 fprintf(file," \nNOME: "); //salva o valor na variavel 
	 fclose(file); // fecha o arquivo 
	 
	 printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usuario
	 scanf("%s", nome); // %s refere-se as strings 
	 
	 file = fopen(arquivo, "a"); // cria um arquivo
	 fprintf(file,nome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a");  // cria um arquivo
	 fprintf(file," \nSOBRENOME: "); // salva o valor da variavel 
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��es do usuario 
	 scanf("%s", sobrenome);
	 
	 file = fopen(arquivo, "a"); // cria um arquivo
	 fprintf(file,sobrenome); // salva a variavel do arquivo
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // cria um arquivo 
	 fprintf(file," \nCARGO: ");  // salva o valor da variavel 
	 fclose(file); // fecha o arquivo 
	 
	 printf("Digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,cargo);
	 fprintf(file, "\n\n");
	 fclose(file);
	 
	 
	 system("pause");
	 
	 
	 
     
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
    char conteudo[100];
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}

printf("\nEssas s�o as informa��es do usu�rio:\n ");
	
while(fgets(conteudo, 100, file) != NULL)
{
	
	printf("%s", conteudo);
}
  	
system ("pause");

	
	
}

int deletar()
{
char cpf[40];

printf("Digite o cpf a ser deletado: ");
scanf("%s",cpf);

remove(cpf);

FILE *file;
file  = fopen(cpf,"r");

if(file == NULL)
{
	printf("O us�ario n�o se encontra no sistema!.\n");
	system("pause");
	}	
	
	else
	{
		
		if (remove(cpf) == 0) 
		{
			printf("CPF de us�ario deletado com sucesso!\n");
			 fclose(file);

			system("pause");
		}
	}
}



int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
  { 
    
	system("cls"); // responsavel por limpar a tela 
	   	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	

	
	printf("Cart�rio da EBAC \n\n");  //inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes \n\n"); 
    printf("\t4 - Sair do sistema \n\n");      
	printf("Op��o:");  //fim do menu
    

    scanf("%d", &opcao); //armazenando a escolha do usuario 
    
    system("cls"); // responsavel po limpar a tela
    
    switch(opcao) //inicio da sele��o
    {
    	case 1:    	
        registro(); // chamada de fun�oes 
		break;
		
		case 2:
     	consulta();
     	break;
     	
     	case 3:
     	deletar();
	 	break;
	 	
	 	case 4:
	 	printf("Obrigado por usar o sistema! \n");
	 	return 0;
	 	break;
	 	
	 	default:
	 	printf("Op��o incorreta\n");
	 	system ("pause");
	 	break;	 					
			
	}  // Fim da sele��o
  
  }
}
