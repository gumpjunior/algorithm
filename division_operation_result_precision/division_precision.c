/*
 ============================================================================
 Name        : res ult.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : When I see a A/B expression, how do I know this is a division
    operation or this is a modulo operation? There is no real difference 
    btw division and modulo for C, but the result type decides/define what 
    operation it is.
    (*)modulo -> result is int, but the operation remainder
    (*)rounding(qu zheng) -> result is int, but the integer part of the op.
       division(chu fa) -> result is float, whole part of the operation.
 Result table:
    |----------------------------|  Note: when the result var type is int, 
    | Result var type is int     |  there is no much meaning to do this 
    |----------------------------|  analysis. Because C will always cut off
    |        |  Bint  |  Bfloat  |  the remainder of the float no matter 
    |----------------------------|  the remainder is greater than 0.5 or 
    |  Aint  |                   |  less than 0.5.
    |----------------------------|
    | Afloat |
    |----------------------------|
    ==============================
    |----------------------------|  Conclusion: once one operand is float,
    | Result var type is float   |  the result will be float number.
    |----------------------------|  Note: the right hand side will be calculated
    |        |  Bint  |  Bfloat  |  first, then assign the result to float
    |----------------------------|  type result, thats why Aint/Bint is int.
    |  Aint  |   int  |  float   |
    |----------------------------|
    | Afloat |  float |  float   |
    |----------------------------|
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    puts("Program starts!\n");

    //
    //float to int assignment
    //
    //When the float is less than 2.5.
    printf("What is the result data type by assigning a float to an int?\n");
    float varFloat = 2.4;
    int   varInt   = varFloat;
    printf("Assign 2.4 to int, varInt = %d\n", varInt);

    //When the float is greater than 2.5.
    varFloat = 2.8;
    varInt   = varFloat;
    printf("Assign 2.8 to int, varInt = %d\n", varInt);


    int Aint = 5;
    float Afloat = 5.0;
    int Bint = 2;
    float Bfloat = 2.0;

    //
    //Result var type is int
    //
    //This test does not mean quite a lot when the result var
    //type is int.
    int Rint;
    Rint = Aint / Bint;
    printf("\nRint = %f\n", (float)Rint);
    printf("Rint = %d\n",        Rint);

    //
    //Result var type is float
    //
    //For division of two integers, NO rounding up to the remainder
    //part. The remainder will be always cut off.
    float Rfloat;
    Rfloat = Aint / Bint;
    printf("\nint/int:     Rfloat = %f\n", Rfloat);
    
    Rfloat = Afloat / Bint;
    printf("float/int:   Rfloat = %f\n", Rfloat);

    Rfloat = Aint / Bfloat;
    printf("int/float:   Rfloat = %f\n", Rfloat);
    
    Rfloat = Afloat / Bfloat;
    printf("float/float: Rfloat = %f\n", Rfloat);

    puts("\nProgram ends!\n");

    return EXIT_SUCCESS;
}
