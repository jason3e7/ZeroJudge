 /*
  * @file d193.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 11526
  * @date 201712061041
  */

#include <stdio.h>

long long int H(int n) {
	long long int res = 0;
	int i;
	for(i = 1; i <= n; i++ ){
		res += (n / i);
	}
	return res;
}

int main() {
	int t, n;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			printf("%llu\n", H(n));
		}
	}
	return 0;
}
