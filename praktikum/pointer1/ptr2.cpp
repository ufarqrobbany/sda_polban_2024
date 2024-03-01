/* --------------------------------------------------------- */
/* File Program : PTR2.CPP */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>

int main() {
    float *pu;                // Deklarasi pointer pu bertipe float
    float nu;                 // Deklarasi variabel nu bertipe float
    float u = 1234;           // Deklarasi dan inisialisasi variabel u bertipe int
    pu = &u;                  // Mengatur pointer pu untuk menunjuk ke alamat memori variabel u
    nu = *pu;                 // Mencoba mengambil nilai yang ditunjuk oleh pointer pu dan menyimpannya dalam variabel nu
    printf("u = %f\n", u);    // Mencetak nilai variabel u
    printf("nu = %f\n", nu);  // Mencetak nilai variabel nu dengan format specifier %f yang salah
    return 0;
}
