 /*
  * @file d441.c
  * @author Jason3e7
  * @algorithm prime
  * @UVa 10780
  * @date 201711251027
  */

#include <stdio.h>
#include <math.h>
#define max 10000

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
	int t, n, m, i, min, count, base, temp;
	int up[5000], down[5000];
	while(scanf("%d", &t) != EOF) {
		count = 1;
		while(t--) {
			scanf("%d %d", &m, &n);
			for(i = 0; i < 5000; i++) {
				up[i] = 0;
				down[i] = 0;
			}			
			base = 2;
			while(m > 1) {
				if(get(base) == 0) {
					while(m % base == 0) {
						m /= base;
						down[base]++;
					}
				}			
				if(base == 2) {
					base++;
				} else {
					base+=2;
				}
			}
			for(i = 2; i <= n; i++) {
				if(i >= 5000 && get(i) == 0) {
					continue;
				}
				temp = i;
				base = 2;
				while(temp > 1) {
					if(get(base) == 0) {
						while(temp % base == 0) {
							temp /= base;
							up[base]++;
						}
					}			
					if(base == 2) {
						base++;
					} else {
						base+=2;
					}
				}
			}	
			/*
			for(i = 2; i < 5000; i++) {
				if(down[i] != 0) {
					printf("%d %d\n", i, down[i]);
				}
			}
			for(i = 2; i < 5000; i++) {
				if(up[i] != 0) {
					printf("%d %d\n", i, up[i]);
				}
			}
			*/	
			min = 10000;
			for(i = 2; i < 5000; i++) {
				if(down[i] != 0) {
					temp = up[i] / down[i];
					if(min > temp) {
						min = temp;
					}
				}
				if(min == 0) {
					break;
				}
			}
			if(min == 0) {
				printf("Case %d:\nImpossible to divide\n", count);
			} else {
				printf("Case %d:\n%d\n", count, min);
			}
			count++;
		}
	}
	return 0;
}

