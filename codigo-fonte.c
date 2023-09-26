#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

/*O meu projeto é basicamente um sistema de cadastramento de produtos podendo ser utilizado por qualquer tipo 
de comércio, empresa ou qualquer nescessidade humana em que a minha aplicação possa se fazer nescessária*/

typedef struct{
	char nameproduct[100];
	char tipeproduct[100];
	float priceproduct;
	int numberrandom;
} Product; // Aqui eu crio um struct onde eu coloco as informações tidas por mim como mais importantes para o meu produto

Product products[100];
int qtd = 0;

void menu();

int choice; // Variável global de escolha

int registration(){ // Nessa função vai ser realizado o cadastro dos produtos preenchendo as informações importantes
	int i, j;
	char backspace;
	int min = 1000;
	int max = 1100;
	
	system("cls");

	printf("== Deseja cadastrar quantos produtos? == \n \n ");
	printf("Nosso sístema no momento só sustenta o cadastramento de até 100 \n");
	scanf("%d", &choice);
	
	system("cls");

	srand(time(NULL)); // Garante que os números que vou gerar serão realmente aleatório

	for (i = 0; i < choice; i++){
		printf("Informe o nome do produto: \n");
		scanf("%s", products[i].nameproduct);
		printf("Informe o tipo do produto (alimentação, casa, limpeza,..): \n");
		scanf(" %s", products[i].tipeproduct);
		printf("Informe o preço do seu produto: \n");
		scanf("%f", &products[i].priceproduct);

		products[qtd].numberrandom = min + (rand() % (max - min)); // o sistema vai gerar um código para cada produto como se fosse um código de identificação
		qtd++;
	}
	
	system("cls");

	menu();
}

int verification(){ // Aqui eu posso verificar quais produtos já foram cadastrados e suas informações
	int i;
	if (qtd == 0){
		printf("Não há produtos cadastrados! \n");
		menu();
	}

	printf("== Aqui está todos os produtos cadastrados == \n \n");

	for (i = 0; i < qtd; i++){
		printf("Código do produto: %d \n", products[i].numberrandom);
		printf("Nome: %s \n", products[i].nameproduct);
		printf("Preço: %.2f \n", products[i].priceproduct);
		printf("Tipo do produto: %s \n", products[i].tipeproduct);
		printf("\n \n");
	}
	printf("Pressione qualquer tecla para continuar:");
	getchar();
	getchar();
	menu();
}

char password[10];

int deleted(){ // Aqui eu posso deletar algum produto já cadastrado
	int i;
	int j;
	int code;
	int flag = 0; // É uma flag onde eu vou retornar se o código foi encontrado
	char key[10];

	printf("Aqui estão seus produtos cadastrados: \n");
	for (i = 0; i < qtd; i++){
		printf("Produto: %s %d \n", products[i].nameproduct, products[i].numberrandom);
	}

	printf("Deseja deletar um produto? Informe o código dele: \n"); // para um produto ser deletado tem que ser informado um número que é gerado pelo sistema
	scanf("%d", &code);
	
	system("cls");

	printf("Para confirmar e assim excluir por completo, informe sua senha: "); // e antes da deleção ser efetuada tem que ser confirmado com a senha cadastrada no inicio do programa
	scanf("%s", key);
	
	system("cls");

	if (strcmp(key, password) == 0){
		for (i = 0; i < qtd; i++){
			if (code == products[i].numberrandom){
				flag = 1;
				for (j = i; j < qtd - 1; j++){
					products[j] = products[j + 1];
				}
				qtd--;
				printf("Produto excluído com sucesso! \n");
				break; // Sai do loop após encontrar o produto
			}
			else{
				printf("Procedimento falhou! \n");
				menu();
			}
		}
	}

	if (flag == 0){
		printf("Produto não foi encontrado! \n");
	}
	printf("Pressione qualquer tecla para continuar...\n");
	getchar();
	getchar();
	menu();
}

int raflle(){ // Aqui vai ser efetuado um sorteio, uma das competências feita no pedido do trabalho
	char yes[10];
	int i, j;
	int number = 1;
	int luckynumber;

	printf("A empresa responsável pela CaduUfersa resolveu fazer um sorteio de um ano do nosso sistema de maneira gratuíta!\n");
	
	system("cls");
	
	printf("Deseja participar?(sim ou não) \n");
	scanf("%s", yes);
	if (strcmp(yes, "não") != 0){
		for (i = 0; i < 3; i++){ // vai ser imprido uma tabela na tela para que o usuário escolha seu número da sorte
			for (j = 0; j < 3; j++){
				printf("%d\t", number); // Tabulação
				number++;
			}
			printf("\n");
		}
		printf("Escolha um valor e boa sorte! \n");
		scanf("%d", &luckynumber);
		goodluck(luckynumber);
	}
	menu();
}

int goodluck(int luckynumber){ // nessa função vai ser sorteado o número e informado ao usuário qual foi e se ele ganhou
	int min1 = 1;
	int max1 = 9;

	int riffle1 =
		min1 + (rand() % (max1 - min1)); // sorteia um número entre 1 e 9

	printf("O número sorteado foi: %d \n", riffle1);

	if (riffle1 == luckynumber){
		printf("Parabéns você ganhou!\n \n \n");
	}
	else{
		printf("Não foi dessa vez!\n \n \n ");
	}
	printf("Pressione qualquer tecla para continuar... \n");
	getchar();
	getchar();
	menu();
}

int closeSystem(){ // Nessa função pode ser realizado o encerramento do programa pelo próprio usuário
	char yes[10];

	printf("Deseja relmente encerrar o sistema? (sim ou não) \n");
	scanf("%s", yes);
	
	system("cls");

	if (strcmp(yes, "sim") == 0){
		printf("Até a próxima! \n");
		return 0;
	}
	else{
		menu();
	}
}

void menu(){ // Aqui é o nosso menu de opções do sistema
	int choice1;

	printf("== Escolha uma opção == \n");
	printf("1. cadastrar produdo \n");
	printf("2. Consultar produtos \n");
	printf("3. Excluir produto \n");
	printf("4. Participar de um sorteio \n");
	printf("5. Fechar sistema \n");

	scanf("%d", &choice1);

	switch (choice1){
	case 1:
		registration();
		break;
	case 2:
		verification();
		break;
	case 3:
		deleted(password);
		break;
	case 4:
		raflle();
		break;
	case 5:
		closeSystem();
		break;
	}
	
	while(choice1 != 1 || 2 || 3 || 4 || 5) {
		printf("Opção inválida! Informe novamente: \n");
		scanf("%d", &choice1);
	}
}

int welcome(char name[15]){ // Mensagem de bem-vindo e apresentação do sistema
	printf("Universidade Federal Rural do Semi-Árido - UFERSA \n");
	printf("Curso: Bacharelado Interdisciplinar em Tecnologia da Informação; Semestre: 2023.1 \n");
	printf("Disciplinas: Algoritmos e Laboratório de algoritmos; Professora doutora: Daniela \n");
	printf("Aluno: Allan Gabriel Silva de Freitas \n");
	printf("Projeto/Prova da unidade II \n \n \n");
	getchar();
	system("cls");
	printf("Olá, seja bem vindo %s \n", name);
	printf("Somos a CaduUfersa\n");
	printf("Um sístema de cadastramento de produtos para auxíliar o seu negócio! "
		   "\n");
	printf("Vem fazer parte deste sístema e impulsione o seu negócio! \n \n \n");
	printf("Pressione qualquer tecla para continuar...");
	getchar();
	getchar();
	menu();
}

int key(char email[30]){ // Aqui nesta função eu passo os parametros para que o sistema considere válido o e-mail informado pelo usuário
	if (strstr(email, "@") != NULL && (strstr(email, "gmail.com") || strstr(email, "hotmail.com") || strstr(email, "yahoo.com")))
	{
		return 1;
	}
	else{
		return 0;
	}
}

int acess(char password[10]){ // mesma função da anterior contudo para a senha que o usuário vai cadastrar
	if (strstr(password, "#") || strstr(password, "@") || strstr(password, "*")){
		return 1;
	}
	else{
		return 0;
	}
}

int login(){ // Nessa função vai ser realizado o login do usuário, informando seu nome, senha e e-mail
	char email[30];
	char name[15];

	printf("Informe seu nome de usuário: \n");
	scanf("%s", name);

	printf("Primeiramente informe seu e-mail:  \n");
	scanf("%s", email);

	while (key(email) == 0){
		printf("E-mail inválido, informe novamente: \n");
		scanf("%s", email);
	}
	
	system("cls");
	
	printf("Informe uma senha: (Nescessário o uso de um dos seguintes caracteres #, @ ou *) \n");
	scanf("%s", password);
	
	getchar();
	system("cls");

	while (acess(password) == 0){
		printf("Senha não válida, informe novamente \n");
		scanf("%s", password);
	}
	printf("Login realizado com sucesso! \n");
	welcome(name);

	return 0;
}

int main(){ // Função main do C
	setlocale(LC_ALL, "portuguese");
	login();
	return 0;
}
