 /*
  * @file d613.c
  * @author Jason3e7
  * @algorithm prime
  * @UVa 1164
  * @date 201711231319
  * @note 1299709 
  */

#include <stdio.h>
#include <math.h>
#define max 1300000

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
	int n, count, shift;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		if(get(n) == 0) {
			printf("0\n");
			continue;
		}
		count = 0;
		shift = 1;
		while(get(n + shift) == 1) {
			shift++;
		}
		count+=shift;
		shift = 1;
		while(get(n - shift) == 1) {
			shift++;
		}
		count+=shift;
	
		printf("%d\n", count);
	}
	return 0;
}

