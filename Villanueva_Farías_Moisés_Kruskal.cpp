/*
    *------------------------*
    |Villanueva Far�as Mois�s|
    |12/05/2020              |
    |Al igual que otros me-  |
    |todos ayuda a encontrar |
    |el camino mas corto     |
    |utilizando un arbol de  |
    |expancion               |
    *------------------------*
*/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 1005

int padre[ MAX ];

void MakeSet( int n ){
    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
}

int Find( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}

void Union( int x , int y ){
    padre[ Find( x ) ] = Find( y );
}

bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}

int V , E;
struct Edge{
    int origen;
    int destino;
    int peso;
    Edge(){}
    bool operator<( const Edge &e ) const {
        return peso < e.peso;
    }
}arista[ MAX ];
Edge MST[ MAX ];

void Kruskal(){
    int origen , destino , peso;
    int total = 0;
    int numAristas = 0;

    MakeSet( V );
    std::sort( arista , arista + E );

    for( int i = 0 ; i < E ; ++i ){
        origen = arista[ i ].origen;
        destino = arista[ i ].destino;
        peso = arista[ i ].peso;

        if( !sameComponent( origen , destino ) ){
            total += peso;
            MST[ numAristas++ ] = arista[ i ];
            Union( origen , destino );
        }
    }


    if( V - 1 != numAristas ){
        puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
        return;
    }
    puts( "Arbol Minimo Expandido contiene las siguientes aristas");
    for( int i = 0 ; i < numAristas ; ++i )
        printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso );

    printf( "El costo minimo de todas las aristas del MST es : %d\n" , total );
}

int main(){
    int mst;
    V=10;
    E=21;

        arista[0].origen=0; arista[0].destino=1; arista[0].peso=105;
        arista[1].origen=0; arista[1].destino=2; arista[1].peso=127;
        arista[2].origen=0; arista[2].destino=5; arista[2].peso=218;

        arista[3].origen=1; arista[3].destino=2; arista[3].peso=231;
        arista[4].origen=1; arista[4].destino=3; arista[4].peso=186;

        arista[5].origen=2; arista[5].destino=5; arista[5].peso=118;
        arista[6].origen=2; arista[6].destino=4; arista[6].peso=190;
        arista[7].origen=2; arista[7].destino=3; arista[7].peso=150;

        arista[8].origen=3; arista[8].destino=4; arista[8].peso=115;
        arista[9].origen=3; arista[9].destino=8; arista[9].peso=196;


        arista[10].origen=4; arista[10].destino=5; arista[10].peso=104;
        arista[11].origen=4; arista[11].destino=6; arista[11].peso=129;
        arista[12].origen=4; arista[12].destino=7; arista[12].peso=142;
        arista[13].origen=4; arista[13].destino=8; arista[13].peso=136;

        arista[14].origen=5; arista[14].destino=6; arista[14].peso=84;
        arista[15].origen=5; arista[15].destino=7; arista[15].peso=134;

        arista[16].origen=6; arista[16].destino=9; arista[16].peso=79;
        arista[17].origen=6; arista[17].destino=7; arista[17].peso=50;

        arista[18].origen=7; arista[18].destino=9; arista[18].peso=99;
        arista[19].origen=7; arista[19].destino=8; arista[19].peso=109;

        arista[20].origen=8; arista[20].destino=9; arista[20].peso=168;



    Kruskal();

    return 0;
}
