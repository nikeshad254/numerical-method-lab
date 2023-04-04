// secant method
#include<stdio.h>
#include<math.h>
#define EPSLION 0.0001 //to find ans till 4 dec places

float findValueAt(float x){
	return x*x*x - 5*x +1;
}

float findX(float x1, float x2){
	return (x1*findValueAt(x2) - x2 * findValueAt(x1)) / (findValueAt(x2) - findValueAt(x1));
}

int main(){
	int i=1, maxIteration;
	float x1, x2, x;

	printf("enter x1, x2 : ");
	scanf("%f %f", &x1, &x2);
	printf("enter maximum no of iterations : ");
	scanf("%d", &maxIteration);
	x = findX(x1, x2);

	do{
		x1 = x2;
		x2 = x;
		printf("iterations = %d, root = %f\n", i, x);
		x = findX(x1, x2);

		if(fabs(x-x2)<EPSLION){
			printf("Final root=%f, Total Iterations=%d", x, i+1);
			return 0;
		}
		i++;
	}while(i<=maxIteration);

	printf("Final Root : %f", x);
	return 0;
}

// use values 2 3 and 10