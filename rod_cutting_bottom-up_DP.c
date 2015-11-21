/*
 ============================================================================
 Name        : rod_cutting_bottom-up_DP.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description : This is the bottom-up dynamic programming version of rod
 	 cutting issue. Refer book <Introduction to Algorithms> P366.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Point(x)
#define NEG_INF	-99999
#define MAX(a, b) ( ((a)>(b)) ? (a) : (b) )
#define MIN(a, b) ( ((a)<(b)) ? (a) : (b) )

//One dimension level array is fine, coz the index(shift position)+1 stands for
//the rod length. For more info, refer branch "rod_cutting_recursive".
int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int bottom_up_rod_cut(int* rodValinLength, int rodLength, int rodLengthSize);

int main(void) {

	printf("!!!Program starts!!!\n");

	int rodLength = 6;		//Change this var to print revenue for rod in diff length.
	int maxValue  = 0;

	maxValue = bottom_up_rod_cut(p, rodLength, (sizeof(p)/sizeof(p[0])) );
	printf("The max value of rod in length %d is %d\n", rodLength, maxValue);

	printf("!!!Program ends!!!\n");
	return EXIT_SUCCESS;

}

int bottom_up_rod_cut(int* rodValinLength, int rodLength, int rodLengthSize)
{

	//maxValue of revenue storage to reduce re-calculation workload.
	//Put it inside instead of as a global array.
	//int revinLength[(sizeof(p)/sizeof(p[0]))] = {0};		//init works
	int revinLength[(sizeof(p)/sizeof(p[0]))];
	revinLength[0] = 0;
	int maxValue = 0;
	int i = 0;
	int j = 0;

	if (rodLength>rodLengthSize || rodLength<=0)
	{
		printf("ERROR: %d is not a valid rod length size.\n", rodLength);
		exit(-1);
	}

	//Know the physical meaning of i, j.
	for (i=1; i<=rodLength; ++i)
	{
		maxValue = NEG_INF;
		for (j=1; j<=i; ++j)		//j<=i!
		{
			//ALthough defined revinLength[] the same size as p, equal to (sizeof(p)/sizeof(p[0])).
			//But by revinLength[i-j], last element of array reinLength is missing assignment.
			//Coz j != 0. But this situation is fine.
			maxValue = MAX(maxValue, p[j-1] + revinLength[i-j] );
		}
		revinLength[i] = maxValue;
	}

	for (i=0; i<rodLengthSize; ++i)
	{
		printf("revinLength[%d] = %d\n", i, revinLength[i]);
	}

	return maxValue;

}
