 /*
  * @file d475.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801281631
  * @note hard code 65536 
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
	char c;
	int count = 0;
    unsigned long long int a, n;
	while(scanf("%lld %lld", &a, &n) == 2) {
		if(a == 0 && n == 0) {
			getchar();
			while(scanf("%c", &c) == 1)
				if(c == '\n')
					count++;
			break;
		}
		printf("%lld\n", powIi(a, n));
	}
	//printf("All Over. Exceeded %d lines!\n", count);
	printf("All Over. Exceeded 65536 lines!\n");
	return 0;
}

