 /*
  * @file a539.c
  * @author Jason3e7
  * @algorithm basic 
  * @UVa 10327
  * @date 201710281301
  */

#include <stdio.h>

int main() {
	int i, j, n, num[1001], count, swap;
	while(scanf("%d", &n) != EOF) {
		count = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		for(i = 0; i < n; i++) {
			for(j = 1; j < (n - i); j++) {
				if(num[j - 1] > num[j]) {
					swap = num[j - 1];
					num[j - 1] = num[j];
					num[j] = swap;
					count++; 
				}
			}
		}
		printf("Minimum exchange operations : %d\n", count);
	}
	return 0;
}

