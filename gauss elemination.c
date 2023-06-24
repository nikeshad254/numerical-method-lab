/*

Gauss Elemination

Enter the number of unknown: 3
Enter coefficient of augmented matrix:
a[1][1] = 2
a[1][2] = 1
a[1][3] = 1
a[1][4] = 10
a[2][1] = 3
a[2][2] = 2
a[2][3] = 3
a[2][4] = 18
a[3][1] = 1
a[3][2] = 4
a[3][3] = 9
a[3][4] = 16

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 10

void main(){
	float a[SIZE][SIZE], x[SIZE], ratio;
	int i, j, k, n;
	
	printf("Enter the number of unknown: ");
	scanf("%d", &n);
	
	printf("Enter coefficient of augmented matrix:\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n+1; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
	
	for(i=1; i<=n-1; i++){
		if(a[i][i] == 0.0){
			printf("Mathematical Error!");
			exit(0);
		}
		for(j=i+1; j<=n; j++){
			ratio = a[j][i]/a[i][i];
			for(k=1; k<=n+1; k++){
				a[j][k] = a[j][k] - ratio*a[i][k];
			}
		}
	}
	
	x[n] = a[n][n+1]/a[n][n];
	for(i=n-1; i>=1; i--){
		x[i] = a[i][n+1];
		for(j=i+1; j<=n; j++){
			x[i] = x[i] - a[i][j]*x[j];
		}
		x[i] = x[i]/a[i][i];
	}
	
	printf("\nSolution:\n");
	for(i=1; i<=n; i++){
		printf("x[%d] = %0.3f\n", i, x[i]);
	}
}