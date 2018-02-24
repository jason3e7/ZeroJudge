 /*
  * @file c315.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802251138
  */

#include <stdio.h>

int main() {
	int n, x, y, a, b;
	while(scanf("%d", &n) != EOF) {
		x = 0, y = 0;
		while(n--) {
			scanf("%d %d", &a, &b);
			switch(a) {
				case 0 :
					y += b;
					break;
				case 1 :
					x += b; 
					break;
				case 2 : 
					y -= b;
					break;
				case 3 : 
					x -= b;
					break;
			}
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}
