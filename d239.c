 /*
  * @file d239.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711221640
  * @note 134043 
  */

#include <stdio.h>
#include <math.h>
#define max 200000

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
	int i, j, num[max] = {0}, temp;
	for(i = 2; i < max; i++) {
		if(get(i) == 0) {
			j = 1;
			temp = i * j;
			while(temp < max) {
				num[temp]++;
				j++;
				temp = i * j;
			}
		}		
		if(i > 2) {
			i++;
		}
	}
	for(i = 2; i < max; i++) {
		if(num[i] == 4 && num[i + 1] == 4 && num[i + 2] == 4 && num[i + 3] == 4) {
			printf("%d\n", i);
		}
	}
	return 0;
}

