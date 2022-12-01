#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(int argc, char *argv[]) {

	if(argc >= 2){		
		int Base=0;
		ListOfNumber List = NULL;		
		
		printf("Dans quelle base est votre liste ? (entre 2 et 16)\n");
		scanf("%d",&Base);		

		while(Base<2 || Base>16){
        		printf("Error ! Dans quelle base est votre liste ? (entre 2 et 16)\n");
        		scanf("%d",&Base);
    		}


		for(int i = 1; i<argc; i++){
			if ( Verification(Base, argv[i]) == 1){
				printf("Le chiffre : %s n'est pas dans la bonne base.\nIl ne sera pas dans la liste.\n", argv[i]);
			} else {
				List = InsererQueue(List, argv[i]);
			}
		}

		if(List != NULL){
			printf("Voici la liste a trier :\n");
    			PrintList(List);

   			List = tri(List,Base);

   			printf("\nVoici la liste trie :\n");
   			PrintList(List);
			printf("\n");
		} else {
			printf("Il n'y a pas de liste !\n");
		}
	} else {
		printf("Il n'y a pas de liste !\n");
	}

    return 0;
}

