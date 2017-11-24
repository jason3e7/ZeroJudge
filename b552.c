 /*
  * @file b552.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711251004
  */

#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 100000

int bitset[(max>>5) + 1] = {0};

int  get(int n) { return bitset[n>>5]>>(n&31)&1; }
void set(int n) { bitset[n>>5] |= 1<<(n&31); }

void primeTable() {
	int i, j, k, temp = (max>>5)+1;
	for(i = 0; i < temp; i++) {
		bitset[i] = 0;
	}
	set(0);
	set(1);
	temp = (int)sqrt(max);
	for(i = 2; i <= temp; i++) {
		if(get(i) == 0) {
			for(k = max / i, j = i * k; k >= i; j -= i, k--) {
				if(get(k) == 0) {
					set(j);
				}
			}
		}
	}
}

int checkPrime(unsigned long long int n) {
	if(n <= 1) {
		return 0;
	}
	if(n <= 100000) {
		return 1 - get(n);
	}
	if(n % 2 == 0 || n % 3 == 0) {
		return 0;
	}
	int i, temp = (int)sqrt(n) + 1;
	for(i = 6; i <= temp; i += 6) {
		if(get(i - 1) == 0 && n % (i - 1) == 0) {
			return 0;
		}
		if(get(i + 1) == 0 && n % (i + 1) == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	primeTable();
	char line[10];
	int i, point;
	unsigned long long int temp, out[10];
	while(scanf("%s", line) != EOF) {
		temp = 0;
		point = 0;
		for(i = 0; i < 10; i++) {
			temp *= 10;
			temp += (line[i] - '0');
			if(checkPrime(temp) == 1) {
				out[point] = temp;
				point++;
				temp = 0;
			}
		}
		printf("%d\n", point);
		for(i = 0; i < point; i++) {
			printf("%llu\n", out[i]);
		}
		printf("\n");
	}
	return 0;
}

