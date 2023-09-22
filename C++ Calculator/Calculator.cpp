#include <iostream>
#include <string>
using std::string; 
using namespace std;

void errorLimit() {
	static int attempts = 0;
	attempts++;
	if (attempts >= 3) {
		exit(1);
	}
}
void numberInputError(double& number) {
	do {
		cin >> number;

		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid number." << endl;
			cin.clear();             
			cin.ignore(1000, '\n'); 
			errorLimit();
		}
		else {
			break;  
		}
	} while (true); 
}

void operationInputError(char& userInputOp) {
	do{
		cin >> userInputOp;
		if (userInputOp != '+' && userInputOp != '-' && userInputOp != '/' && userInputOp != '*') {
			cout << "Invalid input. Please enter a valid operation." << endl;
			errorLimit();
		}
		else {
			break;
		}
	}while (true);
}

int main() {
	string userInput1;
	string userInput2;
	double userNum1;
	double userNum2;
	char operation;
	char choice;
	int attempts = 0;

	do {
			cout << "Please Enter Your First Number." << endl;
			numberInputError(userNum1);

			cout << "Please Enter Your Second Number." << endl;
			numberInputError(userNum2);

			cout << "Please Choose Your Desired Operation (+, -, *, /)." << endl;
			operationInputError(operation);

			switch (operation) {
					
			case '+':
				cout << "The answer is: ";
				cout << userNum1 + userNum2 << endl;
				break;
			case'-':
				cout << "The answer is: ";
				cout << userNum1 - userNum2 << endl;
				break;
			case '*':
				cout << "The answer is: ";
				cout << userNum1 * userNum2 << endl;
				break;
			case'/':
				if (userNum2 == 0) {
					cout << "The answer is undefined" << endl;
				}
				else {
					cout << "The answer is: ";
					cout << userNum1 / userNum2 << endl;
				}
				break;
			default:
				cout << "Operation Entered Invalid." << endl;
			}
			cout << "Do you want to perform another calculation? (y/n): ";
			cin >> choice;
		}
	while (choice == 'y' || choice == 'Y');
	cout << "Calculator closed. Goodbye!" << endl;

	return 0;
}
