#include <iostream>

void PrintArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void ShuffleArr(int* arr, int size)
{
    size_t i;
    for (i = 0; i < size - 1; i++)
    {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void CopyArr(int* source, int* target, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        target[i] = source[i];
    }
}


void Merge(int* arr, int start, int mid, int end)
{
    std::cout << start << " " << mid << " " << end << std::endl;
    int* leftHalf = new int[mid - start + 1];
    int* rightHalf = new int[end - mid];

    CopyArr(arr, leftHalf, 0, mid);
    CopyArr(arr, rightHalf, mid + 1, end);

    // merge together
    int leftIndex = 0;
    int rightIndex = 0;
    for (int i = 0; i < end - start; i++)
    {

    }
    delete[] leftHalf;
    delete[] rightHalf;
}

void MergeSort(int* arr, int start, int end)
{
    int mid = (end - start) + (end / 2);
    if (start < end)
    {
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
    }
    Merge(arr, start, mid, end);
}


int main()
{
    int* arr = new int[100];
    for (int i = 0; i < 100; i++)
        arr[i] = i;

    // MergeSort
    std::cout << "Merge Sort" << std::endl;
    ShuffleArr(arr, 100);
    MergeSort(arr, 0, 100);
    PrintArr(arr, 100);

    // QuickSort
    ShuffleArr(arr, 100);

}
