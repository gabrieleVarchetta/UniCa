//
// Created by GAB on 14/05/2021.
//

#ifndef PROGETTO_2_0_SUPPORTFUNCTIONS_H
#define PROGETTO_2_0_SUPPORTFUNCTIONS_H
#include <time.h>
#include "vectorFunctions.h"
#include "sortingAlgorithms.h"

void operazioniSelection(int *vettore, int dimensione);
void operazioniInsertion(int *vettore, int dimensione);
void operazioniQuick(int *vettore, int dimensione);
void operazioniMerge(int *vettore, int dimensione);
void operazioniHeap(int *vettore, int dimensione);
void stampaTempiConfrontiScambi(double time, int confronti, int scambi, int dim);
void stampaScelteAlgoritmi(void);
void stampaScelteOrdinamentoVettore(void);
void incComparison(void);
void incSwaps(void);
void resetComparison(void);
void resetSwaps(void);
int getComparison(void);
int getSwaps(void);

#endif //PROGETTO_2_0_SUPPORTFUNCTIONS_H
