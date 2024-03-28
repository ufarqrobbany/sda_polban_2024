#include "header.h"

int main() {
    // inisialisasi pointer list kota
    addressK First = NULL;

    // Inisialisasi List
    insertKota(&First, "Bandung");
    insertWarga(First, "Bandung", "Wahab");
    insertWarga(First, "Bandung", "Amir");
    insertWarga(First, "Bandung", "Yahya");
    insertKota(&First, "Jakarta");
    insertWarga(First, "Jakarta", "Badu");
    insertWarga(First, "Jakarta", "Hasan");
    insertKota(&First, "Bogor");

    printf("Initial State\n");
    displayWargaKota(First);
    printf("\n");

    // Program
    // Menambah satu kota "Tasikmalaya"
    insertKota(&First, "Tasikmalaya");
    // Mengubah nama kota "Dari Bandung menjadi Garut"
    changeNamaKota(First, "Bandung", "Garut");
    // Menghapus kota "Bogor"
    deleteKota(&First, "Bogor");
    // Menambah warga "Umar" ke kota "Tasikmalaya"
    insertWarga(First, "Tasikmalaya", "Umar");
    // Mengubah nama warga "Badu" menjadi "Husen" di kota Jakarta
    changeNamaWarga(First, "Jakarta", "Badu", "Husen");
    // Hapus warga "Amir" di Garut
    deleteWarga(First, "Garut", "Amir");
    printf("Final State\n");
    displayWargaKota(First);

    return 0;
}
