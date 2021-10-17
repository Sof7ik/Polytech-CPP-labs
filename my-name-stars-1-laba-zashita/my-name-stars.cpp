#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;

    cout << setw(17) << "*" << setw(3) << "*" << endl;
    cout << setw(11) << "*******" << setw(11) << "*******" << setw(5) << "*" << setw(6) << "*" << setw(15)<< "*******" << endl;
    cout << setw(4) << "*" << setw(7) << "*" << setw(5) << "*" << setw(11) << "*" << setw(6) << "*"  << setw(7) << "*" << setw(8) << "*" << endl;
    cout << setw(3) << "*" << setw(8) << "*" << setw(11) << "*******" << setw(11) << "*******" << setw(15) << "*********" << endl;
    cout << setw(2) << "*" << setw(9) << "*" << setw(5) << "*" << setw(11) << "*" << setw(6) << "*" << setw(6) << "*" << setw(9) << "*" << endl;
    cout << setw(1) << "*" << setw(10) << "*" << setw(11) << "*******" << setw(11) << setw(5) << "*" << setw(6) << "*" << setw(5) << "*" << setw(10) << "*" << endl;

    system("pause");
}