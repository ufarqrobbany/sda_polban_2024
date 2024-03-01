/* --------------------------------------------------------- */
/* File Program : PTR4.CPP */
/* Contoh pemakaian pointer */
/* --------------------------------------------------------- */
#include <stdio.h>

int main() {
    // Deklarasi variabel z, s, dan pointer pz, ps
    int z, s, *pz, *ps;
    // Inisialisasi nilai variabel z
    z = 20;
    // Inisialisasi nilai variabel s
    s = 30;
    // Mengatur pointer pz untuk menunjuk ke alamat memori variabel z
    pz = &z;
    // Mengatur pointer ps untuk menunjuk ke alamat memori variabel s
    ps = &s;
    // Menambahkan nilai yang ditunjuk oleh pz dengan nilai yang ditunjuk oleh ps dan menyimpannya di alamat yang ditunjuk oleh pz
    *pz = *pz + *ps;
    // Mencetak nilai variabel z dan s setelah perubahan melalui pointer
    printf("z = %d, s = %d\n", z, s);
    return 0;
}
