/*
 * @file d681.c
 * @author Jason3e7
 * @date 201510271145
 */

#include <stdio.h>

int main() {
	char bin[6], temp;
	int i, flag, locate = 0, count = 0;
	while(temp = getchar()) {
		if (temp == EOF)
			break;
		if (temp == '\n') {
			printf(" = ");
			for (i = 0; i < 5; i++) { 
				printf("%c", bin[i]);
			}
			printf("\n");
			count = 0;
			locate = 0;
		} else if (count < 5) {
			printf("%c", temp);
			bin[count] = temp;
			count++;
		} else if (temp != ' ') {
			if (temp == '1' || temp == '0') {
				printf("%c", temp);
				if (flag == 1) {
					if (bin[locate] == '1' && temp == '1')
						bin[locate] = '1';
					else
						bin[locate] = '0';
				} else if (flag == 2) {	
					if (bin[locate] == '1' || temp == '1')
						bin[locate] = '1';
					else
						bin[locate] = '0';
				}
				locate++;
			} else if (temp == 'a'){
				printf("&&");
				flag = 1;
				locate = 0;
			} else if (temp == 'o') {
				printf("||");
				flag = 2;
				locate = 0;
			}
		}	
	}
	return 0;
}


// test has wrong, but submit it work. WHY?
// newLine or not newLine
