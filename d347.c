 /*
  * @file d347.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 847
  * @date 201711061023
  */

#include <stdio.h>

int main() {
	int flag;
	unsigned long int n, base;
	while(scanf("%ld", &n) != EOF) {
		base = 1;
		flag = 1;
		while(base < n) {
			if(flag == 1) {
				base *= 9;
				flag = 0;
			} else {
				base *= 2;
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("Stan wins.\n");
		} else {
			printf("Ollie wins.\n");
		}
	}
	return 0;
}

