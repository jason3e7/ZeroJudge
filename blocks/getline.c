 /*
  * @file getline.c
  * @author Jason3e7
  * @algorithm input
  * @date 201710161001
  */

#include <stdio.h>
#include <string.h>

void clean_stdin(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {
	char line[100001];
	int length, n, i;
	while(scanf("%d", &n) != EOF) {
		clean_stdin();
		while(n--) {
			fgets(line, 100001, stdin);
			length = strlen(line);
			for(i = 0; i < length; i++) {
				printf("%c", line[i]);			
			}
		}
	}
	return 0;
}



