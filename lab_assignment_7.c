#include <stdio.h>

void swap(int *xp, int *yp, int *swaps) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
  
  swaps[*xp]++;
  swaps[*yp]++;

}

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                
                swap(&arr[j], &arr[j+1], swaps);
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx;
    int totalSwaps = 0;
  
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {

            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;


            swaps[arr[i]]++;
            swaps[arr[min_idx]]++;


            printf("%d: %d\n", arr[i], swaps[arr[i]]);
            printf("%d: %d\n", arr[min_idx], swaps[arr[min_idx]]);

            totalSwaps += 2;
        }
    }
}


void displaySwaps(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0};
    int swaps2[100] = {0};

    // Bubble Sort for array1
    bubbleSort(array1, n1, swaps1);
    printf("array1 bubble sort:\n");
    displaySwaps(array1, n1, swaps1);
    int totalSwaps1 = 0;
    for (int i = 0; i < n1; i++) {
        totalSwaps1 += swaps1[array1[i]];
    }
    printf("total swaps: %d\n\n", totalSwaps1 / 2);

    // Bubble Sort for array2
    bubbleSort(array2, n2, swaps2);
    printf("array2 bubble sort:\n");
    displaySwaps(array2, n2, swaps2);
    int totalSwaps2 = 0;
    for (int i = 0; i < n2; i++) {
        totalSwaps2 += swaps2[array2[i]];
    }
    printf("total swaps: %d\n\n", totalSwaps2 / 2);

  for (int i = 0; i < 100; i++) {
      swaps1[i] = 0;
      swaps2[i] = 0;
  }

    // Selection Sort for array1
    selectionSort(array1, n1, swaps1);
    printf("array1 selection sort:\n");
    displaySwaps(array1, n1, swaps1);
    totalSwaps1 = 0;
    for (int i = 0; i < n1; i++) {
        totalSwaps1 += swaps1[array1[i]];
    }
    printf("total swaps: %d\n\n", totalSwaps1);

    // Selection Sort for array2
    selectionSort(array2, n2, swaps2);
    printf("array2 selection sort:\n");
    displaySwaps(array2, n2, swaps2);
    totalSwaps2 = 0;
    for (int i = 0; i < n2; i++) {
        totalSwaps2 += swaps2[array2[i]];
    }
    printf("total swaps: %d\n", totalSwaps2);

    return 0;
}

