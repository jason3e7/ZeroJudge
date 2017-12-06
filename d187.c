 /*
  * @file d187.c
  * @author Jason3e7
  * @algorithm string
  * @UVa 11530
  * @date 201712071152
  */

#include <stdio.h>
#include <string.h>

void clean_stdin(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

char* fix_fgets(char* str, int n) {
	char* ret_val;
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
	int map[26] = {
				1, 2, 3, 1, 2, 3,  
		1, 2, 3, 1, 2, 3, 1, 2, 3, 
		1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	int t, i, len, count, c;
	char line[200];
	while(scanf("%d", &t) != EOF) {
		clean_stdin();	
		c = 1;	
		while(t--) {
			fix_fgets(line, 200);
			count = 0;
			len = strlen(line);
			for(i = 0; i < len; i++) {
				if(line[i] == ' ') {
					count++;
				} else {
					count += map[line[i] - 'a']; 
				}
			}
			printf("Case #%d: %d\n", c, count);
			c++;
		}
	}
	return 0;
}
