 /*
  * @file b304.c
  * @author Jason3e7
  * @algorithm stack
  * @UVa 673
  * @date 201711271901
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
	int n, len, i, point;
	char line[128], stack[128];
	scanf("%d", &n); 
		clean_stdin();
		while(n--) {
			fix_fgets(line, 128);
			len = strlen(line);
			point = 0;
			for(i = 0; i < len; i++) {
				switch(line[i]) {
					case ' ' :
						break;
					case '(' :
					case '[' :
						stack[point] = line[i];
						point++;
						break;
					case ')' :
						if(stack[point - 1] == '(') {
							point--;
						} else {
							point = -1;
						}
						break;
					case ']' :
						if(stack[point - 1] == '[') {
							point--;
						} else {
							point = -1;
						}
						break;
					default :
						point = -1;
						break;
				} 
				if(point < 0) {
					break;
				}
			}
			if(point == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	
	return 0;
}

