#include <stdio.h>

#define BLOCK_NUM   10
#define BLOCK_SIZE  8

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;

#define BLOCK( in ) BLOCK_##in


u8_t memp_base[ BLOCK(NUM) ][ BLOCK(SIZE) ];

void *link;

void memp_init( )
{
    void **tmp;
    u8_t in = 0;

    link = 0;
    tmp = ( void **)memp_base;
    for( in = 0; in < BLOCK_NUM; in++ )
    {
        *tmp = link;
        link = ( void *)tmp;
        tmp = ( void **)(( u8_t *)tmp + BLOCK_SIZE);
    }



    return;
}

void memp_print( )
{
    u8_t count = 0;
    u8_t tm = 0;
    void *nn = 0;

    for( tm = 0; tm < BLOCK_NUM; tm++ )
    {
        printf( "%-02d: %#x\r\n", tm+1, memp_base+tm );
    }
    printf( "\r\n" );

    count = 0;
    nn = link; 
    while( 0 != nn )
    {
        count++;
        printf( "%-02d : %#x\r\n", count, nn );
        nn = *( void **)nn;
    }


    return;
}

#if 0
void memp_print( )
{
    u8_t count = 0;
    u8_t tm = 0;
    void **nn = 0;

    for( tm = 0; tm < BLOCK_NUM; tm++ )
    {
        printf( "%d: %#x\r\n", tm, *(int*)(memp_base+tm));
    }

    printf( "\r\n" );
    count = 0;
    nn = &link; 
    while( 0 != *nn )
    {
        count++;
        printf( "%d : %#x\r\n", count, *nn );
        nn = ( void **)*nn;
    }


    return;
}

void memp_print( )
{
    void **tmp;
    u8_t i = 0;

    tmp = ( void **)link;
    while( 0 != *tmp )
    {
        i++;
        printf( "%d: %#x\r\n", i, *tmp );
        tmp = ( void **)*tmp;
    }

    return;
}
#endif

int main( void )
{
    memp_init( );
    memp_print( );

    return 0;
}
