 /*
  * @file c184.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802271030
  */

#include <stdio.h>
#include <math.h>

int sumFactors(int n) {
	int i, res = 1, s = (int)sqrt(n), temp;
	for(i = 2; i <= s; i++) {
		if(n % i == 0) {
			temp = n / i;
			res += i;
			if(i != temp) {
				res += temp;
			} 
		}
	}
	return res;
}

int main() {
	int n, m;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		m = sumFactors(n);
		if(n == m) {
			printf("=%d\n", n);
			continue;
		} 
		if(n == sumFactors(m)) {	
			printf("%d\n", m);
		} else {
			printf("0\n");
		}
	}
	return 0;
}
