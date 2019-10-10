#include <stdio.h>
#include <stdlib.h>

void main(){
	int a1, a2, cans, i, d, cont;
	printf("Insira a posição inicial do primeiro amigo: ");
	scanf("%d", &a1);
	
	printf("Insira a posição inicial do segundo amigo: ");
	scanf("%d", &a2);
	
	printf("\n");
	
	cans = 0;
	d = abs(a1-a2); //como trata-se de distância, importa apenas o módulo da diferença entre as posições; variável inicializada apenas p/ tornar mais 
				 //a solução mais clara, embora incorra em custo adicional (ainda que baixo, neste caso);		 
				 
	if (d%2 == 0){					//se o valor da distância é par,
		for(i=0; i<=abs(a1-a2);i+=2) //então ambos atualizarão seu cansaço em um mesmo valor para cada 2 passos dados, logo: i+=2;
			cans++;
		printf("%d\n", cans);
	}
	else{ 						//caso seja ímpar,
		cont = 0;					//inicia contador
		for(i=0;i<=abs(a1-a2);i+=2){  
			cont++;				//contador é atualizado p/ cada 2 passos dados, porém, ao final, um dos amigos dá um passo a mais;
			cans += i;			//então, o cansaço total levará em conta o número de pares de passos dados mais essa diferença.
		}
		printf("%d\n", cans+cont);
	}
}

