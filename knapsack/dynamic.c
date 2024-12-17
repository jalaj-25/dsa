#include <stdio.h>
#include <time.h>

typedef struct Item {
    int weight;
    int profit;
    float ratio; 
} Item;

void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[max_idx].ratio) {
                max_idx = j;
            }
        }
        Item temp = items[i];
        items[i] = items[max_idx];
        items[max_idx] = temp;
    }
}

float fractionalKnapsack(Item items[], int n, int max_weight) {
    sortItemsByRatio(items, n); 
    float total_profit = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= max_weight) {
            total_profit += items[i].profit; 
            max_weight -= items[i].weight; 
        } else {
            total_profit += items[i].profit * ((float)max_weight / items[i].weight);
            break; 
        }
    }    
    return total_profit;
}

int main() {
    int n, max_weight;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n]; 

    for (int i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter the profit of item %d: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight; 
    }

    printf("Enter max weight: ");
    scanf("%d", &max_weight); 

    clock_t start = clock(); // Start the timer
    float max_profit = fractionalKnapsack(items, n, max_weight);
    clock_t end = clock(); // End the timer

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken

    printf("Maximum profit in the fractional knapsack: %.2f\n", max_profit);
    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}
