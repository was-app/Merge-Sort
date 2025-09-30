#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

void mergeSort(int arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc);
void mergeSortWrapper(int arr[], int n, unsigned long *comp, unsigned long *desloc);

#endif