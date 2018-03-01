 /*
  * @file c304.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803021011
  */

#include <stdio.h>

int main() {
	unsigned long long n, a, b;
	while(scanf("%lld", &n) != EOF) {
		a = n, b = 0;
		while(a != 0) {
			b *= 10;
			b += (a % 10);
			a /= 10;
		}
		printf("%lld\n", b + n);
	}
	return 0;
}
