 /*
  * @file d280.c
  * @author Jason3e7
  * @algorithm math, DP
  * @date 201711111055
  * @note very hate no description about "parameter boundary problem"
  */

#include <stdio.h>
#define maxL 10
#define maxD 4
#define modN 10000

typedef struct {
	int sign;
	int digit[maxL];
	int length;
}bigint;

bigint int2bint(int);
void printBint(bigint);
bigint zeroBint();
int cmpBint(bigint, bigint);
bigint add(bigint, bigint);
bigint addInt(bigint, int);
bigint sub(bigint, bigint);
bigint subInt(bigint, int);

bigint r[21][121];
bigint minusOne;

bigint getComb(int n, int m) {
	bigint sum = zeroBint();
	if(m > n * 6 || n * 1 > m) {
		return sum;
	}
	if(cmpBint(r[n][m], minusOne) != 0) {
		return r[n][m];
	}
	if(n == 1) {
		return addInt(sum, 1);
	}
	int i;
	for(i = 1; i <= 6; i++) {
		sum = add(sum, getComb(n - 1, m - i));
	}
	r[n][m] = sum;
	return sum;
}

void test() {
	printf("getComb\n");
	printf("1 = ");
	printBint(getComb(1, 1));
	printf("1 = ");
	printBint(getComb(1, 6));
	printf("1 = ");
	printBint(getComb(2, 2));
	printf("1 = ");
	printBint(getComb(2, 12));
	printf("2 = ");
	printBint(getComb(2, 3));
	
	printf("10 = ");
	printBint(getComb(3, 15));
	printf("6 = ");
	printBint(getComb(3, 16));
	printf("1 = ");
	printBint(getComb(3, 18));
	
	printf("187890345960720 = ");
	printBint(getComb(20, 69));
	printf("189456975899496 = ");
	printBint(getComb(20, 70));
	printf("187890345960720 = ");
	printBint(getComb(20, 71));
	
	printf("32312202610863 = ");
	printBint(getComb(19, 66));
	printf("32312202610863 = ");
	printBint(getComb(19, 67));
	printf("31753113097485 = ");
	printBint(getComb(19, 68));
}

int main() {
	int i, j;
	minusOne = subInt(zeroBint(), 1);
	for(i = 0; i < 21; i++) {
		for(j = 0; j < 121; j++) {
			r[i][j] = minusOne;
		}
	}
	test();
	int k, n, m;
	while(scanf("%d", &k) != EOF) {
		while(k--) {
			scanf("%d %d", &n, &m);
			if(n <= 0 || n > 20 || n > m || m * 6 < n) {
				break;
			}
			printBint(getComb(n, m));
		}			
	}
	return 0;
}

bigint int2bint(int number) {
	bigint r = zeroBint();
	if(number == 0) {
		return r;
	}
	if(number < 0) {
		r.sign = 1;
		number *= -1;
	}
	r.length = 0;
	while(number != 0) {
		r.digit[r.length] = number % modN;	
		number /= modN;
		r.length++;	
	}
	return r;
}

void printBint(bigint num) {
	int i;
	if(num.sign == 1) {
		printf("-");
	}
	printf("%d", num.digit[num.length - 1]); 
	for(i = num.length - 2; i >= 0; i--) {
		printf("%04d", num.digit[i]); 
	}
	printf("\n");
}

bigint zeroBint() {
	bigint temp;
	int i;
	for(i = 0; i < maxL; i++) {
		temp.digit[i] = 0;
	}
	temp.sign = 0;
	temp.length = 1;
	return temp;
}

int cmpBint(bigint a, bigint b) {
	int i, flag = 1;
	if(a.sign != b.sign) {
		return a.sign - b.sign;
	} else {
		if(a.sign == 1 && b.sign == 1) {
			flag = -1;
		}
		if(a.length > b.length) {
			return 1 * flag;
		}
		if(a.length < b.length) {
			return -1 * flag;
		}
		for(i = a.length - 1; i >= 0; i--) {
			if(a.digit[i] > b.digit[i]) {
				return 1 * flag;
			}
			if(a.digit[i] < b.digit[i]) {
				return -1 * flag;
			}
		}
	}
	return 0;
}

bigint add(bigint a, bigint b) {
	int i, maxLen = a.length;
	if(a.length < b.length) {
		maxLen = b.length; 	
	}
	for(i = 0; i < maxLen; i++) {
		if(i < b.length) {
			a.digit[i] += b.digit[i];
		}
		if(a.digit[i] >= modN) {
			a.digit[i + 1]++;
			a.digit[i] -= modN;
		}	
	}
	if(a.digit[maxLen] != 0) {
		maxLen++;
	}	
	a.length = maxLen;
	return a;
}

bigint addInt(bigint a, int b) {
	return add(a, int2bint(b));
}

bigint sub(bigint a, bigint b) {
	int cmp = cmpBint(a, b), i;
	bigint swap;
	if (cmp == 0) {
		return zeroBint();
	}
	if (cmp == -1) {
		swap = a;
		a = b;
		b = swap;
		
		a.sign = 1;
	}
	for(i = 0; i < a.length; i++) {
		if(i < b.length) {
			a.digit[i] -= b.digit[i];
		}
		if(0 > a.digit[i]) {
			a.digit[i] += modN;
			a.digit[i + 1]--;
		}
	}
	while(a.digit[a.length - 1] == 0) {
		a.length--;
	}
	return a;
}

bigint subInt(bigint a, int b) {
	return sub(a, int2bint(b));
}
