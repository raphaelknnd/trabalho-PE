#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define NOME 50
#define CPF 12
#define END 60
#define TEL 15
#define EMAIL 50
#define CLI 500
#define CONTAS 500

typedef struct
{
	int agencia;
	int nCont;
	float saldo;
	char cpf[CPF];

} tConta;

typedef struct tCliente
{
	char nome[NOME];
	char cpf[CPF];
	char endereco[END];
	char telefone[TEL];
	char email[EMAIL];
	int numConta;
} tCliente;


tCliente cliente[CLI];
tConta contas[CONTAS];

//FUNÇÕES REFENTES AO À FUNÇÃO MENU PRINCIPAL

//AQUI INICIAMOS O MENU CLIENTE E SUAS FUNÇÕES

void menuAlterarCliente(int i, int *x)
{
	setlocale(LC_ALL, "Portuguese");
	int option;
	char cpf3[CPF];
	int aux;

	do
	{
		system("cls");
		printf("<<<<<<<<<<<<<<  O QUE DESEJA ALTERAR?  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Nome                                  |\n");
		printf("| 2- CPF                                   |\n");
		printf("| 3- Endereço                              |\n");
		printf("| 4- Telefone                              |\n");
		printf("| 5- Email                                 |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);


		switch(option)
		{
		case 1:
			printf("Digite o novo Nome: \n");
			scanf("%s", cliente[i].nome);
			system("cls");
			system("color 02");
			printf("NOME ALTERADO COM SUCESSO!\n"); //O nome não pede validação pois, em um mundo com tantas pessoas,
			system("pause");           
			system("color 07");            //pode acontecer de existirem nomes iguais.
			break;
		case 2:
			printf("Digite o novo Cpf: \n");
			int h = 0; // Variável criada com único propósito de validação do cpf.
			scanf("%s", cpf3);
			for(aux = 0; aux <= (*x); aux++)
			{

				if((strcmp(cpf3, cliente[aux].cpf )) == 0)
				{
					h = 1; //se "h" deu 1, é porque já existe este numero de cpf. Passamos para os "if".
				}
			}
			if(h == 1) // se "h" for 1, acusa que já existe e não altera.
			{
				printf("Erro. CPF já cadastrado\n");
				system("pause");
				break;
			}
			
			
				if(strlen(cpf3) != CPF - 1)
		{
			system("cls");
			system("color 04");
			printf("CPF INVÁLIDO! - CERTIFIQUE-SE QUE SEU CPF TEM 11 DIGITOS \n");
			system("pause");
			system("cls");
			system("color 07");
			return;
		}
			
			
			
			
			if(h == 0) // se "h" for 0, é porque não existe, logo, pode ser alterado com sucesso.
			{
				strcpy(cliente[i].cpf, cpf3);
				system("color 02");
				printf("CPF ALTERADO COM SUCESSO!\n");
				system("pause");
				system("color 07");
				break;
			}
		case 3:
			printf("Digite o novo Endereço: \n");  // O endereço também não pede validação pelo mesmo motivo do nome
			scanf("%s", cliente[i].endereco);
			system("color 02");
			printf("ENDEREÇO ALTERADO COM SUCESSO!!\n");
			system("pause");
			system("color 07");
			break;
		case 4:
			printf("Digite o novo Telefone: \n");   //Telefone não pede validação pois duas pessoas podem usar o mesmo
			scanf("%s", cliente[i].telefone);       //numero como por exemplo um residencial
			system("color 02");
			printf("TELEFONE ALTERADO COM SUCESSO!!\n");
			system("pause");
			system("color 07");
			break;
		case 5:
			printf("Digite o novo Email: \n");
			scanf("%s", cliente[i].email);
			system("color 02");
			printf("EMAIL ALTERADO COM SUCESSO!!\n");
			system("pause");
			system("color 07");
			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");

		}

	}
	while(option != 0);

}

void alterarCliente(int *contCli)
{
	//Função criada para validação de cpf antes de iniciar as alterações
	setlocale(LC_ALL, "Portuguese");                //para saber se existe aquele cliente e só assim alterar, já que o que
	char cpf2[CPF];                                 //não existe não pode ser alterado.
	int i;
	int x = *contCli;
	printf("Informe o cpf do usuário: ");
	scanf("%s", cpf2);
	
		if(strlen(cpf2) != CPF - 1)
		{
			system("cls");
			system("color 04");
			printf("CPF INVÁLIDO! - CERTIFIQUE-SE QUE SEU CPF TEM 11 DIGITOS \n");
			system("pause");
			system("cls");
			system("color 07");
			return;
		}

	for(i = 0; i <= x; i++)
	{

		if((strcmp(cpf2, cliente[i].cpf )) == 0)  //Caso encontre o cpf no cadastro, pode ser alterado, e entrará na função
		{
			//que traz os menus perguntando o que deseja alterar. Ao encerrar a função
			menuAlterarCliente(i, &x);   //chamada, ele encerra esta função.
			system("pause");
			system("cls");
			return;
		}
	}
	system("cls");
	system("color 04");
	printf("CPF NÃO ENCONTRADO!\n");     //Caso não encontre CPF nenhum, ele exibirá esta mensagem, limpará a tela e encerrará
	system("pause");                     //essa função
	system("cls");
	system("color 07");

}

void cadastroCliente(int *contCli)    //Função que recebe as informações principais de cada cliente, presentes na estrutura
{
	//cliente do tipo tCliente.
	setlocale(LC_ALL, "Portuguese");
	char cpf2[CPF];
	int i;
	int x = *contCli;
	printf("Informe o cpf que deseja cadastrar: ");
	scanf("%s", cpf2);
	setbuf(stdin, NULL);

	for(i = 0; i <= x; i++)
	{

		if((strcmp(cpf2, cliente[i].cpf )) == 0)  //Neste ponto, o programa faz uma busca no vetor cliente do tipo tCliente,
		{
			//acusa erro caso já exista um cpf com o mesmo número e encerra a função
			printf("Erro. CPF já cadastrado\n");  //voltando assim para o menuCliente.
			system("pause");
			system("cls");
			return;
		}
		if(strlen(cpf2) != CPF - 1)
		{
			system("cls");
			system("color 04");
			printf("CPF INVÁLIDO! - CERTIFIQUE-SE QUE SEU CPF TEM 11 DIGITOS \n");
			system("pause");
			system("cls");
			system("color 07");
			return;
		}
	}                                            //Caso não encontre nada no laço de repetição acima, o programa avança
	strcpy(cliente[x].cpf, cpf2);                //para estas leituras de dados.
	printf("Informe o nome do cliente: ");
	scanf(" %[^\n]s", cliente[x].nome);
	printf("Informe o endereço do cliente: ");
	scanf(" %[^\n]s", cliente[x].endereco);
	printf("Informe o telefone: ");
	scanf("%s", cliente[x].telefone);
	printf("Informe o email: ");
	scanf(" %[^\n]s", cliente[x].email);

	cliente[x].numConta = 0;

	x++;
	*contCli = x;
}


void menuCliente(int *contCli)
{

	setlocale(LC_ALL, "Portuguese");
	int option;
	int y = *contCli;
	do
	{
		system("cls");
		printf("<<<<<<<<<<<<<<  MENU CLIENTE  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Cadastrar Cliente                     |\n");
		printf("| 2- Alterar Cliente                       |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);
		setbuf(stdin, NULL);

		if(option >= 0 && option <= 2)
			system("cls");

		switch(option)
		{
		case 1:
			if(y > CLI)     //Se o número de clientes for excedido, o programa não cadastra mais nada.
			{
				system("cls");
				system("color 04");
				printf("Número de clientes excedido!");
				system("pause");
				system("cls");
				system("color 07");
				break;
			}
			cadastroCliente(&y);
			break;
		case 2:
			alterarCliente(&y);
			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}
	}
	while(option != 0);
	*contCli = y;
}

//FIM MENU CLIENTE

int validarCPF(int *b, int *y)
{
	setlocale(LC_ALL, "Portuguese");
	char cpf4[CPF];
	int aux;

	printf("DIGITE O CPF: ");
	scanf("%s", cpf4);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= CLI; aux++)
	{
		if( strcmp(cliente[aux].cpf, cpf4) == 0)
		{
			strcpy(contas[(*y)].cpf, cpf4);
			cliente[aux].numConta++;
			return 1;
		}
	}
	return 0;
}

//AQUI INICIAMOS O MENU CONTA E SUAS FUNÇÕES

void removerConta(int *contContasMenuConta, int *contClienteMenuConta)
{
	setlocale(LC_ALL, "Portuguese");
	int numAgencia;
	int numConta;
	int aux;
	int aux2;
	int aux3;
	printf("Digite o Numero da Agencia: ");
	scanf("%d", &numAgencia);
	setbuf(stdin, NULL);
	printf("Digite o Numero da Conta: ");
	scanf("%d", &numConta);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= (*contContasMenuConta) ; aux++)
	{
		if(numAgencia == contas[aux].agencia && numConta == contas[aux].nCont)
		{
			for(aux2 = aux; aux2 < (*contContasMenuConta); aux2++)
			{
				contas[aux2].agencia = contas[(aux2 + 1)].agencia;
				contas[aux2].nCont = contas[(aux2 + 1)].nCont;
				contas[aux2].saldo = contas[(aux2 + 1)].saldo;
				strcpy(contas[aux2].cpf, contas[(aux2 + 1)].cpf);
			}
			for(aux3 = 0; aux3 <= (*contClienteMenuConta); aux3++)
			{
				if( strcmp(contas[aux].cpf, cliente[aux3].cpf) == 0)
				{
					cliente[aux3].numConta--;
				}

			}
			(*contContasMenuConta)--;
			system("cls");
			system("color 02");
			printf("CONTA EXCLUIDA COM SUCESSO!");
			system("pause");
			system("cls");
			system("color 07");

			return;
		}
	}
	system("cls");
	system("color 04");
	printf("CONTA INVALIDA!");
	system("pause");
	system("cls");
	system("color 07");
	return;
}

void menuAlterarContas(int *aux, int *contadorContas, int *contadorClientes, int *numAgencia, int *numConta)
{
	setlocale(LC_ALL, "Portuguese");
	int option;
	int i;//auxiliador para pecorrer o vetor de Contas
	int auxiliarContas;
	char cpf[CPF];
	int existe = 0;
	do
	{
		system("cls");
		printf("<<<<<<<<<<<<<<  O QUE DESEJA ALTERAR?  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Numero da agencia                     |\n");
		printf("| 2- Numero da conta                       |\n");
		printf("| 3- CPF                                   |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");

		scanf("%d", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		case 1:
			printf("Digite o novo Numero da Agencia: \n");
			scanf("%i", &auxiliarContas);
			setbuf(stdin, NULL);
			for(i = 0; i <= (*contadorContas); i++)
			{
				if(auxiliarContas == contas[i].agencia && (*numConta) == contas[i].nCont)
				{
					system("cls");
					system("color 04");
					printf("CONTAS JÁ CADASTRADA\n");
					printf("NÃO É POSSÍVEL ALTERAR\n");
					system("pause");
					system("cls");
					system("color 07");
					return;
				}
			}
			system("cls");
			system("color 02");
			printf("NUMERO DA AGENCIA ALTERADA COM SUCESSO!\n");
			contas[(*aux)].agencia = auxiliarContas;
			system("pause");
			system("cls");
			system("color 07");
			break;
		case 2:
			printf("Digite o novo Numero da Conta: \n");
			scanf("%i", &auxiliarContas);
			setbuf(stdin, NULL);
			for(i = 0; i <= (*contadorContas); i++)
			{
				if((*numAgencia) == contas[i].agencia && auxiliarContas == contas[i].nCont)
				{
					system("cls");
					system("color 04");
					printf("CONTAS JÁ CADASTRADA\n");
					printf("NÃO É POSSÍVEL ALTERAR\n");
					system("pause");
					system("cls");
					system("color 07");
					return;
				}
			}
			system("cls");
			system("color 04");
			printf("NUMERO DA CONTA ALTERADA COM SUCESSO!");
			contas[(*aux)].nCont = auxiliarContas;
			system("pause");
			system("cls");
			system("color 07");
			break;
		case 3:
			printf("Digite o novo CPF da Conta: \n");
			scanf("%s", cpf);
			setbuf(stdin, NULL);
			for(i = 0; i <= (*contadorClientes); i++)
			{
				if( strcmp(cpf, cliente[i].cpf) == 0)
				{
					existe = 1;
				}
			}


			if(existe == 0)
			{
				system("cls");
				system("color 04");
				printf("CPF NÃO CADASTRADO!\n");
				system("pause");
				system("cls");
				system("color 07");
				break;
			}

			system("cls");
			system("color 02");
			printf("CPF ALTERADO COM SUCESSO\n");
			strcpy(contas[(*aux)].cpf, cpf);
			cliente[(*aux)].numConta++;
			cliente[i].numConta--;
			system("pause");
			system("cls");
			system("color 07");


			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}
	}
	while(option != 0);
}

void alterarConta(int *contContasMenuConta, int  *contClienteMenuConta)
{
	setlocale(LC_ALL, "Portuguese");
	int numAgencia;
	int numConta;
	int aux;
	int contadorContas = (*contContasMenuConta);
	int contadorClientes = (*contClienteMenuConta);
	printf("Digite o Numero da Agencia: ");
	scanf("%d", &numAgencia);
	printf("Digite o Numero da Conta: ");
	scanf("%d", &numConta);

	for(aux = 0; aux <= contadorContas ; aux++)
	{
		if(numAgencia == contas[aux].agencia && numConta == contas[aux].nCont)
		{
			menuAlterarContas(&aux, &contadorContas, &contadorClientes, &numAgencia, &numConta); //chamada, ele encerra esta função.
			system("pause");
			system("cls");
			return;
		}
	}
	system("cls");
	system("color 04");
	printf("CONTA NÃO CADASTRADA!\n");     //Caso não encontre nenhuma CONTA, ele exibirá esta mensagem, limpará a tela e encerrará
	system("pause");                     //essa função
	system("cls");
	system("color 07");

}

void cadastrarConta(int *contContasMenuConta, int *contClienteMenuConta)
{
	setlocale(LC_ALL, "Portuguese");
	int numAgencia;
	int numConta;
	int aux;
	int y = *contContasMenuConta;
	int b = *contClienteMenuConta;
	int h;


	printf("Digite o numero da Agência: ");
	scanf("%d", &numAgencia);
	setbuf(stdin, NULL);
	printf("Digite o numero da Conta: ");
	scanf("%d", &numConta);
	setbuf(stdin, NULL);



	for(aux = 0; aux <= y; aux++)
	{
		if(numAgencia == contas[aux].agencia && numConta == contas[aux].nCont)
		{
			system("cls");
			system("color 04");
			printf("CONTAS JÁ CADASTRADA\n");
			system("pause");
			system("cls");
			system("color 07");
			return;
		}
	}

	h = validarCPF(&b, &y);
	if(h == 0)
	{
		system("cls");
		system("color 04");
		printf("CPF NÃO CADASTRADO!!\n");
		system("pause");
		system("cls");
		system("color 07");
		return;
	}

	contas[y].agencia = numAgencia;
	contas[y].nCont = numConta;
	contas[y].saldo = -1;
	//O SALDO DA CONTA INICIAL TEM QUE SER >= 0
	do
	{
		printf("DIGITE O SALDO DA CONTA: ");
		scanf("%f", &contas[y].saldo);

		if(contas[y].saldo < 0)
		{
			system("cls");
			system("color 04");
			printf("Valor inválido - UMA CONTA NÃO PODE COMEÇAR NEGATIVADA!!!\n");
			system("pause");
			system("cls");
			system("color 07");
		}

		if(contas[y].saldo > 0)
		{
			system("cls");
			system("color 02");
			printf("CONTA CADASTRADA COM SUCESSO!!\n");
			system("pause");
			system("cls");
			system("color 07");
		}

	}
	while(contas[y].saldo < 0);
	y++;
	*contContasMenuConta = y;
	return;
}

void menuConta(int *contCli, int *contContas)
{
	setlocale(LC_ALL, "Portuguese");
	int contContasMenuConta = *contContas;
	int contClienteMenuConta = *contCli;

	int option;
	do
	{
		printf("<<<<<<<<<<<<<<  MENU CONTA  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Cadastrar Conta                       |\n");
		printf("| 2- Alterar Conta                         |\n");
		printf("| 3- Remover Conta                         |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");


		scanf("%d", &option);
		setbuf(stdin, NULL);

		if(option >= 0 && option <= 3)
			system("cls");

		switch(option)
		{
		case 1:
			if(contContasMenuConta > CONTAS) //Caso o número de contas exceda o valor máximo estipulado no define, o programa
			{
				//não cadastra.
				printf("Número de contas excedido!\n");
				break;
			}
			cadastrarConta(&contContasMenuConta, &contClienteMenuConta);
			;
			break;
		case 2:
			alterarConta(&contContasMenuConta, &contClienteMenuConta)
			;
			break;
		case 3:
			removerConta(&contContasMenuConta, &contClienteMenuConta);

			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}
	}
	while(option != 0);
	*contContas = contContasMenuConta;

}


//AQUI INICIAMOS O MENU MOVIMENTO E SUAS FUNÇÕES
void menuTransferencia(int*contContasMov)
{
	setlocale(LC_ALL, "Portuguese");
	int nCt;
	int nAg;
	int aux;
	float valor;
	int control = 0;
	int y = *contContasMov;
	printf("Informe o número da agência: ");
	scanf("%d", &nAg);
	setbuf(stdin, NULL);
	printf("Informe o número da conta: ");
	scanf("%d", &nCt);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= y; aux++)
	{
		if(nAg == contas[aux].agencia && nCt == contas[aux].nCont)  //se as informações baterem, ele executa tudo do if
		{
			control = 1;
			printf("Informe o valor a ser transferido: ");
			scanf("%f", &valor);
			setbuf(stdin, NULL);

			if(valor > 0 && valor <= contas[aux].saldo)
			{
				contas[aux].saldo = contas[aux].saldo - valor;  //Aqui ocorre a retirada do valor da conta remetente

				printf("Saldo atual: %.2f\n", contas[aux].saldo);
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				system("color 04");
				if(valor > contas[aux].saldo)
					printf("Você não possui saldo suficiente para esta transação!!");
				if(valor < 0)
					printf("Valor inválido!!");
				system("pause");
				system("cls");
				system("color 07");
				return;
			}

		}
		if(control == 0)
		{
			system("cls");
			system("color 04");
			printf("Conta não encontrada!!");     //Pois o numero da conta é formado pela união de numero de
			system("pause");
			system("cls");
			system("color 07");
		}                                         //conta e numero de agencia
	}

	printf("Informe o número da agência referente a conta de destino: ");
	scanf("%d", &nAg);
	setbuf(stdin, NULL);
	printf("Informe o número da conta de destino: ");
	scanf("%d", &nCt);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= y; aux++)
	{
		if(nAg == contas[aux].agencia && nCt == contas[aux].nCont)  //se as informações baterem, ele executa tudo do if
		{
			control = 1;

			contas[aux].saldo = contas[aux].saldo + valor;  //Aqui ocorre a retirada do valor da conta remetente
			printf("Saldo antigo: %.2f\n", contas[aux].saldo - valor);
			printf("Saldo atual: %.2f\n", contas[aux].saldo);
			printf("SUCESSO!!\n");
			system("color 02");
			system("pause");
			system("cls");
			system("color 07");
		}
		if(control == 0)
		{
			system("cls");
			system("color 04");
			printf("Conta não encontrada!!");     //Pois o numero da conta é formado pela união de numero de
			system("pause");
			system("cls");
			system("color 07");
		}
	}
}



void menuSaque(int *contContasMov)
{
	setlocale(LC_ALL, "Portuguese");
	int nCt;
	int nAg;
	int aux;
	float valor;
	int control = 0;
	int y = *contContasMov;
	printf("Informe o número da agência: ");
	scanf("%d", &nAg);
	setbuf(stdin, NULL);
	printf("Informe o número da conta: ");
	scanf("%d", &nCt);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= y; aux++)
	{
		if(nAg == contas[aux].agencia && nCt == contas[aux].nCont)  //se as informações baterem, ele executa tudo do if
		{
			control = 1;
			printf("Informe o valor a ser retirado: ");
			scanf("%f", &valor);
			setbuf(stdin, NULL);

			if(valor > 0 && valor <= contas[aux].saldo)
			{
				contas[aux].saldo = contas[aux].saldo - valor;  //Aqui ocorre o encremento do saldo

				printf("Saldo atual: %.2f\n", contas[aux].saldo);
				printf("SUCESSO!!\n");
				system("color 02");
				system("pause");
				system("cls");
				system("color 07");
				return;
			}
			else
			{
				system("color 04");
				if(valor < 0)
					printf("Valor inválido!\n");
				if(valor > contas[aux].saldo)
					printf("Você não possui saldo suficiente para esta retirada!!\n");
				system("pause");
				system("cls");
				system("color 07");
				return;
			}
		}
		if(control == 0)
		{
			system("cls");
			system("color 04");
			system("color 07");                   //Pois o numero da conta é formado pela união de numero de
			printf("Conta não encontrada!!");     //conta e numero de agencia
			system("pause");
			system("cls");
		}
	}

}

void menuDeposito(int *contContasMov)     //Função responsável por fazer os depósitos em cada conta.
{
	setlocale(LC_ALL, "Portuguese");
	int nCt;
	int nAg;
	int aux;
	float valor;
	int control = 0;
	int y = *contContasMov;
	printf("Informe o número da agência: ");
	scanf("%d", &nAg);
	setbuf(stdin, NULL);
	printf("Informe o número da conta: ");
	scanf("%d", &nCt);
	setbuf(stdin, NULL);

	for(aux = 0; aux <= y; aux++)
	{
		if(nAg == contas[aux].agencia && nCt == contas[aux].nCont)  //se as informações baterem, ele executa tudo do if
		{
			control = 1;
			printf("Informe o valor a ser depositado: ");
			scanf("%f", &valor);
			setbuf(stdin, NULL);
			if(valor > 0)
			{

				contas[aux].saldo = contas[aux].saldo + valor;  //Aqui ocorre o encremento do saldo

				printf("Saldo atual: %.2f\n", contas[aux].saldo);
				printf("SUCESSO!!\n");
				system("color 02");
				system("pause");
				system("cls");
				system("color 07");
				return;
			}
			else
			{
				system("color 04");
				printf("Valor para depósito inválido!!");
				system("pause");
				system("cls");
				system("color 07");
				return;
			}
		}

	}
	if(control == 0)
	{
		system("cls");
		system("color 04");
		system("color 07");                   //Pois o numero da conta é formado pela união de numero de
		printf("Conta não encontrada!!");     //conta e numero de agencia
		system("pause");
		system("cls");
	}
}



void menuMovimento(int *contContas)
{
	setlocale(LC_ALL, "Portuguese");
	int option;
	int contContasMov = *contContas;

	do
	{
		printf("<<<<<<<<<<<<<<  MENU CLIENTE  >>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("--------------------------------------------\n");
		printf("| 1- Depósito                              |\n");
		printf("| 2- Saque                                 |\n");
		printf("| 3- Transferência                         |\n");
		printf("| 0- Sair                                  |\n");
		printf("--------------------------------------------\n");

		scanf("%d", &option);
		setbuf(stdin, NULL);

		if(option >= 0 && option <= 3)
			system("cls");

		switch(option)
		{
		case 1:
			menuDeposito(&contContasMov);
			break;
		case 2:
			menuSaque(&contContasMov);
			break;
		case 3:
			menuTransferencia(&contContasMov);
			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}
	}
	while(option != 0);


}

//FIM MENU MOVIMENTO


//E AQUI INICIAMOS O MENU RELATÓRIOS E SUAS FUNÇÕES

double chartoint(char cpf[CPF])
{
	double aux, soma = 0;
	int i;
	for(i = 0; i < CPF - 1; i++)
	{
		aux = (cpf[i] - '0');
		aux *= pow(10, CPF - 2 - i);
		soma += aux;
	}
	return soma;
}

void merge(double cpf[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	double L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = cpf[l + i];
	for (j = 0; j < n2; j++)
		R[j] = cpf[m + 1 + j];
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			cpf[k] = L[i];
			i++;
		}
		else
		{
			cpf[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		cpf[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		cpf[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(double cpf[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(cpf, l, m);
		mergeSort(cpf, m + 1, r);
		merge(cpf, l, m, r);
	}
}


void dadosClientesAtivos(int *contadorClientesMenuRelatorio)
{
	setlocale(LC_ALL, "Portuguese");
	// tCliente clienteAux[CLI];
	double cpf[CLI];
	int auxClienteAux = 0;
	int aux, aux2;

	for(aux = 0; aux < (*contadorClientesMenuRelatorio); aux++)   //Cria um vetor que vai conter só clientes ativos 
	{
		if(cliente[aux].numConta != 0)
		{
			//clienteAux[auxClienteAux] = cliente[aux];
			cpf[auxClienteAux] = chartoint(cliente[aux].cpf);
			auxClienteAux++;
		}
	}
	mergeSort(cpf, 0, auxClienteAux - 1);    //Função recursiva que vai ordenar os cpf's no vetor 
	for(aux = 0; aux < auxClienteAux; aux++)
	{
		//printf("%.0f\n", cpf[aux]);
		for(aux2 = 0; aux2 < (*contadorClientesMenuRelatorio); aux2++)
		{
			if(cpf[aux] == chartoint(cliente[aux2].cpf))
			{
				printf("NOME: %s\n", cliente[aux2].nome);
				printf("CPF: %s\n", cliente[aux2].cpf);
				printf("ENDEREÇO: %s\n", cliente[aux2].endereco);
				printf("TELEFONE: %s\n", cliente[aux2].telefone);
				printf("EMAIL: %s\n", cliente[aux2].email);
				printf("CONTAS: %d\n\n", cliente[aux2].numConta);
				break;
			}
		}

	}
	system("pause");
	system("cls");
}

void dadosTodosClientes(int *contadorContasMenuRelatorio, int *contadorClientesMenuRelatorio, FILE *file)
{
	setlocale(LC_ALL, "Portuguese");
	int aux;
	int aux2;
	int option;

	for(aux = 0; aux < (*contadorClientesMenuRelatorio); aux++)
	{
		if(cliente[aux].numConta == 0)
		{

			printf("\nNOME: %s\n", cliente[aux].nome);
			printf("CPF: %s\n", cliente[aux].cpf);
			printf("ENDEREÇO: %s\n", cliente[aux].endereco);
			printf("TELEFONE: %s\n", cliente[aux].telefone);
			printf("EMAIL: %s\n", cliente[aux].email);
			printf("CONTAS: %d\n", cliente[aux].numConta);
			printf("CLIENTE NÃO POSSUI CONTA\n\n");
		}
		for(aux2 = 0; aux2 < (*contadorContasMenuRelatorio); aux2++)
		{
			if(strcmp (cliente[aux].cpf, contas[aux2].cpf) == 0)
			{
				printf("NOME: %s\n", cliente[aux].nome);
				printf("CPF: %s\n", cliente[aux].cpf);
				printf("ENDEREÇO: %s\n", cliente[aux].endereco);
				printf("TELEFONE: %s\n", cliente[aux].telefone);
				printf("EMAIL: %s\n", cliente[aux].email);
				printf("CONTAS: %d\n", cliente[aux].numConta);
				printf("AGENCIA: %i\n", contas[aux2].agencia);
				printf("NUMERO DA CONTA: %i\n", contas[aux2].nCont);
				printf("SALDO: %.2f\n\n", contas[aux2].saldo);
			}
		}
	}

	printf("Deseja salvar os dados em um arquivo txt?\n");
	printf("1- Sim\n");
	printf("2- Não\n");
	scanf("%d", &option);

	if(option == 1)
	{

		for(aux = 0; aux < (*contadorClientesMenuRelatorio); aux++)
		{
			if(cliente[aux].numConta == 0)
			{
				fprintf(file, "NOME: %s", cliente[aux].nome);
				fprintf(file, "\nCPF: %s", cliente[aux].cpf);
				fprintf(file, "\nENDEREÇO: %s", cliente[aux].endereco);
				fprintf(file, "\nTELEFONE: %s", cliente[aux].telefone);
				fprintf(file, "\nEMAIL: %s", cliente[aux].email);
				fprintf(file, "\nCONTAS: %i\n\n", cliente[aux].numConta);
			}
			for(aux2 = 0; aux2 < (*contadorContasMenuRelatorio); aux2++)
			{
				if(strcmp (cliente[aux].cpf, contas[aux2].cpf) == 0)
				{
					fprintf(file, "NOME: %s", cliente[aux].nome);
					fprintf(file, "\nCPF: %s", cliente[aux].cpf);
					fprintf(file, "\nENDEREÇO: %s", cliente[aux].endereco);
					fprintf(file, "\nTELEFONE: %s", cliente[aux].telefone);
					fprintf(file, "\nEMAIL: %s", cliente[aux].email);
					fprintf(file, "\nCONTAS: %i", cliente[aux].numConta);
					fprintf(file, "\nAGÊNCIA: %i", contas[aux].agencia);
					fprintf(file, "\nN° CONTA:%i", contas[aux].nCont);
					fprintf(file, "\nSALDO: %.2lf\n\n", contas[aux].saldo);

				}
			}
		}
		printf("ARQUIVO GRAVADO COM SUCESSO!\n");
	}
	system("pause");
	system("cls");
}

void dadosContas(int * contadorContasMenuRelatorio, int * contadorClientesMenuRelatorio, FILE * file)
{
	setlocale(LC_ALL, "Portuguese");
	int aux;
	int auxContas;
	int option;


	for(aux = 0; aux < (*contadorContasMenuRelatorio); aux++)
	{
		for(auxContas = 0; auxContas < (*contadorClientesMenuRelatorio); auxContas++)
			if(strcmp(contas[aux].cpf, cliente[auxContas].cpf) == 0)
			{
				printf("\n\nNOME: %s\n", cliente[auxContas].nome);
				printf("CPF: %s\n", contas[aux].cpf);
				printf("AGENCIA: %i\n", contas[aux].agencia);
				printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
				printf("SALDO: %.2f\n", contas[aux].saldo);
			}
	}

	printf("Deseja salvar os dados em um arquivo txt?\n");
	printf("1- Sim\n");
	printf("2- Não\n");
	scanf("%d", &option);
	if(option == 1)
	{
		for(aux = 0; aux < (*contadorContasMenuRelatorio); aux++)
		{
			for(auxContas = 0; auxContas < (*contadorClientesMenuRelatorio); auxContas++)
				if(strcmp(contas[aux].cpf, cliente[auxContas].cpf) == 0)
				{
					fprintf(file, "NOME: %s", cliente[auxContas].nome);
					fprintf(file, "\nCPF: %s", contas[aux].cpf);
					fprintf(file, "\nAGÊNCIA: %i", contas[aux].agencia);
					fprintf(file, "\nN° CONTA:%i", contas[aux].nCont);
					fprintf(file, "\nSALDO: %.2lf\n\n", contas[aux].saldo);

				}
		}
		printf("ARQUIVO GRAVADO COM SUCESSO!\n");
	}

	system("pause");
	system("cls");
}

void dadosClientes(int * contadorClientesMenuRelatorio, FILE * file)
{
	setlocale(LC_ALL, "Portuguese");
	int aux;
	int option;

	for(aux = 0; aux < (*contadorClientesMenuRelatorio); aux++)
	{
		printf("NOME: %s\n", cliente[aux].nome);
		printf("CPF: %s\n", cliente[aux].cpf);
		printf("ENDEREÇO: %s\n", cliente[aux].endereco);
		printf("TELEFONE: %s\n", cliente[aux].telefone);
		printf("EMAIL: %s\n", cliente[aux].email);
		printf("CONTAS: %d\n\n", cliente[aux].numConta);
	}

	printf("Deseja salvar os dados em um arquivo txt?\n");
	printf("1- Sim\n");
	printf("2- Não\n");
	scanf("%d", &option);

	if(option == 1)
	{

		for(aux = 0; aux < (*contadorClientesMenuRelatorio); aux++)
		{
			fprintf(file, "NOME: %s", cliente[aux].nome);
			fprintf(file, "\nCPF: %s", cliente[aux].cpf);
			fprintf(file, "\nENDEREÇO: %s", cliente[aux].endereco);
			fprintf(file, "\nTELEFONE: %s", cliente[aux].telefone);
			fprintf(file, "\nEMAIL: %s", cliente[aux].email);
			fprintf(file, "\nCONTAS: %i\n\n", cliente[aux].numConta);
		}
		printf("ARQUIVO GRAVADO COM SUCESSO!\n");
	}
	system("pause");
	system("cls");
}

void contasPorSaldo(int  * contadorContasMenuRelatorio, int * contadorClienteMenuRelatorio, FILE *file)
{
	setlocale(LC_ALL, "Portuguese");
	double valorDesejado;
	int op;
	int option;
	int aux;
	int auxNome;
	char nome[NOME];
	char cpf[CPF];
	do
	{
		int control = 0;
		printf("Digite o valor desejado: ");
		scanf("%lf", &valorDesejado);

		printf("|------------------------------------------------------------------------------|\n");
		printf("| 1- MAIOR                                                                     |\n");
		printf("| 2- IGUAL                                                                     |\n");
		printf("| 3- MENOR                                                                     |\n");
		printf("| 0- SAIR                                                                      |\n");
		printf("|------------------------------------------------------------------------------|\n");

		scanf("%d", &op);
		setbuf(stdin, NULL);

		switch(op)
		{
		case 1:
			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo > valorDesejado)
				{
					control = 1;
				}
			}
			
			
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo > valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}
						strcpy(cpf, contas[aux].cpf);
						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n", cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n", contas[aux].saldo);
					}
				}
			 
			 
			 
			 
				printf("Deseja salvar os dados em um arquivo txt?\n");
				printf("1- Sim\n");
				printf("2- Não\n");
				scanf("%d", &option);

				if(option == 1)
				{
					file = fopen("arq_contas_por_saldo_maior.txt", "w");
					for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
					{
						if(contas[aux].saldo > valorDesejado)
						{
							for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
							{
								if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
								{
									strcpy(nome, cliente[auxNome].nome);
								}
							}
							strcpy(cpf, contas[aux].cpf);
							fprintf(file, "NOME: %s\n", nome);
							fprintf(file, "CPF: %s\n", cpf);
							fprintf(file, "NUMERO DA CONTA: %i\n", contas[aux].nCont);
							fprintf(file, "NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
							fprintf(file, "SALDO: %.2f\n\n", contas[aux].saldo);
						}
					}
					fclose(file);
					printf("ARQUIVO GRAVADO COM SUCESSO!\n");
				}
				}
			
			else
			{
				system("cls");
				system("color 04");
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			system("color 07");
			break;
		case 2:
			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo == valorDesejado)
				{
					control = 1;
				}
			}
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo == valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}

						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n", contas[aux].cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n", contas[aux].saldo);
					}
				}


				printf("Deseja salvar os dados em um arquivo txt?\n");
				printf("1- Sim\n");
				printf("2- Não\n");
				scanf("%d", &option);

				if(option == 1)
				{
					file = fopen("arq_contas_por_saldo_igual.txt", "w");

					for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
					{
						if(contas[aux].saldo == valorDesejado)
						{
							for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
							{
								if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
								{
									strcpy(nome, cliente[auxNome].nome);
								}
							}

							fprintf(file, "NOME: %s\n", nome);
							fprintf(file, "CPF: %s\n", contas[aux].cpf);
							fprintf(file, "NUMERO DA CONTA: %i\n", contas[aux].nCont);
							fprintf(file, "NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
							fprintf(file, "SALDO: %.2f\n\n", contas[aux].saldo);
						}
					}
					fclose(file);
					printf("ARQUIVO GRAVADO COM SUCESSO!\n");
				}
			}
			else
			{
				system("cls");
				system("color 04");
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			system("color 07");
			break;
		case 3:
			for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
			{
				if(contas[aux].saldo < valorDesejado)
				{
					control = 1;
				}
			}
			if(control == 1)
			{
				for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
				{
					if(contas[aux].saldo < valorDesejado)
					{
						for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
						{
							if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
							{
								strcpy(nome, cliente[auxNome].nome);
							}
						}

						printf("\nNOME: %s\n", nome);
						printf("CPF: %s\n", contas[aux].cpf);
						printf("NUMERO DA CONTA: %i\n", contas[aux].nCont);
						printf("NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
						printf("SALDO: %.2f\n", (double)contas[aux].saldo);
					}
				}


				printf("Deseja salvar os dados em um arquivo txt?\n");
				printf("1- Sim\n");
				printf("2- Não\n");
				scanf("%d", &option);


				if(option == 1)
				{
					file = fopen("arq_contas_por_saldo_menor.txt", "w");

					for(aux = 0; aux < (*contadorContasMenuRelatorio) ; aux++)
					{
						if(contas[aux].saldo < valorDesejado)
						{
							for(auxNome = 0; auxNome < (*contadorClienteMenuRelatorio); auxNome++)
							{
								if(strcmp(contas[aux].cpf, cliente[auxNome].cpf) == 0)
								{
									strcpy(nome, cliente[auxNome].nome);
								}
							}

							fprintf(file,"NOME: %s\n", nome);
							fprintf(file,"CPF: %s\n", contas[aux].cpf);
							fprintf(file,"NUMERO DA CONTA: %i\n", contas[aux].nCont);
							fprintf(file,"NUMERO DA AGENCIA: %i\n", contas[aux].agencia);
							fprintf(file,"SALDO: %.2f\n\n", (double)contas[aux].saldo);
						}
					}

					fclose(file);
					printf("ARQUIVO GRAVADO COM SUCESSO!\n");
				}

			}
			else
			{
				system("cls");
				system("color 04");
				printf("NÃO EXISTE NENHUMA CONTA COM ESSES REQUISITOS\n");
			}
			system("pause");
			system("cls");
			system("color 07");
			break;
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}

	}
	while(op != 0);
}

void contasDeUmCliente(int * contadorContasMenuRelatorio)
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[CPF];
	int aux;
	int controle = 0;
	printf("Digite um CPF: ");
	scanf("%s", cpf);

	for(aux = 0; aux < (*contadorContasMenuRelatorio); aux++)
	{
		if(strcmp(cpf, contas[aux].cpf) == 0 )
		{
			printf("\nNumero da conta: %d\n", contas[aux].nCont);
			printf("Numero da agencia: %d\n", contas[aux].agencia);
			printf("Saldo da conta: %.2f\n", contas[aux].saldo);
			controle = 1;

		}
	}
	system("pause");
	system("cls");

	if(controle == 0)
	{
		system("cls");
		system("color 04");
		printf("CONTA NÃO CADASTRADA!\n");
		system("pause");
		system("cls");
		system("color 07");
	}

	return;
}

void menuRelatorios(int * contContas, int * contCli)
{
	setlocale(LC_ALL, "Portuguese");
	int contadorContasMenuRelatorio = *contContas;
	int contadorClientesMenuRelatorio = *contCli;
	FILE *file;
	int option;
	do
	{
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  MENU RELATÓRIOS  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		setlocale(LC_ALL, "Portuguese");
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("| 1- Contas de um cliente                                                                     |\n");
		printf("| 2- Dados dos clientes com saldo inferior, superior ou igual a um valor                      |\n");
		printf("| 3- Listar os dados cadastrais de todos clientes (ativos ou não)                             |\n");
		printf("| 4- Listar as informações de todas as contas                                                 |\n");
		printf("| 5- Listar as informações de todos os clientes incluindo suas contas                         |\n");
		printf("| 6- Listar os dados cadastrais de todos os clientes ativos de uma agência ordenados pelo cpf |\n");
		printf("| 0- Sair                                                                                     |\n");
		printf("-----------------------------------------------------------------------------------------------\n");


		scanf("%d", &option);
		setbuf(stdin, NULL);

		if(option >= 0 && option <= 6)
			system("cls");

		switch(option)
		{
		case 1:
			contasDeUmCliente(&contadorContasMenuRelatorio);
			break;
		case 2:
			contasPorSaldo(&contadorContasMenuRelatorio,&contadorClientesMenuRelatorio,file);
			break;
		case 3:
			file = fopen("arq_dados_clientes.txt", "w");
			dadosClientes(&contadorClientesMenuRelatorio, file);
			fclose(file);
			break;
		case 4:
			file = fopen("arq_dados_contas.txt", "w");
			dadosContas(&contadorContasMenuRelatorio, &contadorClientesMenuRelatorio, file);
			fclose(file);
			break;
		case 5:
			file = fopen("arq_dados_todos_clientes_contas.txt", "w");
			dadosTodosClientes(&contadorContasMenuRelatorio, &contadorClientesMenuRelatorio, file);
			fclose(file);
			break;
		case 6:
			dadosClientesAtivos(&contadorClientesMenuRelatorio);
			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("Erro. Informe uma opção válida: \n");
			system("pause");
			system("cls");
			system("color 07");
		}
	}
	while(option != 0);
}

void loading()//animação para entrar no menu principal
{
	int c;
	for(c = 0; c < 3; c++)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading.\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading..\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading...\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading...\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading.....\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading......\n");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       Loading.......\n");
		system("cls");
	}
}


void login()//tela de login que da acesso ao resto do programa
{
	int c;
	char user[9];
	char user1[9] = "rosianni";
	char senha[11];
	char senha2[11] = "computacao";
	int aux = 1;
	do
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n                                          INSIRA O SEU LOGIN: ");
		setbuf(stdin, NULL);
		scanf("%s", user);
		printf("\n                                          INSIRA SUA SENHA: ");
		setbuf(stdin, NULL);
		scanf("%s", senha);

		if((strcmp (user, user1) != 0 ) || (strcmp(senha, senha2) != 0))
		{
			system("cls");
			system("color 04");
			for(c = 0; c < 10; c++)
			{

				printf("\n\n\n\n\n\n\n\n\n\n\n\n                                          USUÁRIO OU SENHA INVÁLIDO\n");
				system("cls");
			}
			system("color 07");
			aux = 0;
		}
		if((strcmp (user, user1) == 0 ) && (strcmp(senha, senha2) == 0))
		{
			loading();
			aux = 1;
		}
	}
	while(aux == 0);
}


// FUNÇÃO DE MENU PRINCIPAL
void menuPrincipal(int * option)
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	int o;
	printf("<<<<<<<<<<<<<< MENU PRINCIPAL >>>>>>>>>>>>>>\n");
	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------\n");
	printf("| 1- Cliente                               |\n");
	printf("| 2- Conta                                 |\n");
	printf("| 3- Movimento                             |\n");
	printf("| 4- Relatório                             |\n");
	printf("| 0- Sair                                  |\n");
	printf("--------------------------------------------\n");
	printf("Informe uma opção: ");
	scanf("%d", &o);
	setbuf(stdin, NULL);
	if(o >= 0 && o <= 4)
		system("cls");
	*option = o;

}


int main()
{

	setlocale(LC_ALL, "Portuguese");
	login();
	int contCli = 0;
	int contContas = 0;
	int option;

	do
	{
		menuPrincipal(&option);
		switch(option)
		{
		case 1:
			menuCliente(&contCli);
			break;
		case 2:
			menuConta(&contCli, &contContas);
			break;
		case 3:
			menuMovimento(&contContas);
			break;
		case 4:
			menuRelatorios(&contContas, &contCli);
			break;
		case 0:
			break;
		default:
			system("cls");
			system("color 04");
			printf("ERRO 404. NOT FOUND.\n");
			system("pause");
			system("cls");
			system("color 07");

		}
	}
	while(option != 0);

	system("color 02");
	printf("\n\n\n\n\n\n\n\n\n\n                                         Programa de gestão bancária finalizado!\n");
	printf("\n                                         By Raphael Kênnedy e Thales Abdon.\n");
	printf("\n                                         Merry Christmas Dra. Rosianni.\n");
	printf("\n                                                          §§");
	printf("\n                                         Coffee is life C\\__/\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	system("pause");
	return 0;
}