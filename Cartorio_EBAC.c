#include <stdio.h> //incluindo a biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //incluindo a biblioteca de aloca��o de espa�o de mem�ria.
#include <locale.h> //incluindo a biblioteca aloca��o de texto por regi�o.
#include <string.h> //incluindo a biblioteca de strings.

int main() //os par�nteses significa uma fun��o; int main � uma fun��o principal.
{// tudo que est� dentro das chaves, s�o os comandos de uma fun��o (int main no caso).
	int opcao=0; //alocando a vari�vel do tipo INT (n�meros inteiros) chamada opcao na mem�ria, endere�ada em 0.
	int repeticao=1; //alocando vari�vel de repeti��o de nome repeticao endere�ada em 1
	
	for(repeticao=1;repeticao=1;) //estrutura de repeti��o que pode ser dividida em 3 par�metros. No caso, o primeiro inicializa a vari�vel e o segundo termina o ciclo
	{
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para portugu�s;
	
		printf("\n\t### Cart�rio EBAC ###\n\n"); //printf(): comando de exibi��o de texto na interface. O texto em si tem que estar entre aspas.
		printf("Escolha a op��o desejada:\n\n"); // \n: pular linhas.
		printf("\t1 - Registro de nomes\n"); //\t: "dentar" ou criar espa�os.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\nDigite a op��o: "); //fim do menu
	
		scanf("%d", &opcao); //aguarda a op��o do usu�rio; a atribui��o %d serve pra alocar a op��o do usu�rio na vari�vel int opcao=0	
	
		system("cls");
		
		switch(opcao) //vari�vel de escolha do usu�rio; in�cio da sele��o.
		{
			case 1:
			registro();
			break; //final do caso
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel. Por favor, escolha a op��o de 1 a 3.\n");
			system("pause");
			break;
		}
	}
}

int registro() //fun��o do menu de registro (1).
	{
		
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para portugu�s;
	//In�cio das cria��es de vari�veis/string.
	char arquivo[40];
	char cpf[40]; //criando uma vari�vel de caracteres (char) de nome cpf com string (colchetes) de 40 caracteres.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //mostra a mensagem pro usu�rio digitar o CPF.
	scanf("%s",cpf); //grava o que o usu�rio digitou (scanf) na string ("%s") de nome (cpf).
	
	strcpy(arquivo, cpf); //copia os valores da string (arquivo e cpf).
	
	FILE *file; //Comando para acessar um arquivo.
	
	file = fopen(arquivo, "w"); //abre o arquivo (fopen); cria o arquivo com nome de arquivo ("w").
	fprintf(file,"O CPF �: "); //grava dentro do arquivo (fprintf) o texto (O CPF �: ).
	fprintf(file,cpf); //grava dentro do arquivo (fprintf) a vari�vel cpf (O texto que o usu�rio digitou).
	fprintf(file,", "); //grava dentro do arquivo (fprintf) uma v�rgula e um espa�o.
	fclose(file); //fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //mostra a mensagem pro usu�rio digitar o nome.
	scanf("%s", nome); //grava na vari�vel nome o que o usu�rio digitou.
	
	file = fopen(arquivo, "a"); //abre o arquivo (fopen) e atualiza arquivo com nome de arquivo ("a").
	fprintf(file,"o nome �: ");
	fprintf(file,nome);
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //mostra a mensagem pro usu�rio digitar o sobrenome.
	scanf("%s", sobrenome); //grava na vari�vel sobrenome o que o usu�rio digitou.
	
	file = fopen(arquivo, "a");
	fprintf(file,"o sobrenome �: ");
	fprintf(file,sobrenome);
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //mostra a mensagem pro usu�rio digitar o cargo.
	scanf("%s", cargo); //grava na vari�vel cargo o que o usu�rio digitou.
	
	file = fopen(arquivo, "a");
	fprintf(file,"e o cargo �: ");
	fprintf(file,cargo);
	fprintf(file,".");
	fclose(file);
	
	system("pause");
	}

int consulta() //fun��o do menu de consultar nomes (2)
{
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para portugu�s;
	
	char cpf[40]; //criando uma vari�vel de caracteres (char) de nome cpf com string (colchetes) de 40 caracteres. CPF digitado pelo usu�rio.
	char conteudo[200]; //criando uma vari�vel de caracteres (char) de nome conteudo com string (colchetes) de 200 caracteres. Informa��es dentro do cadastro.
	
	printf("Digite o CPF a ser consultado: "); //mostra a mensagem pro usu�rio digitar o cpf para consulta.
	scanf("%s",cpf);
	
	FILE *file; //Chamando a biblioteca de gerenciamento de arquivo (FILE) para acessar o arquivo (*file); 
	file = fopen(cpf,"r"); //abre o arquivo (fopen) em forma de leitura ("r") a string digitada pelo usu�rio (cpf).
	
	if(file == NULL) //se (if) o arquivo (file) for igual (==) a nulo (NULL),
	{
		printf("Usu�rio n�o cadastrado!\n"); //mostre a mensagem ao usu�rio que o cadastro n�o existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto (while) tiver dados, grave (fgets) na vari�vel (conteudo), at� 200 caracteres (200) do arquivo (file) se ele foi achado (!= NULL).
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mostra a informa��o solicitada pelo usu�rio
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file); //fecha o arquivo
}

int deletar() //fun��o do menu de deletar nome (3)
{
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para portugu�s;
	
	char cpf[40]; //cria a string (char) com nome (cpf) com ([40]) caracteres.
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; //Chamando a biblioteca de gerenciamento de arquivo (FILE) para acessar o arquivo (*file);
	file = fopen(cpf,"r"); //abre o arquivo (fopen) em forma de leitura ("r") a string digitada pelo usu�rio (cpf).
	
	fclose(file); //fecha o arquivo para poder ser deletado
	remove(cpf); //deleta o arquivo
		
	
	if(file != NULL) //se (if) o arquivo (file) for diferente (!=) de nulo (NULL),
	{
		printf("Usu�rio deletado com sucesso!\n"); //mostre a mensagem ao usu�rio deletado com sucesso!
		system("pause");
	}
	
	if(file == NULL) //se (if) o arquivo (file) for igual (==) a nulo (NULL),
	{
		printf("Usu�rio n�o encontrado!\n"); //mostre a mensagem ao usu�rio n�o existe!
		system("pause");
	}
}
