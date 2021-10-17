#include <iostream>
#include <cmath>

#include <locale.h>

#include <iomanip>

using namespace std;

int main()
{
    setlocale(0, "Russian");

#define PI 3.14159265
#define g 9.81

    float startVelocity = 0;
    float horizonAngle = 0;

    cout << "Введите начальную скорость тела (м/с)..." << endl;
    cin >> startVelocity;

    cout << "Введите угол к горизонту (°)..." << endl;
    cin >> horizonAngle;

    double horizonAngleSinus = sin(horizonAngle * PI / 180);

    float height = pow((startVelocity * horizonAngleSinus), 2) / (2 * g);

    cout << "Максимальная высота полета тела с начальной скоростью "
         << startVelocity << " м/с, брошенного под углом "
         << horizonAngle << "° к горизонту составит " << setprecision(4) << height << "м." << endl
         << endl;

    system("pause");
}