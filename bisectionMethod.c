#include<stdio.h>
#include<conio.h>
#include<math.h>


float f(float x) {
  return (x * x * x - 2 * x - 5);
}
void main() {
  int i, n;
  float x0, x1, x2;
  double f2;

  printf("Enter the  value of x0 = ");
  scanf("%f", & x0);
  printf("Enter the vlaue of x1 = ");
  scanf("%f", & x1);
  printf("Enter the number of iterations n = ");
  scanf("%d", & n);

  printf("\n....................................................................................................\n");
  printf("\n iteration\tx0\t\t\tx1\t\t\tx2\t\t\tf2");
  printf("\n....................................................................................................\n");
  if (f(x0) * f(x1) < 0) {
    for (i = 0; i <= n; i++) {
      x2 = (x0 + x1) / 2;
      f2 = f(x2);
      printf("\n%d\t\t%f\t\t%f\t\t%f\t\t%lf", i, x0, x1, x2, f2);
      if (f2 > 0) {
        x1 = x2;
      } else {
        x0 = x2;
      }
    }
    printf("\n....................................................................................................\n");
    printf("\n\n Approxmimate root = %f", x2);
  } else {
    printf("Invalid Interval");
  }
}