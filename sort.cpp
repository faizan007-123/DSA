#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, choice;

    cout << "Enter no. of elements in the array: ";
    cin >> n;

    int *ptr = new int[n];

    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
        cin >> ptr[i];

    do
    {
        cout << "\nEnter your choice: \n";
        cout << "1. Bubble Sort \n";
        cout << "2. Selection Sort \n";
        cout << "3. Insertion Sort \n";
        cout << "4. Merge Sort \n";
        cout << "5. Quick Sort \n";
        cout << "6. Exit \n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            bubbleSort(ptr, n);
            cout << "After Bubble Sort:\n";
            printArray(ptr, n);
            break;

        case 2:
            selectionSort(ptr, n);
            cout << "After Selection Sort:\n";
            printArray(ptr, n);
            break;

        case 3:
            insertionSort(ptr, n);
            cout << "After Insertion Sort:\n";
            printArray(ptr, n);
            break;

        case 4:
            mergeSort(ptr, 0, n - 1);
            cout << "After Merge Sort:\n";
            printArray(ptr, n);
            break;

        case 5:
            quickSort(ptr, 0, n - 1);
            cout << "After Quick Sort:\n";
            printArray(ptr, n);
            break;

        case 6:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    delete[] ptr;
    return 0;
}
