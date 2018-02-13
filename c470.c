 /*
  * @file c470.c
  * @author Jason3e7
  * @algorithm math
  * @date 201802131420
  */

#include <stdio.h>

int main() {
	int n, temp, sum[2], point;
	while(scanf("%d", &n) != EOF) {
		sum[0] = 0, sum[1] = 0, point = 0;
		while(n--) {
			scanf("%d", &temp);
			sum[point] += temp;
			point = 1 - point;
		}
		if(sum[0] > sum[1]) {
			printf("%d\n", sum[0]);
		} else {
			printf("%d\n", sum[1]);
		}
	}
	return 0;
}
