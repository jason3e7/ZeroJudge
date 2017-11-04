 /*
  * @file d134.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 369
  * @date 201711051039
  */

#include <stdio.h>

unsigned long long int cal(int n, int m) {
	unsigned long long int sum = 1; 
	int mul[101] = {0};
	int div[101] = {0};
	int diff = (n - m), i, j, temp;
	if(diff > m) {
		temp = diff;
		diff = m;
		m = temp;
	}
	for(i = m + 1; i <= n; i++) {
		mul[i] = i;
	}
	for(i = 2; i <= diff; i++) {
		temp = i;
		j = 2;
		while(temp != 1) {
			if(temp % j == 0) {
				div[j]++;
				temp /= j;
			} else {
				j++;
			}
		}	
	}
	for(i = 2; i <= 100; i++) {
		while(div[i] != 0) {
			for(j = m + 1; j <= n; j++)  {
				if(mul[j] % i == 0) {
					mul[j] /= i;
					div[i]--;
					break;
				}
			}
		}
	}
	for(i = m + 1; i <= n; i++) {
		sum *= mul[i];
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

