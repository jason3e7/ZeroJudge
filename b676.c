 /*
  * @file b676.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801071104
  */

#include <stdio.h>

int main() {
	int x;	
	char out;
	while(scanf("%d", &x) != EOF) {
		switch(x % 5) {
			case 0:
				out = 'U';
				break;
			case 1:
				out = 'G';
				break;
			case 2:
				out = 'Y';
				break;
			case 3:
				out = 'T';
				break;
			case 4:
				out = 'I';
				break;
			default:
				out = 'F';
		}
		printf("%c\n", out);
	}
	return 0;
}

