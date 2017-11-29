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
int cmpBint(bigint, bigint);
int checkBintZero(bigint);
bigint add(bigint, bigint);
bigint sub(bigint, bigint);
bigint mul(bigint, bigint);
bigint mulInt(bigint, int);
bigint div(bigint, bigint);
bigint mod(bigint, bigint);
bigint powInt(bigint, int);
int powIi(int, int);
int getDigitLen(bigint);

int main() {
	bigint f[801], temp, c;
	int i, j, k;
	f[0] = zeroBint();
	f[1] = zeroBint();
	f[2] = int2bint(1);
	for(i = 3; i <= 100; i++) {
		temp = int2bint(1);
		for(j = 2; j <= i; j++) {
			temp = mulInt(temp, j);
		}
		c = int2bint(1);
		for(j = i; j >= 3; j--) {
			c = mulInt(c, j);
			c = div(c, int2bint(i - j + 1));
			temp = sub(temp, mul(c, f[j - 1]));
		}
		f[i] = sub(temp, int2bint(1));
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

int bint2int(bigint number) {
	int r = 0, i, base = 1;
	if(number.length == 1) {
		return number.digit[0];
	}
	for(i = 0; i < number.length; i++) {
		r += (number.digit[i] * base);
		base *= modN;
	}
	if(number.sign == 1) {
		r *= -1;
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

bigint subInt(bigint a, int b) {
	return sub(a, int2bint(b));
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

int getDigitLen(bigint num) {
	int temp = num.digit[num.length - 1], len = (num.length - 1) * maxD;
	if(temp == 0) {
		return 1;
	}
	while(temp != 0) {
		len++;
		temp /= 10;
	}
	return len;
}

bigint div(bigint a, bigint b) {
	if(checkBintZero(a) == 1 || cmpBint(a, b) == -1 || checkBintZero(b) == 1) {
		return zeroBint();
	}
	int maxDigit = getDigitLen(a) - getDigitLen(b) + 1;
	int digit[maxL] = {0}, point = maxDigit, i, sum;
	bigint ten = int2bint(10), base, temp;
	while(point--) {
		base = mul(b, powInt(ten, point));
		if(cmpBint(a, base) == -1) {
			continue;
		}
		for(i = 9; i >= 1; i--) {
			temp = mulInt(base, i);
			if(cmpBint(a, temp) >= 0) {
				a = sub(a, temp);
				digit[point] = i;
				break;
			}
		}
		if(checkBintZero(a) == 1) {
			break;
		}
	}
	temp = zeroBint();
	for(i = 0; i <= maxDigit; i++) {
		temp.digit[i / maxD] += (digit[i] * powIi(10, i % maxD));
	}	
	temp.length = (maxDigit / maxD) + 1;
	while(temp.digit[temp.length - 1] == 0) {
		temp.length--;
	}
	return temp;
}

bigint powInt(bigint a, int b) {
	bigint base = int2bint(1);
	while(b--) { 
		base = mul(base, a);
	}
	return base;
}

int powIi(int a, int b) {
	int base = 1;
	while(b--) { 
		base *= a;
	}
	return base;
}

