#include <stdio.h> //biblioteca de comunicação com usuario 
#include <stdlib.h> //biblioteca de comunicação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	 //inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
   	char nome[40];
	char sobrenome[40];   	
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação de usuário
	scanf("%s", cpf); //%s referente-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file;
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abrir arquivo e atualizar informaçãoes 
	fprintf(file,","); //salva dentro
	fclose(file); // fechar 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // atualizar arquivo
	fprintf(file,nome); //salvando nome dentro do arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadatrado; ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // abri o arquivo e atuliza 
	fprintf(file,sobrenome); // joga dentro do arquivo o sobrenome
	fclose(file); // fechar 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastro; ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // abre o arquivo que esta dentro variaves e atualiza 
	fprintf(file,cargo); // coloca as informações dentro arquivo a variavel cargo
	fclose(file); // fechar 
	
	system("pause");
				
}
   	
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // arquivo de cpf a ser consultado
	char conteudo[200]; // conteudo de cpf
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); // conjuto de variaves 
	
	FILE *file; // consutar arquivo
	file = fopen(cpf,"r"); // ler arquivo cpf
	
	if(file == NULL) // arquivo que não existe 
	{
	   printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // laço de repetição equando estiver informações ele traz para o usuario
	{
	     printf("\nEssas são as informações do usuario; ");
	     printf("%s", conteudo); // 
	     printf("\n\n");		
	}

    system("pause");

		
}

int deletar()
{
     char cpf[40];
     
     printf("digita o cpf a ser deletado ");
     scanf("%s",cpf);

     remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuario não se encontra no sistema.\n");
    	system("pause");
	}
    
    
    
}


int main()
    {
	int opcao=0; // Definindo variáveis 
	int laco=1;

    for(laco=1;laco=1;)
    {

	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	printf("### cartório da EBAC ###\n\n"); //Inicio do menu
	printf("EScolha a opção do menu:\n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("opção:"); // fim do menu
	
	scanf("%d",  &opcao); //Armazenado a escolha do usuário
	
    system("cls"); // responsavel de limpar a tela


    switch(opcao) // inicio da seleção do menu
    {
        	case 1:
            registro(); // chamada de funções
            break;
        
            case 2:
         	consulta(); // consulta de nomes 
            break;
        
            case 3:
            deletar(); // deletar nomes 	
         	break;	
         	
         	case 4:
         	printf("Obrigado por utilizar o sistema!\n");	
         	return 0;
         	break;
	    
	    	default:
		    printf("Essa opção não está disponivel!\n");	
            system("pause");
		    break;	
    	}   //fim da seleção\
	
   
}
		}	