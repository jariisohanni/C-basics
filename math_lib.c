#include <stdio.h>

#include "math_lib.h"

int factorial(int n)
{
    int fact = 1;
    for( int i = 1; i <= n ; i++)
    {
        fact *= i;
        printf("For execution number %d, factrional %d \n", i, fact);
    }

    return fact;

}
