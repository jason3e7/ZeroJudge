 /*
  * @file d873.c
  * @author Jason3e7
  * @algorithm big number
  * @UVa 873
  * @date 201711070933
  * @note while(*end++){}; end-=2;
  */

#include <stdio.h>
#include <string.h>
#define maxLength 10001

char * fix_fgets(char * str, int n) {
	char * ret_val;
	int i;
	ret_val = fgets(str, n, stdin);
	if(ret_val) {
		for(i = 0; i < n; i++) {
			if(str[i] == '\n' || str[i] == '\r') {
				str[i] = '\0';
				break;
			}
		} 
	}
	return ret_val;
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
    return str;  
}  

typedef struct {
	char sign;
	char digit[maxLength];
	int length;
}bigNumber;

char* checkNum(char* num)  {
	int i, length = strlen(num), firstNotZero = -1;
	for(i = 0; i < length; i++) {
		if('1' <= num[i] && num[i] <= '9') {
			firstNotZero = i;
			break;
		}
	}
	if(firstNotZero == -1) {
		return "0";
	}
	for(i = firstNotZero; i < length; i++) {
		num[i - firstNotZero] = num[i];
	}
	num[length - firstNotZero] = '\0';
	return num;
}

bigNumber str2bigNumber(char* number) {
	bigNumber r;
	number = checkNum(number);
	strcpy(r.digit, strrev(number));
	r.length = strlen(r.digit);
	r.sign = '+';
	return r;
}

int compare(bigNumber a, bigNumber b) {
	int i;
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
	a.digit[maxLen] = '\0';
	a.length = maxLen;
	if(zeroFlag == 1) {
		a.digit[0] = '0';
		a.digit[1] = '\0';
		a.length = 1;
		a.sign = '+';
	}
	return a;
}

int main() {
	char a[maxLength], b[maxLength], operator, line[maxLength];
	bigNumber base = {'+', "7463847412", 10};
	while(fix_fgets(line, maxLength) != NULL) {
		printf("%s\n", line);
		sscanf(line, "%s %c %s", a, &operator, b);
		bigNumber aNum = str2bigNumber(a);
		bigNumber bNum = str2bigNumber(b);
		if (compare(aNum, base) == 1) {
			printf("first number too big\n");
		}
		if (compare(bNum, base) == 1) {
			printf("second number too big\n");
		}
		if(operator == '+') {
			aNum = plus(aNum, bNum);
			if (compare(aNum, base) == 1) {
				printf("result too big\n");
			}
		}
		if(operator == '*') {
			aNum = mul(aNum, bNum);
			if (compare(aNum, base) == 1) {
				printf("result too big\n");
			}
		}
	}
	return 0;
}

