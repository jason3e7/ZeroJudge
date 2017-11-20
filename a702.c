 /*
  * @file a702.c
  * @author Jason3e7
  * @algorithm prime
  * @date 201711211129
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
	int out[100000], i, temp = max - 4, point = 0;
	for(i = 3; i <= temp; i += 2) {
		if(get(i) == 0 && get(i + 4) == 0) {
			out[point] = i;
			point++;
		}
		if(point >= 100000) {
			break;
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("(%d, %d)\n", out[n - 1], out[n - 1] + 4);
	}
	return 0;
}

