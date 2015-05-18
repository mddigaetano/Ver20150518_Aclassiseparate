#define MAX_NOMELEN 25
#define MAX_CLASSELEN 5
#define END_STR "[fine]"
#define FNAME_M "maschi.csv"
#define FNAME_F "femmine.csv"

typedef struct s_studente{
    char nome[MAX_NOMELEN];
    char cognome[MAX_NOMELEN];
    char classe[MAX_CLASSELEN];
    int sesso;
    unsigned int eta;
} studente;

studente* Inserimento(studente*, int, int*);
void Ordinamento(studente*, int);
int ScritturaFile(studente*,int);
studente* riallocaStudente(studente*, int);