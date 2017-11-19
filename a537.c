 /*
  * @file a537.c
  * @author Jason3e7
  * @algorithm prime
  * @UVa 10789
  * @date 201711201046
  * @note '0' => 48, 'z' => 122
  */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 2000

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
	char line[2000];
	int sum[75];
	int n, i, len, count, flag;
	while(scanf("%d", &n) != EOF) {
		count = 1;
		while(n--) {
			flag = 0;
			for(i = 0; i < 75; i++) {
				sum[i] = 0;
			}
			scanf("%s", line);
			len = strlen(line);
			for(i = 0; i < len; i++) {
				sum[line[i] - '0']++;
			}
			printf("Case %d: ", count);
			for(i = 0; i < 75; i++) {
				if(get(sum[i]) == 0) {
					printf("%c", i + '0');
					flag = 1;
				}
			}
			if(flag == 0) {
				printf("empty");
			}
			printf("\n");
			count++;
		}
	}
	return 0;
}

