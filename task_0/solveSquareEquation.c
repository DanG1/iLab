#include <stdio.h>
#include <math.h>   // for sqrt()
#include <stdlib.h> // for malloc() & free()

const int INFINITE_ROOTS = -1;

double* solveSquareEquation (double a, double b, double c); //initializing; see determination inside main()

int main(){
	double a; double b; double c; double* root; int quantity;
    printf ("\nInput\n\ta:");
	scanf("%lg", &a);
	printf ("\tb:");
	scanf("%lg", &b);
	printf ("\tc:");
	scanf("%lg", &c);

    // taking a part of code in {...} to determine and use the function,
    // which was initialized before main()
	{
     double* solveSquareEquation (double a, double b, double c){

// Ну и желательно перед main() писать прототип, а только потом функцию,
// Потому что main() самая интересная часть программы, она проверяется первой - so it was YOUR wish :)
	double Discr; int quantity;
	double* root=(double*)malloc(3*sizeof(double));
		if (a==0) {
			if (b==0) {
				if(c==0) {
					quantity=INFINITE_ROOTS;
					root[1]=0;
					root[2]=0;
					}
				else {
					quantity=0;
					root[1]=0;
					root[2]=0;
					}
				}
			else {
				quantity=1;
				root[1]=-c/b;
				root[2]=root[1];
				}
			}
		else {
			Discr=b*b-4*a*c;
			if (Discr<0) {
					quantity=0;
					root[1]=0;
					root[2]=0;
					}
			else {
				root[1]=(-b-sqrt(Discr))/(2*a);
				root[2]=(-b+sqrt(Discr))/(2*a);
				if (Discr==0){
					quantity=1;
					}
				else{
					quantity=2;
					}
				}
			}
    root[0]=quantity;

    return root;
};

	root=solveSquareEquation(a,b,c);
	}

	quantity=root[0];


// This code does not seem to corrupt roots anymore:

/*	double* it_will_corrupt_roots = ( double *) malloc( 3 * sizeof( double));
	it_will_corrupt_roots[1] = 666e66;
	it_will_corrupt_roots[2] = 777e77;
	free( it_will_corrupt_roots); */


	switch (quantity){
		case 0: printf("\nNo roots\n"); break;
		case 1: printf("\nOne root: %lg\n",root[1]); break;
		case 2: printf("\nTwo roots: %lg and %lg\n", root[1], root[2]); break;
		default: printf("\nAny real number is a root\n"); break;

	}
 free(root);
return 0;
}
