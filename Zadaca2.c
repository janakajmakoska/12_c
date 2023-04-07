#include <stdio.h>
#include <string.h>

void generatePhoneNumber(char *str) {
    char phoneNumber[8] = "";
    int i;

    for (i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case 'A':
            case 'B':
            case 'C':
                phoneNumber[i] = '2';
                break;
            case 'D':
            case 'E':
            case 'F':
                phoneNumber[i] = '3';
                break;
            case 'G':
            case 'H':
            case 'I':
                phoneNumber[i] = '4';
                break;
            case 'J':
            case 'K':
            case 'L':
                phoneNumber[i] = '5';
                break;
            case 'M':
            case 'N':
            case 'O':
                phoneNumber[i] = '6';
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                phoneNumber[i] = '7';
                break;
            case 'T':
            case 'U':
            case 'V':
                phoneNumber[i] = '8';
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                phoneNumber[i] = '9';
                break;
        }
    }

    printf("%s = %s\n", str, phoneNumber);
}

int main() {
    char str[8];
    printf("Внесете седумбуквен стринг: ");
    scanf("%s", str);
    generatePhoneNumber(str);
    return 0;
}
