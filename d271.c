 /*
  * @file d271.c
  * @author Jason3e7
  * @algorithm matrix, fast power, math
  * @UVa 11582
  * @date 201711131029
  * @note a451.c very interesting 
2 ^ 64 = 18446744073709551616
% n => n ^ 2 repeat

loop 100 so mod 100
f((2002 ^ 2) % 100) => f((2002 % 100) ^ 2)
  */ 
 
#include <stdio.h>

int fastPower(int n, unsigned long long int b, int m) {
	int r = 1; 
	while(b != 0) {
		if(b % 2 == 1) {
			r = (r * n) % m;
		}
		n = (n * n) % m;
		b /= 2;
	}
	return r;
}

int main() {
	int t, n, f[1000001], loop, i, locator; 
	unsigned long long int a, b;
	while(scanf("%d", &t) != EOF) {	
		while(t--) {
			scanf("%llu %llu %d", &a, &b, &n);
			if(n == 1 ||a == 0) {
				printf("0\n");
				continue;
			}
			if(a == 1 || b == 0) {
				printf("1\n");
				continue;
			}
			f[0] = 0;
			f[1] = 1;
			loop = 2;
			for(i = 2; i < 1000001; i++) {
				f[i] = (f[i - 1] + f[i - 2]) % n;
				if(f[i] == f[1] && f[i - 1] == f[0]) {
					loop = i - 1;
					break;
				}
			}
			locator = fastPower(a % loop, b, loop);
			printf("%d\n", f[locator]);
		}
	}
	return 0;
}

