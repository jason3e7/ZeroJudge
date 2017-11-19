 /*
  * @file prime.c
  * @author Jason3e7
  * @algorithm math
  * @date 201711181505
  * @note 2147483647 is a prime
  * sieve of Eratosthenes
  * bitset 
  * n>>5 => n / 32
  * n&31 => n & 11111 => 0 ~ 31 => n % 32
  * n&1 => get end of bit
  *
  * bitset[n>>5] >>(n&31) &1
  * get (n / 32) memory >> (n % 32) &1
  *
  * bitset[n>>5] |= 1<<(x&31)
  * get (n / 32) memory |= (1 << (n % 32))
  */

#include <stdio.h>
#include <math.h>
#include <time.h>
#define max 2147483647

int bitset[(max>>5) + 1] = {0};

int  get(int n) { return bitset[n>>5]>>(n&31)&1; }
void set(int n) { bitset[n>>5] |= 1<<(n&31); }

void primeTable() {
	int i, j, temp = (max>>5)+1;
	for(i = 0; i < temp; i++) {
		bitset[i] = 0;
	}
	set(0);
	set(1);
	temp = (int)sqrt(max);
	for(i = 2; i <= max; i++) {
		if(i > temp) {
			break;
		}
		if(get(i) == 0) {
			for(j = i * i; j <= max; j += i) {
				set(j);
				if(i > max - j) {
					break;
				}
			}
		}
		if(i == max) {
			break;
		}
	}
}

int checkPrime(int n) {
	if(n < 0) {
		return -1;
	} else if(n <= 1) {
		return 0;
	}
	if(get(n) == 0) {
		return 1;
	} else {
		return 0;
	}
	if(n == 2 || n == 3) {
		return 1;
	}
	if(n % 2 == 0 || n % 3 == 0) {
		return 0;
	}
	int i, temp = (int)sqrt(n) + 1;
	for(i = 6; i <= temp; i += 6) {
		if(n % (i - 1) == 0 || n % (i + 1) == 0) {
			return 0;
		}
	}
	return 1;
}

void test() {
	clock_t begin = clock();
	primeTable();
	printf("0 = %d\n", checkPrime(1));
	printf("1 = %d\n", checkPrime(2));
	printf("1 = %d\n", checkPrime(3));
	printf("0 = %d\n", checkPrime(4));
	printf("1 = %d\n", checkPrime(5));
	printf("0 = %d\n", checkPrime(6));
	printf("1 = %d\n", checkPrime(7));
	printf("0 = %d\n", checkPrime(8));
	printf("0 = %d\n", checkPrime(9));
	printf("1 = %d\n", checkPrime(11));
	printf("0 = %d\n", checkPrime(121));
	printf("1 = %d\n", checkPrime(65537));
	printf("1 = %d\n", checkPrime(524287));
	printf("0 = %d\n", checkPrime(994009));
	printf("1 = %d\n", checkPrime(2147483647));
	int i;
	for(i = 2147483647; i >= 2147000000; i--) {
		checkPrime(i);
	}
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


