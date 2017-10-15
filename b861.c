 /*
  * @file b861.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710160938
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
	int length, t, i, eat, overflag;
	while(scanf("%d", &t) != EOF) {
		clean_stdin();
		while(t--) {
			fgets(line, 100001, stdin);
			length = strlen(line);
						
			eat = 0;
			overflag = 0;
			for(i = 0; i < length; i++) {
				if(line[i] == 'c' && line[i + 1] == 'h' && line[i + 2] == 'i') {
					eat++;
					i += 2;
				} else if(line[i] == 't' && line[i + 1] == 'u') {
					eat--;
					i++;
				}
		
				if(eat < 0) {
					overflag = 1;
				}	
			}
			if(overflag == 1) {
				if(eat > 0) {
					printf("chi pu tao bu tu pu tao pi, bu chi pu tao dao tu pu tao pi\n");
				} else {
					printf("bu chi pu tao dao tu pu tao pi\n");
				}
			} else {
				if(eat > 0) {
					printf("chi pu tao bu tu pu tao pi\n");
				} else {
					printf("chi pu tao tu pu tao pi\n");
				}
			}
		}
	}
	return 0;
}



