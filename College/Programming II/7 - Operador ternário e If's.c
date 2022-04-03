#include <stdio.h>

int main(void) {
	float nota = 10;
//	if (condição) comando; else comando;
// comando; pode ser comando simples
// pode ser um bloco {c1; c2; .. cn;}
	if (nota >= 6){
		puts("Aprovado");
	}  // fim do if
	else {
		puts("Reprovado");
	} // fim do else
	
	if (nota >= 6) puts("Aprovado");
	else puts("Reprovado");

// if com o ponto e virgula colocado no lugar errado
	if (nota >= 6) puts("Aprovado");
	else /* comando nulo */; puts("Reprovado");

// com operador ternário
  printf ("\n%s \n", nota >= 6 ? "APROVADO" : "REPROVADO");
  puts(nota >= 6 ? "APROVADO" : "REPROVADO");
  (nota >= 6) ? puts( "APROVADO" ) : puts ("REPROVADO");
  
//maior = (a > b) ? a: b;

// parte 2

	float imc;
	float peso = 76.560;
	float altura = 1.75;

	imc = peso / (altura * altura);
	// 
	if (imc == 25.0) {
		printf("\nigual %f \n", imc);
	} else {
		printf("\n %6.1f diferente de 25.0\n", imc);
	}

	nota = 3.9;

	if (nota < 4){
    puts("R");
  } else if (nota < 6){
    puts("F");
  } else if (nota < 7.5){
    puts("C");
  } else if (nota < 9.0){
    puts("B");
  } else {
		puts("A");
	}


  // outra maneira
  
  float media = 9;

    if (media >= 9){
        puts ("Conceito A");
    }
    else if ( media > 7.5){
            puts( "Conceito B");
    }
    else if ( media > 6 ){
        puts ("Conceito C");
    }
    else if ( media > 4 ){
        puts( "Conceito F");
    }
    else{
        puts( "Conceito R" );
    }

  return 0;
}
/*

implementar nota por conceito em uma escola 
Conceito     Faixa 
   A ->    9.0 - 10.0
   B ->    7.5 -  8.9
	 C ->    6.0 -  7.4
	 F ->    4.0 -  5.9
	 R ->    0.0 -  3.9  

*/
