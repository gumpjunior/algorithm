/*
 ============================================================================
 Name        : rod_cutting_recursive.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description : Rod cutting from <introduction to algorithms> P363.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Point(x)
#define NEG_INF	-99999
#define MAX(a, b) ( ((a)>(b)) ? (a) : (b) )
// #define MIN(a, b) ( ((a)<(b)) ? (a) : (b) )


int cut_rod(int*, int, int);

//Value of rod in different length
//Point(x): 2nd dimension size is required.
//int p[][2] = {
//	//{length, value},
//	//{0, 0},		// Because cutLength starts from 1, do not need this line.
//	{1, 1},
//	{2, 5},
//	{3, 8},
//	{4, 9},
//	{5, 10},
//	{6, 17},
//	{7, 17},
//	{8, 20},
//	{9, 24},
//	{10, 30},		// Rod length must less than 10, otherwise recursive func will fail.
//					// cutLength = 10 means no cut.
//};
//One dimension level array is fine, coz the index(shift position)+1 stands for
//the rod length.
int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int main(void) {

	puts("Program starts\n");
	printf("minimum int = %d\n", NEG_INF);

	int rodLength = 4;
	int maxValue = NEG_INF;

	//Point(x): the value is 10. Coz 'p' is the pointer to the whole array.
	printf("in main: (sizeof(p)/sizeof(p[0])) = %d\n", (sizeof(p)/sizeof(p[0])));

	maxValue = cut_rod(p, rodLength, (sizeof(p)/sizeof(p[0])) );
	printf("The max value of rod in length %d is %d\n", rodLength, maxValue);

	puts("Program ends\n");
	return EXIT_SUCCESS;

}

//Input:  (1) value of rod in different length, array p.
//  	  (2) length of the rod, rodLength.
//Output: The maximum value of rod in length rodLength.
//CUT-ROD(p, n) on book P363.
//Point(x): pass array size in.
int cut_rod(int* p, int rodLength, int arrSize)
{

	int cutLength = 0;
	int maxValue = NEG_INF;

	//Point (x)
	//	The value is 1. Coz 'p' pointes to the 1st element of the array after passing in.
	printf("in func cur_rod: (sizeof(p)/sizeof(p[0])) = %d\n", (sizeof(p)/sizeof(p[0])));

	if ( rodLength > arrSize )
	{
		printf("ERROR: ");
		printf("rod length must equal or less than %d\n", (sizeof(p)/sizeof(p[0])));
		exit(-1);
	}

	if (rodLength == 0)
		return 0;

	// 1. Need to think carefully! cutLength should start from 1 and at most equal
	// to rodLength, which means no cut.
	// 2. cutLength cannot start from 0. Otherwise the inner call to cut_rod will
	// be a dead loop, coz "rodLength - cutLength" never becomes smaller.
	for (cutLength=1; cutLength<=rodLength; ++cutLength)
	{
		maxValue = MAX(maxValue, *(p+cutLength-1) + cut_rod(p, rodLength - cutLength, arrSize));
	}

	return maxValue;

}
