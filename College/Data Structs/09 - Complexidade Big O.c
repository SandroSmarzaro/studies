#include <stdio.h>

int main(void) {
	int	n = 10;
	for (int i = 0; i < n; i = i + 1){ 
		for(int j = 0; j < n; j = j + 1){
			  printf("* ");
		}
		printf("\n");
	}
	// O(nˆ2)

	puts("");
	for (int i = 0; i < n; i = i + 1){
		for(int j = i; j < n; j = j + 1){
			  printf("* ");
		}
		printf("\n");
	}
}

/*
	n + (n-1) + (n-2) + .... 3 + 2 + 1
	n*(n + 1) / 2
	(nˆ2 + n) / 2
	f(n) = nˆ2/2   +  n/2
	O(f(n)) = O(nˆ2/2   +  n/2) = O(nˆ2)

	[1 2 3 4]
	(1 + 4) * 4 / 2

	1 2 3 4
	4 3 2 1
	-------
	5 5 5 5 --> 20 / 2 ->> 10

	200
	10000
	100000

	$$$
	(9000 - 11000)

*/