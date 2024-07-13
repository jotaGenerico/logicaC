/*
 * Arquivo: Estruturas.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * estrutura anônima
 * membros a, b e c, do tipo inteiro
 */
struct {
    int a;
    int b;
    int c;              // inicialização usando designadores
} v1, v2 = { 4, 8, 2 }, vn = { .a = 3, .b = 9, .c = 15 };

/*
 * estrutura chamada x
 * membros a, b e c do tipo inteiro
 */
struct x {
    int a;
    int b;
    int c;
};

/*
 * definição de tipo (Data) usando
 * uma estrutura anônima
 */
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

/*
 * definição de tipo (Pessoa) usando
 * uma estrutura chamada Pessoa.
 * atenção: essa é a forma que usaremos.
 */
typedef struct Pessoa {
    char nomeCompleto[40];
    float peso;
    Data dataNascimento;
} Pessoa;

void imprimirX( struct x p );
void imprimirData( Data d );
void imprimirDataPonteiro( Data *d );
Pessoa novaPessoa( const char *nc, float p, Data *dn );
void imprimirPessoa( Pessoa *p );

int main( void ) {

    /* declaração de uma variável do tipo struct x e
     * inicialização.
     */
    struct x x1 = { 1, 2, 3 }; // em ordem

    /* declaração de uma variável do tipo struct x e
     * inicialização usando designadores.
     */
    struct x x2 = { .a = 3, .b = 4, .c = 5 }; // a ordem não importa

    /* declaração de uma variável do tipo Data
     * (que deriva de uma estrutura anônima) e inicilização.
     */
    Data d1 = { 23, 5, 2002 };

    /* declaração de uma variável do tipo Data
     * (que deriva de uma estrutura anônima) e inicialização
     * usando designadores.
     */
    Data d2 = { .dia = 25, .mes = 2, .ano = 1985 };

    // declaração de um array com 5 datas
    Data dArray[5];

    /* d2 é copiada, membro a membro para
     * dataNascimento de p1.
     */
    Pessoa p1 = {
        .nomeCompleto = "David Buzatto",
        .peso = 120,
        .dataNascimento = d2
    };

    // p1 é copiado, membro a membro para p2
    Pessoa p2 = p1;
    p2.peso = 90;

    // criando uma nova pessoa através de uma função
    Pessoa p3 = novaPessoa( "Maria da Silva", 55, &d1 );

    /* declarando uma nova pessoa, que receberá os dados pela
     * entrada.
     */
    Pessoa p4;

    /* inicializando os membros de uma instância da
     * estrutura anônima.
     */
    v1.a = 5;
    v1.b = 5;
    v1.c = 5;

    imprimirX( x1 );
    printf( "\n" );

    imprimirX( x2 );
    printf( "\n" );

    imprimirData( d1 );
    printf( "\n" );

    // reatribuindo os valores em uma estrutura
    // forma correta
    d1 = (Data){
        .dia = 30,
        .mes = 4,
        .ano = 2024
    };

    /* forma incorreta
    d1 = {
        .dia = 30,
        .mes = 4,
        .ano = 2024
    };*/
    
    imprimirData( d1 );
    printf( "\n" );

    imprimirDataPonteiro( &d2 );
    printf( "\n" );

    imprimirPessoa( &p1 );
    printf( "\n" );

    imprimirPessoa( &p2 );
    printf( "\n" );

    imprimirPessoa( &p3 );
    printf( "\n" );

    printf( "Entre com o nome: " );
    fgets( p4.nomeCompleto, 40, stdin );
    p4.nomeCompleto[strlen(p4.nomeCompleto)-1] = '\0';

    printf( "Entre com o peso: " );
    scanf( "%f", &p4.peso );

    printf( "Data de nascimento:\n" );
    printf( "    dia: " );
    scanf( "%d", &p4.dataNascimento.dia );
    printf( "    mes: " );
    scanf( "%d", &p4.dataNascimento.mes );
    printf( "    ano: " );
    scanf( "%d", &p4.dataNascimento.ano );

    imprimirPessoa( &p4 );
    printf( "\n" );

    for ( int i = 0; i < 5; i++ ) {
        printf( "Data %d\n", i+1 );
        printf( "    dia: " );
        scanf( "%d", &dArray[i].dia );
        printf( "    mes: " );
        scanf( "%d", &dArray[i].mes );
        printf( "    ano: " );
        scanf( "%d", &dArray[i].ano );
    }

    printf( "Datas:\n" );
    for ( int i = 0; i < 5; i++ ) {
        printf( "    Data %d: ", i+1 );
        imprimirData( dArray[i] );
        printf( "\n" );
    }

    return 0;

}

void imprimirX( struct x p ) {
    printf( "%d %d %d", p.a, p.b, p.c );
}

void imprimirData( Data d ) {
    printf( "%02d/%02d/%04d", d.dia, d.mes, d.ano );
}

void imprimirDataPonteiro( Data *d ) {

    // d->dia   =>   (*d).dia, ou seja, o operador -> é um atalho
    printf( "%02d/%02d/%04d", d->dia, d->mes, (*d).ano );

    /* pode-se usar uma expressão com -> para receber valor, por
     * exemplo d->dia = 25; (o membro dia da estrutura apontada
     * por d recebe o valor 25).
     */

}

Pessoa novaPessoa( const char *nc, float p, Data *dn ) {

    Pessoa pe;

    // copia a string
    strcpy( pe.nomeCompleto, nc );

    // copia o peso
    pe.peso = p;

    // copia, membro a membro, os dados de dn
    pe.dataNascimento = *dn;

    return pe;

}

void imprimirPessoa( Pessoa *p ) {

    printf( "%s, nascido(a) em ", p->nomeCompleto );
    imprimirDataPonteiro( &p->dataNascimento );
    printf( " e tem peso = %.2fkg", p->peso );

}
