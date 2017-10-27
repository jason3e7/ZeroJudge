 /*
  * @file a111.c
  * @author Jason3e7
  * @algorithm basic 
  * @UVa 12149
  * @date 201710280946
  */

#include <stdio.h>

int main() {
	int i, n, sum;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		sum = 0;
		for(i = 0; i < n; i++) {
			sum += (n - i) * (n - i);
		}
		printf("%d\n", sum);
	}
	return 0;
}

