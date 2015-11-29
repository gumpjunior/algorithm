/*
 ============================================================================
 Name        : triangle_bottom_up.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NEG_INF -99999
#define POS_INF  99999
#define ARRSIZE 4
#define DEBUG_LOCAL 1

//int min_path_search_bottom_up(int* arr, int arrSize);
int min_path_search_bottom_up(int (*arr)[4], int arrSize);

int main(void) {

	printf("Program starts!\n");

	//Do not need to declare both row and column. Because this is an square
	//array. For example, there are 10 items in last row, for the row above the
	//next row below, always 1 item is missing. So totally there are 10 rows.
	//int counti, countj, row, column;
	//counti = countj = row = column = 0;
	//row = column = 4;
	//int triangle[row][column];
	//for (counti=0; counti<row; ++counti)
	//{
	//	for (countj=0; countj<column; ++countj)
	//	{
	//		triangle[counti][countj] = NEG_INF;
	//	}
	//}
	int sum = POS_INF;
	int triangle[ARRSIZE][ARRSIZE] = {
		{2, NEG_INF, NEG_INF, NEG_INF},
		{3, 4,       NEG_INF, NEG_INF},
		{6, 5,       7,       NEG_INF},
		{4, 1,       8,       3},
	};
	
	sum = min_path_search_bottom_up(triangle, ARRSIZE);
	printf("min sum = %d\n", sum);

	printf("Program ends!\n");
	return EXIT_SUCCESS;

}

//Input: A pointer to the triangle array.
//Function: Output the min sum as return value. If debug enabled, then, print out 
//		the number along the path when searching.
//Return: return the sum of numbers along the minimum path.
//More info: (*)refer <simple_examples_of_dynamic_programming.pdf> in onenote for
//		more info about algorithm. (*)arrSize equals to both arrRow and
//		arrColumn. Coz this 2 dimension array is a square array. (*)Array notation 
//		version. This will take effect over how array is transferred into the
//		function. Here is "int (*arr)[4]".

int min_path_search_bottom_up(int (*arr)[ARRSIZE], int arrSize)
{

	int minSum = POS_INF;
	int minSumArr[arrSize];			//For minSum storage of each node in the row
	int counti, countj;
	counti = countj = 0;			//countj is used as column item index.
	int leftSum, rightSum;
	leftSum = rightSum = 0;			//leftSum: 5+4;		rightSum: 5+8;
	int tempMin = POS_INF;
	int tempIndex = 0;

	//Some necessary checking.
	//For example, array row should equal to array column. arrSize should be greater 
    //than 0. But not write the code, only list the idea here.

	//According to the algorithm, need an array to save the temp min sum for each 
    //item of current row to each item in the row below. Initialize this array by 
    //the last row of triangle.
	for (countj=0; countj<arrSize; ++countj)
	{
		minSumArr[countj] = arr[arrSize-1][countj];
	}

	//Print out the min value of the last line for debug.
	if (DEBUG_LOCAL)
	{
		for (countj=0; countj<arrSize; ++countj)
		{
			if (tempMin>minSumArr[countj])
			{
				tempMin = minSumArr[countj];
			}
		}
		printf("%d\n", tempMin);
	}

	//
	for (counti=(arrSize-2); counti>=0; --counti)		//counti is used as row item index.
	{
		for (countj=0; countj<(counti+1); ++countj)
		{
			leftSum  = minSumArr[countj]   + arr[counti][countj];
			rightSum = minSumArr[countj+1] + arr[counti][countj];
			if (leftSum < rightSum)
			{
				minSumArr[countj] = leftSum;
			}
			else
			{
				minSumArr[countj] = rightSum;
			}
		}
		
		//
		if (DEBUG_LOCAL)
		{
			tempMin = POS_INF;
			for (countj=0; countj<(counti+1); ++countj)
			{
				if (tempMin>minSumArr[countj])
				{
					tempMin = minSumArr[countj];
					tempIndex = countj;
				}
			}
			printf("%d\n", arr[counti][tempIndex]);
		}
	}

	minSum = minSumArr[0];

	return minSum;

}

