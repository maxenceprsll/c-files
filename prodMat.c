#include <stdio.h>
#include <gsl/gsl_blas.h>

int saisir(gsl_matrix *m) {

	FILE * data;
	data = fopen("mat.txt","r");
	gsl_matrix_fscanf(data,m);
	fclose(data);
	return 0;
}

int main(){

	gsl_matrix * A = gsl_matrix_alloc(2,3);
	saisir(A);

	gsl_matrix * B = gsl_matrix_alloc(3,2);
	saisir(B);

	gsl_matrix * C;
	C=gsl_matrix_alloc(2,2);

	/* Calcul C = A B */
	//C=a.A.B+b.C avec a=1 et b=0
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, A, B, 1.0, C);
		//CblasNoTrans: pas de transposition, ni conjugaison
	FILE * data;
	data = fopen("mat2.txt","w");
	gsl_matrix_fprintf(data,C,"%f");
return 0;
}
