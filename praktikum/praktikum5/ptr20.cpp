/*---------------------------------------------------------------------------*/
/* File : PTR20.cpp */
/* Deskripsi : contoh pendefinisian struct dan pointer ke struct */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    /* kamus */

    /* cara 3 : INI yang membuat TYPE baru */
    printf("Cara 3\n");
    typedef struct {
        float y;
        float x;
    } Point;                                    /* nama type */
    Point *P2;                                  /* deklarasi pointer ke struct */
    Point *P3 = (Point *)malloc(sizeof(Point)); /* deklarasi alokasi */

    printf("alamat : %p\n", &P2);
    printf("nilai : %d\n", P2->x);

    /* program */

    /* Cara 1 : mengacu elemen pointer ke struct */
    printf("\nCara 1\n");
    printf("Titik P2, dengan P2->x dan P2->y : \n");
    P2 = (Point *)malloc(sizeof(Point)); /* Alokasi */
    P2->x = 9.12;                        /* Isi nilai komponen */
    P2->y = 2.567;
    printf("P2.x = %f \nP2.y = %f \n", P2->x, P2->y);

    /* Cara 2 : Perhatikanlah tanda kurung, lihat prioritas () dibuku TC */
    printf("\nCara 2\n");
    (*P3).x = 0.5; /* Mendefinisikan isi */
    (*P3).y = 10.5;
    printf("P3.x = %f \nP3.y = %f \n", (*P3).x, (*P3).y);

    printf("\n");
    printf("%p %p %f\n", &P2, P2, P2->x);
    printf("alamat struct: %p\n", &(*P2));
    printf("alamat x: %p, nilai x: %f\n", &(*P2).x, (*P2).x);
    printf("alamat y: %p, nilai y: %f\n", &(*P2).y, (*P2).y);

    printf("\n");
    printf("%p %p %f\n", &P3, P3, P3->x);
    printf("%p\n", &(*P3));
    printf("%p %f\n", &(*P3).x, (*P3).x);
    printf("%p\n", &(*P3).y);

    return 0;
}