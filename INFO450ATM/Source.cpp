#include <iostream>
using namespace std;

void GetBills(int &amount, int &fifty, int &twenty, int &ten, int &five, int &one);

int main()
{
	char again = 'y'; // set up do-while loop
	int amount = 0, fifty = 0, twenty = 0, ten = 0, five = 0, one = 0; // initialize variables
	cout << "This program will allow you to make a withdrawal from the ATM.\nIt will give out the least amount of bills possible, prioritizing large bills." << endl;

	do // this loop contains the main program after variable declarations; if the user chooses, the loop will restart
	{
		cout << "Enter withdrawal amount: $";
		cin >> amount; // accepts user input

		while (amount > 300 || amount < 1) // checks to see if amount is outside of limit
		// if so, it prints an error message and starts the loop over; if not, it does nothing and continues
		{ 
			cout << "Sorry, withdrawals must be between $1 and $300. Please try again." << endl;
			cout << "Enter withdrawal amount: $";
			cin >> amount;
		}

		GetBills(amount, fifty, twenty, ten, five, one); // calls GetBills() function to calculate number of bills needed

		cout << "You will now be given:" << endl; // these six lines tell the user how many bills will be given
		cout << fifty << " $50 bills." << endl; // they do not actually generate money though
		cout << twenty << " $20 bills." << endl;
		cout << ten << " $10 bills." << endl;
		cout << five << " $5 bills." << endl;
		cout << one << " $1 bills." << endl;


		cout << endl << endl << "Would you like to make another withdrawal? Y/N: ";
		cin >> again; // restarts loop if user enters y or Y
	} while (again == 'y' || again == 'Y');

	system("pause"); // pause before closing program
	return 0; // close program
}

void GetBills(int &amount, int &fifty, int &twenty, int &ten, int &five, int &one)
{
	fifty = 0; // these five lines set the bill amounts to zero for all of them
	twenty = 0; // if this is not done, the bills will add up in subsequent loops
	ten = 0;
	five = 0;
	one = 0;

	if (amount / 50 >= 1) // check if at least one $50 bill can be given out
	{
		fifty = amount / 50; // since fifty is an integer, the number will be rounded down; ex. $165 / 50 would become 3
		amount = amount - (fifty * 50); // subtract $50 bills from the amount
	}

	if (amount / 20 >= 1) // check if at least one $20 bill can be given out after above bills
	{
		twenty = amount / 20; // see above
		amount = amount - (twenty * 20); // subtract $20 bills from the amount
	}

	if (amount / 10 >= 1) // check if at least one $10 bill can be given out after above bills
	{
		ten = amount / 10; // see above
		amount = amount - (ten * 10); // subtract $10 bills from the amount
	}

	if (amount / 5 >= 1) // check if at least one $5 bill can be given out after above bills
	{
		five = amount / 5; // see above
		amount = amount - (five * 5); // subtract $5 bills from the amount
	}

	one = amount; // this one doesn't need an if statement; if there are no $1 bills, nothing will change
	amount = 0;  // changes the amount to zero to prepare for future loops of the main program
}