#include <stdio.h>
int main() {
    float d, *pd;
    d = 54.5;
    printf("Isi d semula = %g\n", d);
    printf("Isi pd semula = %p\n", pd);
    printf("Isi d semula = %p\n", &d);
    pd = &d;
    //*pd = *pd + 10;
    pd = pd + 10;
    printf("Isi d kini = %g\n", d);
    printf("Isi d kini = %p\n", &d);
    printf("Isi pd kini = %p\n", pd);
    return 0;
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}