#include <iostream>
using namespace std;
#define N 3


void inputMatrix(int mat[N][N], char name)
{
    cout << "Enter elements for matrix " << name << ":\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
}

void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void addMatrix(int a[N][N], int b[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] + b[i][j];

    cout << "Addition of A and B:\n";
    displayMatrix(c);
}

void subtractMatrix(int a[N][N], int b[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] - b[i][j];

    cout << "Subtraction of A and B:\n";
    displayMatrix(c);
}

void multiplyMatrix(int a[N][N], int b[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << "Multiplication of A and B:\n";
    displayMatrix(c);
}

void transposeMatrix(int a[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[j][i];

    cout << "Transpose of A:\n";
    displayMatrix(c);
}

int main()
{
    int a[N][N], b[N][N], c[N][N];
    int choice;

    inputMatrix(a, 'A');
    inputMatrix(b, 'B');

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Transpose of A\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addMatrix(a, b, c);
                break;

            case 2:
                subtractMatrix(a, b, c);
                break;

            case 3:
                multiplyMatrix(a, b, c);
                break;

            case 4:
                transposeMatrix(a, c);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Input...\n";
        }

    } while (choice != 5);

    return 0;
}
