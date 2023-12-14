#include <iostream>
using namespace std;

template <typename T>
void selectionSort1(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void intarr()
{
    cout << "Enter the size of integer array : ";
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " no of element ";
        cin >> arr[i];
    }
    cout<<" Array before sorting : ";
    printArray(arr, size);
    selectionSort1(arr, size);
    cout<<" Array after sorting : ";
    printArray(arr, size);
}
void floatarr()
{
    cout << "Enter the size of float array : ";
    int size;
    cin >> size;
    float arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " no of element ";
        cin >> arr[i];
    }
    cout<<" Array before sorting : ";
    printArray(arr, size);
    selectionSort1(arr, size);
    cout<<" Array after sorting : ";
    printArray(arr, size);
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Integer Array\n2. Float Array\n3. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            intarr();
            break;
        case 2:
            floatarr();
            break;
        case 3:
            cout << "Exited!!!";
            break;
        default:
            break;
        }
    } while (choice == 1 || choice == 2);
    return 0;
}
