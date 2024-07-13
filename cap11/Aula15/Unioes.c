/* 
 * Arquivo: Unioes.c
 * Autor: Prof. Dr. David Buzatto
 */
 
#include <stdio.h>
#include <stdlib.h>

/*
 * união anônima
 * membros a, b e c, do tipo inteiro
 */
union {
    int a;
    int b;
    int c;
} v1, v2 = { 4 }, vn = { .b = 3 };
// na linha acima: só é permitido inicializar um membro!

/*
 * união chamada x
 * membros a, b e c do tipo inteiro
 */
union x {
    int a;
    int b;
    int c;
};

/*
 * definição de tipo (Numero) usando
 * uma união chamada Numero.
 * atenção: essa é a forma que usaremos.
 */
typedef union Numero {
    int inteiro;
    float decimal;
} Numero;

/*
 * definição de tipo (ItemCatalogo) usando
 * estruturas e uniões
 */
typedef struct ItemCatalogo {
    int identificador;
    float preco;
    int tipoDoItem;
    union {
        struct {
            char titulo[41];
            char autor[41];
            int quantidadePaginas;
        } livro;
        struct {
            char formato[41];
        } caneca;
        struct {
            char formato[41];
            int cor;
            char tamanho[4];
        } camiseta;
    } item;
} ItemCatalogo;

void imprimirX( union x p );
void imprimirNumero( Numero n );
void imprimirNumeroPonteiro( Numero *n );
void imprimirItemCatalogo( ItemCatalogo *i );

int main( void ) {

    // declaração de uma variável do tipo union x e
    // inicialização. só é permitido inicializar UM membro.
    union x x1 = { 1 }; // em ordem

    // declaração de uma variável do tipo union x e
    // inicialização. só é permitido inicializar UM membro.
    union x x2 = { .b = 4 }; // ordem não importa

    // declaração de uma variável do tipo Numero
    // (que deriva de uma união) e inicilização
    Numero n1 = { 23 };

    // declaração de uma variável do tipo Numero
    // (que deriva de uma união) e inicilização
    // usando designadores
    Numero n2 = { .decimal = 4.5 };

    // declaração e inicialização de quatro instâncias de ItemCatalogo
    ItemCatalogo i1 = {
        .identificador = 104,
        .preco = 49.99,
        .tipoDoItem = 1,
        .item.livro.titulo = "C Programming: a modern approach",
        .item.livro.autor = "King, K. N.",
        .item.livro.quantidadePaginas = 805
    };

    ItemCatalogo i2 = {
        .identificador = 205,
        .preco = 20.50,
        .tipoDoItem = 2,
        .item.caneca.formato = "cafe"
    };

    ItemCatalogo i3 = {
        .identificador = 174,
        .preco = 29.99,
        .tipoDoItem = 3,
        .item.camiseta.formato = "Gola V",
        .item.camiseta.cor = 20,
        .item.camiseta.tamanho = "GG"
    };

    ItemCatalogo i4 = {
        .identificador = 421,
        .preco = 34.99,
        .tipoDoItem = 4,
        .item.camiseta.formato = "Gola Polo",
        .item.camiseta.cor = 15,
        .item.camiseta.tamanho = "M"
    };

    // inicializando os membros de uma instância da
    // união anônima
    v1.c = 5;

    imprimirX( x1 );
    printf( "\n" );

    imprimirX( x2 );
    printf( "\n" );

    imprimirNumero( n1 );
    printf( "\n" );

    imprimirNumeroPonteiro( &n2 );
    printf( "\n\n" );

    imprimirItemCatalogo( &i1 );
    printf( "\n\n" );

    imprimirItemCatalogo( &i2 );
    printf( "\n\n" );

    imprimirItemCatalogo( &i3 );
    printf( "\n\n" );

    imprimirItemCatalogo( &i4 );
    printf( "\n" );

    return 0;

}

void imprimirX( union x p ) {
    printf( "%d %d %d", p.a, p.b, p.c );
}

void imprimirNumero( Numero n ) {
    printf( "%d - %.2f", n.inteiro, n.decimal );
}

void imprimirNumeroPonteiro( Numero *n ) {
    printf( "%d - %.2f", n->inteiro, n->decimal );
}

void imprimirItemCatalogo( ItemCatalogo *i ) {

    printf( "Item do Catalogo: %d (R$%.2f)\n", 
            i->identificador, i->preco );
            
    switch ( i->tipoDoItem ) {
        case 1:
            printf( "Livro:\n" );
            printf( "     Titulo: %s\n", i->item.livro.titulo );
            printf( "      Autor: %s\n", i->item.livro.autor );
            printf( "    Paginas: %d", i->item.livro.quantidadePaginas );
            break;
        case 2:
            printf( "Caneca:\n" );
            printf( "    Formato: %s", i->item.caneca.formato );
            break;
        case 3:
            printf( "Camiseta:\n" );
            printf( "    Formato: %s\n", i->item.camiseta.formato );
            printf( "        Cor: %d\n", i->item.camiseta.cor );
            printf( "    Tamanho: %s", i->item.camiseta.tamanho );
            break;
        default:
            printf( "Tipo de item desconhecido!" );
            break;
    }

}
