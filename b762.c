 /*
  * @file b762.c
  * @author Jason3e7
  * @algorithm string
  * @date 201710011712
  */

#include <stdio.h>
#include <string.h>
int main() {
	int n, kill, assist, conKill, die;
	char cmd[100];
	while(scanf("%d", &n) != EOF) {
		kill = 0, assist = 0, conKill = 0, die = 0;
		while(n--) {
			scanf("%s", cmd);
			if(strcmp(cmd, "Get_Kill") == 0) {
				kill++;
				conKill++;
				switch(conKill) {
					case 1 :
					case 2 :
						printf("You have slain an enemie.\n");
						break;
					case 3 :
						printf("KILLING SPREE!\n");
						break;
					case 4 :
						printf("RAMPAGE~\n");
						break;
					case 5 :
						printf("UNSTOPPABLE!\n");
						break;
					case 6 :
						printf("DOMINATING!\n");
						break;
					case 7 :
						printf("GUALIKE!\n");
						break;
					default : 
						printf("LEGENDARY!\n");
						break;
				}
				continue;
			}
			if(strcmp(cmd, "Get_Assist") == 0) {
				assist++;
				continue;
			}
			if(strcmp(cmd, "Die") == 0) {
				die++;
				if (conKill >= 3) {
					printf("SHUTDOWN.\n");
				} else {
					printf("You have been slained.\n");
				}
				conKill = 0;
			}
		}
		printf("%d/%d/%d\n", kill, die, assist);
	}
	return 0;
}

