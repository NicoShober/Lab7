#ifndef UWYONMAE_H
#define UWYONAME_H

// Optimized implementation of Bubble sort 
#include <stdio.h> 

void swapBubble(int *xp, int *yp);
void bubbleSort(int arr[], int n);

void insertionSort(int arr[], int n);

void swapSelection(int *xp, int *yp);
void selectionSort(int arr[], int n);

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

void swapQuick(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);


/* Function to print an array */
void printArray(int arr[], int size);


#endif UWYONAME_H






