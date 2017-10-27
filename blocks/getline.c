 /*
  * @file getline.c
  * @author Jason3e7
  * @algorithm input
  * @date 201710181500
  */

#include <stdio.h>
#include <string.h>

void clean_stdin(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

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

int getLineNumber(char line[], int number[], int* point) {
	int length = strlen(line), flag = 0, count = 0, i;
	for(i = 0; i < length; i++) {
		if('0' <= line[i] && line[i] <= '9') {
			count *= 10;
			count += (line[i] - '0');
			flag = 1;
			if(i == length - 1) {
				number[*point] = count;
				(*point)++;
			}
		} else {
			if(flag == 1) {
				number[*point] = count;
				(*point)++;
				count = 0;
				flag = 0;
			}
		}
	}
	if((*point) == 0) {
		return 0;
	}
	return 1;
}

int main() {
	char line[100001];
	int length, n, i, num[101], point;
	scanf("%d", &n);
	printf("%d\n", n);
	clean_stdin();
	while(fix_fgets(line, 100001) != NULL) {
		printf("%s\n", line);
		point = 0;
		if(getLineNumber(line, num, &point)) {
			for(i = 0; i < point; i++) {
				printf("%d,", num[i]);
			}
			printf("\n");
		} else {
			printf("No Number\n");
		}
	}
	return 0;
}



