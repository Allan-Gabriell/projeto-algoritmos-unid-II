#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

/*O meu projeto � basicamente um sistema de cadastramento de produtos podendo ser utilizado por qualquer tipo 
de com�rcio, empresa ou qualquer nescessidade humana em que a minha aplica��o possa se fazer nescess�ria*/

typedef struct{
	char nameproduct[100];
	char tipeproduct[100];
	float priceproduct;
	int numberrandom;
} Product; // Aqui eu crio um struct onde eu coloco as informa��es tidas por mim como mais importantes para o meu produto

Product products[100];
int qtd = 0;

void menu();

int choice; // Vari�vel global de escolha

int registration(){ // Nessa fun��o vai ser realizado o cadastro dos produtos preenchendo as informa��es importantes
	int i, j;
	char backspace;
	int min = 1000;
	int max = 1100;
	
	system("cls");

	printf("== Deseja cadastrar quantos produtos? == \n \n ");
	printf("Nosso s�stema no momento s� sustenta o cadastramento de at� 100 \n");
	scanf("%d", &choice);
	
	system("cls");

	srand(time(NULL)); // Garante que os n�meros que vou gerar ser�o realmente aleat�rio

	for (i = 0; i < choice; i++){
		printf("Informe o nome do produto: \n");
		scanf("%s", products[i].nameproduct);
		printf("Informe o tipo do produto (alimenta��o, casa, limpeza,..): \n");
		scanf(" %s", products[i].tipeproduct);
		printf("Informe o pre�o do seu produto: \n");
		scanf("%f", &products[i].priceproduct);

		products[qtd].numberrandom = min + (rand() % (max - min)); // o sistema vai gerar um c�digo para cada produto como se fosse um c�digo de identifica��o
		qtd++;
	}
	
	system("cls");

	menu();
}

int verification(){ // Aqui eu posso verificar quais produtos j� foram cadastrados e suas informa��es
	int i;
	if (qtd == 0){
		printf("N�o h� produtos cadastrados! \n");
		menu();
	}

	printf("== Aqui est� todos os produtos cadastrados == \n \n");

	for (i = 0; i < qtd; i++){
		printf("C�digo do produto: %d \n", products[i].numberrandom);
		printf("Nome: %s \n", products[i].nameproduct);
		printf("Pre�o: %.2f \n", products[i].priceproduct);
		printf("Tipo do produto: %s \n", products[i].tipeproduct);
		printf("\n \n");
	}
	printf("Pressione qualquer tecla para continuar:");
	getchar();
	getchar();
	menu();
}

char password[10];

int deleted(){ // Aqui eu posso deletar algum produto j� cadastrado
	int i;
	int j;
	int code;
	int flag = 0; // � uma flag onde eu vou retornar se o c�digo foi encontrado
	char key[10];

	printf("Aqui est�o seus produtos cadastrados: \n");
	for (i = 0; i < qtd; i++){
		printf("Produto: %s %d \n", products[i].nameproduct, products[i].numberrandom);
	}

	printf("Deseja deletar um produto? Informe o c�digo dele: \n"); // para um produto ser deletado tem que ser informado um n�mero que � gerado pelo sistema
	scanf("%d", &code);
	
	system("cls");

	printf("Para confirmar e assim excluir por completo, informe sua senha: "); // e antes da dele��o ser efetuada tem que ser confirmado com a senha cadastrada no inicio do programa
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
				printf("Produto exclu�do com sucesso! \n");
				break; // Sai do loop ap�s encontrar o produto
			}
			else{
				printf("Procedimento falhou! \n");
				menu();
			}
		}
	}

	if (flag == 0){
		printf("Produto n�o foi encontrado! \n");
	}
	printf("Pressione qualquer tecla para continuar...\n");
	getchar();
	getchar();
	menu();
}

int raflle(){ // Aqui vai ser efetuado um sorteio, uma das compet�ncias feita no pedido do trabalho
	char yes[10];
	int i, j;
	int number = 1;
	int luckynumber;

	printf("A empresa respons�vel pela CaduUfersa resolveu fazer um sorteio de um ano do nosso sistema de maneira gratu�ta!\n");
	
	system("cls");
	
	printf("Deseja participar?(sim ou n�o) \n");
	scanf("%s", yes);
	if (strcmp(yes, "n�o") != 0){
		for (i = 0; i < 3; i++){ // vai ser imprido uma tabela na tela para que o usu�rio escolha seu n�mero da sorte
			for (j = 0; j < 3; j++){
				printf("%d\t", number); // Tabula��o
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

int goodluck(int luckynumber){ // nessa fun��o vai ser sorteado o n�mero e informado ao usu�rio qual foi e se ele ganhou
	int min1 = 1;
	int max1 = 9;

	int riffle1 =
		min1 + (rand() % (max1 - min1)); // sorteia um n�mero entre 1 e 9

	printf("O n�mero sorteado foi: %d \n", riffle1);

	if (riffle1 == luckynumber){
		printf("Parab�ns voc� ganhou!\n \n \n");
	}
	else{
		printf("N�o foi dessa vez!\n \n \n ");
	}
	printf("Pressione qualquer tecla para continuar... \n");
	getchar();
	getchar();
	menu();
}

int closeSystem(){ // Nessa fun��o pode ser realizado o encerramento do programa pelo pr�prio usu�rio
	char yes[10];

	printf("Deseja relmente encerrar o sistema? (sim ou n�o) \n");
	scanf("%s", yes);
	
	system("cls");

	if (strcmp(yes, "sim") == 0){
		printf("At� a pr�xima! \n");
		return 0;
	}
	else{
		menu();
	}
}

void menu(){ // Aqui � o nosso menu de op��es do sistema
	int choice1;

	printf("== Escolha uma op��o == \n");
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
		printf("Op��o inv�lida! Informe novamente: \n");
		scanf("%d", &choice1);
	}
}

int welcome(char name[15]){ // Mensagem de bem-vindo e apresenta��o do sistema
	printf("Universidade Federal Rural do Semi-�rido - UFERSA \n");
	printf("Curso: Bacharelado Interdisciplinar em Tecnologia da Informa��o; Semestre: 2023.1 \n");
	printf("Disciplinas: Algoritmos e Laborat�rio de algoritmos; Professora doutora: Daniela \n");
	printf("Aluno: Allan Gabriel Silva de Freitas \n");
	printf("Projeto/Prova da unidade II \n \n \n");
	getchar();
	system("cls");
	printf("Ol�, seja bem vindo %s \n", name);
	printf("Somos a CaduUfersa\n");
	printf("Um s�stema de cadastramento de produtos para aux�liar o seu neg�cio! "
		   "\n");
	printf("Vem fazer parte deste s�stema e impulsione o seu neg�cio! \n \n \n");
	printf("Pressione qualquer tecla para continuar...");
	getchar();
	getchar();
	menu();
}

int key(char email[30]){ // Aqui nesta fun��o eu passo os parametros para que o sistema considere v�lido o e-mail informado pelo usu�rio
	if (strstr(email, "@") != NULL && (strstr(email, "gmail.com") || strstr(email, "hotmail.com") || strstr(email, "yahoo.com")))
	{
		return 1;
	}
	else{
		return 0;
	}
}

int acess(char password[10]){ // mesma fun��o da anterior contudo para a senha que o usu�rio vai cadastrar
	if (strstr(password, "#") || strstr(password, "@") || strstr(password, "*")){
		return 1;
	}
	else{
		return 0;
	}
}

int login(){ // Nessa fun��o vai ser realizado o login do usu�rio, informando seu nome, senha e e-mail
	char email[30];
	char name[15];

	printf("Informe seu nome de usu�rio: \n");
	scanf("%s", name);

	printf("Primeiramente informe seu e-mail:  \n");
	scanf("%s", email);

	while (key(email) == 0){
		printf("E-mail inv�lido, informe novamente: \n");
		scanf("%s", email);
	}
	
	system("cls");
	
	printf("Informe uma senha: (Nescess�rio o uso de um dos seguintes caracteres #, @ ou *) \n");
	scanf("%s", password);
	
	getchar();
	system("cls");

	while (acess(password) == 0){
		printf("Senha n�o v�lida, informe novamente \n");
		scanf("%s", password);
	}
	printf("Login realizado com sucesso! \n");
	welcome(name);

	return 0;
}

int main(){ // Fun��o main do C
	setlocale(LC_ALL, "portuguese");
	login();
	return 0;
}
