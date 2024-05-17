#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int podatak;
    struct element *sledeci;
} Element;

void dodaj_sortirano(Element **glava, int broj) {
    Element *novi = (Element*) malloc(sizeof(Element));

    if(novi == NULL) {
        printf("Greska pri alokaciji memorije\n");
        exit(0);
    }

    novi->podatak = broj;
    novi->sledeci = NULL;

    if(*glava == NULL) {
        *glava = novi;
        return;
    } 

    Element *trenutni = *glava;
    Element *prehodni = NULL;

    if(trenutni->podatak >= broj) {
        novi->sledeci = trenutni;
        *glava = novi;
        return;
    }

    while(trenutni && trenutni->podatak < broj) {
        prehodni = trenutni;
        trenutni = trenutni->sledeci;
    }

    novi->sledeci = prehodni->sledeci;
    prehodni->sledeci = novi;
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

    dodaj_sortirano(&glava, 1);
    dodaj_sortirano(&glava, 8);
    dodaj_sortirano(&glava, 0);
    dodaj_sortirano(&glava, 4);
    dodaj_sortirano(&glava, 2);
    dodaj_sortirano(&glava, 0);
    dodaj_sortirano(&glava, 0);
    dodaj_sortirano(&glava, 4);

    ispis(glava);

    printf("\n");
    return 0;
}