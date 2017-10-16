 /*
  * @file a690.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710161930
  */

#include <stdio.h>

int main() {
	int n, i;
	while(scanf("%d", &n) != EOF) {
		printf("[");
		for(i = n;i >= 1;i--) {
			printf("%d", i);
			if(i != 1) {
				printf(" ");
			}
		}
		for(i = 2;i <= n;i++) {
			if(i != 1) {
				printf(" ");
			}
			printf("%d", i);
		}
		printf("]\n");
	}
	return 0;
}



