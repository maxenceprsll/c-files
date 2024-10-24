/*
 * Calcul du polynôme en utilsant la fonction de gsl
 */
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <gsl/gsl_poly.h>

#define N 10
#define M 10000


int main(){
  FILE  * f,* data;
  data = fopen("poly_gsl.dat", "w");
  int i=1;
  const double A[N]={-3,1,2,-5,0.4,0.2,-0.3,0.1,-0.03,0.01};
  float x,h,a,b,y;
  a=0;b=1;
  h=(b-a)/M;
  x=0,y=0;
  for(i=0;i<=M;i++){
    //printf("%f %f\n",x,gsl_poly_eval(A,N,x));
    y=gsl_poly_eval(A,N,x);
    fprintf(data,"%f %f\n",x,y);

    x+=h;
  } 
  fclose(data);
      // Ouverture du shell et lancement d'octave
  f = popen("octave -i", "w");
      // exécution des commandes d'octave pour tracer le graphe
  fprintf(f," load poly_gsl.dat \n ");
  fprintf(f, " plot(poly_gsl(:,1),poly_gsl(:,2))\n ");
  fprintf(f, " print -dpng poly.png \n");
  fflush(f);
    // fermeture d'octave après 5 secondes
    sleep(5);
    pclose(f);
    return 1;
}
