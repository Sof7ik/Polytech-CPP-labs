#include <iostream>
#include <cmath>

double checkFunc(float x)
{
	return sqrt(1 + x);
}

double mathRow(double x, double Eps)
{
	double sum = x / 2;
	double lastElem = sum;

	for (int i = 0; abs(lastElem) < Eps; i++)
	{
		if (i != 0)
		{
			lastElem = lastElem * x / pow(2, (i + 2));
			sum = sum + lastElem;
		}

		// cout << "Last elem = " << abs(lastElem) << "; sum is " << sum << endl;
	}

	return sum;
}

int main()
{
	using namespace std;

	double x = 0;
	double Epsilon = 0.0001;

	cout << "Fill in number ( must be <|1| )..." << endl;
	cin >> x;

	if (abs(x) < 1)
	{
		cout << "Total row sum = " << mathRow(x, Epsilon) << endl;
		cout << "check func is " << checkFunc(x) << endl;
	}
	else
	{
		cout << "Error occured. Filled number must be <|1|. Try again!";
	}

	system("pause");
}