 /*
  * @file structAndBigNumber.c
  * @author Jason3e7
  * @algorithm big number
  * @date 201711071428
  * @note negative
  */

#include <stdio.h>
#include <string.h>
#define maxLength 10001

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

typedef struct {
	char sign;
	char digit[maxLength];
	int length;
}bigNumber;

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

bigNumber mul(bigNumber a, bigNumber b) {
	int i, j, sum[maxLength] = {0}, zeroFlag = 1;
	for(i = 0; i < a.length; i++) {
		for(j = 0; j < b.length; j++) {
			sum[i + j] += (a.digit[i] - '0') * (b.digit[j] - '0');
		}
	}
	int maxLen = a.length + b.length - 1;	
	for(i = 0; i < maxLen; i++) {
		if(sum[i] > 0) {
			zeroFlag = 0;
		}
		if(sum[i] / 10 >= 1) {
			sum[i + 1] += (sum[i] / 10);
			sum[i] %= 10;
		}
		a.digit[i] = sum[i] + '0';
	}
	if(sum[maxLen] != 0) {
		zeroFlag = 0;
		a.digit[maxLen] = sum[maxLen] + '0';
		maxLen++;
	}
	if(zeroFlag == 1) {
		a.digit[0] = '0';
		a.digit[1] = '\0';
		a.length = 1;
		a.sign = '+';
	} else {
		a.digit[maxLen] = '\0';
		a.length = maxLen;
	}
	return a;
}

bigNumber arithmetic(bigNumber a, bigNumber b, char operator) {
	switch (operator) {
		case '+':
			return plus(a, b);
			break;
		case '-':
			break;
		case '*':
			return mul(a, b);
			break;
		case '/':
			break;
		default : 
			break;
	}
	bigNumber temp = {'+', "0", 1};
	return temp;
}

int main() {
	char a[maxLength], b[maxLength], operator;
	while(scanf("%s %c %s", a, &operator, b) != EOF) {
		bigNumber aNum = str2bigNumber(a);
		bigNumber bNum = str2bigNumber(b);
		print(arithmetic(aNum, bNum, operator));
	}
	return 0;
}

