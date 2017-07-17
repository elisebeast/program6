#include <iostream> //allows you to use cin and cout
#include <cmath>  //allows you to calculate with sine function
#include <cstdlib> //use exit function
#include <iomanip> //setw and formatting
using namespace std;

const int SIZE = 20;	
double sine_values[SIZE];

//FUNCTION DECLARATIONS

void fill_array(double array[], int SIZE); //no user input or output to screen--merely fills the array with numbers
void display_options(void); //will display options
void choose_option(int& option); //user makes selection, which is stored to option (the condition of the while loop), and option is the int value returned by the function
 
void initialize_option_1(double& a); //prompts user to initialize a for the equation, from the keyboard. updates the value of a
void calculate_option_1(double a, double& y); //returns the value of y (calculated)
void display_option_1(void); //uses cout to display results of calculation 1

void initialize_option_2(double& b); //prompts user to initialize b for the equation, from the keyboard. updates the value of b
void calculate_option_2(double b, double& y); //returns the value of y (calculated)
void display_option_2(void); //uses cout to display results of calculation 2

void initialize_option_3(double& a, double& b); //prompts user to initialize a and b for the equation. updates a and b
void calculate_option_3(double a, double b, double& y); //returns the calculated value of y
void display_option_3(void); //uses cout to display resluts of calcluation 3

int main()
{

int start = 0, option; //condition for making the program loop
double a = 0, b = 0, y = 0;

fill_array(sine_values, SIZE); //don't use brackets next to the array in the function call!!

	while (start == 0)
	{
		option = 0; //allows option to be cleared every time loop is run again. This way I also don't have to put it at the end of every if/else branch.
		display_options();//display menu: user enters and updates the option value
		choose_option(option);
	
		if (option == 1)
		{
			initialize_option_1(a);
			calculate_option_1(a,y);
			display_option_1();

			start = 0; //doesn't prompt user to start over, it just does once the selected option is finished.
		}
		else if (option == 2)
		{
			initialize_option_2(b);
			calculate_option_2(b,y);
			display_option_2();
			start = 0;
		}
		else if (option == 3)
		{
			initialize_option_3(a, b);
			calculate_option_3(a,b,y);
			display_option_3();
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
void fill_array(double array[], int SIZE) //function before while loop is entered, fills the array with index values
{
	int i = 0;
		for (i = 0; i < SIZE; i++)
			sine_values[i] = i;
}
void display_options(void) //function inside of while loop before options if-else branching, displays options
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
void calculate_option_1(double a, double& y)
{
	int i = 0;
	
	for (i = 0; i < SIZE; i++)
	{	
		sine_values[i] = a*sin(i);
		y = sine_values[i];
	}
}
void display_option_1(void)
{
	int i = 0;
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
		for (i = 0; i < SIZE; i++)
		{
			std::cout <<
			std::fixed <<
			std::setprecision(3);
			cout << setw(7) << i;
			cout << setw(11) << sine_values[i] << endl;
		}
	cout << endl;
}

//all function for option 2
void initialize_option_2(double& b)
{
	cout << "Enter the value of b: ";
	cin >> b;
	cout << endl;
}
void calculate_option_2(double b, double& y)
{
	int i = 0;
	
	for (i = 0; i < SIZE; i++)
	{	
		sine_values[i] = sin(i) + b;
		y = sine_values[i];
	}
}
void display_option_2(void)
{
	int i = 0;
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
		for (i = 0; i < SIZE; i++)
		{
			std::cout <<
			std::fixed <<
			std::setprecision(3);
			cout << setw(7) << i;
			cout << setw(11) << sine_values[i] << endl;
		}
	cout << endl;
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
void calculate_option_3(double a, double b, double& y)
{
		int i = 0;
	
	for (i = 0; i < SIZE; i++)
	{	
		sine_values[i] = (a*sin(i)) + b;
		y = sine_values[i];
	}
}
void display_option_3(void)
{
	int i = 0;
	cout << setw(7) << "x" << setw(11) << "y" << endl;
	cout << setw (7) << "--"<< setw(11)<< "-----" << endl;
		for (i = 0; i < SIZE; i++)
		{
			std::cout <<
			std::fixed <<
			std::setprecision(3);
			cout << setw(7) << i;
			cout << setw(11) << sine_values[i] << endl;
		}
	cout << endl;
}
