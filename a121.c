 /*
  * @file a121.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711191937
  */

#include <stdio.h>
#include <math.h>
#define max 100000000

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
	int a, b, i, sum;
	while(scanf("%d %d", &a, &b) != EOF) {
		sum = 0;
		for(i = a; i <= b; i++) {
			if(get(i) == 0) {
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

