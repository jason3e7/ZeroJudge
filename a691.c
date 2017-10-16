 /*
  * @file a691.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710161937
  */

#include <stdio.h>

int main() {
	int n, i;
	while(scanf("%d", &n) != EOF) {
		for(i = 1; i <= n; i++) {
			if(i % 3 == 0 || i % 10 == 3) {
				printf("YA\n");
				continue;
			}
			printf("%d\n", i);
		}
	}
	return 0;
}



