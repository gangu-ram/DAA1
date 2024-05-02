#include <stdio.h>
#include <stdlib.h>

struct Item 
{
    int value;
    int weight;
};

int compare(const void *a, const void *b) 
{
    double ratio1 = ((double)((struct Item *)a)->value / (double)((struct Item *)a)->weight);
    double ratio2 = ((double)((struct Item *)b)->value / (double)((struct Item *)b)->weight);
    return ratio2 > ratio1 ? 1 : -1;
}

double fractionalKnapsack(int W, struct Item arr[], int n) 
{
 
    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0;  
    double finalValue = 0.0; 

 
    for (int i = 0; i < n; i++) 
    {
         
        if (currentWeight + arr[i].weight <= W) 
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else 
        {
            
            int remaining = W - currentWeight;
            finalValue += arr[i].value * ((double)remaining / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() 
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);

    struct Item arr[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
