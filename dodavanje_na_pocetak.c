#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int podatak;
    struct element *sledeci;
} Element;

void dodaj_na_pocetak(Element **glava, int broj) {
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
        novi->sledeci = *glava;
        *glava = novi;
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

    dodaj_na_pocetak(&glava, 1);
    dodaj_na_pocetak(&glava, 8);
    dodaj_na_pocetak(&glava, 0);
    dodaj_na_pocetak(&glava, 4);
    dodaj_na_pocetak(&glava, 2);
    dodaj_na_pocetak(&glava, 0);
    dodaj_na_pocetak(&glava, 0);
    dodaj_na_pocetak(&glava, 4);

    ispis(glava);

    printf("\n");
    return 0;
}