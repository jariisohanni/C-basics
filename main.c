#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> //Define EXIT_SUCCESS
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#include "math_lib.h"

void basicExample();
void variableNamingExample();
void dataSizeAndTypeExample();
void arithmeticExample();
void blockExample();
void conditionalExample();
void conditionalExample2();
void conditionalExample3();
void switchExample(char c);
void switchExample2(int number);
void whileExample(int max_guess);
int forExample(int n);
int doWhileExample(int safe_guard);
int functionExample(int value);
void functionByReference(int *param);

void fileWriteExample(char* text);
void fileReadExample();

void pointerExample();
int multipleReturnValues(int a, int b, int *x, int *y);
char* outOfScopeExample();

void arraysAndPointersExample();
void stringAsArrays();

int* searchArrayItem(int* arr, int value, int l);

void assignment1();
void assignment2();
void assignment3();
void assignment4();

#define NUMBER_TO_GUESS 2
#define CHAR_TO_GUESS 'A'

const int M = 3;
const int N = 3;
void insertValue(int arr[M][N], int i, int j, int val);
void printArray(int arr[M][N]);

#define SIZEOF_ARRAY( arr ) sizeof( arr ) / sizeof( arr[0] )

int main(int argc, char *argv[])
{
    //fileWriteExample("char* text");
    //fileReadExample();
    //pointerExample();

    //int x = 1, y = 2;
    //
    //multipleReturnValues(10,10, &x, &y);
    //printf("values after: %d,%d \n", x,y);
    //arraysAndPointersExample();
    //stringAsArrays();

    int array[] = {10,13,43,33,92,4,11};

    int* p_loc = searchArrayItem(&array, 33,SIZEOF_ARRAY(array));
    printf("value before: %p \n", p_loc);
/*
    char* string = outOfScopeExample();
    puts (string) ;
*/
    //doWhileExample(5);
    /*int value = 5;
    int ref_value = 6;



    printf("value before: %d \n", value);
    int new_value = functionExample(value);
    printf("value after: %d, %d \n", value, new_value);

    int var  = 10;
    printf("value before: %d \n", var);
    functionByReference(&var);
    printf("value after: %d \n", var);


    int f = factorial(5);

    int arr[3][3] = {};

    insertValue(arr, 0,0, 10);
    printArray(arr);*/
    return EXIT_SUCCESS;
}

//CHECK THIS
//#define array_length (arr) (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof ((arr)[0]))

int* searchArrayItem(int* arr, int value, int l)
{
    int *parr , *parrend = arr + l;

    for (parr = arr ; parr < parrend ; parr++)
    {
        if (*parr == value )
            return parr ;
    }

}

void stringAsArrays()
{
   char str[] = "This is a string.";
   char str2[] = "aaaaa";
   char final[100] = {};

   char *pc = str ;

   str[10] = 'A';

   *(pc+10) = 'S';
   //puts( str );


   strcpy( final ,str );
   strcpy( final ,str2 );
   puts( final );

   strncpy( final ,str,3 );
   puts( final );
   //https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm

   if (strcmp(final, str ) == 0) //trcmp returns 0 if string are same
   {
       //String are same
   }

   strcat(final, str);
   puts( final );

   char *p_loc;
   p_loc = strchr(final, 'a');
   if(p_loc != NULL)
   {
       printf("%c", *(p_loc+1)); //Print next char after first A
   }

}

void arraysAndPointersExample()
{
    int arr[10] = {}; //Initialises arrey with zeros

    printf("size of int %d, and arr %d, lenght of array %d",
           sizeof(int),
           sizeof(arr),
           sizeof(arr) / sizeof(int)
           );

    int arr2[] = {5,5,5,5,5}; //Initialises arrey with values

    int a = arr [0];

    //These are same
    int *p_a = arr;
    int *p_a2 = &arr[0];

    //Using pointer to initialize array with values
    for(int i = 0; i < 8; i++)
        *(p_a++) = 5;

    //Above one is the same as this but faster
    for(int i = 0; i < 8; i++)
        arr[i] = 5;

    //Access element 5 of array directly
    p_a = arr;
    *(p_a + 5) = 10;

}

void pointerExample()
{
    int a;
    float b;
    char c;

    printf("Address of a: %p\n", &a);
    printf("Address of b: %p\n", &b);
    printf("Address of c: %p\n", &c);

    int n = 4;
    double pi = 3.14159;

    int *p_n = &n ; /* address of n */
    double *p_pi = &pi ; /* address of pi */

    printf("Value of c: %p\n", p_n);
    printf("Value of c: %p\n", p_pi);

    //Priting value which is stored in p_pi memory location
    printf ( "pi = %g\n" ,*p_pi ) ;

    //Adding 5.0 to value which is store in p_pi memory location
    *p_pi = *p_pi + 5.0;

    printf ( "pi = %g\n" ,*p_pi ) ;

}

char* outOfScopeExample()
{
    static char msg[] = "Aren’t pointers fun?" ;
    return msg;
}

int multipleReturnValues(int a, int b, int *p_x, int *p_y)
{

    *(p_x) = *(p_x) * 10;
    *(p_y) = *(p_y) * 10;

    return 1;
}

void fileWriteExample(char* text)
{
    FILE *fp;
    fp = fopen("test.txt", "w");

    /* C file open modes
     * 	rb		open for reading (The file must exist)	beginning
    w	wb		open for writing (creates file if it doesn't exist). Deletes content and overwrites the file.	beginning
    a	ab		open for appending (creates file if it doesn't exist)	end
    r+	rb+	r+b	open for reading and writing (The file must exist)	beginning
    w+	wb+	w+b	open for reading and writing. If file exists deletes content and overwrites the file, otherwise creates an empty new file	beginning
    a+	ab+	a+b	open for reading and writing (append if file exists)	end
    */

    if(fp != NULL)
    {
        fputs(text, fp);
        fclose(fp);
    }
    else //IF file not open
    {
       printf("file can't be opened\n");
    }
}

void fileReadExample()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    char str[60];
    if(fp != NULL)
    {
        if( fgets (str, 60, fp)!=NULL)
        {
              /* writing content to stdout */
              puts(str);
        }
        fclose(fp);
    }
    else //IF file not open
    {
       printf("file can't be opened\n");
    }


}
void insertValue(int arr[M][N], int i, int j, int val)
{
    arr[i][j] = val;
}

void printArray(int arr[M][N])
{
    int i, j;
        for (i = 0; i < M; i++)
          for (j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
}



void functionByReference(int *param)
{
    printf("I've received value %d\n", *param);
    (*param) = 5;
}

int functionExample ( int value )
{
    value = 7;
    return value;
}

int continueExample(int n)
{
    int sumOfNonEven = 0;

    for( int i = 0; i <= n ; i++)
    {
        if(i % 2 == 0)
            continue;

        sumOfNonEven += i;
    }

    return sumOfNonEven;

}


int doWhileExample(int safe_guard)
{
    int i = 0;
    char c ;
    do
    {
        puts ( "Keep going? (y/n) " ) ;
        c = getchar () ;
        getchar () ;
        i++;

    } while ( c == 'y' && i < safe_guard);

    return 0;
}

int forExample(int n)
{
    int fact = 1;
    for( int i = 1; i <= n ; i++)
    {
        fact *= i;
        printf("For execution number %d, factrional %d \n", i, fact);
    }

    return fact;

}

void whileExample(int max_guess)
{
    int loops = 1;

    int safety_limit = 10;

    while(loops <= max_guess)
    {
        printf("Loop number: %d (of %d) \n", loops, max_guess);

        if(loops == safety_limit)
            break;

        loops++;
    }

}

void switchExample(char c)
{
    switch (c)
    {
        case CHAR_TO_GUESS: //See no curly brackets needed here
            puts("Yes that what we are looking for");
            puts("Congrats");
            break;
        case 'B': //See no curly brackets needed here
            puts("Nope that was B");
            break;
        case 'C':
        case 'D':
        case 'E':
            puts("Nope that was C or D or E");
            break;
        default:
            puts("default excecuted!");
            //No need for break if default is last
    }
}

void switchExample2(int number)
{
    switch (number)
    {
        case NUMBER_TO_GUESS: //See no curly brackets needed here
            puts("Yes that what we are looking for");
            puts("Congrats");
            break;
        default:
            puts("default excecuted!");
            //No need for break if default is last
    }
}


void conditionalExample(int guess)
{
    //ONLY IF EXAMPLE
    if ( guess == NUMBER_TO_GUESS )
    {
        puts("You guessed right number");
        return;
    }

    // IF - ELSE EXAMPLE
    if ( guess % 2 == 0 )
        puts("Yes our number is even, so you are close");
    else
        puts("You guessed odd but our number is even");

}

void conditionalExample2(int guess)
{
    //IF-else if - else example
    if ( guess == NUMBER_TO_GUESS ) //For one line after if no brackets needed
        puts("You guessed right number");
    else if ( guess % 2 == 0 )
        puts("Yes our number is even, so you are close");
    else //If multiple lines then brackets needed
    {
        puts("You guessed odd but our number is even");
        puts("Congrats!");
    }


}

void conditionalExample3(int guess)
{
    //Using of multiple conditions (AND / OR)

    if( guess == (NUMBER_TO_GUESS - 1) || guess == (NUMBER_TO_GUESS + 1) )
        puts("Hey, you are very close");

}

void blockExample()
{
    int var = 1;

    {
        int var2 = 2;
        printf("%d",var2);
    }

    //var2 = 2; <<- Not availble any more as outside of the block
}

void basicExample()
{
    /*Examples of printing to console*/
    const char msg [ ] = "hello, students" ; // store msg to array then print

    puts("Hello this in application for Friday 22nd April 2022") ;  //Prints literal string
    puts(msg) ; //Prints array that contains charac

    puts("\\") ;
    puts("-> tab \t, -> cr \r, -> lf \n ");
    puts("\r\n"); //<- newline and goes to index 0 of that line
    puts("Hello new line") ;

    putchar(msg[1]); //prints value from array

    /*getting input from user - one character*/
    puts("\nPlease enter character:");
    char a = getchar(); //return character from stdin
    puts("You entered char:");
    putchar(a); //prints value from array
    puts("\n");

    /*getting input from user - string*/ //OLD C AND UNSAFE
    char str[5];
    getchar(); // HACK to make gets work: https://stackoverflow.com/questions/19691015/gets-not-working
    printf("Enter a string : ");
    gets(str); //This dangerous as might lead to overflow, use fgets instead
    puts(str);

    /*getting input from user best way- string*/ //NEW C AND SAFE
    printf("Enter a 2nd string : ");
    char input[5]; //4 chars + null terminator
    fgets(input, sizeof(input), stdin);
    printf("\n Your input: %s", &input);



    /*Data type conversion example*/
    int i = 1;
    float f;
    f = i + 3.1415; /* i is promoted to float */
    printf("Value of f: %1.5f \n",f);

    int result;
    float x1 = 1.5, x2 = 1.7;
    result = x1+x2; //Actual results would be flot 3.2 -> while running it will 3
    printf("results of result: %d \n",result);

    //Convert char to int automatically
    char A = 'A';
    printf("results of result: %d \n",A);

    //Forced type conversion
    int r2;
    float x3 = 1.5;
    r2 = (int) x3;
    printf("value of r2: %d \n",r2);
}



void variableNamingExample()
{
   //All these forbidden
   //int while, for, if, break, continue;

   //Good practive is to have consts as CAPITALISED
   const float PI = 3.1415; //Use const to make variable immutable

   //This wont work
   //PI = 3.4;

   int x; int X; //declares two different variables.
   //int money$owed; //(incorrect: cannot contain $)
   int total_count; //(correct)
   int score2; //(correct)
   //int 2ndscore //(incorrect: must start with a letter)
   //int long //(incorrect: cannot use keyword)


}

void dataSizeAndTypeExample()
{
   unsigned char usigned_a = 129; //ranges [0, 255]
   char char_a = 128; //ranges [-128, 127]

   printf("unsigned char a: %hu \n",usigned_a);
   printf("unsigned char a: %hi \n",char_a);

   printf("size char: %lu \n",sizeof(char));
   printf("size short: %lu \n",sizeof(short));
   printf("size int: %lu \n",sizeof(int));
   printf("size long: %lu \n",sizeof(long));

   printf("size char: %lu \n",sizeof(char));
   printf("size short: %lu \n",sizeof(short));
   printf("size float: %lu \n",sizeof(float));
   printf("size double: %lu \n",sizeof(double));

   //Application is using 10 ints -> 40 bytes of memory
   //Application is using 10 chars -> 10 bytes of memory
   //Difference x4

   //Variable declarations
   char var_a; //uninitialized ∗/
   char var_a2='A'; // intialized to ’A’∗/
   char var_a3='A',var_b='B'; //multiple variables initialized ∗/

   int xx, yy, zz;
   xx = yy = zz = 1;

}

void arithmeticExample()
{
    float res1 = 3/2; //Integer division result is 1
    float res2 = 3.0/2; //Both are coverted to float division result is 1.5
    float res3 = 3/2.0; //Both are coverted to float division result is 1.5

    printf("res1: %1.2f \n",res1);
    printf("res2: %1.2f \n",res2);
    printf("res3: %1.2f \n",res3);

    int cmp_1 =  1 < 2;
    int cmp_2 =  1 >= 2;

    printf("cmp_1: %d \n",cmp_1);
    printf("cmp_2: %d \n",cmp_2);

    int cmp_3 =  1 == 2;
    int cmp_4 =  1 != 2;

    printf("cmp_3: %d \n",cmp_3);
    printf("cmp_4: %d \n",cmp_4);

    int cmp_5 =  1 == 1 && 2 == 2; // -> 1 as both are true
    int cmp_6 =  2 == 1 && 2 == 2; // -> 0 as only later one is true

    printf("cmp_5: %d \n",cmp_5);
    printf("cmp_6: %d \n",cmp_6);

    int cmp_7 =  1 == 1 || 2 == 2; // -> 1 as both are true
    int cmp_8 =  2 == 1 || 2 == 2; // -> 1 as either is true

    printf("cmp_7: %d \n",cmp_7);
    printf("cmp_8: %d \n",cmp_8);

    int cmp_9 =  ! (1 == 2);//inverts the result as 1

    printf("cmp_9: %d \n",cmp_9);

    //Prefix and postfix incerements and decr

    int x = 0;

    //x++ -> Postfix -> Both result x as increased by 1, can be used instead of x=x+1
    x = 0;
    printf("Postfix: %d \n",x++);

    x = 0;
    //++x -> Prefix -> Both result x as increased by 1, can be used instead of x=x+1
    printf("Prefix: %d \n",++x);


    //x-- -> Postfix -> Both result x as increased by 1, can be used instead of x=x+1
    x = 0;
    printf("Postfix: %d \n",x--);

    x = 0;
    //--x -> Prefix -> Both result x as increased by 1, can be used instead of x=x+1
    printf("Prefix: %d \n",--x);

    x += 4; /*is the same as x = x + 4*/
    printf("Prefix: %d \n",x);
    //works also for - * /
}

void assignment1()
{
    //Size of data types
    printf("size char: %lu \n",sizeof(char));
    printf("size short: %lu \n",sizeof(short));
    printf("size int: %lu \n",sizeof(int));
    printf("size long: %lu \n",sizeof(long));

    printf("size char: %lu \n",sizeof(char));
    printf("size short: %lu \n",sizeof(short));
    printf("size float: %lu \n",sizeof(float));
    printf("size double: %lu \n",sizeof(double));

    //To make next lines work, use #include <limits.h> at the begining of the file
    printf("The number of bits in a byte %d\n", CHAR_BIT);
    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

    printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);

    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);

    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);
}

void assignment2()
{
    //Print numeric values of characters A,B,C and a,b,c

    printf("A = %d, B = %d, C = %d \n", 'A','B','C');
    printf("a = %d, b = %d, c = %d \n", 'a','b','c');
}

void assignment3()
{
    puts("\nPlease enter  1st character:");
    char ans_1 = getchar(); //return character from stdin

    getchar(); //HACK

    puts("\nPlease enter  2nd character:");
    char ans_2 = getchar(); //return character from stdin

    printf("Characters are same (0 = no, 1 = yes): %d", ans_1 == ans_2);

}

void assignment4()
{
    /*fist name and age*/
    printf("Enter name 1 : ");
    char name1[50]; //4 chars + null terminator
    fgets(name1, sizeof(name1), stdin);

    printf("Enter age 1 : ");
    int age1;
    scanf("%d", &age1);

    getchar(); //HACK

    printf("Enter name 2 : ");
    char name2[50];
    fgets(name2, sizeof(name2), stdin);

    printf("Enter age 2 : ");
    int age2;
    scanf("%d", &age2);

    printf ("Name 1: %s, age 1: %d,  Name 2: %s, age 2: %d, difference: %d",name1, age2, name2, age2, age1-age2);

}

