//File name: program6.cpp
//Author: Elise Chavez
//Student ID: e837r258
//Assignment Number: 6
//Description: Uses an array of numbers to store pre-calculated values of the sine function of certain values, and can then display values of various different formulas further calculated from the score values
//Last Changed: July 17, 2017


#include <iostream> //allows you to use cin and cout
#include <cmath>  //allows you to calculate with sine function
#include <cstdlib> //use exit function
#include <iomanip> //setw and formatting
using namespace std;

const int SIZE = 20;	
double sine_values[SIZE];

//FUNCTION DECLARATIONS

void fill_array(double array[]); //no user input or output to screen--merely fills the array with numbers
void display_options(void); //will display options
void choose_option(int& option); //user makes selection, which is stored to option (the condition of the while loop), and option is the int value returned by the function
 
void initialize_option_1(double& a); //prompts user to initialize a for the equation, from the keyboard. updates the value of a
void calculate_option_1(double a); //multiplies pre-calculated sine valley with a, and displays results

void initialize_option_2(double& b); //prompts user to initialize b for the equation, from the keyboard. updates the value of b
void calculate_option_2(double b); //adds pre-calculated sine valley with b, and displays results

void initialize_option_3(double& a, double& b); //prompts user to initialize a and b for the equation. updates a and b
void calculate_option_3(double a, double b); //multiplies pre-calculated sine valley with a, adds b, and displays results

int main()
{

int start = 0, option; //condition for making the program loop
double a = 0, b = 0;

fill_array(sine_values); //don't use brackets next to the array in the function call!! //also don't need to include SIZE parameter bc SIZE is included when the array is declared

	while (start == 0)
	{
		option = 0; //allows option to be cleared every time loop is run again. This way I also don't have to put it at the end of every if/else branch.
		display_options();//display menu: user enters and updates the option value
		choose_option(option);
	
		if (option == 1)
		{
			initialize_option_1(a);
			calculate_option_1(a);
			start = 0; //doesn't prompt user to start over, it just does once the selected option is finished.
		}
		else if (option == 2)
		{
			initialize_option_2(b);
			calculate_option_2(b);
			start = 0;
		}
		else if (option == 3)
		{
			initialize_option_3(a,b);
			calculate_option_3(a,b);
			start = 0;
		}	
		else if (option == 4) //option to quit. 
		{	
			exit(0);
		}
		else 	//illegal options 
		{	cout << "Not a valid option; returning to options!" << endl;
		start = 0;  //uses start so it as least starts the loop over if option is incorrect
		}
	}//end of while loop
return 0;	
}


//FUNCTION DEFINITIONS
void fill_array(double array[]) //function before while loop is entered, fills the array with index values
{
	int i = 0;
		for (i = 0; i < SIZE; i++)
			sine_values[i] = sin(i);
}
void display_options(void) //function loop before options if-else branching, displays options
{
	cout <<  "Formulas for which you can display values:" << endl
	     << "   " << "1. y = a sin(x)" << endl
		 << "   " << right << "2. y = sin(x) + b" << endl
		 << "   " << right << "3. y = a sin(x) + b" << endl
		 << "   " << right << "4. Quit" << endl;
return;
}
void choose_option(int& option) //function inside of while loop before options if-else branching, prompts user to make a selection which determine which if-else branch it goes to
{
 cout << "Enter the number of your choice: ";
 cin >> option;
 cout << endl;
}


//all functions for option 1
void initialize_option_1(double& a)
{
	cout << "Enter the value of a: ";
	cin >> a;
	cout << endl;
}
void calculate_option_1(double a)
{
	int i = 0;
	double option1[SIZE];
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
	
	for (i = 0; i < SIZE; i++)
	{	
		option1[i] = a*sine_values[i]; //array option1 is the y. need a new array here to store the new sine values to, or it will store over the original precalculated values---that will make the next option's calculations options wrong, e.g., instead of adding two to the precalcluated sine values, it will add 2 to the new calcluated sine values
		
		std::cout <<
		std::fixed <<
		std::setprecision(3);
		cout << setw(7) << i;
		cout << setw(11) << option1[i] << endl;
	}
}

//all function for option 2
void initialize_option_2(double& b)
{
	cout << "Enter the value of b: ";
	cin >> b;
	cout << endl;
}
void calculate_option_2(double b)
{
	int i = 0;
	double option2[SIZE];
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
	
	for (i = 0; i < SIZE; i++)
	{	
		option2[i] = sine_values[i] + b; //array option2 is the y. need new array so these results stay independent from the original precalculated sine vales and the other calculated sine values
		
		std::cout <<
		std::fixed <<
		std::setprecision(3);
		cout << setw(7) << i;
		cout << setw(11) << option2[i] << endl;
	}
}

//all functions for option 3
void initialize_option_3(double& a, double& b)
{
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	cout << endl;
	
}
void calculate_option_3(double a, double b)
{
		int i = 0;
		double option3[SIZE];
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
	
	for (i = 0; i < SIZE; i++)
	{	
		option3[i] = (a*sine_values[i]) + b; //option3 array is y
		
		std::cout <<
		std::fixed <<
		std::setprecision(3);
		cout << setw(7) << i;
		cout << setw(11) << option3[i] << endl;
	}
}
