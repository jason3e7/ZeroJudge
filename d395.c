 /*
  * @file d395.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 10519
  * @date 201711301035
  * @note draw a big circle, move circle
  * 0 => 1
  * 1 => 2
  * 2 => 2 + (2 - 1) * 2 = 4
  * 3 => 4 + (3 - 1) * 2 = 8
  *
  * f(0) = 1
  * f(n) = f(n - 1) + (n - 1) * 2
  * 
  * f(1) - f(0) = 1
  * f(2) - f(1) = 2
  * f(3) - f(2) = 4
  * f(4) - f(3) = 6
  * f(5) - f(4) = 8
  * ...
  * f(n) - f(n - 1) = (n - 1) * 2           
  * =============================
  * f(n) - f(0) = 1 + (1 + 2 + 3 + 4 ... + n - 1) * 2
  * f(n) = (((n - 1) + 1) * (n - 1)) / 2 * 2 + 1 + f(0)
  * f(n) = n * n - n + 2
  */

#include <stdio.h>
#include <string.h>
#define maxL 500
#define maxD 4
#define modN 10000

typedef struct {
	int sign;
	int digit[maxL];
	int length;
}bigint;

bigint str2bint(char*);
bigint int2bint(int);
void printBint(bigint);
bigint zeroBint();
int cmpBint(bigint, bigint);
int checkBintZero(bigint);
bigint add(bigint, bigint);
bigint sub(bigint, bigint);
bigint mul(bigint, bigint);
bigint mulInt(bigint, int);
int powIi(int, int);

int main() {
	char line[105];
	bigint n;
	while(scanf("%s", line) != EOF) {
		n = str2bint(line);
		if(checkBintZero(n) == 1) {
			printf("1\n");
			continue;
		}
		n = add(sub(mul(n, n), n), int2bint(2));
		printBint(n);
	}
	return 0;
}

bigint str2bint(char* number) {
	bigint r = zeroBint();
	int begin = 0;
	if(number[begin] == '-') {
		r.sign = 1;
		begin++;
	}
	int i, j, len = strlen(number);
	for(i = len - 1, j = 0; i >= begin; i--, j++) {
		if(j % maxD == 0 && j != 0) {
			r.length++;
		} 
		r.digit[r.length - 1] += ((number[i] - '0') * powIi(10, j % maxD));
	}
	return r;
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

int checkBintZero(bigint num) {
	if(num.length == 1 && num.digit[0] == 0 && num.sign == 0) {
		return 1;
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

bigint mul(bigint a, bigint b) {
	bigint sum = zeroBint();
	if((a.length == 1 && a.digit[0] == 0) || (b.length == 1 && b.digit[0] == 0)) {
		return sum;
	}
	if(a.length == 1 && a.digit[0] == 1) {
		return b;
	}
	if(b.length == 1 && b.digit[0] == 1) {
		return a;
	}
	int i, j, temp;
	for(i = 0; i < a.length; i++) {
		for(j = 0; j < b.length; j++) {
			sum.digit[i + j] += a.digit[i] * b.digit[j];
			temp = sum.digit[i + j] / modN;
			if(temp >= 1) {
				sum.digit[i + j + 1] += temp;
				sum.digit[i + j] %= modN;
			}
		}
	}
	sum.length = a.length + b.length - 1;	
	if(sum.digit[sum.length] != 0) {
		sum.length++;
	}
	return sum;
}

bigint mulInt(bigint a, int b) {
	return mul(a, int2bint(b));
}

int powIi(int a, int b) {
	int base = 1;
	while(b--) { 
		base *= a;
	}
	return base;
}
