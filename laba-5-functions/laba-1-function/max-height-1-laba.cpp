#include <iostream>
#include <cmath>

#include <locale.h>

#include <iomanip>

using namespace std;

float calculateMaxHeight(float velocity, float angle)
{
#define PI 3.14159265
#define g 9.81

    float horizonAngleSinus = sin(angle * PI / 180);

    float height = pow((velocity * horizonAngleSinus), 2) / (2 * g);

    cout
        << "Max body's flight height with start velocity "
        << velocity << " m/s, thrown with "
        << angle << "° angle to horizon is " << setprecision(4) << height << "m." << endl
        << endl;
}

int main()
{
    setlocale(0, "Russian");

    float startVelocity = 0;
    float horizonAngle = 0;

    cout << "Fill in start velocity (m/s)..." << endl;
    cin >> startVelocity;

    cout << "Fill in ange to hoziron (°)..." << endl;
    cin >> horizonAngle;

    calculateMaxHeight(startVelocity, horizonAngle);

    system("pause");
}