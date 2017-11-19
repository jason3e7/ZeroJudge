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

int main() {
	primeTable();
	int i, prime[1280000] = {0}, point = 1;
	prime[0] = 2;
	for(i = 3; i <= max; i+=2) {
		if(get(i) == 0) {
			prime[point] = i;
			point++;
		}
	}
	int x, base, sum;
	while(scanf("%d", &x) != EOF) {
		sum = 0;
		base = 0;
		while(x >= 2) {
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

