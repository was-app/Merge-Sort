#include "merge_sort.h"


void swap(int *a, int *b, long unsigned int *desloc) {
    int aux = *a;
    *a = *b;
    *b = aux;
    (*desloc) += 3;
}


void merge(int arr[], int l, int m, int r, long unsigned int *comp, long unsigned int *desloc) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        (*comp)++;
        (*desloc)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        (*desloc)++;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        (*desloc)++;
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comp, desloc);
        mergeSort(arr, m + 1, r, comp, desloc);
        merge(arr, l, m, r, comp, desloc);
    }
}

void mergeSortWrapper(int arr[], int n, unsigned long *comp, unsigned long *desloc) {
    mergeSort(arr, 0, n-1, comp, desloc);
}
