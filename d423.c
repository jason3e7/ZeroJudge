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

int prime[5000], point;

void primeTable() {
	int i, j, flag;
	prime[0] = 2;
	point = 1;
	for(i = 3; i * i < 10000002 ;i += 2) {
		flag = 1;
		for(j = 1; j < point; j++) {
			if(i % prime[j] == 0) {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			prime[point] = i;
			point++;
		}
	}
}

char pSum[10000002];

void pSumTable() {
	int i, j;
	for(i = 0; i < 10000002; i++) {
		pSum[i] = 0;
	}
	for(i = 2; i < 10000001; i++) {
		for(j = 0; i >= prime[j] && j < point; j++) {
			if(i % prime[j] == 0) {
				pSum[i] = pSum[i / prime[j]] + 1;
				break;
			}
		}
		if(pSum[i] == 0) {
			pSum[i] = 1;
		}
	}
}

int main() {
	primeTable();
	pSumTable();
	int n, i, sum, out, count = 1;
    while(scanf("%d", &n) != EOF) {
		if(n < 0) {
			break;
		}
		sum = 0, out = 0;
		for(i = 2; sum < n; i++) {
			sum += pSum[i];
			out = i;
		}
		if(sum == n) {
			printf("Case %d: %d!\n", count, out);
		} else {
			printf("Case %d: Not possible.\n", count);
		}
		count++;
	}
    return 0;
}

