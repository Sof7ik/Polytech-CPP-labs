#include <iostream>
#include <cmath>

double checkFunc(float x)
{
	return sqrt(1 + x);
}

int main()
{
	using namespace std;

	double x = 0;
	double Epsilon = 0.0001;

	cout << "Fill in number ( must be <|1| )..." << endl;
	cin >> x;

	double sum = x / 2;
	double lastElem = sum;

	if (abs(x) < 1)
	{
		for (int i = 0; abs(lastElem) < Epsilon; i++)
		{
			if (i != 0)
			{
				lastElem = lastElem * x / pow(2, (i + 2));
				sum = sum + lastElem;
			}

			// cout << "Last elem = " << abs(lastElem) << "; sum is " << sum << endl;
		}

		// cout << "Total row sum = " << scientific << sum + 1 << endl;
	}
	else
	{
		cout << "Error occured. Filled number must be <|1|. Try again!";
	}

	cout << "check func is " << checkFunc(x) << endl;

	system("pause");
}