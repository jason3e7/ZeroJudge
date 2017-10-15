 /*
  * @file b884.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710161102
  */

#include <stdio.h>

int main() {
	int n, x, y, length;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d %d", &x, &y);
			x = (x >= 0) ? x : (-1 * x);
			y = (y >= 0) ? y : (-1 * y);
			length = 100 - (x + y);
			if(length <= 0 || length >= 100) {
				printf("evil!!\n");
			} else if(0 < length && length <= 30) {
				printf("sad!\n");
			} else if(30 < length && length <= 60) {
				printf("hmm~~\n");
			} else if(60 < length && length < 100) {
				printf("Happyyummy\n");
			}
		}
	}
	return 0;
}



