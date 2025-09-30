#include "sort.h"
#include <stdlib.h>

void selectionSort(int arr[], int n, unsigned long *comp, unsigned long *desloc) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*comp)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*desloc) += 3;
        }
    }
}

void insertionSort(int arr[], int n, unsigned long *comp, unsigned long *desloc) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0) {
            (*comp)++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                (*desloc)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        (*desloc)++;
    }
}

void bubbleSort(int arr[], int n, unsigned long *comp, unsigned long *desloc) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*desloc) += 3;
            }
        }
    }
}
