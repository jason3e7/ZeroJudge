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

int main() {
	char line[100001];
	int length, n, i;
	scanf("%d", &n);
	printf("%d\n", n);
	clean_stdin();
	while(fix_fgets(line, 100001) != NULL) {
		printf("%s\n", line);
	}
	return 0;
}



