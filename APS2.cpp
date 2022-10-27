#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>
//Implementar um programa que utilize uma lista simplesmente encadeada que faça:
//a. Manipule dados de pessoas. Para isso, utilize um registro que tenha os seguintes dados: nome, data
//de nascimento, cpf, rg, endereço, telefone e e-mail;
//b. Insira os dados na lista (utilize uma função que já carrega dados pré-cadastrados);
//c. Permita consultas por: cpf ou telefone e exiba os resultados na tela; 
//d. Permita excluir os dados das pessoas através de consultas por cpf ou telefone. 
int i, op;
char x[3];
struct Pessoas {
	char nome[50];
	char data[50];
	int cpf, rg, telefone;
	char endereco[100];
	char email[70];
} dados[10];
// função para ADICIONAR uma pessoa
void Add(){
	
	system("cls");
	printf("\nPROGRAMA UNICARIOCA");
	printf("\nADICIONAR");
	if(i < 10){
		printf("\nPESSOA %d\n", i+1);
		printf("Nome: ");
		scanf("%s", &dados[i].nome);
		printf("Data Nascimento: ");
		scanf("%s", &dados[i].data);
		printf("CPF: ");
		scanf("%d", &dados[i].cpf);
		printf("RG: ");
		scanf("%d", &dados[i].rg);
		printf("Telefone: ");
		scanf("%d", &dados[i].telefone);
		printf("Endereço: ");
		scanf("%s", &dados[i].endereco);
		printf("Email: ");
		scanf("%s", &dados[i].email);
		i++;
	}
	else{
		printf("\nTA LOTADO");
	}
}

// funçao para PESQUISAR uma pessoa
void Pesquisar(){
	int j, CPF;
	
	system("cls");
	printf("\nPROGRAMA UNICARIOCA");
	printf("\nPESQUISAR\n");
	printf("\nCPF para buscar: ");
	scanf("%d", &CPF);
	for(j=0;j <= i-1;j++)
	{
		if(dados[j].cpf == CPF){
			printf("\nNome: %s", dados[j].nome);
			printf("\nData Nascimento: %s", dados[j].data);
			printf("\nRG: %d", dados[j].rg);
			printf("\nTelefone: %d", dados[j].telefone);
			printf("\nEndereço: %s", dados[j].endereco);
			printf("\nEmail: %s",dados[j].email);
			printf("\n");
		}
		
	}
	printf("\nDigite uma tecla para voltar ao menu -> ");
	scanf("%s", &x);
}

//funçao para REMOVER um registro
void Excluir(){
	int j, remover_CPF; 
	
	system("cls");
	printf("\nPROGRAMA UNICARIOCA");
	printf("\nEXCLUIR");
	printf("\nQual pessoa deseja remover [cpf]? ");
	scanf("%d", &remover_CPF);
	for(j=0;j<=i-1;j++){
		if(dados[j].cpf == remover_CPF){
			strcpy(dados[j].nome, dados[j+1].nome);
		    dados[j].cpf = dados[j+1].cpf;
			strcpy(dados[j].data, dados[j+1].data);
			strcpy(dados[j].email, dados[j+1].email);
			strcpy(dados[j].endereco, dados[j+1].endereco);
			dados[j].rg = dados[j+1].rg;
			dados[j].telefone, dados[j+1].telefone;
			i--;
		}
	}
}



int main(){
	setlocale(LC_ALL, "Portuguese");
	
	do{
		system("cls");
		printf("\nPROGRAMA UNICARIOCA");
		printf("\n[1] Inserir");
		printf("\n[2] Consultar");
		printf("\n[3] Excluir");
		printf("\n[0] Sair");
		printf("\nOpcao: ");
		scanf("%d", &op);
		switch (op){
			case 1:
				Add();
				break;
			case 2:
				Pesquisar();
				break;
			case 3:
				Excluir();
				break;
		}
	} while(op!=0);
	
	printf("\nOBRIGADO! VOLTE SEMPRE!!");
}