 /*
  * @file b863.c
  * @author Jason3e7
  * @algorithm algorithm
  * @date 201710181119
  */

#include <stdio.h>

int main() {
	int t, length, i, j, out, durian[100001];
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &length);
			out = (length - 1) * 2;
			for(i = 0; i < length; i++) {
				scanf("%d", &durian[i]);
			}
			for(i = length - 1, j = length - 1; i >= 0; i--, j++) {
				if(durian[i] - j > 0) {
					out += (durian[i] - j);
					j += (durian[i] - j);
				}
			}
			printf("%d\n", out);
		}
	}
	return 0;
}



