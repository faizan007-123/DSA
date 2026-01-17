#include <iostream>
using namespace std; 
int main()
{   
    int n,sum;
    int ch;
    
    cout << "Enter no. of elements in the array: ";
    cin >> n;
    
    int *p = new int[n];
    
    
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    cin >> p[i];
    
    cout << "Original Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
        
        do
        {
        cout << "\nEnter your choice: \n";
        cout << "1.Traversal [Sum of elements] \n";
        cout << "2.Insertion \n";
        cout << "3.Updation \n";
        cout << "4.Deletion \n";
        cout << "5.Exit \n";
        cin >> ch;

        switch (ch)
        {

        case 1:
            sum = 0;
            
            for (int i = 0; i < n; i++)
                sum += p[i];
                
                cout << "Sum: " << sum << endl;
                break;
                
        case 2:
        {
            int *temp = new int[n + 1];
            int ind;
            int x;
            
            cout << "Enter the index no. and the element to be inserted: " << endl;
            cin >> ind >> x;
            
            for (int i = 0,j = 0; i < n + 1; i++,j++)
            {
                if(i == ind) {
                    temp[i] = x;
                    temp[i + 1] = p[j];
                    i = i + 1;
                }
                else
                temp[i] = p[j];
                
            }
            
            cout << "New Array: " << endl;
            
            for(int c = 0; c < n + 1; c++)
            cout << temp[c] << " ";
            
            cout << "\n";
            break;
        }    
            
        case 3:
            int rep;
            int index;
            
            cout << "Enter the index no. and the new value: ";
            cin >> index >> rep;
            
            for (int k = 0; k < n; k++)
            {
                if(k == index) 
                p[k] = rep;
            }
            
            cout << "Updated array: " << endl;
            for (int k = 0; k < n; k++)
            cout << p[k] << " ";
            
            cout << "\n";
            break;
            
        case 4:
        {
            int *t = new int[n - 1];
            int del;

            cout << "Enter the index no. of element to be deleted: ";
            cin >> del;

            for (int i = 0, j = 0; i < n; i++,j++)
            {
                if(i == del) {
                    t[j] = p[i + 1];
                    i = i + 1;
                }
                else
                    t[j] = p[i];
            }

            cout << "New array: \n";
            for(int a = 0; a < n - 1; a++)
                cout << t[a] << " ";

        
            break;
        }

        default:
            cout << "Exiting the program...\n";
            break;
        }

    } while (ch != 5);
    

    return 0;
}