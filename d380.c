 /*
  * @file d380.c
  * @author Jason3e7
  * @algorithm bigint
  * @UVa 10106
  * @date 201712021051
  */

#include <stdio.h>
#include <string.h>
#define maxL 20000
#define maxD 4
#define modN 10000

typedef struct {
	int sign;
	int digit[maxL];
	int length;
}bigint;

bigint str2bint(char*);
void printBint(bigint);
bigint zeroBint();
bigint mul(bigint, bigint);
int powIi(int, int);

int main() {
	char a[300], b[300];
	while(scanf("%s %s", a, b) != EOF) {
		printBint(mul(str2bint(a), str2bint(b)));
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
	while(number[begin] == '0') {
		begin++;
	}	
	for(i = len - 1, j = 0; i >= begin; i--, j++) {
		if(j % maxD == 0 && j != 0) {
			r.length++;
		} 
		r.digit[r.length - 1] += ((number[i] - '0') * powIi(10, j % maxD));
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

int powIi(int a, int b) {
	int base = 1;
	while(b--) { 
		base *= a;
	}
	return base;
}
