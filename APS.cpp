//Nome da disciplina: Programação Estruturada
//Código da Turma: 931 
//Nome e Matricula: Vinicius Nobrega Costa | 2022100111

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// fazer a soma recursiva dos pares
float somatorio (float x[], int cont) {
	static float soma_auxiliar;
	int aux;
	
	if (cont<10 ){
		aux = x[cont];
		if (aux%2 == 0){
			soma_auxiliar += x[cont]; 
			cont++;
			somatorio(x, cont);
		} else {
			cont++;
			somatorio(x, cont);
		}
	} else {
		aux = soma_auxiliar;
		soma_auxiliar = 0;
		return aux;
	}
}

//gerar numeros aleatorios
void gerar_aleatorio(float x[]){
	int cont;
	
	for (cont=0; cont<10;cont++){
		x[cont] = rand() % 50;
		printf("%.1f : ", x[cont]);	
	}
}

int main (){
	
float vetor[10], soma = 0, maior_soma = 0;
int  i=1;	
srand(time(NULL));
		//gerando 5 vetores
		for (i; i<=5; i++){	
				printf("\n----------------------- %d VETOR-------------------------\n", i);
				gerar_aleatorio(vetor);
				soma = somatorio(vetor, 0);
				if (soma > maior_soma){
					maior_soma = soma;
				}
				printf("\nSoma dos pares %d: %.1f\n", i, soma);
		}
		
		printf("\n Maior soma: %.1f", maior_soma);
}
