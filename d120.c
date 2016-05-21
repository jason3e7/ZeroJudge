/*
 * @file d120.c
 * @author Jason3e7
 * @date 201605211120
 */

#include <stdio.h>

int main() {
	int n, m, i;
	while(scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		m = n;
		int count = 0, top = n / 2;
		for (i = 2; i <= top; i++) {
			if (n % i == 0) {
				count++;
				while (n % i == 0) 
					n /= i;
			}
			if (n == 1)
				break;
			if (i > 2)
				i++;
		}
		if (count == 0)
			count++;
		printf("%d : %d\n", m, count);	
	}
	return 0;
}

