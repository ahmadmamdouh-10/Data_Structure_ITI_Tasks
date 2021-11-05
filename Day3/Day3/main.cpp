#include <iostream>

using namespace std;

void Swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

void BubbleSort(int *arr, int size)
{
    int sorted = 0, loops = 0;

    for(int counter = 0 ; counter < size - 1 && sorted == 0; counter++)
    {
        sorted = 1;

        for(int index = 0; index < size - 1 - counter; index++)
        {
            if(arr[index] > arr[index + 1])
            {
                Swap(arr[index], arr[index + 1]);
                sorted = 0;
            }
            loops++;
        }

    }

    cout << "loops = " << loops << endl;
}

void SelectionSort(int *arr, int size)
{
    int minIndex;

    for(int counter = 0; counter < size -1 ; counter++)
    {
        minIndex = counter;

        for(int index = minIndex + 1; index < size ; index++)
        {
            if(arr[index] < arr[minIndex])
            {
                minIndex = index;
            }
        }
        Swap(arr[counter], arr[minIndex]);
    }

}

int BinarySearch(int *arr, int size, int data)
{
    BubbleSort(arr, size);


}

void Display(int *arr, int size)
{
    for(int index = 0; index < size; index++)
    {
        cout << arr[index] << "\t";
    }
}

int main()
{
    int arr[] ={4, 2, 5, 1, 6, 3};

    SelectionSort(arr, 6);
    Display(arr, 6);

    return 0;
}
