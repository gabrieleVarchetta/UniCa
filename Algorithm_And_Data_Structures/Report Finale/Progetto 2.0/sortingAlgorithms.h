//
// Created by GAB on 14/05/2021.
//

#ifndef PROGETTO_2_0_SORTINGALGORITHMS_H
#define PROGETTO_2_0_SORTINGALGORITHMS_H

//Funzione scambio
void swap(int *variabile1, int *variabile2);

//Funzioni SelectionSort
void selectionSort(int *array, int dimensione);

//Funzioni InserctionSort
void insertionSort(int *array, int dimensione);

//Funzioni QuickSort
void quickSort(int *array, int u, int v);
int perno(int *array, int primo, int ultimo);

//Funzioni HeapSort
void heapSort(int *vettore, int n);
void adatta(int *array, int radice, int n);

//Funzioni MergeSort
void mergeSort(int *vettore, int *ordinata, int lower, int upper);
void merge(int *array, int *ordinata, int i, int m, int n);

#endif //PROGETTO_2_0_SORTINGALGORITHMS_H
