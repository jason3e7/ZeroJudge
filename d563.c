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

void getLineNumber(int* number) {
	int temp = 0, flag = 0, point = 0;
	char c;
    do {
		c = getchar();
		if('0' <= c && c <= '9') {
        	temp *= 10;
			temp += (c - '0');
			flag = 1;
		} else {
			if(flag == 1) {
				number[point] = temp;
				temp = 0;
				flag = 0; 
				point++;
			}
		}
    } while (c != '\n' && c != EOF); 
}

int main() {
	int n, number[100001], i, j, sum, begin, end;
	char c;
	while(scanf("%d", &n) != EOF) {
		sum = 0;
		begin = 0;
		end = 0;
		clean_stdin();
		getLineNumber(&number[0]);
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


