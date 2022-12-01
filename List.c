#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Verification (int Base, char valeur[]){

    int i=0;

    while (valeur[i]!='\0'){ // Ce while permet de parcourir tous les caracteres de la valeur
        if(Base<=10){ // Si la base est entre 2 et 10 il n'y aura pas de probleme car elle est composée que de chiffres compris entre 0 et 9 
            if(valeur[i]>='0'+ Base || valeur[i] <'0'){
                return 1;
            }
        } else { // Si la base est superieur à 10 il faut verifie qu'elle est composée de chiffres compris entre 0 et 9 et des lettres de A à F
            if ((valeur[i] < '0' || valeur[i] > '9') && (valeur[i] < 'A' || valeur[i] >= 'A' + Base - 10)) {
                return 1;
            }
        }
        i++;
    }

    return 0;
}

ListOfNumber InsererQueue (ListOfNumber l, char* e){

    Element* newel = NULL;
    newel = (Element *) malloc( sizeof( Element ) ) ;
    newel->value=e;
    newel->next=NULL;

    if(l==NULL){ // si la liste est nul alors la liste aura qu'un element, qui est l'element ajouter

        l=newel;

    } else { 

        Element* p = l;

        while(p->next != NULL){ // parcourt tout la liste jusqu'au dernier element
            p=p->next;
        }

        p->next = newel; // ajoute l'element voulu à la fin de la liste
    }

    return l;
}

ListOfNumber tri(ListOfNumber List, int Base){

    Element** Seau;
    int i;
    int j;
    int l;
    int k;
    int max;

    max = LONGUEUR(List);
	
    Seau=(Element**)malloc(sizeof (Element*)*Base); // Initialise le tableau de liste de caractere
    for(i=0; i<Base; i++ ){
        Seau[i]=NULL;
    }

    for(j=0; j<max; j++){ // Repete n fois le procesus

        Element* f = List;

        while(f != NULL){ // parcourt toute la liste 

            char Nbr_carac = f->value[max-1-j]; // prends le caractere voulu en valeur
            int Nbr;

            if (Nbr_carac <= 70 && Nbr_carac >= 65) { // Verifie si la valeur est une lettre
                Nbr = Nbr_carac - 'A' + 10; // Transforme la lettre en entier de 10 à 15
            } else {
                Nbr = Nbr_carac - '0'; // Transforme le caractere en entier de 0 à 9
            }

            Seau[Nbr]=InsererQueue(Seau[Nbr], f->value); // insere la valeur dans le seau correspondant au caractere rechercher 
            f = f->next;
        }

        PrintTab(Seau, Base, j); // Affiche les tableaux

        List = viderListe(List); // Vide la liste

        for(l=0;l<Base;l++){
            List = concat(List, Seau[l]); // Assemble tout les seaux dans une liste
	    Seau[l] = NULL;
        }

    }

    for(k=0;k<Base;k++){ // libere la memoire du tableau de liste
           free(Seau[k]);
    }
    free(Seau);

    return List;

}


void PrintTab(Element** Seau, int Base, int Etape){

    int i;

    printf("\nEtape n %d:\n", Etape+1);

    for(i=0; i<Base; i++){

        PrintList(Seau[i]); // Affiche la liste corespondante au ieme Seau

    }


}

int LONGUEUR(ListOfNumber List){

    int max=0;
    int taille;

    Element* p = List;

    while (p != NULL){ // Parcourt toute la liste

        taille = strlen(p->value); // calcule la taille de la valeur

        if (taille>max){ // Si la taille est supurieur à l'ancien maximum alors la taille devient le maximum
            max=taille;
        }
        p = p->next ;
    }

    Element *index = List;

    while(index != NULL){ // parcourt la liste
        if(strlen(index->value) < max){ // Si la taille de la valeur est inferieur au maximum alors la valeur aura des 0 devant afin que toutes les valeurs soient de meme taille
            char * Full_number = (char*) malloc(sizeof(char)*max);
            int taille = (int)strlen(index->value);
            while(taille + (int)strlen(Full_number) != max) {
                strcat(Full_number, "0");
            }
            strcat(Full_number, index->value);
            index->value = Full_number;
        }
        index = index->next;
    }

    return max;
}

ListOfNumber concat(ListOfNumber List, ListOfNumber Seau){

    if(List==NULL) {
        return Seau;
    }else { 
        Element *tmp = List;
        while (tmp->next != NULL) { // Parcourt la liste
            tmp = tmp->next;
        }
        tmp->next = Seau; // ajouter le Seau à la fin de la liste
        return List;
    }

}

void PrintList (ListOfNumber List){

    if (List != NULL){
        Element* p = List;

        while (p != NULL) { // parcourt la liste et affiche toute ces valeurs
            printf("%s ", p->value);
            p = p->next ;
        }
    }
}

Element * viderListe(Element *liste)
{
    if(liste == NULL){
        return liste;
    }

    if(liste->next == NULL){ // libere l'unique valeur de la liste
       Element *p = liste;
       free(p);
       liste->next = NULL;

       return liste;
    }

    Element *elem = liste;

    while(elem != NULL) // Parcourt la liste en liberant toutes ces valeurs
    {
        Element *aSupprimer = elem;
        elem = elem->next;
        free(aSupprimer);
    }

    return elem;
}