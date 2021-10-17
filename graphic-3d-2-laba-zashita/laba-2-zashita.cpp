#include <iostream>
#include <locale>
#include <cmath>

float coordinateIsInSphere(float x, float y, float z)
{
    return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

bool coordinateIsInCylinder(float x, float y, float z)
{
    return sqrt((pow(z - y, 2) + pow(x - z, 2) + pow(y - x, 2)) / 3) < 0.2;
}

int main()
{
    using namespace std;

    float x, y, z = 0;
    float Radius = 1;

    setlocale(0, "");

    cout << "Введите Ваши точки ..." << endl;
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;
    cout << "Z = ";
    cin >> z;

    if (coordinateIsInCylinder(x, y, z))
    {
        cout << "Точка в цилиндре";
        return 0;
    }

    if (coordinateIsInSphere(x, y, z) < pow(2, Radius) && !coordinateIsInCylinder(x, y, z))
    {
        cout << "Точка в сфере";
    }
    else if (coordinateIsInSphere(x, y, z) >= pow(2, Radius) && !coordinateIsInCylinder(x, y, z))
    {
        cout << "Точка вне сферы";
    }
}