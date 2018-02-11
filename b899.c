 /*
  * @file b899.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802112155
  */

#include <stdio.h>

int main() {
	int x[4], y[4], diff[3];
	while(scanf("%d %d", &x[0], &y[0]) != EOF) {
		scanf("%d %d", &x[1], &y[1]);
		scanf("%d %d", &x[2], &y[2]);
		diff[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
		diff[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
		diff[2] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
		if(diff[0] == diff[1]) {
			x[3] = x[0] + x[2] - x[1];
			y[3] = y[0] + y[2] - y[1];
		} else if(diff[0] == diff[2]) {
			x[3] = x[1] + x[2] - x[0];
			y[3] = y[1] + y[2] - y[0];
		} else if(diff[1] == diff[2]) {
			x[3] = x[0] + x[1] - x[2];
			y[3] = y[0] + y[1] - y[2];
		}
		printf("%d %d\n", x[3], y[3]);
	}
	return 0;
}

