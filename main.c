#include <stdio.h>
#include <stdlib.h>

#include "MyHeader.h"

int main(int argc, char** argv) {
    studente *arrayDinamico;
    int n;
    
    printf("Inizio Provolone\n");
    printf("Classi separate\n\n");
    
    arrayDinamico=(studente*)malloc(sizeof(studente));
    
    arrayDinamico=Inserimento(arrayDinamico,1, &n);
    
    Ordinamento(arrayDinamico,n);
    
    ScritturaFile(arrayDinamico,n);
    
    free(arrayDinamico);
    
    printf("\nFine Provolone");
    
    return (EXIT_SUCCESS);
}