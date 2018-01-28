 /*
  * @file d493.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801281609
  */

#include <stdio.h>

unsigned long long int powIi(unsigned long long int x, unsigned long long int n) {
	int point, bit[64], i;
	unsigned long long out;
	point = 0;
	do {
		bit[point] = n % 2;
		point++;
	} while(n /= 2);
	out = 1;
	for(i = 0; i < point; i++) {
		if(bit[i] == 1) {
			out *= x;
		}
		x = x * x;
	}
	return out;
}

int main() {
    unsigned long long int a, n;
	while(scanf("%lld %lld", &a, &n) != EOF) {
		printf("%lld\n", powIi(a, n));
	}
	return 0;
}
