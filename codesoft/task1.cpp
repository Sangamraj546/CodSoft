#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int number, guess; 
	int count = 0;
	srand(time(0));
	number = rand() % 100; 
	cout << "Guess My Number Game by Sangam Raj\n\n";

	do
	{
		cout << "Enter a number to guess  : ";
		cin >> guess;
		count++;

		if (guess > number)
			cout << "Too high!\n\n";
		else if (guess < number)
			cout << "Too low!\n\n";
		else{
		    cout<<endl<<"Your number is : "<<guess<<endl;
		    cout << "\nCorrect! You got it in " << count << " guesses!\n";
		}
	} while (guess != number);

	return 0;
}
