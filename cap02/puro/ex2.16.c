#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero;

    printf("Digite um número entre 1 e 3999: ");
    scanf("%d", &numero);

    if(numero < 1 || numero > 3999){
        printf("Numero incorreto!\n");
        return 1;
    }

    printf("%d = ", numero);

    if (numero >= 1000) {
        if (numero >= 3000) {
            printf("MMM");
            numero -= 3000;
        } else if (numero >= 2000) {
            printf("MM");
            numero -= 2000;
        } else if (numero >= 1000) {
            printf("M");
            numero -= 1000;
        }
    }

    if (numero >= 100) {
        if (numero >= 900) {
            printf("CM");
            numero -= 900;
        } else if (numero >= 800) {
            printf("DCCC");
            numero -= 800;
        } else if (numero >= 700) {
            printf("DCC");
            numero -= 700;
        } else if (numero >= 600) {
            printf("DC");
            numero -= 600;
        } else if (numero >= 500) {
            printf("D");
            numero -= 500;
        } else if (numero >= 400) {
            printf("CD");
            numero -= 400;
        } else if (numero >= 300) {
            printf("CCC");
            numero -= 300;
        } else if (numero >= 200) {
            printf("CC");
            numero -= 200;
        } else if (numero >= 100) {
            printf("C");
            numero -= 100;
        }
    }

    if (numero >= 10) {
        if (numero >= 90) {
            printf("XC");
            numero -= 90;
        } else if (numero >= 80) {
            printf("LXXX");
            numero -= 80;
        } else if (numero >= 70) {
            printf("LXX");
            numero -= 70;
        } else if (numero >= 60) {
            printf("LX");
            numero -= 60;
        } else if (numero >= 50) {
            printf("L");
            numero -= 50;
        } else if (numero >= 40) {
            printf("XL");
            numero -= 40;
        } else if (numero >= 30) {
            printf("XXX");
            numero -= 30;
        } else if (numero >= 20) {
            printf("XX");
            numero -= 20;
        } else if (numero >= 10) {
            printf("X");
            numero -= 10;
        }
    }

    if (numero >= 1) {
        if (numero == 9) {
            printf("IX");
            numero -= 9;
        } else if (numero >= 8) {
            printf("VIII");
            numero -= 8;
        } else if (numero >= 7) {
            printf("VII");
            numero -= 7;
        } else if (numero >= 6) {
            printf("VI");
            numero -= 6;
        } else if (numero == 5) {
            printf("V");
            numero -= 5;
        } else if (numero == 4) {
            printf("IV");
            numero -= 4;
        } else if (numero == 3) {
            printf("III");
            numero -= 3;
        } else if (numero == 2) {
            printf("II");
            numero -= 2;
        } else if (numero == 1) {
            printf("I");
            numero -= 1;
        }
    }

    printf("\n");

    return 0;
}
