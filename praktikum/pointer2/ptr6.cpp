/* ----------------------------------------------------- */
/* File Program : PTR6.CPP */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */
#include <stdio.h>
int main() {
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    // Deklarasi variabel array
    static int tgl_lahir[] = {18, 6, 1989};
    int *ptgl;
    ptgl = tgl_lahir;
    printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
    printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);

    for (int i = 0; i < sizeof(tgl_lahir) / sizeof(int); i++) {
        printf("Alamat %d bernilai %d\n", (ptgl + i), *(ptgl + i));
    }
    return 0;
}

/* Variabel bersifat statis artinya variabel tersebut akan mempertahankan nilainya di antara pemanggilan fungsi yang berbeda.
        Dalam hal ini, tgl_lahir adalah variabel lokal yang akan mempertahankan nilainya setelah fungsi selesai dieksekusi. */
/* Dalam aturan khusus bahasa C, saat kita menetapkan suatu array ke pointer, kita tidak perlu menggunakan tanda '&'(address of)
        untuk mendapatkan alamat memori dari array tersebut.
        Jadi, dalam contoh ptgl = tgl_lahir;, tgl_lahir adalah nama array itu sendiri. Ketika Anda menggunakan nama array dalam konteks
        di mana alamat memori diharapkan, itu akan secara otomatis memberikan alamat memori dari elemen pertama array tersebut.

/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/