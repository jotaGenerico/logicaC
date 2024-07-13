// achei q seria um otimo lugar para testar os ternarios
// ja q iria testar tambem aproveitei para ver declaraçao mais eficiente de variaveis
// e na formataçao do print uma operaçao direta
// acho q ateh agora podemos dizer q c eh um python cagador de regra ou
// python eh um c ++++++++
// hu3 ;P

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float num1, num2, num3;
    float primeiro, segundo;

    printf("N1: ");
    scanf("%f", &num1);

    printf("N2: ");
    scanf("%f", &num2);

    printf("N3: ");
    scanf("%f", &num3);

    if (num1 >= num2 && num1 >= num3) {
        primeiro = num1;
        segundo = (num2 >= num3) ? num2 : num3;

    } else if (num2 >= num1 && num2 >= num3) {
        primeiro = num2;
        segundo = (num1 >= num3) ? num1 : num3;

    } else {
        primeiro = num3;
        segundo = (num1 >= num2) ? num1 : num2;

    }

    printf("A soma dos dois numeros maiores fornecidos e %.2f\n", primeiro + segundo);

    return 0;
}
