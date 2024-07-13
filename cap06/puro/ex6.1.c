#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    float a, b, c;
    float x1, x2;
    float delta;

    printf("a: ");
    scanf("%f", &a);

    printf("b: ");
    scanf("%f", &b);

    printf("c: ");
    scanf("%f", &c);

    if(a != 0){
        delta = pow(b, 2) - (4 * a *c);
        printf("Delta: %.2f\n", delta);

        if(delta < 0){
            printf("S = {}\n");
        }
        else if(delta == 0){
            x1 = -b / (2 * a);
            printf("S = {%.2f}\n", x1);
        }
        else{
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            if(x1 < x2){
                printf("S = {%.2f, %.2f}\n", x1, x2);
            }
            else{
                printf("S = {%.2f, %.2f}\n", x2, x1);
            }
        }

    }
    else{
        printf("Nao existe equacao do segundo grau!\n");
    }


    return 0;
}
