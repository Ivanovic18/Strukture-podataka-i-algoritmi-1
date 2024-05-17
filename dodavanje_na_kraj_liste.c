#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int podatak;
    struct element *sledeci;
} Element;

void dodaj_na_kraj(Element **glava, int broj) {
    Element *novi = (Element*) malloc(sizeof(Element));

    if(novi == NULL) {
        printf("Greska pri alokaciji memorije\n");
        exit(0);
    }

    novi->podatak = broj;
    novi->sledeci = NULL;

    if(*glava == NULL) {
        *glava = novi;
    } else {
        Element *pomocni = *glava;
        while(pomocni->sledeci != NULL)
            pomocni = pomocni->sledeci;
        
        pomocni->sledeci = novi;
    }
}

void ispis(Element *glava) {
    if(glava == NULL) {
        printf("Lista je prazna\n");
        return;
    } else {
        while(glava) {
            printf("%d ", glava->podatak);
            glava = glava->sledeci;
        }
        printf("\n");
    }
}

int main() {
    Element *glava = NULL;

    dodaj_na_kraj(&glava, 1);
    dodaj_na_kraj(&glava, 8);
    dodaj_na_kraj(&glava, 0);
    dodaj_na_kraj(&glava, 4);
    dodaj_na_kraj(&glava, 2);
    dodaj_na_kraj(&glava, 0);
    dodaj_na_kraj(&glava, 0);
    dodaj_na_kraj(&glava, 4);

    ispis(glava);

    printf("\n");
    return 0;
}