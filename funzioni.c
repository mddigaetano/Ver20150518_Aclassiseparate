#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyHeader.h"

studente* riallocaStudente(studente *arrayDinamicoCorrente,int dimensioneCorrente){
    studente *arrayDinamicoRiallocato=NULL;
    int i;
    
    arrayDinamicoRiallocato=(studente*)malloc((dimensioneCorrente*2)*sizeof(studente));
    
    for(i=0;i<dimensioneCorrente;i++){
        arrayDinamicoRiallocato[i]=arrayDinamicoCorrente[i];
    }
    free(arrayDinamicoCorrente);
    
    return arrayDinamicoRiallocato;
}

studente* Inserimento(studente* arrayDinamico, int dimensione, int* i){
    studente temp;
    
    *i=0;
    
    strcpy(temp.nome,"inizio");
    
    while(strcmp(temp.nome,END_STR)){
        printf("%d° studente\n", (*i)+1);
        printf("Inserisci il nome(%s per finire)(MAX %d caratteri): ",END_STR,MAX_NOMELEN);
        scanf("\n%[^\n]",temp.nome);
        
        if(strcmp(temp.nome,END_STR)){
            printf("Inserisci il cognome(MAX %d caratteri): ", MAX_NOMELEN);
            scanf("\n%[^\n]", temp.cognome);
            
            printf("Inserisci la classe(MAX %d caratteri): ", MAX_CLASSELEN);
            scanf("\n%[^\n]", temp.classe);
            
            printf("Inserisci il sesso(1-Maschio, 2-Femmina): ");
            scanf("%d", &(temp.sesso));
            
            printf("Inserisci l'eta': ");
            scanf("%d",&(temp.eta));
            
            if(!(*i<dimensione)){
                arrayDinamico=riallocaStudente(arrayDinamico,dimensione);
                dimensione*=2;
            }
            arrayDinamico[*i]=temp;
                (*i)++;
        }
    }
    
    return arrayDinamico;
}

void Ordinamento(studente v[], int n){
    int i,min,j;
    studente scambio;
    
    for(i=0;i<n-1;i++){
        min=i;
        
        for(j=i+1;j<n;j++){
            if(strcmp(v[j].cognome,v[min].cognome)<0){
                min=j;
            }
        }
        if(i != min){
            scambio=v[i];
            v[i]=v[min];
            v[min]=scambio;
        }
    }
}

int ScritturaFile(studente* array, int n){
    FILE *fileM, *fileF;
    int i;
    
    if((fileM=fopen(FNAME_M,"w")) && (fileF=fopen(FNAME_F,"w"))){
        fprintf(fileM,"Nome;Cognome;Classe;Sesso;Eta'\n");
        fprintf(fileF,"Nome;Cognome;Classe;Sesso;Eta'\n");
        
        for(i=0;i<n;i++){
            if(array[i].sesso == 1){
                fprintf(fileM,"%s;%s;%s;%d;%d\n",array[i].nome,array[i].cognome,array[i].classe,array[i].sesso,array[i].eta);
            }
            else if(array[i].sesso == 2){
                fprintf(fileF,"%s;%s;%s;%d;%d\n",array[i].nome,array[i].cognome,array[i].classe,array[i].sesso,array[i].eta);
            }
        }
        
        fclose(fileM);
        fclose(fileF);
    }
    else
        return -1;
    return 0;
}