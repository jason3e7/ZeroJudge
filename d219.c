 /*
  * @file d219.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 374
  * @date 201712051026
  * @note (a * b) mod c => ((a mod c) * (b mod c)) mod c
  * fast power
  */

#include <stdio.h>

int main() {
	int b, p, m, i, base, r;
	while(scanf("%d %d %d", &b, &p, &m) != EOF) {
		if(b == 0 || m == 1) {
			printf("0\n");
			continue;
		}
		r = 1;
		base = b % m;
		while(p != 0) {
			if (p % 2 == 1) {
				r = ((r % m) * (base % m) % m);
			}
			p /= 2;
			base = ((base % m) * (base % m) % m);
		}
		printf("%d\n", r);
	}
	return 0;
}
