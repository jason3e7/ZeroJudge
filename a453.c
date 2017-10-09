 /*
  * @file a453.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710101054
  */

#include <stdio.h>
#include <math.h>
int main() {
	int n, a, b, c, d;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d %d %d", &a, &b, &c);
			d = b * b - 4 * a * c;
			if(d >= 0 && (int)sqrt(d)*(int)sqrt(d) == d) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}

