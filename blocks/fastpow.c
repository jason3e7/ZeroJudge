 /*
  * @file fastpow.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710261421
  */

#include <stdio.h>

int main() {
	int x, n, point, bit[32], i, out;
	while(scanf("%d %d", &x, &n) != EOF) {
		point = 0;
		do {
			bit[point] = n%2;
			point++;
		} while(n/=2);
		out = 1;
		for(i = 0; i < point; i++) {
			if(bit[i] == 1) {
				out *= x;
			}
			x = x * x;
		}
		printf("%d\n", out);
	}
	return 0;
}

