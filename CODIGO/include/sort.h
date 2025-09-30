#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

void selectionSort(int arr[], int n, unsigned long *comp, unsigned long *desloc);
void insertionSort(int arr[], int n, unsigned long *comp, unsigned long *desloc);
void bubbleSort(int arr[], int n, unsigned long *comp, unsigned long *desloc);

#endif