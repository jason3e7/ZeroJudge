 /*
  * @file c222.c
  * @author Jason3e7
  * @algorithm logic
  * @UVa 10469
  * @date 201709271037
  */

#include <stdio.h>
int main() {
	unsigned int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a ^ b);
	}
	return 0;
}
