/*
 ============================================================================
 Name        : rod_cutting_top-bottom_DP.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description : This is the top-bottom version of rod cutting in dynamic
 	 	 	   programming. For more info, refer book P365.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEG_INF	-99999
#define MAX(a, b) ( ((a)>(b)) ? (a) : (b) )
#define MIN(a, b) ( ((a)<(b)) ? (a) : (b) )

//One dimension level array is fine, coz the index(shift position)+1 stands for
//the rod length.
int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int memorized_cut_rod(int*, int, int);
int memorized_cut_rod_aux(int*, int, int*);

int main(void) {

	printf("Program starts!\n");

	int rodLength = 4;		//Change this var to print revenue for rod in diff length.
	int maxValue  = 0;
	int rodLengthSize = sizeof(p)/sizeof(p[0]);

	//maxValue = bottom_up_rod_cut(p, rodLength, (sizeof(p)/sizeof(p[0])) );
	maxValue = memorized_cut_rod(p, rodLength, rodLengthSize);
	printf("The max value of rod in length %d is %d\n", rodLength, maxValue);

	printf("Program ends!\n");
	return EXIT_SUCCESS;

}

int memorized_cut_rod(int* rodValinLength, int rodLength, int rodLengthSize)
{
	int maxValue = 0;
	int revinLengthSize = rodLengthSize+1;
	int revinLength[revinLengthSize];		//Book P365, array r[] ranges from 0 to n. So adding 1 here.
											//revinLength[] is r[] in book.
	int count = 0;

	if (rodLength>rodLengthSize || rodLength<0)
	{
		printf("ERROR: %d is not a valid rod length size.\n", rodLength);
		exit(-1);
	}

	for (count=0; count<revinLengthSize; ++count)
	{
		revinLength[count] = NEG_INF;
	}
	maxValue = memorized_cut_rod_aux(rodValinLength, rodLength, revinLength);

	return maxValue;
}

int memorized_cut_rod_aux(int* rodValinLength, int rodLength, int* revinLength)
{
	int maxValue = 0;
	int count    = 0;

	if (revinLength[rodLength] >= 0)
	{
		return revinLength[rodLength];
	}

	if (rodLength == 0)
	{
		maxValue = 0;
	}
	else
	{
		maxValue = NEG_INF;
		for (count=0; count<rodLength; ++count)
		{
			maxValue = MAX(maxValue, memorized_cut_rod_aux(rodValinLength, rodLength-count, revinLength));
		}
		revinLength[rodLength] = maxValue;
	}

	return maxValue;
}
