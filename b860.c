 /*
  * @file b860.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710021158
  */

#include <stdio.h>
int main() {
	int c, w, out;
	while(scanf("%d %d", &c, &w) != EOF) {
		out = 0;
		while(1) {
			if(w == 0 || (w + c) < 13) {
				break;
			}
			if(c >= 12 && w >= 1) {
				c -= 10;
				w--;
				out++;
				continue;
			}
			if((w + c) >= 13) {
				w -= (12 - c);
				w--;
				c = 2;
				out++;
			}
		}
		printf("%d\n", out);
	}
	return 0;
}

