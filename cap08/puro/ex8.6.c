#include <stdio.h>
#include <stdlib.h>

void pInterno(const double *a1, const double *a2, double *pi, int n);

#define N 5

int main(void){

    double a1[N];
    double a2[N];
    double pi[N];

    for(int i=0; i < N; i++){
        printf("a1[%d]: ", i);
        scanf("%lf", &a1[i]);
    }
        
    for(int i=0; i < N; i++){
        printf("a2[%d]: ", i);
        scanf("%lf", &a2[i]);
    }

    pInterno(a1, a2, pi, N);

    for(int i=0; i < N; i++){
        printf("%.2lf x %.2lf = %.2lf\n", a1[i], a2[i], pi[i]);
    }

    return 0;
}

void pInterno(const double *a1, const double *a2, double *pi, int n){
    for(int i=0; i < n; i++){
        pi[i] = a1[i] * a2[i];
    }
}