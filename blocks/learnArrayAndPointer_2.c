 /*
  * @file learnArrayAndPointer_2.c
  * @author Jason3e7
  * @algorithm array and pointer
  * @date 201710202055
  */

#include <stdio.h>

/* 1D array function */
void swap_strPtr(char** str1_ptr, char** str2_ptr) {
	printf("%p => %p, %p => %p\n", str1_ptr, *str1_ptr, str2_ptr, *str2_ptr);
	char* temp = *str1_ptr;
	*str1_ptr = *str2_ptr;
	*str2_ptr = temp;
	printf("swap %s, %s\n", *str1_ptr, *str2_ptr);	
} 
void swap_intPtr(int** c, int** d) {
	printf("c=%p(value=%p) d=%p(value=%p)\n", c, *c, d, *d);
	int* temp = *c;
    *c = *d;
    *d = temp;
}

void swap_intArrayPtr(int (*c)[2], int (*d)[2]) {
	printf("c=%p(value=%p) d=%p(value=%p)\n", c, *c, d, *d);
	int (*temp)[2] = c;
    c = d;
    d = temp;
	printf("c=%p(value=%p) d=%p(value=%p)\n", c, *c, d, *d);
}

int main() {
	printf("===1D array===\n");	
	printf("====char array====\n");	
	char* str1 = "hello1";
	/* CE
		incompatible integer to pointer conversion initializing 'char *' with an expression of type 'int'
		excess elements in scalar initializer
		char* str1 = {'h', 'e', 'l', 'l', 'o', '1', '\0'};
	*/
	char str2[7] = "hello2";
	char* str2Ptr = str2;
	/* Bus error: 10
		str1[0] = 'a';
	*/
	printf("%s => %p, %s => %p, %s Ptr => %p\n", str1, &str1, str2, &str2, str2Ptr, &str2Ptr);
	swap_strPtr(&str1, &str2Ptr);
	printf("====int array====\n");
	printf("call by value of pointer\n");
	int a[2] = {5, 2};
	int b[2] = {3, 4};
	/* CE 
		int *c = {6, 7};
	*/
	printf("a(add=%p), b(add=%p)\n", a, b);
	int* aPtr = a;
	int* bPtr = b;
	// no error
	aPtr[0] = 1;
	printf("a(add=%p) %p, b(add=%p) %p\n", a, aPtr, b, bPtr);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", a[0], a[1], b[0], b[1]);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", aPtr[0], aPtr[1], bPtr[0], bPtr[1]);
	printf("use pointer to operator !?\n");
	/* CE
		incompatible pointer types passing 'int (*)[2]' to parameter of type 'int **'
		swap_intPtr(&a, &b);
	*/
	swap_intPtr(&aPtr, &bPtr);
	printf("a(add=%p) %p, b(add=%p) %p\n", a, aPtr, b, bPtr);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", a[0], a[1], b[0], b[1]);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", aPtr[0], aPtr[1], bPtr[0], bPtr[1]);
	printf("\n");
	/* CE
		incompatible pointer types initializing 'int *' with an expression of type 'int (*)[2]'
		int *aaPtr = &a;
	*/
	int (*a1Ptr)[] = &a;
	int (*a2Ptr)[2] = &a;
	int (*b1Ptr)[] = &b;
	int (*b2Ptr)[2] = &b;

	printf("int (*a1Ptr)[] => %p, int (*a2Ptr)[2] => %p\n", a1Ptr, a2Ptr);
	/* CE
		subscript of pointer to incomplete type 'int []'	
		printf("%p\n", a1Ptr[0]);
	*/
	printf("%p %d %p %d\n", a2Ptr[0], *a2Ptr[0], a2Ptr[1], *a2Ptr[1]);
	/* can go this. but what happened ?
		a1Ptr = b2Ptr;
		a2Ptr = b1Ptr;
	*/
	/* CE
		incompatible pointer types passing 'int (**)[]' to parameter of type 'int **'
		swap_intPtr(&a1Ptr, &b1Ptr);
		incompatible pointer types passing 'int (**)[2]' to parameter of type 'int **'
		swap_intPtr(&a2Ptr, &b2Ptr);
	*/
	printf("What is 'int *a[]' and 'int *a[2]' ?\n");
	printf("int* a[2]; == int* (a[2]); // An array of int pointers.\n");
	printf("int (*a)[2]; // A pointer to an array of integers.\n");
	swap_intArrayPtr(a2Ptr, b2Ptr);	
	printf("a(add=%p) %p, b(add=%p) %p\n", a, &a, b, &b);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", a[0], a[1], b[0], b[1]);
	printf("*a2Ptr = %p, *b2Ptr = %p\n", *a2Ptr, *b2Ptr);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", *a2Ptr[0], *a2Ptr[1], *b2Ptr[0], *b2Ptr[1]);
	printf("a[0] = %d, a[1] = %d, b[0] = %d, b[1] = %d\n", (*a2Ptr)[0], (*a2Ptr)[1], (*b2Ptr)[0], (*b2Ptr)[1]);
	return 0;
}

