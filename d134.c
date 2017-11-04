 /*
  * @file d134.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 369
  * @date 201711051039
  * @note Pascal's triangle !?
  */

#include <stdio.h>

unsigned long long int cal(int n, int m) {
	unsigned long long int sum = 1; 
	int mul[101] = {0};
	int diff = (n - m), i, j, temp;
	if(diff > m) {
		temp = diff;
		diff = m;
		m = temp;
	}
	for(i = m + 1; i <= n; i++) {
		temp = i;
		j = 2;
		while(temp != 1) {
			if(temp % j == 0) {
				mul[j]++;
				temp /= j;
			} else {
				j++;
			}
		}	
	}
	for(i = 2; i <= diff; i++) {
		temp = i;
		j = 2;
		while(temp != 1) {
			if(temp % j == 0) {
				mul[j]--;
				temp /= j;
			} else {
				j++;
			}
		}	
	}
	for(i = 2; i <= 100; i++) {
		while(mul[i]--) {
			sum *= i;
		}
	}
	return sum;
}

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		if(n == 0 && m == 0) {
			break;
		}
		printf("%d things taken %d at a time is %llu exactly.\n", n, m, cal(n, m));
	}
	return 0;
}

