 /*
  * @file b330.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801041637
  */

#include <stdio.h>

int main() {
	int i, temp, n, x, count;
	while(scanf("%d %d", &n, &x) != EOF) {
		count = 0;
		for(i = 1; i <= n; i++) {
			temp = i;
			while(temp) {
				if(temp % 10 == x) {
					count++;
				}
				temp /= 10;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

