#include<stdio.h>

void knapsack(int weight[], int profit[], int n, int max_weight) {
    float ratio[n];    //calc ratio
    float final_array[n]; //knapsack final answer
    for(int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / weight[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                float temp_ratio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_ratio;

                int temp_weight = weight[i];
                weight[i] = weight[j];
                weight[j] = temp_weight;

                int  temp_profit = profit[i];
                profit[i] = profit[j];
                profit[j] = temp_profit;
            }   
        }
    }

    for (int i = 0; i < n; i++) {
        final_array[i] = 0.0; // Initialize final_array
    }
    
    float total_profit = 0.0; // Variable to keep track of total profit

    for (int i = 0; i < n; i++) {
        if (weight[i] > max_weight) {
            continue; // If the next item can't fit, break
        }
        final_array[i] = 1.0; // Take the whole item
        total_profit += profit[i]; // Add to total profit
        max_weight = max_weight - weight[i]; // Decrease remaining capacity
        if (max_weight <= 0) break;
    }

    if(max_weight > 0 && n > 0 && weight[n - 1] <= max_weight) { //if knapsack is empty or not
        final_array[n - 1] = 1.0; //if full item is used 
        total_profit += profit[n - 1]; //increase profit
    } else if(n > 0) {
        final_array[n - 1] = (float)max_weight / weight[n - 1];
        total_profit+= (float)max_weight / weight[n - 1] * profit[n - 1];
    }

    printf("Ratio od the items included is: ");
    for(int i = 0; i < n; i++) {
        printf("Ratio of Item%d: %.2f", i + 1, ratio[i]);
        printf("\n");
        return 0;
    }

    printf("Items included in the knapsack (as fractions):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, final_array[i]);
        printf("\n");
    }

    printf("total profit: %.2f\n", total_profit);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weight[n], profit[n], max_weight;
    //weight of knapsack
    for(int i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }
    
    //profit of knapsack
    for(int i = 0; i < n; i++) {
        printf("Enter the profit of item %d: ", i + 1);
        scanf("%d", &profit[i]);
    }

    printf("Enter max weight: ");
    scanf("%d", &max_weight); //getting max weight

    knapsack(weight, profit, n, max_weight);
}