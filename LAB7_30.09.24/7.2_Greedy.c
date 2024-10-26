#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int item_id;
    float profit;
    float weight;
    float profit_weight_ratio;
} ITEM;

void swap(ITEM *a, ITEM *b)
{
    ITEM temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(ITEM arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(ITEM arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void fractionalKnapsack(ITEM items[], int n, int capacity)
{
    float total_profit = 0.0;
    printf("Item No\tprofit\t\tWeight\t\tAmount to be taken\n");

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            total_profit += items[i].profit;
            capacity -= items[i].weight;
            printf("%d\t%.6f\t%.6f\t1.000000\n", items[i].item_id, items[i].profit, items[i].weight);
        }
        else if (capacity > 0)
        {
            float fraction = (float)capacity / items[i].weight;
            total_profit += items[i].profit * fraction;
            printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].profit, items[i].weight, fraction);
            capacity = 0; // Knapsack is full
        }
        else
        {
            printf("%d\t%.6f\t%.6f\t0.000000\n", items[i].item_id, items[i].profit, items[i].weight);
        }
    }

    printf("Maximum profit: %.6f\n", total_profit);
}

int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    heapSort(items, n);

    for (int i = 0; i < n / 2; i++)
    {
        swap(&items[i], &items[n - i - 1]);
    }

    fractionalKnapsack(items, n, capacity);

    return 0;
}
