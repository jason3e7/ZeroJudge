 /*
  * @file d859.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801211435
  * @note include self
  */

#include <stdio.h>

int main() {
	int i, j, temp, out[1001];
	out[0] = 0;
	out[1] = 1;
	for(i = 2; i <= 1000; i += 2) {
		out[i] = 1;
		temp = i / 2;
		for(j = 1; j <= temp; j++) {
			out[i] += out[j];
		}
		out[i + 1] = out[i];
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", out[n]);
	}
	return 0;
}
