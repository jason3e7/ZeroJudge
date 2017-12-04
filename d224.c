 /*
  * @file d224.c
  * @author Jason3e7
  * @algorithm math
  * @UVa 11296
  * @date 201712041001
  * @note x + 2 * (y + z) = n

0 1 2

2 0
1 1
0 2

1 0
0 1

0 0

  */

#include <stdio.h>

int main() {
	unsigned long long int n, yz;
	while(scanf("%llu", &n) != EOF) {
		yz = n / 2;
		if(yz == 0) {
			printf("1\n");
			continue;
		}
		yz++;
		if(yz % 2 == 1) {
			printf("%llu\n", ((yz + 1) / 2) * yz);		
		} else {
			printf("%llu\n", (yz + 1) * (yz / 2));		
		}
	}
	return 0;
}
