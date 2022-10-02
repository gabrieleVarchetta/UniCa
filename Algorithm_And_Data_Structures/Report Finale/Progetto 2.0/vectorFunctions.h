//
// Created by GAB on 14/05/2021.
//

#ifndef PROGETTO_2_0_VECTORFUNCTIONS_H
#define PROGETTO_2_0_VECTORFUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
typedef enum{SELECTION_SORT, INSERTION_SORT, MERGE_SORT, HEAP_SORT, QUICK_SORT} sortingAlgo;

int *genera_array(int dimensione, inputType tipo_schema, sortingAlgo algo);
int inserisciDimensione(void);
void stampaVettore(int *array, int dimensione);
void stampaHeap(int *array, int dimensione);

#endif //PROGETTO_2_0_VECTORFUNCTIONS_H
