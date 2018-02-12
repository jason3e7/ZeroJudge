 /*
  * @file b898.c
  * @author Jason3e7
  * @algorithm bigint
  * @date 201802130917
  */

#include <stdio.h>
#include <string.h>
#define maxLength 100001

typedef struct {
	char sign;
	char digit[maxLength];
	int length;
}bigNumber;

bigNumber str2bigNumber(char*);
void print(bigNumber);
int compare(bigNumber, bigNumber);
bigNumber zero();

int main() {
	int n;
	char a[maxLength], b[maxLength], c[maxLength];
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%s %s %s", a, b, c);
			bigNumber aNum = str2bigNumber(a);
			bigNumber bNum = str2bigNumber(b);
			bigNumber cNum = str2bigNumber(c);
			if(compare(aNum, bNum) == 1) {
				if(compare(aNum, cNum) == 1) {
					print(aNum);
				} else {
					print(cNum);
				}
			} else {
				if(compare(bNum, cNum) == 1) {
					print(bNum);
				} else {
					print(cNum);
				}
			}
		}
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
	printf("%s\n", strrev(num.digit));
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
