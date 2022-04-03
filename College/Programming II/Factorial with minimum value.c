#include <stdio.h>

int FAT_MN(n, m) {
  int result;
  
  if (n == m){
    return m;  
  }              
  else{
    result = FAT_MN(n - 1, m) * n;
  }
      
  return result;
}


int main (){
  int n;     
  int m;
  int aux;

  printf("N: ");
  scanf("%d", &n);
  printf("M: ");
  scanf("%d", &m);
  if (m > n){
    n = aux;
    n = m;
    m = aux;
  }
  printf("\nFatorial de %d Minimo %d = %d \n", n, m,FAT_MN(n, m));

  return 0;
}