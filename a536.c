 /*
  * @file a536.c
  * @author Jason3e7
  * @algorithm basic 
  * @UVa 11689
  * @date 201710281313
  */

#include <stdio.h>

int main() {
	int n, count, e, f, c, temp;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			count = 0;
			scanf("%d %d %d", &e, &f, &c);
			e += f;
			f = 0;
			while(e / c) {
				count += e / c;
				e = (e / c) + (e % c);
			}
			printf("%d\n", count);
		}
	}
	return 0;
}

