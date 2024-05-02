#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
// Function to print the subset whose sum is equal to the target
void printSubset(int subset[], int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
{
        printf("%d ", subset[i]);
    }
    printf("\n");
}
// Recursive function to find subsets with the given sum
void subsetSum(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int index, int *solutionSpaceIndex, int solutionSpace[][MAX_SIZE])
 {
    if (sum == targetSum)
{
        // Store the subset in the solution space
        for (int i = 0; i < subsetSize; i++)
{
            solutionSpace[*solutionSpaceIndex][i] = subset[i];
        }
        // Increment solution space index
        (*solutionSpaceIndex)++;
        return;
    }
    // Include elements in the subset one by one
    for (int i = index; i < n; i++) {
        subset[subsetSize] = set[i];
        // Move to the next element to include in the subset
        subsetSum(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1, solutionSpaceIndex, solutionSpace);
    }
}
// Wrapper function to initialize subset and call subsetSum function
int findSubsets(int set[], int n, int targetSum, int solutionSpace[][MAX_SIZE])
 {
    int subset[MAX_SIZE];
    int solutionSpaceIndex = 0;
    subsetSum(set, subset, n, 0, 0, targetSum, 0, &solutionSpaceIndex, solutionSpace);
    return solutionSpaceIndex;
}
// Driver code
int main()
 {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;
    int solutionSpace[MAX_SIZE][MAX_SIZE];
    printf("Subsets with sum %d are:\n", targetSum);
    int numSubsets = findSubsets(set, n, targetSum, solutionSpace);
    // Print the solution space
    for (int i = 0; i < numSubsets; i++)
 {
        printf("Subset %d: ", i + 1);
        for (int j = 0; solutionSpace[i][j] != 0; j++)
 {
            printf("%d ", solutionSpace[i][j]);
        }
        printf("\n");
    }

    return 0;
}
