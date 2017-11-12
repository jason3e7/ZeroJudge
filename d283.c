 /*
  * @file d283.c
  * @author Jason3e7
  * @algorithm matrix, fast power, bigint
  * @date 201711111023
  */ 
 
#include <stdio.h>

#define maxL 2000
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
bigint add(bigint, bigint);
bigint mul(bigint, bigint);

bigint matrixFastPowxer(int n) {
	bigint base[2][2] = {{int2bint(1), int2bint(1)}, {int2bint(1), zeroBint()}}, r[2][2], temp[2][2]; 
	int firstFlag = 1;
	while(n != 0) {
		if(n % 2 == 1) {
			if(firstFlag == 1) {
				r[0][0] = base[0][0];
				r[0][1] = base[0][1];
				r[1][0] = base[1][0];
				r[1][1] = base[1][1];
				firstFlag = 0;
			} else {
				temp[0][0] = add(mul(r[0][0], base[0][0]), mul(r[0][1], base[1][0]));
				temp[0][1] = add(mul(r[0][0], base[0][1]), mul(r[0][1], base[1][1]));
				temp[1][0] = add(mul(r[1][0], base[0][0]), mul(r[1][1], base[1][0]));
				temp[1][1] = add(mul(r[1][0], base[0][1]), mul(r[1][1], base[1][1]));
				r[0][0] = temp[0][0];
				r[0][1] = temp[0][1];
				r[1][0] = temp[1][0];
				r[1][1] = temp[1][1];
			}
		}
		temp[0][0] = add(mul(base[0][0], base[0][0]), mul(base[0][1], base[1][0]));
		temp[0][1] = add(mul(base[0][0], base[0][1]), mul(base[0][1], base[1][1]));
		temp[1][0] = add(mul(base[1][0], base[0][0]), mul(base[1][1], base[1][0]));
		temp[1][1] = add(mul(base[1][0], base[0][1]), mul(base[1][1], base[1][1]));
		base[0][0] = temp[0][0];
		base[0][1] = temp[0][1];
		base[1][0] = temp[1][0];
		base[1][1] = temp[1][1];
		n /= 2;
	}
	return r[0][0];
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {	
		if(n == 0) {
			printf("0\n");
			continue;
		}
		if(n == 1) {
			printf("1\n");
			continue;
		}
		printBint(matrixFastPowxer(n - 1));
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
