#include <stdio.h> //incluindo a biblioteca de comunicação com o usuário.
#include <stdlib.h> //incluindo a biblioteca de alocação de espaço de memória.
#include <locale.h> //incluindo a biblioteca alocação de texto por região.
#include <string.h> //incluindo a biblioteca de strings.

int main() //os parênteses significa uma função; int main é uma função principal.
{// tudo que está dentro das chaves, são os comandos de uma função (int main no caso).
	int opcao=0; //alocando a variável do tipo INT (números inteiros) chamada opcao na memória, endereçada em 0.
	int repeticao=1; //alocando variável de repetição de nome repeticao endereçada em 1
	
	for(repeticao=1;repeticao=1;) //estrutura de repetição que pode ser dividida em 3 parâmetros. No caso, o primeiro inicializa a variável e o segundo termina o ciclo
	{
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para português;
	
		printf("\n\t### Cartório EBAC ###\n\n"); //printf(): comando de exibição de texto na interface. O texto em si tem que estar entre aspas.
		printf("Escolha a opção desejada:\n\n"); // \n: pular linhas.
		printf("\t1 - Registro de nomes\n"); //\t: "dentar" ou criar espaços.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\nDigite a opção: "); //fim do menu
	
		scanf("%d", &opcao); //aguarda a opção do usuário; a atribuição %d serve pra alocar a opção do usuário na variável int opcao=0	
	
		system("cls");
		
		switch(opcao) //variável de escolha do usuário; início da seleção.
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
			printf("Essa opção não está disponível. Por favor, escolha a opção de 1 a 3.\n");
			system("pause");
			break;
		}
	}
}

int registro() //função do menu de registro (1).
	{
		
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para português;
	//Início das criações de variáveis/string.
	char arquivo[40];
	char cpf[40]; //criando uma variável de caracteres (char) de nome cpf com string (colchetes) de 40 caracteres.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //mostra a mensagem pro usuário digitar o CPF.
	scanf("%s",cpf); //grava o que o usuário digitou (scanf) na string ("%s") de nome (cpf).
	
	strcpy(arquivo, cpf); //copia os valores da string (arquivo e cpf).
	
	FILE *file; //Comando para acessar um arquivo.
	
	file = fopen(arquivo, "w"); //abre o arquivo (fopen); cria o arquivo com nome de arquivo ("w").
	fprintf(file,"O CPF é: "); //grava dentro do arquivo (fprintf) o texto (O CPF é: ).
	fprintf(file,cpf); //grava dentro do arquivo (fprintf) a variável cpf (O texto que o usuário digitou).
	fprintf(file,", "); //grava dentro do arquivo (fprintf) uma vírgula e um espaço.
	fclose(file); //fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //mostra a mensagem pro usuário digitar o nome.
	scanf("%s", nome); //grava na variável nome o que o usuário digitou.
	
	file = fopen(arquivo, "a"); //abre o arquivo (fopen) e atualiza arquivo com nome de arquivo ("a").
	fprintf(file,"o nome é: ");
	fprintf(file,nome);
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //mostra a mensagem pro usuário digitar o sobrenome.
	scanf("%s", sobrenome); //grava na variável sobrenome o que o usuário digitou.
	
	file = fopen(arquivo, "a");
	fprintf(file,"o sobrenome é: ");
	fprintf(file,sobrenome);
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //mostra a mensagem pro usuário digitar o cargo.
	scanf("%s", cargo); //grava na variável cargo o que o usuário digitou.
	
	file = fopen(arquivo, "a");
	fprintf(file,"e o cargo é: ");
	fprintf(file,cargo);
	fprintf(file,".");
	fclose(file);
	
	system("pause");
	}

int consulta() //função do menu de consultar nomes (2)
{
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para português;
	
	char cpf[40]; //criando uma variável de caracteres (char) de nome cpf com string (colchetes) de 40 caracteres. CPF digitado pelo usuário.
	char conteudo[200]; //criando uma variável de caracteres (char) de nome conteudo com string (colchetes) de 200 caracteres. Informações dentro do cadastro.
	
	printf("Digite o CPF a ser consultado: "); //mostra a mensagem pro usuário digitar o cpf para consulta.
	scanf("%s",cpf);
	
	FILE *file; //Chamando a biblioteca de gerenciamento de arquivo (FILE) para acessar o arquivo (*file); 
	file = fopen(cpf,"r"); //abre o arquivo (fopen) em forma de leitura ("r") a string digitada pelo usuário (cpf).
	
	if(file == NULL) //se (if) o arquivo (file) for igual (==) a nulo (NULL),
	{
		printf("Usuário não cadastrado!\n"); //mostre a mensagem ao usuário que o cadastro não existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto (while) tiver dados, grave (fgets) na variável (conteudo), até 200 caracteres (200) do arquivo (file) se ele foi achado (!= NULL).
	{
		printf("\nEssas são as informações do usuário: "); //mostra a informação solicitada pelo usuário
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file); //fecha o arquivo
}

int deletar() //função do menu de deletar nome (3)
{
	setlocale(LC_ALL, "Portuguese"); //definindo a localicade (idioma) dos textos para português;
	
	char cpf[40]; //cria a string (char) com nome (cpf) com ([40]) caracteres.
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; //Chamando a biblioteca de gerenciamento de arquivo (FILE) para acessar o arquivo (*file);
	file = fopen(cpf,"r"); //abre o arquivo (fopen) em forma de leitura ("r") a string digitada pelo usuário (cpf).
	
	fclose(file); //fecha o arquivo para poder ser deletado
	remove(cpf); //deleta o arquivo
		
	
	if(file != NULL) //se (if) o arquivo (file) for diferente (!=) de nulo (NULL),
	{
		printf("Usuário deletado com sucesso!\n"); //mostre a mensagem ao usuário deletado com sucesso!
		system("pause");
	}
	
	if(file == NULL) //se (if) o arquivo (file) for igual (==) a nulo (NULL),
	{
		printf("Usuário não encontrado!\n"); //mostre a mensagem ao usuário não existe!
		system("pause");
	}
}
