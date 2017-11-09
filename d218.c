 /*
  * @file d218.c
  * @author Jason3e7
  * @algorithm big number
  * @date 201711091432
  */
  
#include <stdio.h>
#include <time.h>
#define maxL 1000
#define maxD 4
#define modN 10000

typedef struct {
	int sign;
	int digit[maxL];
	int length;
}bigint;

bigint int2bigint(int);
void print(bigint);
bigint zero();
bigint plus(bigint, bigint);
bigint mul(bigint, bigint);

int main() {
	int i, n;
	bigint sum, base, temp;
	sum = zero();	
	for(i = 1; i <= 1000; i++) {
		n = i;
		base = int2bigint(i);
		temp = int2bigint(1);
		while(n--) {
			temp = mul(base, temp);
		}
		sum = plus(sum, temp);
	}
	print(sum);
	return 0;
}

bigint int2bigint(int number) {
	bigint r = zero();
	if(number == 0) {
		return r;
	}
	if(number > 0) {
		r.sign = 0;
	} else {
		r.sign = 1;
	}
	r.length = 0;
	while(number != 0) {
		r.digit[r.length] = number % modN;	
		number /= modN;
		r.length++;	
	}
	return r;
}

void print(bigint num) {
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

bigint zero() {
	bigint temp;
	int i;
	for(i = 0; i < maxL; i++) {
		temp.digit[i] = 0;
	}
	temp.sign = 0;
	temp.length = 1;
	return temp;
}

bigint plus(bigint a, bigint b) {
	int maxLen, i;
	if(a.length > b.length) {
		maxLen = a.length; 	
	} else {
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
	bigint sum = zero();
	if((a.length == 1 && a.digit[0] == 0) || (b.length == 1 && b.digit[0] == 0)) {
		return sum;
	}
	int i, j;
	for(i = 0; i < a.length; i++) {
		for(j = 0; j < b.length; j++) {
			sum.digit[i + j] += a.digit[i] * b.digit[j];
		}
	}
	sum.length = a.length + b.length - 1;	
	for(i = 0; i < sum.length; i++) {
		if(sum.digit[i] / modN >= 1) {
			sum.digit[i + 1] += (sum.digit[i] / modN);
		}
		sum.digit[i] %= modN;
	}
	if(sum.digit[sum.length] != 0) {
		sum.length++;
	}
	return sum;
}

