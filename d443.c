 /*
  * @file d443.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 10497
  * @date 201711291428
  * @note
f(n) = n! - C(n, 1) * f(n-1) - C(n, 2) * f(n-2) - ... - 1

f(3) = 6 - 3 * 1 - 1 = 2;
f(4) = 24 - 4 * 2 - 6 * 1 - 1 = 9;
  */

#include <stdio.h>

int main() {
	int n, f[11] = {0}, i, j, k, temp, c;
	f[0] = 0;
	f[1] = 0;
	f[2] = 1;
	for(i = 3; i <= 10; i++) {
		temp = 1;
		for(j = 2; j <= i; j++) {
			temp *= j;
		}
		c = 1;
		for(j = i; j >= 3; j--) {
			c *= j;
			c /= (i - j + 1);
			temp -= (c * f[j - 1]);
		}
		f[i] = temp - 1;
		printf("%d => %d\n", i, f[i]);
	}
	while(scanf("%d", &n) != EOF) {
		if(n == -1) {
			break;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}

