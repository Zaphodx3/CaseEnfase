#include <stdio.h>
#include <stdlib.h>

int* q(int *v, int e, int d); //protótipos das funções
int f(int i, int vet[], int v[], int n, int a, int b);

int main(){
	int n, *v, *vet, *ord, i, esq, dir;
	
	scanf("%d", &n);
	v=(int*)malloc(n*sizeof(int)); //alocando espaço p/ o vetor de entrada
	vet=(int*)malloc(n*sizeof(int)); //alocando espaço p/ o vetor resultante
	
	for(i=0;i<n;i++){ //inserindo elementos em v[]
		scanf("%d", &v[i]);
	}
	printf("\n");
	
	q(v,0,n-1); //ordena v[] em ordem crescente
	printf("%d\n",f(n-1,vet,v,n,v[0],v[1]));
	
	printf("\n");
	
	free(v); //libera espaço de memória dos vetores alocados
	free(vet);
}

int f(int i, int vet[], int v[], int n, int a, int b){ //calcula o prefixo do maior elemento de uma sequência "Fibonnaccica"; 
	int cont=0, max;							//**funcionando apenas p/ sequências nas quais vet[0] + vet[1] = vet[2];
	while(i>0){								//para consertar o problema, seria necessário alterar o código de maneira que, ao verificar o
		if(a + b == v[i]){						//o valor da soma do próximo par (v[i],v[i+1]), o "i" iterado deveria percorrer o vetor buscando
			vet[cont] = v[i-2];					//o resultado correspondente e uma das saídas seria usar recursão, "abrindo mão" do recurso 
			vet[cont+1] = v[i-1];				//puramente iterativo.
			vet[cont+2] = v[i];
			cont++;
		}
	i--;
	}
	if(cont < n){
		for(cont;cont<n;cont++){
			for(i;i<n;i++){
				if(vet[cont] + vet[cont+1] == v[i]){
					vet[cont+2] = v[i]; 
				}
			}
		}
	}
	
	
	max = vet[n-1];
	cont=n-1;
	
	for(i=n-1;i>0;i--){
		if(max < vet[i]){
			max = vet[i];
			cont--;
		}
	}
	return cont+1;
}

int* q(int v[], int esq, int dir){ //quicksort para ordenação do vetor (p/ facilitar a implementação)
	int i, j, x, y;
     
    i = esq;
    j = dir;
    x = v[(esq + dir) / 2];
     
    while(i <= j) {
        while(v[i] < x && i < dir) {
            i++;
        }
        while(v[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        q(v, esq, j);
    }
    if(i < dir) {
        q(v, i, dir);
    }
}
