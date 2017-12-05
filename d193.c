 /*
  * @file d193.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 11526
  * @date 201712061041
  */

#include <stdio.h>
#define max 2147483647

long long int H(int n) {
	long long int res = n;
	int buttom = 2, num, top;
	while(buttom <= n) {
		num = n / buttom;
		top = n / num;
		res += (top - buttom + 1) * num;
		if(top >= max) {
			break;
		}
		buttom = top + 1;
	}
	return res;
}

int main() {
	int t, n;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			if(n > 0) {
				printf("%llu\n", H(n));
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
