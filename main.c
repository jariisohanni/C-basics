#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> //Define EXIT_SUCCESS

/* <- Start of multiline comment

  Anything that goes is ommitted by compiler (or preprocessor)

-> End of multiline comment */

int multiply (int value1, int value2);

int main(int argc, char *argv[])
{
    printf("Our first appliction!\n"); //Prints text inside quotes

    //This how we initialise variables
    int x1 = 0;
    int x2 = 3;

    printf("x1 %d \n", x1);
    printf("x2 %d \n", x2);

    //Printing of variables
    short a = 2, b = 4, c = 8;
    printf("a %d, b %d, c %d,   \n", a,b,c);

    //Some arithmetics
    int x = 3;
    int y = 5;
    y = (x+3) * ( x/(y-4) ) ;
    printf("y: %d \n", y);

    x += 3; // is the same as x = x + 3
    x /= 3; // is the same as x = x / 3

    x++; //Increases x by 1, is same as x = x + 1
    x--; //Increases x by 1, is same as x = x - 1

    //Finally functions
    int v = multiply(2,3);
    printf("v is: %d \n", v);

    //For loop + command line arguments
    for (int i = 0; i < argc; i++)
    {
        printf("argument %d is %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}

int multiply (int value1, int value2)
{
    int result;
    result = value1 * value2;
    return result;
}
