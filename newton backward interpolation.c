//newton forward interpolation method

/*

	n = 5

	X= 1891 1901 1911 1921 1931
	Y= 46 66 81 93 101

	x= 1925

*/

#include <stdio.h>

void main() {
	float x, u, y, u1;
	int i, j, n, fact;

	printf("Enter the terms : ");
	scanf("%d", &n);

	float a[n][n+1];

	printf("Enter the values of X: ");
	for(i=0; i<n; i++)
		scanf("%f", &a[i][0]);

	printf("Enter the values of Y: ");
	for(i=0; i<n; i++)
		scanf("%f", &a[i][1]);
		
	printf("Enter the value of x for which you want y: ");
	scanf("%f", &x);

	//difference table creation
	for(j=2; j<=n; j++)
		for(i=0; i<n-j+1; i++)
			a[i][j] = a[i+1][j-1] - a[i][j-1];

	//printing difference table
	printf("The difference table is as follows: \n");

	for(i=0; i<n; i++) {
		for(j=0; j<=n; j++)
			printf("\t%f", a[i][j]);
		printf("\n");
	}

	u = (x-a[n-1][0])/(a[1][0]-a[0][0]);
	y = a[n-1][1];
	u1 = u;
	fact = 1;
	j=2;
	
	for(i=2; i<=n; i++) {
		y = y + (u1 * a[i][i])/fact;
		fact = fact * j;
		u1 = u1 * (u+(j-1));
		j++;
	}
	printf("\n\nValue at x=%f is y=%f", x, y);

}