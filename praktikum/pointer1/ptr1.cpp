/* --------------------------------------------------------- */
/* File Program : PTR1.CPP */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>
int main() {
    // Deklarasi dua variabel bertipe integer, x dan y
    int x, y;
    // Deklarasi sebuah pointer px yang akan menunjuk ke alamat memori variabel bertipe integer
    int *px;
    // Inisialisasi variabel x dengan nilai 87
    x = 87;
    // Mengatur nilai pointer px untuk menunjuk ke alamat memori variabel x
    px = &x;
    // Mengambil nilai yang ditunjuk oleh pointer px dan menyimpannya dalam variabel y
    y = *px;
    // Mencetak alamat memori variabel x menggunakan format specifier %p
    printf("Alamat x = %p\n", &x);
    // Mencetak nilai variabel x menggunakan format specifier %d
    printf("Isi px = %d\n", x);
    // Mencetak nilai yang ditunjuk oleh pointer px menggunakan format specifier %d
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    // Mencetak nilai variabel y menggunakan format specifier %d.
    printf("Nilai y = %d\n", y);
    // Mencetak alamat memori variabel y
    printf("Alamat y = %p\n", &y);
    return 0;
}
