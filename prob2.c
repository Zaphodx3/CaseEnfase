#include <stdio.h>
#include <stdlib.h>

int val(char m[3][3], int x, int o, int p); //validade
char venc(char m[3][3], int x, int o, int p); //vencedor
int prox(char m[3][3], int x, int o, int p); //proximo a jogar

void main()
{
	char c1[3], c2[3], c3[3], m[3][3], x, o, p;
	int i, j;
	
	for(i=0;i<3;i++)
		scanf("%c", &c1[i]);

	for(i=0;i<3;i++)
		scanf(" %c", &c2[i]);
	
	for(i=0;i<3;i++)
		scanf(" %c", &c3[i]);
	x=0;
	o=0;
	p=9;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m[0][j] = c1[j];
			m[1][j] = c2[j];
			m[2][j] = c3[j];
			
			if(m[i][j] == 'X')
				x += 1;
			if(m[i][j] == '0')
				o += 1;
		}
	}
	p -= x+o;
	if(val(m,x,o,p)){
		if(prox(m,x,o,p)){
			switch(venc(m,x,o,p)){
				case 'X':
					printf("O primeiro jogador venceu");
				break;
		
				case '0':
					printf("O segundo jogador venceu");
				break;
			
				case '.':
					printf("Empate");
				break;
			}
			printf("\n");
		}
	}	
	
}

int val(char m[][3], int x, int o, int p){
	char ch=venc(m,x,o,p);
	/*if(ch == 'X' || ch == '0'){
		printf("%c\n", ch); // jogo acabou: alguém venceu
	}*/
	if(abs(x-o)<=1){
		return 1;
	}
	else{
		if(venc(m,x,o,p) == 'X' && venc(m,x,o,p) == '0' || o > x){
			printf("Inválido\n");
			return 0;
		}
	}
		
}

char venc(char m[][3], int x, int o, int p){
	if(m[0][0]==m[0][1] && m[0][1]==m[0][2]){
		printf("1\n");
		return m[0][0];
	}
		
	else if(m[1][0]==m[1][1] && m[1][1]==m[1][2]){
			printf("2\n");
		return m[1][0];
	}
	
	else if(m[2][0]==m[2][1] && m[2][1]==m[2][2]){
		printf("3\n");
		return m[2][0];
	}
	
	else if(m[0][0]==m[1][0] && m[1][0]==m[2][0]){
			printf("4\n");
		return m[0][0];
	}
	
	else if(m[0][1]==m[1][1] && m[1][1]==m[2][1]){
		printf("5\n");
		return m[0][1];
	}
	
	else if(m[0][2]==m[1][2] && m[1][2]==m[2][2]){
			printf("6\n");
		return m[0][2];
	}
	
	else if(m[0][0] == m[1][1] && m[1][1] == m[2][2] || m[0][2]==m[1][1] && m[1][1]==m[2][0]){
		printf("7\n");
		return m[1][1];
	}
	
	else{
			printf("8\n");
		if(p==0 && o<=x)
			return '.';
	}
	
}

int prox(char m[][3], int x, int o, int p){
	if(x<5 && p!=0){
		if(o<x)
			printf("Segundo\n");
		else
			printf("Primeiro\n");
	return 0;
	}
	else
		return 1;
}
