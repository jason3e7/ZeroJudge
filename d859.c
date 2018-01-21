 /*
  * @file d859.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801211435
  * @note include self
  */

#include <stdio.h>

int main() {
	int addNum, i, temp, out[501];
	out[0] = 0;
	out[1] = 1;
	out[2] = 2;
	addNum = 2;
	for(i = 3; i <= 500; i+=2) {
		out[i] = out[i - 1] + out[addNum];
		out[i + 1] = out[i] + out[addNum];
		addNum++;
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", out[(n / 2) + 1]);
	}
	return 0;
}
