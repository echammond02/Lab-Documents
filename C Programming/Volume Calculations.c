/*

Program Description: Provides the user with a menu to allow them to calculate the volume, gallons,
and cost of a hot tub or a pool. The user can also choose to calculate the factorial of a chosen number,
choose an amount of disks in a game of Tower of Hanoi and get a list of moves to complete it. The user
may also choose to calculate a fibonacci sequence given a number, or calculate the sum of a number and all
of its predecessors until 0.

All code is in a do(while) loop so that the user can have the option to do another calculation after the
previous one has completed.

All mathematical calculations are done on the backend and are not present to the user interface.

**************************************************

Date last modified: 2/1/23

Libraries included: stdio.h and math.h

CONSTANTS defined: M_PI

**************************************************

*/

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI acos (-1.0)
#endif

int hotTubCalculations();
int poolCalculations();
int userInput();
int factorial(int n);
void runHanoi(int n, char x, char y, char z);
int fibonacci(int n);
int sum_N(int n);

//GLOBAL VARIABLES ***********************************************
float poolLength = 0;
float poolWidth = 0;
float shallowDepth = 0; //MAKE SURE TO SUBTRACT 6in
float deepDepth = 0; //MAKE SURE TO SUBTRACT 6in
float deepLength = 0;
float shallowLength = 0;
float walkLength = 0;
int counter = 0; //Counter variable to return the amount of selections that the user has chosen.

float hotTubWidth = 0;
float hotTubDepth = 0;
int hotTubX = 0;


//FUNCTION TO ASK THE USER WHAT THEY WANT TO DO AND HANDLE USER INPUTS
int userInput()
{

int user = 3; //Creation of choice variable

//START OF THE BIG LOOP FOR THE WHOLE THING
do
{

//Ask the user which one they would like to calculate
int choice = 3;
	printf("\n*************************************************************************************************************\n");
	printf("\t\t\t\tMENU\t\t");
	printf("\n");
	printf("1)\tCalculate the volume, gallons, and cost to fill up a hot tub or pool.\n");
	printf("2)\tCalculate the factorial of a number.\n");
	printf("3)\tPrint all moves made for a game of Tower of Hanoi.\n");
	printf("4)\tPrint out a list of Fibonacci numbers.\n");
	printf("5)\tPrint out a number of your choosing as well as the sum of all integers until that number.\n");
	printf("*************************************************************************************************************\n\n\n");
	printf("Choose the option that you would like to do:\n");
	scanf("%d", &choice);

if (choice == 1)
{
	printf("\nWould you like to use a hot tub (Enter 0) or a pool? (Enter 1)");
        scanf("%d", &choice);
}

if (choice == 0)
{
printf("\nYou have chosen a hot tub\n");

//
//HOT TUB SECTION *******************************************************************
//


	//Ask the user what the hot tub dimensions are
do
{
	printf("\nWhat is the width of the hot tub in feet? (Must be between 8-14 ft)\n");
	scanf("%f", &hotTubWidth);
if (hotTubWidth > 14 || hotTubWidth < 8)

{
	printf("\nThis value is not in the range of accepted values. Please try again\n");
}
else
{
	printf("\n%.2f feet in width, okay. What is the Depth of the hot tub? (Must be between 3-5ft)\n", hotTubWidth);
	scanf("%f", &hotTubDepth);
	if (hotTubDepth > 5 || hotTubDepth < 3)
	{
		printf("This value is not in the range of accepted values. Please try again");
	}
	else
	{
	printf("\n%.2f feet in depth.\n\n", hotTubDepth);
	hotTubX=1;
	}

}
//Subtracting the 6in
hotTubDepth = hotTubDepth - 0.5;
//End of while
}
while (hotTubX == 0);



if (hotTubX == 1)
{

//Call to calculate hot tub values and display to user.
hotTubCalculations();
}

		}

else if (choice == 1)
{

printf("\nYou have chosen a pool\n");

//
//POOL SECTION **********************************************************************
//


//Start of user inputs **********************************************************************
int b = 0;
while (b != 1)
{
printf("\nPlease enter the length of the main part of the pool (between 40-70ft): \n");
scanf("%f", &poolLength);
if (poolLength < 40 || poolLength > 70)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
}


b = 0;
while (b != 1)
{
printf("\n%.2f feet. Please enter the width of the pool (between 15-30ft): \n", poolLength);
scanf("%f", &poolWidth);
if (poolWidth < 15 || poolWidth > 30)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
}

b = 0;
while (b != 1)
{
printf("\n%.2f feet. Please enter the depth of the shallow end (between: 0-5ft) \n", poolWidth);
scanf("%f", &shallowDepth);
if (shallowDepth < 0 || poolWidth > 30)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
//Subtract 6in for the top
shallowDepth = shallowDepth - 0.5;
}

b = 0;
while (b != 1)
{
printf("\n%.2f feet. Please enter the depth of the deep end (between 6-15ft) \n", shallowDepth);
scanf("%f", &deepDepth);
if (deepDepth < 6 || deepDepth > 15)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
//Subtract 6in from the top
deepDepth = deepDepth - 0.5;
}

//1/3 pool length and 1/2 the pool length calculations
float thirdPoolLength = (poolLength / 3);
float halfPoolLength = (poolLength / 2);


b = 0;
while (b != 1)
{
printf("\n%.2f feet. Please enter the length of the deep end (between 12ft and %.2fft) \n", deepDepth, halfPoolLength);
scanf("%f", &deepLength);
if (deepLength < 12 || deepLength > halfPoolLength)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
}


b = 0;
while (b != 1)
{
printf("\n%.2f feet. Please enter the length of the shallow end (between 10ft and %.2fft): \n", deepLength, halfPoolLength);
scanf("%f", &shallowLength);
if (shallowLength < 10 || shallowLength > halfPoolLength)
{
printf("This value is not between the contraints. Please try again.");
}
else (b=1);
}


b = 0;
while (b != 1)
{
printf("%.2f feet. Please enter the length of the walk-in end (between 5ft and %.2fft): \n", shallowLength, thirdPoolLength);
scanf("%f", &walkLength);
if (walkLength < 5 || walkLength > thirdPoolLength)
{
printf("%.2f feet.\n", walkLength);
}
else (b=1);
}

//Call to pool calculations to take the values inputted and calculate/show the user.
poolCalculations();

//END OF USER INPUTS **************************************************


}//END OF POOL ELIF

//IF FOR FACTORIAL CHOICE
else if (choice == 2)
{
int n = 0; //factorial number
	printf("\nYou have chosen to do a factorial.\n");
	printf("What integer would you like to take the factorial of?");
	scanf("%d", &n);
int fac = factorial(n);
	printf("\nThe factorial of %d is %d\n\n", n, fac);
}//END OF FACTORIAL ELIF


//IF FOR TOWERS OF HANOI
else if (choice == 3)
{

int n = 0; //disks
printf("\nChoose how many disks for the game: ");
scanf("%d", &n);
printf("\n");
runHanoi(n, 'A', 'C', 'B');

} //END OF TOWER CHOICE


//IF FOR FIBONACCI NUMBERS
else if (choice == 4)
{
int n = 0; //Fibonacci number
int i = 0; //Incrementer for fibonacci for the loop
int ctr = 0; //Counter for the loop
	printf("\nWhat number would you like the fibonacci sequence for?");
	scanf("%d", &n);

//Loop for Fibonacci
printf("The series is: \n");

for ( ctr = 1; ctr <= n; ctr++ )
{
	printf("%d\n", fibonacci(i));
	i++;
}


}//END OF FIBONACCI NUMBERS



//IF FOR SUM OF N
else if (choice == 5)
{

int n = 0;
printf("\nWhat number would you like to find the sum of n for?");
scanf("%d", &n);
printf("\n%d\n", sum_N(n));

}//END OF SUM OF N CHOICE
counter++;
printf("Would you like to do another? (0 for no, 1 for yes)");
scanf("%d", &user);

if (user == 0 )
{
        printf("\n\nEnding the program. We hope to be used again soon! :)\n\n");
}

} //END OF THE BIG DO WHILE
while (user == 1);


}//END OF USER INPUT FUNCTION




//HOT TUB CALC FUNCTION
int hotTubCalculations()
{

float radius = (hotTubWidth / 2);

//HOT TUB SIZE ********************
float hotTubArea = ( M_PI * pow(radius, 2) );
//printf("Hot tub size: %.2f", hotTubArea);


//HOT TUB VOLUME ******************
//Calculation of the hot tub volume
float hotTubVolume = ( pow(radius, 2) * hotTubDepth * M_PI );
//printf("The volume of the hot tub is: %.2f", hotTubVolume);


//HOT TUB COST ********************
float hotTubGallons = hotTubVolume * 7.481;
float hotTubCost = (hotTubGallons * 28) / 100;
//printf("The cost of filling the hot tub is $%.2f", hotTubCost);



//PRINTING OUT ALL VALUES OF HOT TUB
printf("\n\n*****************\nHot Tub Information:\n");
printf("\nHot tub width: %.2f feet\n", hotTubWidth);
printf("\nHot tub depth: %.2f feet\n", hotTubDepth);
printf("\nThe volume of the hot tub: %.2f cubic feet\n", hotTubVolume);
printf("\nThe gallons of the hot tub: %.2f gallons\n", hotTubGallons);
printf("\nThe cost of filling the hot tub: $%.2f\n", hotTubCost);
printf("\n*****************\n\n");

	return 0;
}// END OF HOT TUB CALCS



//POOL CALC FUNCTION
int poolCalculations()

{

//Pool volume 1
float poolVolume1 = 0;
poolVolume1 = (deepLength * poolWidth * deepDepth);

//Pool Volume 2
float poolVolume2 = 0;
float tLength = (poolLength - deepLength - shallowLength - walkLength);
poolVolume2 = ((shallowDepth + deepDepth) * tLength /2 ) * poolWidth;

//Pool Volume 3
float poolVolume3 = 0;
poolVolume3 = (shallowDepth * shallowLength * poolWidth);

//Pool Volume 4
float poolVolume4 = 0;
poolVolume4 = (walkLength * shallowDepth)/2 * poolWidth;

//Total pool volume
float totalPoolVolume = (poolVolume1 + poolVolume2 + poolVolume3 + poolVolume4);

//Pool gallons
float poolGallons = (totalPoolVolume * 7.481);

//Pool cost
float poolCost = 0;
poolCost = ((poolGallons * 28) / 100 );


//DISPLAY TO THE USER FOR THE POOL
printf("\n\n*****************************\n");
printf("Pool Information:\n");
printf("Pool Length: %.2fft\n", poolLength);
printf("Pool Width: %.2fft\n", poolWidth);
printf("Pool Shallow end depth: %.2fft\n", shallowDepth);
printf("Pool Deep end depth: %.2fft\n", deepDepth);
printf("Pool Deep end length: %.2fft\n", deepLength);
printf("Pool Shallow end length: %.2fft\n", shallowLength);
printf("Pool Walk-in end length: %.2fft\n", walkLength);
printf("\nPool volume: %.2f cubic feet\n", totalPoolVolume);
printf("Pool gallons: %.2f gallons\n", poolGallons);
printf("Cost to fill up the pool: $%.2f\n", poolCost);
printf("*****************************\n\n");
	return 0;
} //END OF POOL CALCULATION FUNCTION


//FUNCTION TO GIVE THE FACTORIAL OF A NUMBER
int factorial(int n)
{

	if (n==0)
		return 1;
	else
		return n * factorial(n - 1);

}//End of Factorial Function


//FUNCTION FOR TOWERS OF HANOI
void runHanoi(int n, char x, char y, char z)
{

	if (n == 1)
	{
		printf("\nMove disk 1 from stick %c to stick %c\n", x, y);
		return;
	}
	else
	{
		//Hanoi Algorithm slightly changed from CNIT315 lab manual. Taken from geeksforgeeks.org
		runHanoi(n-1,x,z,y); //Takes the current disk - 1 (the next lowest disk), and moves it from the rod it is at to the 'y' where the rod is going where n doesn't equal 1.
		printf("Move disk %d from stick %c to stick %c", n, x, y); //printf to notify the user
		runHanoi(n-1,z,y,x); //Recursive #2. Takes the current disk -  (the next lowest disk), and moes it to the third rod that isn't the x or y.
	}

}//End of Hanoi function

//FUNCTION FOR FIBONACCI NUMBERS
int fibonacci(int n)
{

	if (n == 0)
	{
	return 0;
	}
	else
	if (n == 1)
	{
	return 1;
	}
	else
	{
	return ( fibonacci(n-1) + fibonacci(n-2) );
	}
return n;
}//End of the Fibonacci function

int sum_N(int n)
{

if (n <= 1) //IF N is 1 or less, just return it.
{
return n;
}
else
{
return n + sum_N(n-1); //Otherwise, use itself PLUS the sum of the one before it calling it recursively.
}

//Different solution by my roomate: return n*(n+1)/2;
}

//Start of the main
int main ()

{

//Call to start menu for user input
userInput();
printf("\nNumber of processes done: %d\n\n", counter);
	return counter; //main return

}
