#include<stdio.h>

float findValueAt(float x) {
	return x*x*x;
}

void main() {
	float i, h, a, b, sum=0;
	int n;

	printf("give value of a: ");
	scanf("%f", &a);

	printf("give value of b: ");
	scanf("%f", &b);

	printf("give value of n: ");
	scanf("%d", &n);

	h = (b-a)/n;

	sum = findValueAt(a) + findValueAt(b);

	for(i=a+h; i<b; i=i+h) {
		sum = sum + 2 * findValueAt(i);
	}

	sum = (h*sum)/2;

	printf("Trapezoidal Rule gives answer: %f", sum);
}