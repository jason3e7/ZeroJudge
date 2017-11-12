 /*
  * @file bigNumberWithString.c
  * @author Jason3e7
  * @algorithm big number
  * @date 201711071428
  * @note only positive integer no negative
  * @test case
= + =
0 + 0
1 + 0
0 + 1
1 + 1
1 + 99
99 + 1

= - =
0 - 0
0 - 1
1 - 0
1 - 1
100 - 1
1 - 100

= * =
0 * 0
0 * 1
1 * 0
1 * 1
2 * 5
5 * 2

= / =
0 / 0
0 / 1
1 / 0
1 / 1
2 / 5
5 / 2

= % =
0 % 0
0 % 1
1 % 0
1 % 1
2 % 5
5 % 2
  */

#include <stdio.h>
#include <string.h>
#define maxLength 10001

typedef struct {
	char sign;
	char digit[maxLength];
	int length;
}bigNumber;

bigNumber int2bigNumber(int);
bigNumber str2bigNumber(char*);
void print(bigNumber);
int compare(bigNumber, bigNumber);
bigNumber zero();
bigNumber plus(bigNumber, bigNumber);
bigNumber minus(bigNumber, bigNumber);
bigNumber mul(bigNumber, bigNumber);
bigNumber div(bigNumber, bigNumber);
bigNumber mod(bigNumber, bigNumber);
bigNumber arithmetic(bigNumber, bigNumber, char);

int main() {
	char a[maxLength], operator, c[maxLength];
	int b;
	while(scanf("%s %c %s", a, &operator, c) != EOF) {
		bigNumber aNum = str2bigNumber(a);
		bigNumber bNum = str2bigNumber(c);
		print(arithmetic(aNum, bNum, operator));
	}
	return 0;
}

char* strrev(char* str)  {  
    char* begin = str;      
    char* end = str + strlen(str) - 1;  
    char swap;  
  
    while(begin < end) {
        swap = *begin;  
        *begin++ = *end;
        *end-- = swap;
    }   
    return(str);  
}  

bigNumber int2bigNumber(int number) {
	bigNumber r;
	if(number == 0) {
		return zero();
	}
	if(number >= 0) {
		r.sign = '+';
	} else {
		r.sign = '-';
	}
	r.length = 0;
	while(number != 0) {
		r.digit[r.length] = ('0' + number % 10);	
		number /= 10;
		r.length++;	
	}
	return r;
}

bigNumber str2bigNumber(char* number) {
	bigNumber r;
	strcpy(r.digit, strrev(number));
	r.length = strlen(r.digit);
	if(r.digit[r.length - 1] == '-') {
		r.sign = '-';
		r.digit[r.length - 1] = '\0';
	} else {
		r.sign = '+';
	}
	return r;
}

void print(bigNumber num) {
	if(num.sign == '-') {
		printf("-");
	}
	printf("%s ", strrev(num.digit));
	printf("length : %d\n", num.length);
}

int compare(bigNumber a, bigNumber b) {
	int i;
	if(a.sign == '+' && b.sign == '-') {
		return 1;
	} else if(a.sign == '-' && b.sign == '+') {
		return -1;
	} else if(a.sign == '+' && b.sign == '+') {
		if(a.length > b.length) {
			return 1;
		}
		if(a.length < b.length) {
			return -1;
		}
		for(i = a.length - 1; i >= 0; i--) {
			if(a.digit[i] > b.digit[i]) {
				return 1;
			}
			if(a.digit[i] < b.digit[i]) {
				return -1;
			}
		}
	} else {
		if(a.length < b.length) {
			return 1;
		}
		if(a.length > b.length) {
			return -1;
		}
		for(i = a.length - 1; i >= 0; i--) {
			if(a.digit[i] < b.digit[i]) {
				return 1;
			}
			if(a.digit[i] > b.digit[i]) {
				return -1;
			}
		}
	}
	return 0;
}

bigNumber zero() {
	bigNumber temp = {'+', "0", 1};
	return temp;
}

bigNumber plus(bigNumber a, bigNumber b) {
	int maxLen, i;
	if(a.length > b.length) {
		maxLen = a.length; 	
	} else {
		maxLen = b.length; 
	}
	for(i = 0; i < maxLen; i++) {
		if('0' > b.digit[i] || b.digit[i] > '9') {
			break;
		}
		if('0' <= a.digit[i] && a.digit[i] <= '9') {
			a.digit[i] += (b.digit[i] - '0');
		} else {
			a.digit[i] = b.digit[i];
		}
	}
	for(i = 0; i < maxLen - 1; i++) {
		if(a.digit[i] > '9') {
			a.digit[i] -= 10;
			a.digit[i + 1]++;
		}
	}
	a.length = maxLen;	
	if(a.digit[maxLen - 1] > '9') {
		a.digit[maxLen - 1] -= 10;
		a.digit[maxLen] = '1';
		a.digit[maxLen + 1] = '\0';
		a.length++;
	}
	return a;
}

bigNumber minus(bigNumber a, bigNumber b) {
	int cmp = compare(a, b), i;
	if (cmp == 1) {
		for(i = 0; i < a.length; i++) {
			if(i < b.length) {
				a.digit[i] -= (b.digit[i] - '0');
			}
			if('0' > a.digit[i]) {
				a.digit[i] += 10;
				a.digit[i + 1]--;
			}
		}
		while(a.digit[a.length - 1] == '0') {
			a.digit[a.length - 1] = '\0';
			a.length--;
		}
		return a;
	} else if (cmp == -1) {
		for(i = 0; i < b.length; i++) {
			if(i < a.length) {
				b.digit[i] -= (a.digit[i] - '0');
			}
			if('0' > b.digit[i]) {
				b.digit[i] += 10;
				b.digit[i + 1]--;
			}
		}
		while(b.digit[b.length - 1] == '0') {
			b.digit[b.length - 1] = '\0';
			b.length--;
		}
		b.sign = '-';
		return b;
	}
	a = zero();
	return a;
}

bigNumber mul(bigNumber a, bigNumber b) {
	if((a.length == 1 && a.digit[0] == '0') || (b.length == 1 && b.digit[0] == '0')) {
		return zero();	
	}
	int i, j, sum[maxLength] = {0};
	for(i = 0; i < a.length; i++) {
		for(j = 0; j < b.length; j++) {
			sum[i + j] += (a.digit[i] - '0') * (b.digit[j] - '0');
			if(sum[i + j] / 10 >= 1) {
				sum[i + j + 1] += (sum[i + j] / 10);
				sum[i + j] %= 10;
			}
		}
	}
	int maxLen = a.length + b.length - 1;	
	for(i = 0; i < maxLen; i++) {
		a.digit[i] = sum[i] + '0';
	}
	if(sum[maxLen] != 0) {
		a.digit[maxLen] = sum[maxLen] + '0';
		maxLen++;
	}
	a.digit[maxLen] = '\0';
	a.length = maxLen;
	return a;
}

bigNumber div(bigNumber a, bigNumber b) {
	if(compare(b, zero()) == 0) {
		printf("Error div by zero\n");
		return zero();
	}
	bigNumber temp = zero();
	while(compare(a, b) >= 0) {
		a = minus(a, b);
		temp = plus(temp, int2bigNumber(1));
	}
	return temp;
}

bigNumber mod(bigNumber a, bigNumber b) {
	if(compare(b, zero()) == 0) {
		printf("Error div by zero\n");
		return zero();
	}
	while(compare(a, b) >= 0) {
		a = minus(a, b);
	}
	return a;
}

bigNumber arithmetic(bigNumber a, bigNumber b, char operator) {
	switch (operator) {
		case '+':
			return plus(a, b);
			break;
		case '-':
			return minus(a, b);
			break;
		case '*':
			return mul(a, b);
			break;
		case '/':
			return div(a, b);
			break;
		case '%':
			return mod(a, b);
			break;;
		default : 
			break;
	}
	return zero();
}

