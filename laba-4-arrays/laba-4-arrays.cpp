#include <iostream>
#include <iomanip>

int main()
{
    srand(time(0));
    using namespace std;

    int matrixSize = 3;

    // cout << "Fill in matrix size..." << endl;
    // cin >> matrixSize;

    cout << "Matrix size is " << matrixSize << endl;

    int **matrix = new int *[matrixSize];
    int *lastColumn = new int[matrixSize];

    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = new int[matrixSize];
    }

    // rows
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            int randNumber = -3 + rand() % 6;

            if (j == matrixSize - 1) lastColumn[i] = randNumber;

            matrix[i][j] = randNumber;
        }
    }

    cout << "matrix is " << endl;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "last column is" << endl;

    for (int i = 0; i < matrixSize; i++)
    {
        cout << lastColumn[i] << endl;
    }

    cout << "__________________" << endl;


    int* resultVector = new int[matrixSize];

    // main manipulations
    for (int i = 0; i < matrixSize; i++)
    {
        // each row
        int summ = 0;

        cout << "initial row summ = " << summ << endl << endl;
        for (int j = 0; j < matrixSize; j++)
        {
            // each elem
            //cout << matrix[i][j] << endl;

            cout << "summ before each elem = " << summ << endl;

            int resultNumber = matrix[i][j] * lastColumn[j];

            cout << "elem = " << matrix[i][j] << " x " << lastColumn[j] << " = " << resultNumber << endl;
            summ = summ + resultNumber;
            
            cout << "summ after each elem = " << summ << endl << endl;
        }

        cout << endl << "summ after all row elem = " << summ << endl;
        
        resultVector[i] = summ;

        cout << "____" << endl;
    }

    delete[] matrix;
    delete[] lastColumn;

    cout << "Result is:" << endl;

    for (int k = 0; k < matrixSize; k++)
    {
        cout << setw(2) << resultVector[k] << endl;
    }

    system("pause");
}