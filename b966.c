 /*
  * @file b966.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803081122
  */

#include <stdio.h>

int main() {
	int n, a, b, i, sum;
	short int num[1000001];
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 1000001; i++) {
			num[i] = 0;
		}
		while(n--) {
			scanf("%d %d", &a, &b);
			for(i = a; i < b; i++) {
				num[i] = 1;
			}
		}
		sum = 0;
		for(i = 0; i < 1000001; i++) {
			sum += num[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
