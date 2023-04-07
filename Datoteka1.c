#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Дефинирање на структурата за делот
typedef struct {
    int code;
    char name[20];
    int quantity;
    float price;
} Part;

// Прототипи на функциите
void addPart();
void listPart();
void listAllParts();
void updatePart();
void deletePart();
void sellPart();

int main() {
    int choice;
    do {
        printf("\n\n");
        printf("1. Додади дел\n");
        printf("2. Испечати информации за дел по код\n");
        printf("3. Испечати информации за сите делови\n");
        printf("4. Ажурирај информации за дел\n");
        printf("5. Избриши дел\n");
        printf("6. Излез\n");
        printf("\n");
        printf("Изберете опција: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPart();
                break;
            case 2:
                listPart();
                break;
            case 3:
                listAllParts();
                break;
            case 4:
                updatePart();
                break;
            case 5:
                deletePart();
                break;
            case 6:
                printf("Крај на програмата.\n");
                break;
            default:
                printf("Погрешен избор!\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

// Функција за додавање на ново дело
void addPart() {
    Part p;
    FILE *fp;
    fp = fopen("hardware.dat", "ab");
    printf("Внесете код на делот: ");
    scanf("%d", &p.code);
    printf("Внесете име на делот: ");
    scanf("%s", p.name);
    printf("Внесете количина на делот: ");
    scanf("%d", &p.quantity);
    printf("Внесете цена на делот: ");
    scanf("%f", &p.price);
    fwrite(&p, sizeof(Part), 1, fp);
    fclose(fp);
}

// Функција за испечатување на информации за дел по код
void listPart() {
    int code;
    Part p;
    FILE *fp;
    fp = fopen("hardware.dat", "rb");
    printf("Внесете код на делот: ");
    scanf("%d", &code);
    while (fread(&p, sizeof(Part), 1, fp)) {
        if (p.code == code) {
            printf("Код: %d\n", p.code);
            printf("Име: %s\n", p.name);
            printf("Количина: %d\n", p.quantity);
            printf("Цена: %.2f\n", p.price);
            break;
        }
    }
    fclose(fp);
}

// Функција за испечатување на информации за сите делови
void listAllParts() {
Part p;
FILE *fp;
fp = fopen("hardware.dat", "rb");
printf("Сите делови:\n");
while (fread(&p, sizeof(Part), 1, fp)) {
printf("Код: %d\n", p.code);
printf("Име: %s\n", p.name);
printf("Количина: %d\n", p.quantity);
printf("Цена: %.2f\n", p.price);
printf("\n");
}
fclose(fp);
}

// Функција за ажурирање на информации за дел
void updatePart() {
int code, found = 0;
Part p;
FILE *fp;
fp = fopen("hardware.dat", "r+b");
printf("Внесете код на делот за ажурирање: ");
scanf("%d", &code);
while (fread(&p, sizeof(Part), 1, fp) && found == 0) {
if (p.code == code) {
printf("Код: %d\n", p.code);
printf("Име: %s\n", p.name);
printf("Количина: %d\n", p.quantity);
printf("Цена: %.2f\n", p.price);
printf("Внесете нови информации за делот:\n");
printf("Внесете ново име на делот: ");
scanf("%s", p.name);
printf("Внесете нова количина на делот: ");
scanf("%d", &p.quantity);
printf("Внесете нова цена на делот: ");
scanf("%f", &p.price);
fseek(fp, -sizeof(Part), SEEK_CUR);
fwrite(&p, sizeof(Part), 1, fp);
found = 1;
}
}
fclose(fp);
if (found == 0) {
printf("Делот не е пронајден!\n");
}
}

// Функција за бришење на дел
void deletePart() {
int code, found = 0;
Part p;
FILE *fp, *tempfp;
fp = fopen("hardware.dat", "rb");
tempfp = fopen("temp.dat", "wb");
printf("Внесете код на делот за бришење: ");
scanf("%d", &code);
while (fread(&p, sizeof(Part), 1, fp)) {
if (p.code != code) {
fwrite(&p, sizeof(Part), 1, tempfp);
} else {
found = 1;
}
}
fclose(fp);
fclose(tempfp);
remove("hardware.dat");
rename("temp.dat", "hardware.dat");
if (found == 1) {
printf("Делот е успешно избришан.\n");
} else {
printf("Делот не е пронајден!\n");
}
}
