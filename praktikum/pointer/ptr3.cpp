/* --------------------------------------------------------- */
/* File Program : PTR3.CPP */
/* Contoh pengubahan isi suatu variabel melalui pointer */
/* Tujuan : Menggunakan type data pointer dan manipulasinya */
/* --------------------------------------------------------- */
#include <stdio.h>

int main() {
    // Deklarasi variabel d bertipe float dan pointer pd bertipe float
    float d, *pd;
    // Inisialisasi nilai variabel d
    d = 54.5;
    // Mencetak nilai awal variabel d
    printf("Isi d semula = %g\n", d);
    // Mengatur pointer pd untuk menunjuk ke alamat memori variabel d
    pd = &d;
    // Mengubah nilai yang ditunjuk oleh pointer pd dengan menambahkannya 10
    *pd = *pd + 10;
    // Mencetak nilai variabel d setelah diubah melalui pointer
    printf("Isi d kini = %g\n", d);
    return 0;
}
