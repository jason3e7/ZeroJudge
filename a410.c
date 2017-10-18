 /*
  * @file a410.c
  * @author Jason3e7
  * @algorithm math(Cramer's rule)
  * @date 201710190934
  */

#include <stdio.h>

int main() {
	int a, b, c, d, e, f;
	float x, y, delta;
	while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF) {
		delta = a * e - b * d;
		x = c * e - b * f;
		y = a * f - c * d;
		if(delta == 0) {
			if(y == 0 && x == 0) {
				printf("Too many\n");
			} else {
				printf("No answer\n");
			}
		} else {
			printf("x=%.2f\ny=%.2f\n", x / delta, y / delta);
		}
	}
	return 0;
}



