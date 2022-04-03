#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 4

void romberg();
double function (double x);
double trapezium (float a, float b, float n);

int main (){
  romberg();
  return 0;
}
void romberg (){
  double s[MAX];
  double var;

  for (int i = 1; i < MAX; i++)
    s[i] = 1;
  for (int k = 1; k < MAX; k++){
    for (int i = 1; i <= k; i++){
      if (i == 1){
        var = s[i];
        s[i] = trapezium(0, 0.8, pow(2, k-1));
      }
      else{
        s[k] = (pow(4 , i - 1) * s[i - 1] - var ) / (pow(4, i - 1) - 1);                    
        var = s[i];
        s[i] = s[k];  
      }
    }
    for (int i = 1; i <= k; i++)
      printf ("  %f  ", s[i]);
    printf ("\n");
  }
}
double trapezium (float a, float b, float n){
  double sum = 0;
  double h;

  h = (b - a) / n ;
  for (int i = 0; i < n; i++){
    sum += (function(a) + function((a + h))) * h / 2;
    a = a + h;
  }
  return sum;
}
double function (double x){
  return 0.2 + 25 * x - 200 * (pow(x, 2)) + 675 * (pow(x, 3)) - 900 * (pow(x, 4)) + 400 * (pow(x, 5));
}
