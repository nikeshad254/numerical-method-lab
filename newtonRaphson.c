#include<stdio.h>
#include<math.h>

float f(float x) {
    return x * x + 4 * x - 1;
}

float df(float x) {
    return 2 * x + 4;
}

int main() {
    int i, n;
    float h, x0, x1, allerr;

    printf("\nEnter x0, allowed error and maximum iterations: ");
    scanf("%f %f %d", & x0, & allerr, & n);
    printf("\n");

    for (i = 1; i <= n; i++) {
        h = f(x0) / df(x0);
        x1 = x0 - h;
        printf("at iteration no. %3d, x = %9.6f\n", i, x1);

        if (fabs(x1 - x0) < allerr) {
            printf("\nAfter %3d iterations, root = %8.6f\n", i, x1);
            return 0;
        }
        x0 = x1;
    }
    printf("\nthe required solution doesn't converge or iterations are insufficient\n");
    return 1;

}

// newton ralphson ends here values 2 0.0001 10 \n