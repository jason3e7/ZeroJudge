 /*
  * @file a121.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711191944
  * @note 20000000 => 1270607
  */

#include <stdio.h>
#include <math.h>
#define max 20000000

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

int checkPrime(int n) {
	if(n < 0) {
		return -1;
	} else if(n <= 1) {
		return 0;
	}
	if(n <= 20000000) {
		if(get(n) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	if(n == 2 || n == 3) {
		return 1;
	}
	if(n % 2 == 0 || n % 3 == 0) {
		return 0;
	}
	int i, temp = (int)sqrt(n) + 1;
	for(i = 6; i <= temp; i += 6) {
		if(n % (i - 1) == 0 || n % (i + 1) == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	primeTable();
	int i, prime[1270608] = {0}, point = 1;
	prime[0] = 2;
	for(i = 3; i <= max; i+=2) {
		if(get(i) == 0) {
			prime[point] = i;
			point++;
		}
	}
	int x, base, sum;
	while(scanf("%d", &x) != EOF) {
		if(checkPrime(x) == 1) {
			printf("%d\n", x);
			continue;
		}
		sum = 0;
		base = 0;
		while(x >= 2 && base < 1270608) {
			while(x % prime[base] == 0) {
				x /= prime[base];
				sum += prime[base];
			}
			base++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

