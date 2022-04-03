/*
	Escopo de identificadores
*/

#include <stdio.h>

void global(void);
void local(void);
void estatico(void);

int x = 1;

int main(){
	int x = 10;
	printf("\n\nx local %d x da função de onde é chamado", x);
	{ // início do do escopo
		printf("\n\nx do bloco %d interno ao bloco", x);	
		int x = 1000;
		printf("\n\nx do bloco %d interno ao bloco", x);
	} // fim do escopo
	printf("\n\nx local %d x da função de onde é chamado", x);
	estatico();
	global();
	local();
	estatico();
	estatico();

}

void local(void){
	int x = 40;
	printf("\n\nx local %d entrando na função local", x);
	x *= 10;
	printf("\nx local %d saindo da função local", x);
}

void estatico(void){
	static int x = 0;
	printf("\n\nx estático %d entrando na função estático", x);
	x++;
	printf("\nx estático %d saindo da função estático", x);
}

void global(void){
	printf("\n\nx global %d entrando na funçao global", x);
	x++;
	printf("\nx global %d saindo da função global", x);
}

