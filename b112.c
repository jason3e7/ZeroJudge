 /*
  * @file b112.c
  * @author Jason3e7
  * @algorithm GCD
  * @date 201712311121
  */

#include <stdio.h>

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int main() {
	int n, out, temp;
	while(scanf("%d", &n) != EOF) {
		out = 0;
		while(n--) {
			scanf("%d", &temp);
			if(out == 0) {
				out = temp;
			} else {
				out = GCD(out, temp);
			}
		}
		printf("%d\n", out);
	}
	return 0;
}

