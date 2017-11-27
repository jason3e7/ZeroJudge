 /*
  * @file b587.c
  * @author Jason3e7
  * @algorithm DP
  * @UVa 10918
  * @date 201711280957
  * @note

****   AA**   AA**   A***
**** = BB** + B*** + A***
****   CC**   B***   BB**

  f(n)   =  f(n-2)   +  g(n-1)  +  g(n-1)

***   A**   AA*
*** = A** + BB*
 **    **    CC

  g(n)   =   f(n-1)  +   g(n-2)

  */

#include <stdio.h>

int main() {
	int n, f[31] = {0}, g[31] = {0}, i;
	f[2] = 3;
	g[1] = 1;
	for(i = 3; i <= 30; i++) {
		if(i % 2 == 1) {
			g[i] = f[i - 1] + g[i - 2];
		} else {
			f[i] = f[i - 2] + (g[i - 1] * 2);
		}
	}
	while(scanf("%d", &n) != EOF) {
		if(n == -1) {
			break;
		}
		if(n == 0) {
			printf("1\n");
		} else if (n % 2 == 1) {
			printf("0\n");
		} else {
			printf("%d\n", f[n]);
		}
	}
	return 0;
}

