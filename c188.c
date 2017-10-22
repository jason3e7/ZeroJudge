 /*
  * @file c188.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710221500
  */

#include <stdio.h>

int main() {
	long int out[201];
	int i, j;
	for(i = 0; i < 201; i++) {
		out[i] = 1;
	}
	for(i = 2; i < 201; i++) {
		for(j = i; j < 201; j++) {
			out[j] += out[j - i];
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {			
		printf("%ld\n", out[n]);
	}
	return 0;
}

