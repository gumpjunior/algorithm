/*
 ============================================================================
 Name        : search.c
 Author      : Dongyue Jiao
 Version     :
 Copyright   : Your copyright notice
 Description : search a range, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Notice:
 * 1. When passing an array pointer into a function,
 * pass the array size together.
 * 2. When passing the array size into the function,
 * need to calculate the array size outside the func.
 * Coz sizeof(pArr)/sizeof(int) inside function
 * equals 1.
 * 3. C cannot return multiple values, so update the
 * variable referred by pointers.
 */
int search_for_a_range(int* pArr, int size,
		int* firstIndex, int* lastIndex, int target)
{
	int start = 0;
	int end   = size;
	int middle = 0;

	//find first location
	while(start+1 < end)
	{
		middle = start + (end-start)/2;
		if(*(pArr+middle) < target)
		{
			start = middle;
		}
		else if(*(pArr+middle) > target)
		{
			end = middle;
		}
		else		//middle == target
		{
			end = middle;
		}
	}

									//check "end" first
	if(*(pArr+start) == target)		//Choose if-else if instead of
	{								//if-if. Coz easy to tell logic
		*firstIndex = start;		//flow.
	}
	else if(*(pArr+end) == target)
	{
		*firstIndex = end;
	}
	else	//Do not forget
	{
		*firstIndex = -1;
	}

	start = 0;
	end   = size;
	middle = 0;
	//find last location
	while(start+1 < end)
	{
		middle = start + (end-start)/2;
		if(*(pArr+middle) < target)
		{
			start = middle;
		}
		else if(*(pArr+middle) > target)
		{
			end = start;
		}
		else
		{
			start = middle;
		}
	}

	if(*(pArr+end) == target)		//check "end" first
	{
		*lastIndex = end;
	}
	else if(*(pArr+start) == target)
	{
		*lastIndex = start;
	}
	else
	{
		*lastIndex = -1;
	}

	return 0;
}

int main(void) {
	printf("========== program start ==========\n");

	int target 	    = 8;
	int inputSeq[6] = {5, 7, 7, 8, 8, 10};
	int arrSize	    = sizeof(inputSeq)/sizeof(int);
	int  startingPoint = 0;
	int  endingPoint   = 0;
	int* firstIndex    = &startingPoint;
	int* lastIndex     = &endingPoint;
	search_for_a_range(inputSeq, arrSize,
			firstIndex, lastIndex, target);
	printf("firIndex = %d\nlastIndex = %d\n", *firstIndex, *lastIndex);

	target 	      = 9;
	startingPoint = 0;
	endingPoint   = 0;
	search_for_a_range(inputSeq, arrSize,
			firstIndex, lastIndex, target);
	printf("firIndex = %d\nlastIndex = %d\n", *firstIndex, *lastIndex);

	printf("========== program end ==========\n");
	return EXIT_SUCCESS;
}
