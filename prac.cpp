#include <iostream>
using namespace std;
#define N 3

int main()
{   
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int choice;

    cout << "Enter elements for matrix A: ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    }
    
    cout << "\nEnter elements for matrix B: ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> b[i][j];
    }
    
    do
    {
        cout << "Enter your choice: \n";
        cout << "1. Addition of A and B \n";
        cout << "2. Subtraction of A and B \n"; 
        cout << "3. Multiplication of A and B \n"; 
        cout << "4. Transpose of A \n";
        cout << "5. Exit \n"; 
        cin >> choice;

        switch (choice)
        {
            case 1:
            for (int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                    c[i][j] = a[i][j] + b[i][j];
            }

            cout << "Addition of A and B: \n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;
     
            case 2:
            for (int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                    c[i][j] = a[i][j] - b[i][j];
            }

            cout << "Subtraction of A and B: \n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;
     
            case 3:
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    c[i][j] = 0;
                    for (int k = 0; k < N; k++)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            cout << "Multiplication of A and B: \n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    cout << c[i][j] << "  ";
                
                cout << "\n";
            }
            break;

            case 4:
            for (int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                    c[i][j] = a[j][i];
            }

            cout << "Transpose of A: \n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;

            case 5:
            cout << "Exiting...\n";
            break;

            default:
            cout << "Invalid Input...\n";
            cout << "Try again...\n";
            break;
        }

    } while (choice != 5);
    
    return 0;
}
