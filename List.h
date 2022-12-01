
#ifndef LO21_PROJET_LIST_H
#define LO21_PROJET_LIST_H

typedef struct elem {
    char* value ;
    struct elem* next ;
} Element ;

typedef Element* ListOfNumber;

ListOfNumber InsererQueue (ListOfNumber l, char* e);

int Verification (int Base, char* valeur);

ListOfNumber tri(ListOfNumber List, int Base);

void PrintTab(Element** Seau, int Base, int Etape);

int LONGUEUR(ListOfNumber List);

ListOfNumber concat(ListOfNumber List, ListOfNumber Seau);

void PrintList (ListOfNumber List);

Element * viderListe(Element *liste);

#endif //LO21_PROJET_LIST_H
