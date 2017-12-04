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
	int b, p, m, i, base, output;
	while(scanf("%d %d %d", &b, &p, &m) != EOF) {
		if(b == 0 || m == 1) {
			printf("0\n");
			continue;
		}
		output = 1;
		base = b % p;
		for(i = 0; (1 << i) <= p; i++) {
			if (p & (1 << i)) {
				output = ((output % m) * (base % m) % m);
			}
			base = ((base % m) * (base % m) % m);
		}
		printf("%d\n", output);
	}
	return 0;
}
