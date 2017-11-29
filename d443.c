 /*
  * @file d443.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 10497
  * @date 201711291428
  * @note
f(n) = n! - C(n, 1) * f(n-1) - C(n, 2) * f(n-2) - ... - 1

f(3) = 6 - 3 * 1 - 1 = 2;
f(4) = 24 - 4 * 2 - 6 * 1 - 1 = 9;
 
==========
f[n] = (n-1) * f[n-1] + (n-1) * f[n-2]
f[n] = (n-1) * (f[n-1] + f[n-2])
n - 1 => first choice 
f[n - 2] => if second choice is first location, possible set.
f[n - 1] => if second choice is not first location, possible set.

f[2] = 1;
   
2xxx       1xx    3xx 4xx  
3xxx  * (  x1x +  x2x x4x  )
4xxx       xx1    xx2 xx3

  */

#include <stdio.h>
#include <string.h>
#define maxL 1000
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
bigint mulInt(bigint, int);

int main() {
	bigint f[801], temp, c;
	int i, j, k;
	f[0] = zeroBint();
	f[1] = zeroBint();
	f[2] = int2bint(1);
	for(i = 3; i <= 800; i++) {
		f[i] = mulInt(add(f[i - 1], f[i - 2]), i - 1);
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == -1) {
			break;
		}
		printBint(f[n]);
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

bigint mulInt(bigint a, int b) {
	return mul(a, int2bint(b));
}
