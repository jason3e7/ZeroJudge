 /*
  * @file d218.c
  * @author Jason3e7
  * @algorithm big number
  * @date 201711091432
  */
  
#include <stdio.h>
#include <string.h>
#define maxLength 100001

typedef struct {
	char sign;
	char digit[maxLength];
	int length;
}bigNumber;

bigNumber int2bigNumber(int);
void print(bigNumber);
bigNumber zero();
bigNumber plus(bigNumber, bigNumber);
bigNumber mul(bigNumber, bigNumber);

int main() {
	int i, n;
	bigNumber sum, base, temp;
	sum = zero();
	base = zero();
	for(i = 1; i <= 1000; i++) {
		n = i;
		base = int2bigNumber(i);
		temp = int2bigNumber(1);
		while(n--) {
			temp = mul(base, temp);
		}
		sum = plus(sum, temp);
	}
	print(sum);
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
	if(number > 0) {
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

void print(bigNumber num) {
	if(num.sign == '-') {
		printf("-");
	}
	printf("%s\n", strrev(num.digit));
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
		a = zero();
	} else {
		a.digit[maxLen] = '\0';
		a.length = maxLen;
	}
	return a;
}

