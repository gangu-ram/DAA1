#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start, end;
    double time_taken;

    start = clock();  

    quickSort(arr, 0, n - 1);

    end = clock();  

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", time_taken);

    return 0;
}
