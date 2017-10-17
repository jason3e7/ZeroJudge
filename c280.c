 /*
  * @file c280.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710171435
  */

#include <stdio.h>

int main() {
	unsigned long long int number[81];
	int i, n;
	number[1] = 1;
	number[2] = 1;
	for(i = 3; i < 81; i++) {
		number[i] = number[i - 1] + number[i - 2];
	}
	while(scanf("%d", &n) != EOF) {
		printf("%llu\n", number[n]);
	}
	return 0;
}



