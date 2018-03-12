 /*
  * @file c164.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803121323
  */

#include <stdio.h>

int main() {
	int k, i, temp, point, sum[10001];
	sum[0] = 1;
	point = 1;
	for(i = 2; point < 10001; i++) {
		temp = i;
		while(temp--) {
			sum[point] = sum[point - 1] + i;
			point++;
			if(point >= 10001) {
				break;
			}
		}
	}
	while(scanf("%d", &k) != EOF) {
		printf("%d\n", sum[k - 1]);
	}
	return 0;
}
