 /*
  * @file d563.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710121006
  */

#include <stdio.h>

void clean_stdin(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int input(void) {   
	char cha;   
	int x = 0; 
	do {
		cha = getchar();
	} while ('0' > cha || cha > '9');
	x = cha - '0';   
	cha = getchar();
	while ('0' <= cha && cha <= '9') {
		x = x * 10 + (cha - '0');
		cha = getchar();
	}
    return x;
}

int main() {
	int n, number[100001], i, j, sum, begin, end;
	char c;
	while(scanf("%d", &n) != EOF) {
		sum = 0;
		begin = 0;
		end = 0;
		clean_stdin();
		for(i = 0; i < n; i++) {
			number[i] = input();
		}
		for(i = 0; i < n; i++) {
			begin += number[i];
			end = 0;
			for(j = n - 1; j >= 0; j--) {
				end += number[j];
				if(begin == end) {
					sum++;
				}
				if(end >= begin) {
					break;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}


