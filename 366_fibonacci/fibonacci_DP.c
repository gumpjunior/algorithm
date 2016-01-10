/*
 ============================================================================
 Name        : fibonacci_DP.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description : Bottom-up version for Fibonacci series.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci_bottom_up_solution(int);

int fibonacci_top_down_by_pointer(int num);
int fibonacci_top_down_recursive(int num, int* fibSeries);

int main(void) {

	printf("Program starts!\n");

	int num    = 4;
	int result = 0;
	int count  = 0;

	//Test for function "fibonacci_bottom_up_solution".
	printf("fibonacci_bottom_up_solution\n");
	//Test one by one number.
	result = fibonacci_bottom_up_solution(num);
	printf("%dth number in Fibonacci Series is: %d\n", num, result);

	//Generate a series of Fibonacci number.
	for (count=1; count<10; ++count)
	{
		result = fibonacci_bottom_up_solution(count);
		printf("%dth number in Fibonacci Series is: %d\n", count, result);
	}

	//Test for function "fibonacci_top_down_by_pointer".
	printf("fibonacci_top_down_by_pointer\n");
	//Generate a series of Fibonacci number.
	for (count=1; count<10; ++count)
	{
		result = fibonacci_top_down_by_pointer(count);
		printf("%dth number in Fibonacci Series is: %d\n", count, result);
	}

	printf("Program ends!\n");
	return EXIT_SUCCESS;

}


//Parameter:  
//Return:     The "num"th number in Fibonacci Series.
//Func description: Fibonacci Series is not 0th based series.
//		This is bottom-up version.
int fibonacci_bottom_up_solution(int num)
{
	int num1, num2;
	int num_th = 0;
	int count  = 0;

	num1 = 1;
	num2 = 1;

	if (num<1)
	{
		printf("ERROR: Index is out of range for Fibonacci Series.\n");
		exit(-1);
	}
	else if (num<3)
	{
		num_th = num1;
	}
	else
	{
		for (count=3; count<num+1; ++count)
		{
			num_th = num1 + num2;
			num1   = num2;
			num2   = num_th;
		}
		num_th = num2;
	}

	return num_th;
}


//Parameter:  
//Return:     The "num"th number in Fibonacci Series.
//Func description: Fibonacci Series is not 0th based series.
//		This is top-down version.
int fibonacci_top_down_by_pointer(int num)
{
	int num_th = 0;
	int* fibSeries = NULL;		//To store the fib numbers already calculated.

	if (num<1)
	{
		printf("ERROR: Index is out of range for Fibonacci Series.\n");
		exit(-1);
	}

	fibSeries = (int*)malloc(num * sizeof(int));
	if (fibSeries == NULL)
	{
		printf("ERROR: memory allocation failed.\n");
		return (-1);
	}
	else
	{
		memset(fibSeries, 0, num*sizeof(int));
	}

	*(fibSeries)   = 1;		//num1
	*(fibSeries+1) = 1;		//num2
	
	num_th = fibonacci_top_down_recursive(num, fibSeries);
	
	free(fibSeries);

	return num_th;
}

int fibonacci_top_down_recursive(int num, int* fibSeries)
{

	int num_th = 0;
	if (*(fibSeries+num-1) != 0)		//Return num_th number if already exists.
	{
		num_th = *(fibSeries+num-1);
	}
	else									//Calculate recursively, save and return.
	{
		num_th = fibonacci_top_down_recursive(num-1, fibSeries) + fibonacci_top_down_recursive(num-2, fibSeries);
	}

	return num_th;
}


