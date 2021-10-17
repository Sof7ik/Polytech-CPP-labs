#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;

    // render column rows
    for (int k = 0; k <= 1; k++)
    {
        // multiplicator after "x";
        for (int i = 2; i <= 10; i++)
        {
            // first multiplicator
            for (int j = 1; j <= 4; j++)
            {
                //                 4 + (1*4) + 1    == 9
                cout << setw(2) << j + k * 4 + 1 << " X " << setw(2) << i << " = " << setw(2) << (j + k * 4 + 1) * i << "\t\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    system("pause");
}