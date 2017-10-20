 /*
  * @file learnArrayAndPointer.c
  * @author Jason3e7
  * @algorithm array and pointer
  * @date 20171021832
  */

#include <stdio.h>

/* 1D array function */
void swap_p(int* c, int* d) {
	printf("c=%p(value=%d) d=%p(value=%d)\n", c, *c, d, *d);
	int temp = *c;
    *c = *d;
    *d = temp;
}
void one_getArray(int n[]) {
	printf("%p\n", n);
	printf("%d\n", n[0]);
}
void two_getArray(int* n) {
	printf("%p\n", n);
	printf("%d\n", n[0]);
}
void swap_strPtr(char** str1_ptr, char** str2_ptr) {
	printf("%p => %p, %p => %p\n", str1_ptr, *str1_ptr, str2_ptr, *str2_ptr);
	char* temp = *str1_ptr;
	*str1_ptr = *str2_ptr;
	*str2_ptr = temp;
	printf("swap %s, %s\n", *str1_ptr, *str2_ptr);	
} 

int main() {
	printf("===1D array===\n");	
	printf("====int array====\n");	
	printf("call by value of pointer\n");
	int a[2] = {1, 2};
	printf("array a=%p\n", a);
	printf("a[0]=%d(add=%p) a[1]=%d(add=%p)\n", a[0], &a[0], a[1], &a[1]);
	swap_p(&a[0], &a[1]);
	printf("a[0]=%d(add=%p) a[1]=%d(add=%p)\n", a[0], &a[0], a[1], &a[1]);
	printf("\n");

	int b[2] = {1, 2};
	int c[] = {1, 2};
	/* CE
		int *d = {1, 2};
		but can use
		char* str1 = "hello";
	*/
	printf("(int b[2] = {1, 2}; ) != (int c[] = {1, 2}; ) !?\n");
	one_getArray(b);
	one_getArray(c);
	/* CE
		one_getArray(b[]);
	*/
	two_getArray(b);
	two_getArray(c);
	
	printf("====char array====\n");	
	char* str1 = "aaaaaa";
	char* str2 = "hello2";
	char str3[] = "hello3";
	char str4[] = {'h', 'e', 'l', 'l', 'o', '4'};
	char str5[6] = {'h', 'e', 'l', 'l', 'o', '5'};
	char str6[7] = {'h', 'e', 'l', 'l', 'o', '6', '\0'};
	printf("str1 = %s\n", str1);
	str1 = "hello world";
	printf("str1 = %s\n", str1);
	str1 = "hello1";
	/* Bus error: 10
		str1[0] = 'a';
		printf("str1 = %s\n", str1);
	*/
	/* CE
		char* str7 = {'h', 'e', 'l', 'l', 'o'};
	*/
	printf("(char str[] = \"string\";) != (char str[10] = \"string\";)\n");
	printf("%s => %p, %s => %p\n", str1, &str1, str2, &str2);
	swap_strPtr(&str1, &str2);
	/* CE 
		incompatible pointer types passing 'char (*)[7]' to parameter of type 'char **'
		printf("%s => %p, %s => %p\n", str1, &str1, str3, &str3);
		swap_strPtr(&str1, &str3);
	*/
	char* str7 = str3;
	printf("%s => %p, %s => %p, %s Ptr => %p\n", str1, &str1, str3, &str3, str7, &str7);
	swap_strPtr(&str1, &str7);
	printf("char* a != char a[] are different types\n");
    printf("str2 sizeof %ld => size of pointer to char\n", sizeof(str2));
    printf("str3 sizeof %ld => size of char array in memory\n", sizeof(str3));
	/*	
		incompatible pointer types passing 'char (*)[6]' to parameter of type 'char **'
		printf("%s => %p, %s => %p\n", str1, &str1, str4, &str4);
		swap_strPtr(&str1, &str4);
	
		printf("%s => %p, %s => %p\n", str3, &str3, str2, &str2);
		swap_strPtr(&str3, &str4);
	*/
	str7 = str6;
	printf("%s => %p, %s => %p, %s Ptr => %p\n", str1, &str1, str6, &str6, str7, &str7);
	swap_strPtr(&str1, &str7);
	printf("str4 no line end, so maybe show other data.\n");
	str7 = str4;
	printf("%s => %p, %s => %p, %s Ptr => %p\n", str1, &str1, str4, &str4, str7, &str7);
	swap_strPtr(&str1, &str7);
	return 0;
}

