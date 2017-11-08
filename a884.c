 /*
  * @file a884.c
  * @author Jason3e7
  * @algorithm big number
  * @UVa 11448
  * @date 201711091141
  */

#include <stdio.h>
#include <string.h>
#define maxLength 10002

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

void print(bigNumber num) {
	if(num.sign == '-') {
		printf("-");
	}
	printf("%s\n", strrev(num.digit));
}

bigNumber str2bigNumber(char* number) {
	bigNumber r;
	strcpy(r.digit, strrev(number));
	r.length = strlen(r.digit);
	r.sign = '+';
	return r;
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

bigNumber minus(bigNumber a, bigNumber b) {
	int cmp = compare(a, b), i;
	if (cmp == 1) {
		for(i = 0; i < b.length; i++) {
			a.digit[i] -= (b.digit[i] - '0');
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
		for(i = 0; i < a.length; i++) {
			b.digit[i] -= (a.digit[i] - '0');
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
	a.digit[0] = '0';
	a.digit[1] = '\0';
	a.sign = '+';
	a.length = 1;
	return a;
}

int main() {
	int n;
	char a[maxLength], b[maxLength];
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%s %s", a, b);
			bigNumber aNum = str2bigNumber(a);
			bigNumber bNum = str2bigNumber(b);
			print(minus(aNum, bNum));
		}
	}
	return 0;
}

