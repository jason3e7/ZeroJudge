 /*
  * @file b538.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710191218
  */

#include <stdio.h>

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int main() {
	int a, b, c, d, gcd;
	char op;
	while(scanf("%d %d %d %d %c", &a, &b, &c, &d, &op) != EOF) {
		switch(op) {
			case '+' :
				a = a * d + b * c;
				b = b * d;
				break;
			case '-' :
				a = a * d - b * c;
				b = b * d;
				break;
			case '*' :
				a = a * c;
				b = b * d;
				break;
			case '/' :
				a = a * d;
				b = b * c;
				break;
			defaulf :
				break;
		}
		if(a % b == 0) {
			printf("%d\n", a / b);
		} else {
			gcd = GCD(a, b);
			if((gcd < 0 && b > 0) || (b < 0 && gcd > 0)) {
				gcd *= -1;
			}
			printf("%d/%d\n", a / gcd, b / gcd);
		}
	}
	return 0;
}

