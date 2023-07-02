/*
Runge Kutta Method

Initial Condition:
 x0 = 0
 y0 = 1
enter calculation point xn = 0.4
number of steps = 2

*/
#include <stdio.h>
#define f(x,y) (y*y-x*x)/(y*y+x*x)

void main(){
	int i, n;
	float k1, k2, k3, k4, k, h, xn, yn, x0, y0;
	
	printf("Initial Condition:\n x0 = ");
	scanf("%f", &x0);
	printf(" y0 = ");
	scanf("%f", &y0);
	
	printf("enter calculation point xn = ");
	scanf("%f", &xn);
	
	printf("number of steps = ");
	scanf("%d", &n);
	
	h = (xn-x0)/n;
	
	printf("\nx0\ty0\txn\n");
	for(i=0; i<n; i++){
		k1 = f(x0, y0);
		k2 = f((x0+h/2), (y0+(k1*h)/2));
		k3 = f((x0+h/2), (y0+(k2*h)/2));
		k4 = f((x0+h), (y0+h*k3));
		k = (k1+2*k2+2*k3+k4)/6;
		
		yn = y0 + k*h;
		printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
		
		x0 = x0 + h;
		y0 = yn;
	}
	
	printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);
	
	
}
