#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(const string& input);

void performOp(const string& input, stack<double>& calcStack);

int main()
{
	cout << "RPN CALCULATOR" << endl;

	stack<double> calcStack;
	string input;
	
	while (true)
	{
		double num;

		cout << ">>";
		cin >> input;
		
		if (istringstream(input) >> num)
		{
			calcStack.push(num);
		}
		else if (isOperator(input))
		{
			performOp(input, calcStack);
		}
		else if (input == "quit")
		{
			return 0;
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
	}
	return 0;
}

bool isOperator(const string& input)
{
	string ops[] = { "-", "+", "*", "/" };
	
	for (int i = 0; i < 4; i++)
	{
		if (input == ops[i])
		{
			return true;
		}
	}
	return false;
}

void performOp(const string& input, stack<double>& calcStack)
{
	double lVal, rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if (input == "-")
	{
		result = lVal - rVal;
	}
	else if (input == "+")
	{
		result = lVal + rVal;
	}
	else if (input == "*")
	{
		result = lVal * rVal;
	}
	else
	{
		result = lVal / rVal;
	}
	
	cout << result << endl;

	calcStack.push(result);
}