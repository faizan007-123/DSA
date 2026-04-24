#include <stdio.h>
#include <stdlib.h>

void traverse(int *, int *);
void insert(int *, int *);
void delete(int *, int *);
void update(int *);
void merge(int *, int *, int *, int *);

void main()
{
    int n, choice;
    int *arr;

    printf("Enter no. of elements in the array 1: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    int *brr;    
    int m;

    printf("Enter no. of elements in the array 2: ");
    scanf("%d", &m);

    brr = (int *)malloc(m * sizeof(int));

    printf("Enter array elements: ");
    for (int j = 0; j < m; j++)
        scanf("%d",&brr[j]);

    do
    {
        printf("1.Traversal\n");
        printf("2.Insertion\n");
        printf("3.Deletion\n");
        printf("4.Updation\n");
        printf("5.Merging\n");
        printf("6.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            traverse(arr, &n);
            break;

        case 2:
            insert(arr, &n);
            break;

        case 3:
            delete(arr, &n);
            break;

        case 4:
            update(arr);
            break;
            
        case 5:
            merge(arr, &n, brr, &m);
            break;

        case 6:
            printf("Program will exit...\n");
            break;  

        default:
            printf("Try Again...\n");
            break;
        }

    } while (choice != 6);

    free(arr);
}

void traverse(int *a, int *s)
{        
    printf("Array Elements: ");
    for (int j = 0; j < *s; j++) 
        printf("%d ",a[j]);    

    printf("\n");
}

void insert(int *a, int *s) 
{
    int new;
    int index;
    int temp;

    printf("Enter the value to be inserted and the position of the element: ");
    scanf("%d%d",&new,&index);

    *s = *s + 1;
    a = (int *) realloc(a, (*s) * sizeof(int));

    for (int i = index; i < *s; i++)
    {
        temp = a[i];
        a[i] = new;
        new = temp;
    }
}

void delete(int *a, int *s) 
{
    int index;
    int temp;

    printf("Enter the position of the element: ");
    scanf("%d",&index);

    for (int i = index; i < *s - 1; i++)
        a[i] = a[i + 1];

    *s = *s - 1;
    a = (int *) realloc(a, (*s) * sizeof(int));
}

void update(int *a) 
{
    int val;
    int index;

    printf("Enter the new value and the index of the element to be modified: ");
    scanf("%d%d",&val,&index);

    a[index] = val;    
}

void merge(int *a, int *s, int *b, int *t) 
{
    int *c;
    int i;

    c = malloc((*s + *t) * sizeof(int));

    for (i = 0; i < *s; i++)
        c[i] = a[i];
        
    int j = i;
    int x = 0;

    while(j < (*s + *t))
    {
        c[j] = b[x];
        x++;
        j++;
    }

    printf("Merged Array: \n");
    for (int k = 0; k < (*s + *t); k++)
        printf("%d ",c[k]);
        
    printf("\n");

}
