#include <stdio.h>  //biblioteca de comunicação com o usuário 
#include <stdlib.h>  //biblioteca de alocação de espaço em memoria 
#include <locale.h>  //biblioteca de alocação de texto por região 
#include <string.h>  //biblioteca reponsável por cuidar das string

int registro() //  Responsavel por cadastrar os os usuarios no sistema
{
	// Inicio da criação de variaveis/strings  
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     // Final da criação de variaveis/strings  

     
     printf("Digite o CPF a ser cadastrado: "); // Coletando infotmação do usúario 
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
	 
	 printf("Digite o nome a ser cadastrado: "); // coletando informação do usuario
	 scanf("%s", nome); // %s refere-se as strings 
	 
	 file = fopen(arquivo, "a"); // cria um arquivo
	 fprintf(file,nome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a");  // cria um arquivo
	 fprintf(file," \nSOBRENOME: "); // salva o valor da variavel 
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado: "); // coletando informações do usuario 
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
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}

printf("\nEssas são as informações do usuário:\n ");
	
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
	printf("O usúario não se encontra no sistema!.\n");
	system("pause");
	}	
	
	else
	{
		
		if (remove(cpf) == 0) 
		{
			printf("CPF de usúario deletado com sucesso!\n");
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
	

	
	printf("Cartório da EBAC \n\n");  //inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes \n\n"); 
    printf("\t4 - Sair do sistema \n\n");      
	printf("Opção:");  //fim do menu
    

    scanf("%d", &opcao); //armazenando a escolha do usuario 
    
    system("cls"); // responsavel po limpar a tela
    
    switch(opcao) //inicio da seleção
    {
    	case 1:    	
        registro(); // chamada de funçoes 
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
	 	printf("Opção incorreta\n");
	 	system ("pause");
	 	break;	 					
			
	}  // Fim da seleção
  
  }
}
