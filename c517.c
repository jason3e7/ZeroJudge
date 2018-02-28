 /*
  * @file c517.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803011047
  */

#include <stdio.h>

int main() {
	int x[3], y[3];
	unsigned long long d;
	while(scanf("%d %d", &x[0], &y[0]) != EOF) {
		scanf("%d %d", &x[1], &y[1]);
		scanf("%d %d", &x[2], &y[2]);
		d = 0;
		if(x[0] < x[1]) {
			d += (x[1] - x[0]);
		}
		if(x[0] > x[2]) {
			d += (x[0] - x[2]);
		}
		if(y[0] < y[1]) {
			d += (y[1] - y[0]);
		}
		if(y[0] > y[2]) {
			d += (y[0] - y[2]);
		}
		printf("%lld\n", d);
	}
	return 0;
}
