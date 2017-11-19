 /*
  * @file b513.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711201031
  */

#include <stdio.h>
#include <math.h>
#define max 65535

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
	int n, x;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d", &x);
			if(get(x) == 0) {
				printf("Y\n");
			} else {
				printf("N\n");
			} 
		}
	}
	return 0;
}

