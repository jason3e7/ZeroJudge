 /*
  * @file a993.c
  * @author Jason3e7
  * @algorithm math
  * @UVa 10127
  * @date 201802190909
  * @note 
  * n * x = 111...
  * 111... / n = x
  */

#include <stdio.h>

int main() {
	int n, digit, r;
	while(scanf("%d", &n) != EOF) {
		r = 1;
		digit = 1;
		while((r %= n) != 0) {
			r = r * 10 + 1;
			digit++;
		}
		printf("%d\n", digit);
	}
	return 0;
}
