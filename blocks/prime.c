 /*
  * @file prime.c
  * @author Jason3e7
  * @algorithm math
  * @date 201711181505
  * @note 2147483647 is a prime
  */

#include <stdio.h>
#include <time.h>

int checkPrime(int n) {
	if(n < 0) {
		return -1;
	} else if(n <= 1) {
		return 0;
	}
	int i;
	for(i = 2; i < n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void test() {
	clock_t begin = clock();
	printf("0 = %d\n", checkPrime(1));
	printf("1 = %d\n", checkPrime(2));
	printf("1 = %d\n", checkPrime(3));
	printf("0 = %d\n", checkPrime(4));
	printf("1 = %d\n", checkPrime(5));
	printf("1 = %d\n", checkPrime(11));
	printf("1 = %d\n", checkPrime(2147483647));
	clock_t end = clock();
	printf("time:%lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

int main() {
	test();
	int n;
	while(scanf("%d", &n) != EOF) {
		if(checkPrime(n) == 1) {
			printf("prime\n");
		} else {
			printf("not prime\n");
		} 
	}
	return 0;
}

