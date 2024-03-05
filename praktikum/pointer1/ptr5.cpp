/* --------------------------------------------------------------------------------------------- */
/* File Program : PTR5.CPP */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* --------------------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Kamus Data (deklarasi, inisialisasi nilai variabel) */
    int i = 5, j;
    char c = 'X';
    // alokasi memori dinamik untuk integer
    int *Ptri = (int *)malloc(4);
    int *Ptrj = (int *)malloc(sizeof(int));
    // alokasi memori dinamik untuk float
    float *fx = (float *)malloc(sizeof(float));
    int A[5];
    float f = 7.23;

    /* Program */
    *Ptri = 8;  // Mengisi nilai yang ditunjuk oleh Ptri dengan 8
    *Ptrj = 0;  // Mengisi nilai yang ditunjuk oleh Ptrj dengan 0
    *fx = 3;    // Mengisi nilai yang ditunjuk oleh fx dengan 3

    // Cetak alamat dan nilai dari variabel i
    printf("Alamat i = %x \n", &i);
    printf("Nilai i = %d \n", i);
    printf("Ukuran int = %d byte\n\n", sizeof(int));

    // Cetak alamat dan nilai dari variabel j (belum diinisialisasi)
    printf("Alamat j = %x \n", &j);
    printf("Nilai j = %d \n", j);
    printf("Ukuran char = %d byte\n\n", sizeof(char));

    // Cetak alamat dan nilai dari variabel c
    printf("Alamat c = %x \n", &c);
    printf("Nilai c = %c \n", c);
    printf("Ukuran char = %d byte\n\n", sizeof(char));

    // Cetak alamat, isi, dan nilai yang ditunjuk oleh Ptri
    printf("Alamat Ptri = %x \n", &Ptri);
    printf("Isi var Ptri = %x \n", Ptri);
    printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
    printf("Ukuran pointer int = %d byte\n\n", sizeof(int *));

    // Cetak alamat, isi, dan nilai yang ditunjuk oleh Ptrj
    printf("Alamat Ptrj = %x \n", &Ptrj);
    printf("Isi var Ptrj = %x \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);

    // Mengisi Ptrj dengan Ptri
    Ptrj = Ptri;

    // Cetak isi dan nilai yang ditunjuk oleh Ptrj setelah perubahan
    printf("Isi var Ptrj sekarang = %x \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);

    // Cetak alamat dan isi array A
    printf("Alamat A = %x \n", &A);
    printf("Isi var A = %x \n", A[0]);
    printf("Ukuran array A = %d byte\n\n", sizeof(A));

    // Cetak alamat dan nilai dari variabel f
    printf("Alamat f = %x \n", &f);
    printf("Nilai f = %f \n", f);
    printf("Ukuran float = %d byte\n\n", sizeof(float));

    return 0;
}
