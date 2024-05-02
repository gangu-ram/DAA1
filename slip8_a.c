#include <stdio.h>
#include <stdlib.h>

 
struct Item {
    int value;
    int weight;
    float ratio;  
};

 
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

 
float fractionalKnapsack(int capacity, struct Item items[], int n) {
 
    qsort(items, n, sizeof(items[0]), compare);

    float totalValue = 0;  
    int remainingCapacity = capacity;  

 
    for (int i = 0; i < n; i++) {
 
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {  
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;  
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int n;  
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];  

 
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; 
    }

 
    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
