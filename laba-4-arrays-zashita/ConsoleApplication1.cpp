#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");

    int rows = 3;
    int cols = 3;

    // rangle of matrix elements
    int range = 20;

    cout << "Input number of rows and columns of the array by space..." << endl;
    cin >> rows >> cols;
    cout << endl << endl;

    int** matrix = new int* [rows];

    // list of all possible matrix elements
    int *matrixElemsList = new int[range];

    // list of elements quantity in matrix
    int* matrixElemsQuntity = new int[range];

    // list of matrix elements indexes sum
    int* matrixElemsIndexesSum = new int[range];

    for (int k = 0; k < rows; k++)
    {
        matrix[k] = new int[cols];
    }

    int matrixElemsListCounter = 0;
    for (int rowNumber = 0; rowNumber < rows; rowNumber++)
    {
        for (int colNumber = 0; colNumber < cols; colNumber++)
        {
            int element = -(range / 2) + rand() % ((range / 2) + 1);
            matrix[rowNumber][colNumber] = element;
            cout << setw(3) << element << " ";

            bool included = false;
            for (int k=0; k < matrixElemsListCounter; k++)
            {
                if (matrixElemsList[k] == element)
                {
                    included = true;
                }
            }

            if (!included)
            {
                matrixElemsList[matrixElemsListCounter] = element;
                matrixElemsQuntity[matrixElemsListCounter] = 0;
                matrixElemsIndexesSum[matrixElemsListCounter] = rowNumber + colNumber;
                matrixElemsListCounter++;
            }
        }
        cout << endl;
    }

    for (int rowNumber = 0; rowNumber < rows; rowNumber++)
    {
        for (int colNumber = 0; colNumber < cols; colNumber++)
        {
            int element = matrix[rowNumber][colNumber];

            for (int k = 0; k < matrixElemsListCounter; k++)
            {
                if (matrixElemsList[k] == element)
                {
                    matrixElemsQuntity[k]++;
                    matrixElemsIndexesSum[k] = rowNumber+colNumber;
                }
            }
        }
    }

    cout << endl << "after calculating:" << endl << endl << setw(30) << left << "список элементов:";
    for (int k = 0; k < matrixElemsListCounter; k++)
    {
        cout << setw(3) << right << matrixElemsList[k] << " | ";
    }

    cout << endl << setw(30) << left << "количество вхождений:";
    for (int k = 0; k < matrixElemsListCounter; k++)
    {
        cout << setw(3) << right << matrixElemsQuntity[k] << " | ";
    }

    cout << endl << setw(30) << left << "максимальная сумма индексов:";
    for (int k = 0; k < matrixElemsListCounter; k++)
    {
        cout << setw(3) << right << matrixElemsIndexesSum[k] << " | ";
    }
    cout << endl << endl;

    int mostOftenNumber = 0;
    int repeatQuantity = 0;
    int indexesSum = 0;

    // по всему массиву неповторяющихся матричных элементов
    for (int k = 0; k < matrixElemsListCounter; k++)
    {
        // если количество раз вхождений этого элемента больше количества вхождений текущего
        if (matrixElemsQuntity[k] > repeatQuantity)
        {
            // в самый повторяемый элемент кладем текущий элемент
            mostOftenNumber = matrixElemsList[k];

            // сумму индексов самого повторяющегося элемента меняем на сумму индексов текущего 
            // элемента
            indexesSum = matrixElemsIndexesSum[k];

            // количество вхождений делаем количество вхождений текущего элемента
            repeatQuantity = matrixElemsQuntity[k];
        }
        // если количество вхождений текущего элемента совпадает с количеством вхождений самого частого элемента
        else if (matrixElemsQuntity[k] == repeatQuantity)
        {
            // если сумма индексов текущего элемента больше суммы индексов самого частого элемента
            if (matrixElemsIndexesSum[k] > indexesSum)
            {
                // самое частое теперь текущее
                mostOftenNumber = matrixElemsList[k];
                repeatQuantity = matrixElemsQuntity[k];
                indexesSum = matrixElemsIndexesSum[k];
            }
        }
    }

    cout << "Самое повторяемое число: " << mostOftenNumber
        << ". Количество повторений: " << repeatQuantity
        << ". Сумма индексов: " << indexesSum << endl;

    // clean memory
    for (int k = 0; k < rows; k++)
    {
        delete[] matrix[k];
    }
    delete[] matrix;

    delete[] matrixElemsIndexesSum;
    delete[] matrixElemsList;
    delete[] matrixElemsQuntity;

    system("pause");
    return 0;
}