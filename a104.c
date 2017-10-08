 /*
  * @file a104.c
  * @author Jason3e7
  * @algorithm basic and input
  * @date 201710091013
  */

#include <stdio.h>
int main() {
	int n, number[1001], i, j, temp, nn;
	while(scanf("%d", &n) != EOF) {
		nn = n - 1;
		for(i = 0; i < n; i++) {
			scanf("%d", &number[i]);
		}	
		for(i = 0; i < n; i++) {
			for(j = 0; j < (nn - i); j++) {
				if(number[j] > number[j + 1]) {
					temp = number[j];
					number[j] = number[j + 1];
					number[j + 1] = temp;
				}
			} 
		}
		for(i = 0; i < nn; i++) {
			printf("%d ", number[i]);
		}
		printf("%d\n", number[nn]);
	}
	return 0;
}

