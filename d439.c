 /*
  * @file d439.c
  * @author Jason3e7
  * @algorithm prime
  * @UVa 11226
  * @date 201711231418
  */

#include <stdio.h>
#include <math.h>
#define max 500000

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

int sopf(int n) {
	int count = 0, div = 2;
	while(n > 1) {
		if(get(n) == 0) {
			count += n;
			break;
		}
		if(get(div) == 0 && n % div == 0) {
			while(n % div == 0) {
				n /= div;
				count += div;
			}
		}
		if(div == 2) {
			div++;
		} else {
			div += 2;
		}
	}
	return count;
}

int main() {
	primeTable();
	int i, sopfA[max + 1] = {0};
	for(i = 2; i <= max; i++) {
		sopfA[i] = sopf(i);
	} 
	int lsopfA[max + 1] = {0};
	for(i = 2; i <= max; i++) {
		if(get(i) == 0 || i == sopfA[i]) {
			lsopfA[i] = 1;
		} else {
			lsopfA[i] = lsopfA[sopfA[i]] + 1;
		}
	}

	int t, n, m, maxSum, count, swap;
	while(scanf("%d", &t) != EOF) {
		count = 1;
		while(t--) {
			scanf("%d %d", &n, &m);
			if(n > m) {
				swap = n;
				n = m;
				m = swap;
			}
			maxSum = 0;
			for(i = n; i <= m; i++) {
				if(lsopfA[i] > maxSum) {
					maxSum = lsopfA[i];
				}
			}
			printf("Case #%d:\n%d\n", count, maxSum);
			count++;
		}
	}
	return 0;
}

