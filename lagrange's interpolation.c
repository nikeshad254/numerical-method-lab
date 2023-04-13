/*	lagrange's interpolation method

	Testing values:
	
	n = 4
	
	X = 5 6 9 11
	Y = 12 13 14 16
	
	find y at x = 10;

*/

#include <stdio.h>

void main(){

	int i, j, n;
	float x, sum=0, term;

	printf(" enter the value of n = ");
	scanf("%d", &n);

	float X[n], Y[n];

	printf(" enter the value of X = ");
	for(i=0; i<n; i++)
		scanf("%f", &X[i]);

	printf(" enter the value of Y = ");
	for(i=0; i<n; i++)
		scanf("%f", &Y[i]);

	printf("\n To calculate y enter the value of x = ");
	scanf("%f", &x);

	for(i=0; i<n; i++){
		term = 1;
		for(j=0; j<n; j++){
			if(i!=j)
				term *= (x-X[j])/(X[i]-X[j]);
		}
		sum += term*Y[i];
	}

	printf("\n\n The value of y is: %f\n", sum);
}