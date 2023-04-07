#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Дефиниција на структурата Vraboten
typedef struct Vraboten {
    int id;
    char ime[50];
    char prezime[50];
    int vozrast;
    char pol;
    char bracnaSostojba;
    int kredibilnost;
    char adresa[100];
    int tekovnaPlata;
    int poranesnaPlata;
} Vraboten;

void vnesi_vraboten(Vraboten* vraboteni, int *n) {
    printf("ID: ");
    scanf("%d", &vraboteni[*n].id);
    printf("Ime: ");
    scanf("%c", &vraboteni[*n].ime);
    printf("Prezime: ");
    scanf("%c", &vraboteni[*n].prezime);
    printf("Vozrast: ");
    scanf("%d", &vraboteni[*n].vozrast);
    printf("Pol: ");
    scanf("%c", &vraboteni[*n].pol);
    printf("Brachna sostojba: ");
    scanf("%c", &vraboteni[*n].bracnaSostojba);
    printf("Kreditna istorija (0-100): ");
    scanf("%d", &vraboteni[*n].kredibilnost);
    printf("Adresa: ");
    scanf("%c", &vraboteni[*n].adresa);
    printf("Tekovna plata: ");
    scanf("%d", &vraboteni[*n].tekovnaPlata);
    printf("Poraneshna plata: ");
    scanf("%d", &vraboteni[*n].poranesnaPlata);
}

// Функција за сортирање на вработените по кредибилност
void sort_kred(Vraboten *vraboteni, int n) {
    int i, j;
    Vraboten temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (vraboteni[i].kredibilnost < vraboteni[j].kredibilnost) {
                temp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = temp;
            }
        }
    }
}

// Функција за сортирање на вработените по тековна плата
void sort_tekovnaPlata(Vraboten *vraboteni, int n) {
    int i, j;
    Vraboten temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (vraboteni[i].tekovnaPlata < vraboteni[j].tekovnaPlata) {
                temp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = temp;
            }
        }
    }
}

// Функција за сортирање на вработените по поранешна плата
void sort_poranesnaPlata(Vraboten *vraboteni, int n) {
    int i, j;
    Vraboten temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (vraboteni[i].poranesnaPlata < vraboteni[j].poranesnaPlata) {
                temp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = temp;
            }
        }
    }
}

// Функција за корегирање на податоците за еден вработен
void koregiraj_vraboten(Vraboten *vraboteni, int *n, int id) {
    int i;
    for (i = 0; i < *n; i++) {
        if (vraboteni[i].id == id) {
            printf("Vnesete novi vrednosti za vraboten %d\n", id);
            printf("Ime: ");
            scanf("%c", vraboteni[i].ime);
            printf("Prezime: ");
            scanf("%c", vraboteni[i].prezime);
            printf("Vozrast: ");
            scanf("%d", &vraboteni[i].vozrast);
            printf("Pol: ");
            scanf("%c", vraboteni[i].pol);
            printf("Bracna sostojba: ");
            scanf("%c", vraboteni[i].bracnaSostojba);
            printf("Kredibilnost: ");
            scanf("%d", vraboteni[i].kredibilnost);
            printf("Adresa: ");
            scanf("%c", vraboteni[i].adresa);
            printf("Tekovna plata: ");
            scanf("%d", &vraboteni[i].tekovnaPlata);
            printf("Poranesna plata: ");
            scanf("%d", &vraboteni[i].poranesnaPlata);
            printf("Informaciite za vraboteniot se uspesno promeneti.\n");
            return;
        }
    }
    printf("Ne postoi vraboten so dadeniot ID.\n");
}
void koregiraj_kredibilnost(Vraboten* vraboteni, int n) {
    for (int i = 0; i < n; i++) {
        if (vraboteni[i].tekovnaPlata > vraboteni[i].poranesnaPlata) {
            vraboteni[i].kredibilnost += 3;
            vraboteni[i].poranesnaPlata = vraboteni[i].tekovnaPlata;
        }
        else if (vraboteni[i].tekovnaPlata < vraboteni[i].poranesnaPlata) {
            vraboteni [i].kredibilnost -= 3;
            vraboteni[i].tekovnaPlata = vraboteni[i].poranesnaPlata;
        }
    }
}

int main() {
    Vraboten vraboteni[50];
    int n = 0;
    int izbor,i;

    do {
        printf("\nMenu:\n");
        printf("1. Vnesi vraboten\n");
        printf("2. Koregiraj kredibilnost\n");
        printf("3. Sortiraj po poraneshna plata\n");
        printf("4. Sortiraj po tekovna plata \n");
        printf("5. Sortiraj po kredibilnost \n");
        printf("6. Promeni podatoci\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                for(i=0;i<n;i++){
                vnesi_vraboten(vraboteni, &n);
                }
                break;
            case 2:
                koregiraj_kredibilnost(vraboteni, n);
                break;
            case 3:
                sort_poranesnaPlata(vraboteni, n);
                break;
            case 4:
                sort_tekovnaPlata(vraboteni, n);
                break;
            case 5:
                sort_kred(vraboteni, n);
                break;
            case 6:
                koregiraj_vraboten(vraboteni, n, id);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (izbor != 0);

    return 0;
}