#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> //Define EXIT_SUCCESS

#include <limits.h>

void basicExample();
void variableNamingExample();
void dataSizeAndTypeExample();
void arithmeticExample();

void assignment1();
void assignment2();
void assignment3();
void assignment4();

int main(int argc, char *argv[])
{
    assignment4();
    return EXIT_SUCCESS;
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

