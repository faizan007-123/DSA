#include <iostream>
using namespace std;
int main()
{   
    int a[3][3];
    int b[3][3];
    int c[3][3];
    int choice;

    cout << "Enter elements for matrix A: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    
    cout << "\nEnter elements for matrix B: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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
            for (int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                    c[i][j] = a[i][j] + b[i][j];
            }

            cout << "Addition of A and B: \n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;
     
            case 2:
            for (int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                    c[i][j] = a[i][j] - b[i][j];
            }

            cout << "Subtraction of A and B: \n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;
     
            case 3:

            break;

            case 4:
            for (int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                    c[i][j] = a[j][i];
            }

            cout << "Transpose of A: \n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << c[i][j] << "  ";                
                
                cout << "\n";
            }
            break;

            default:
            cout << "Invalid Input...\n";
            cout << "Try again...\n";
            break;
        }

    } while (choice != 5);
    
    return 0;
}