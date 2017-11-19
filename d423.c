 /*
  * @file d423.c
  * @author Jason3e7
  * @algorithm math
  * @UVa 10856
  * @date 201711181153
  * @note 10000002 ^ (1/2) = 3162...
  * prime[445] = 3137 
  * 2 ^ 24 = 16777216 > 10000002
  */ 

#include <stdio.h>
#include <math.h>
#define max 10000001
#define pSumMax 10000

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

char pSum[pSumMax];

int getPrimeCount(int n) {
	if(n < pSumMax) {
		return pSum[n];
	}
	if(get(n) == 0) {
		return 1;
	}
	if(n % 2 == 0) {
		return getPrimeCount(n / 2) + 1;
	}
	int i;
	for(i = 3; i < n; i += 2) {
		if(get(i) == 0 && n % i == 0) {
			return getPrimeCount(n / i) + 1;
		}
	}
	return 0;
}

int main() {
	primeTable();
	pSum[0] = 0;
	pSum[1] = 0;
	int i, j;
	for(i = 2; i < pSumMax; i++) {
		if(get(i) == 0) {
			pSum[i] = 1;
		}
		for(j = 2; j < pSumMax; j++) {
			if(get(j) == 0 && i % j == 0) {
				pSum[i] = pSum[i / j] + 1;
				break;
			}
		}
	}
	int n, sum, count = 1;
    while(scanf("%d", &n) != EOF) {
		if(n < 0) {
			break;
		}
		sum = 0;
		for(i = 2; sum < n; i++) {
			sum += getPrimeCount(i);
		}
		if(sum == n) {
			printf("Case %d: %d!\n", count, i - 1);
		} else {
			printf("Case %d: Not possible.\n", count);
		}
		count++;
	}
    return 0;
}

