 /*
  * @file b863.c
  * @author Jason3e7
  * @algorithm algorithm
  * @date 201710181119
  */

#include <stdio.h>

int main() {
	int t, length, i, j, out, temp;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &length);
			out = (length - 1) * 2;
			for(i = 0; i < length; i++) {
				scanf("%d", &temp);
				if(temp + i > out) {
					out = temp + i;
				}
			}
			printf("%d\n", out);
		}
	}
	return 0;
}



