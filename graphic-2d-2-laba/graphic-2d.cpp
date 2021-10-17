#include <iostream>
#include <cstdlib>

void getSectorByCoordinates(float x, float y);
void inputXY();

int main()
{
    using namespace std;
    setlocale(0, "Russian");

    inputXY();

    system("pause");
}

void inputXY()
{
    using namespace std;

    float x, y = 0;

    cout << "Введите точки X и Y через Enter" << endl;
    cin >> x;
    cin >> y;

    getSectorByCoordinates(x, y);
}

void getSectorByCoordinates(float x, float y)
{
    using namespace std;

    int res = -1;

    cout << "X = " << x << ", Y = " << y << endl;

    double quadraticParabol = -pow(x, 2) - 1;
    float straightLine = -x;
    float sqrtFunc = -sqrt(x);

    float Radius = sqrt(x * x + y * y);

    // I square
    // check 5th and 4th sectors
    if (x > 0 && y > 0)
    {
        // 4th sector
        if (y < 1) res = 4;

        //5th sector
        else if (y > 1) res = 5;
    }

    // II square
    // check 6, 7, 8, 15, 16, 17, 18
    if (y > 0 && x < 0)
    {
        // 6th, 7th, 8th sectors
        if (Radius > 2)
        {
            // 6th sector
            if (y > -x)
            {
                res = 6;
            }
            // 7th, 8th sectors
            else if (y < -x)
            {
                if (y > 1) res = 7;
                else if (y < 1) res = 8;
            }
        }
        // 15th, 16th, 17th, 18th
        else
        {
            // 15th, 16th sectors
            if (y < -x)
            {
                if (y > 1) res = 16;
                else if (y < 1) res = 15;
            }
            // 17th, 18th sectors
            else if (y > -x)
            {
                if (y > 1) res = 17;
                else if (y < 1) res = 18;
            }
        }
    }

    // III square
    // 9th, 10th, 13th, 14th sectors
    if (x < 0 && y < 0)
    {
        // 9th, 10th sectors
        if (Radius > 2)
        {
            if (y < quadraticParabol) res = 10;
            else res = 9;
        }
        // 13th, 14th sectors
        else
        {
            if (y > quadraticParabol) res = 14;
            else res = 13;
        }
    }

    // IV square
    // 1st, 2nd, 3rd, 11, 12, 19, 20, 21, 22
    if (x > 0 && y < 0)
    {
        // 3, 2, 1, 11
        if (Radius > 2)
        {
            if (y > sqrtFunc) res = 3;
            else if (y < sqrtFunc && y > straightLine) res = 2;
            else if (y < straightLine && y > quadraticParabol) res = 1;
            else if (y < quadraticParabol) res = 11;
        }
        // 19, 20, 21, 22, 12
        else
        {
            if (y > straightLine && y > sqrtFunc) res = 19;
            else if (y < straightLine && y > sqrtFunc) res = 20;
            else if (y > sqrtFunc && y < straightLine) res = 22;
            else if (y < sqrtFunc && y < straightLine && y > quadraticParabol) res = 21;
            else if (y < quadraticParabol) res = 12;
        }
    }

    // default output
    if (x == 0 && y == 0)
    {
        res = 20;
    }

    // пересечения
    // прямая в I и II четвертях
    if (y == 1)
    {
        if (x > 0) res = 5;
        else if (x == 0) res = 18;
        else if (x < 0)
        {
            cout << "Radius = " << Radius << endl;

            if (y == straightLine)
            {
                cout << "попали в y=-x" << endl;
                res = 18;
            }
            if (Radius == 2)
            {
                cout << "Попали в точку" << endl;
                res = 16;
            }
            if (Radius > 2) res = 8;
            if (Radius < 2) res = 16;
        }
    }

    // прямая y=-x
    if (y == straightLine)
    {
        //II square
        if (x < 0 && Radius == 2) res = 17;
        if (x < 0 && Radius > 2) res = 7;

        // IV square
        if (x > 0)
        {
            if (y == sqrtFunc) res = 22;

            if (Radius == 2 || Radius <= 2) res = 22;
            else if (Radius > 2) res = 2;

            if (x < 1) res = 20;
        }
    }

    // парабола в нижней части графика
    if (y == quadraticParabol)
    {
        if (x == 0) res = 21;
        else if (x < 0 && Radius == 2) res = 14;
        else if (x > 0 && Radius == 2) res = 21;
    }

    // y = -корень из x
    if (y == sqrtFunc)
    {
        if (Radius == 2) res = 22;
        else if (Radius > 2) res = 3;

        if (x < 1) res = 21;
        else if (x >= 1 && Radius <= 2) res = 22;
    }

    if (x == 0 && y > 2) res = 6;
    if (x == 0 && (y > 1 && y < 2) || (y == 2)) res = 17;

    if (x < 0 && y == 0)
    {
        if (Radius < 2) res = 14;
        else if (Radius > 2) res = 9;
        else if (Radius == 2) res = 15;
    }
    if (x > 0 && y == 0)
    {
        if (Radius == 2 || Radius < 2) res = 19;
        else if (Radius > 2) res = 4;
    }

    if (x == 0) {
        if (y == -2 || (y < -1 && y > -2)) res = 13;
        else if (y < -2) res = 11;
        else if (y > -1 && y < 0) res = 21;
        else if (y > 0 && y < 1) res = 18;
    }

    cout << "Заданная точка лежит в " << res << " секторе" << endl << "________________________________________" << endl;

    inputXY();
}