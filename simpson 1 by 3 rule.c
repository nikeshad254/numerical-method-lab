/*
simpsons 1/3 rule

a = 0, b = 6, n = 6

ans:- 1.366173413

*/
#include <stdio.h>

float findValueAt(float x) {
    return 1 / (1 + x * x);
}

int main() {
    float a, b, h, i, sum = 0;
    int n, term = 1;

    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = findValueAt(a) + findValueAt(b);

    for (i = a + h; i < b; i = i + h) {
        if (term % 2 == 0)
            sum = sum + 2 * findValueAt(i);
        else
            sum = sum + 4 * findValueAt(i);
        term++;
    }

    sum = h * sum / 3;

    printf("\nThe result from Simpson's 1/3 rule is: %f\n", sum);

    return 0;
}
