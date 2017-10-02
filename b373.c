 /*
  * @file b373.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710031020
  */

#include <stdio.h>
int main() {
	int n, train[10001], i, j, swap, temp;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &train[i]);
		}
		swap = 0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n - 1 - i; j++) {
				if(train[j] > train[j + 1]) {
					temp = train[j];
					train[j] = train[j + 1];
					train[j + 1] = temp;
					swap++;
				}
			}
		}
		for(i = 0; i < n; i++) {
			printf("%d", train[i]);
		}
		printf("%d\n", swap);
	}
	return 0;
}

