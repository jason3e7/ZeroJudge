 /*
  * @file b759.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710011202
  */

#include <stdio.h>
#include <string.h>
int main() {
	char x[1001], temp;
	int len, i, j;
	while(scanf("%s", x) != EOF) {
		len = strlen(x);
		for(i = 0; i < len; i++) {
			printf("%s\n", x);
			temp = x[0];
			for(j = 1; j < len; j++) {
				x[j - 1] = x[j];
			}
			x[len - 1] = temp;
		}
	}
	return 0;
}

