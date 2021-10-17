#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;

    for (int i = 5; i < 14; i++)
    {
        cout << i - (i - 2) << " x " << setw(2) << left << i - 3 << " = " << setw(2) << right << (i - (i - 2)) * (i - 3) << "\t\t" << i - (i - 3) << " x " << setw(2) << left << i - 3 << " = " << setw(2) << right << (i - (i - 3)) * (i - 3) << "\t\t" << i - (i - 4) << " x " << setw(2) << left << i - 3 << " = " << setw(2) << right << (i - (i - 4)) * (i - 3) << "\t\t" << i - (i - 5) << " x " << setw(2) << left << i - 3 << " = " << setw(2) << right << (i - (i - 5)) * (i - 3) << endl;
    }
    cout << endl;
    for (int i = 9; i < 18; i++)
    {
        cout << (i - (i - 6)) << " x " << setw(2) << left << (i - 7) << " = " << setw(2) << right << (i - (i - 6)) * (i - 7) << "\t\t" << (i - (i - 7)) << " x " << setw(2) << left << (i - 7) << " = " << setw(2) << right << (i - (i - 7)) * (i - 7) << "\t\t" << (i - (i - 8)) << " x " << setw(2) << left << (i - 7) << " = " << setw(2) << right << (i - (i - 8)) * (i - 7) << "\t\t" << (i - (i - 9)) << " x " << setw(2) << left << (i - 7) << " = " << setw(2) << right << (i - (i - 9)) * (i - 7) << endl;
    }

    system("pause");
}