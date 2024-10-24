/*
 * Calcul du polynôme avec la méthode d'Horner 
 */
#include <stdio.h>
#define N 9
#define M 10000000

float Horner(float * A,float x){
  int i;
  float P;
  P=A[N];
  for(i=N-1;i>=0;i--){
    P=P*x+A[i];
  } 
  return P;
}

int main(){
  int i=1;
  float x=0,deltax=10.0/M;
  float coef[N+1]={-3, 1, 2, -5, 0.4, 0.2, -0.3, 0.1, -0.03, 0.01};
  for(i=0;i<=M;i++){
    //printf("%f %f\n",x,Horner(coef,x));
    Horner(coef,x);
    x+=deltax;
  } 
  return (0);
}
