
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	
	//============================================================
	// The variable space declared directly by data type can NOT
	// be freed manually.
	//============================================================
	
	int var = 8;
	int* pVar = &var;
	printf("var = %d\n", var);
	//For the following two lines, compilation is fine.
	//free(pVar);					//running errors:invalid pointer.
	//printf("var = %d\n", var);
	
	//============================================================
	// Only space allocated by "malloc" can be freed.
    // The space of var declared by "int" cannot be freed.
	//============================================================
	
	int* pVar2 = (int*)malloc(sizeof(int));
	*(pVar2) = 9;
	printf("var2_value   = %d\n", *(pVar2));
	printf("var2_address = %p\n", pVar2);
	free(pVar2);
	//Although pVar2 has been freed, it is still LEGAL to be called below.
	printf("var2_value   = %d\n", *(pVar2));	//Print out: var2_value = 0
	printf("var2_address = %p\n", pVar2);		//print out: var2_address = xxxxx
    //Free a same pointer twice is ILLEGAL!
    //free(pVar2);

	return EXIT_SUCCESS;

}


