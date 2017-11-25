 /*
  * @file d441.c
  * @author Jason3e7
  * @algorithm prime
  * @UVa 10780
  * @date 201711251027
  * @note 3 27
  * 27 / 3  = 9
  * 27 / 9  = 3
  * 27 / 27 = 1
  * 9 + 3 + 1 = 14
  * UVa WA at while !?
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
	int t, n, m, i, count, temp, minT, baseT, divT;
	count = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		minT = max;
		i = 2; 
		while(i <= m) {
			baseT = 0;
			divT = 0;
			if(get(i) == 0) {
				temp = m;
				while(temp % i == 0) {
					temp /= i;
					baseT++;
				}
					
				if(baseT > 0) {
					temp = i;
					while(n >= temp) {
						divT += (n / temp);
						temp *= i;
					}
				
					temp = divT / baseT;
					if(minT > temp) {
						minT = temp;
					}
				}
			}	

			if(i == 2) {
				i++;
			} else {
				i += 2;
			}
		}	
		if(minT == 0) {
			printf("Case %d:\nImpossible to divide\n", count);
		} else {
			printf("Case %d:\n%d\n", count, minT);
		}
		count++;	
	}
	return 0;
}

