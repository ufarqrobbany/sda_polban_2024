#include "ptr21.h"

int main() {
    linkedList *list;
    int option = 1;
    int new_data, prev_data, next_data, pos;

    /* PROGRAM */
    /* Create list kosong */
    initList(&list);

    system("cls");
    do {
        printf("\n\n");
        displayList(list);
        printf("=========================================\n");
        printf("1. Tambah Node\n");
        printf("2. Ubah Nilai Node\n");
        printf("3. Hapus Node\n");
        printf("4. Keluar\n");
        printf("=========================================\n");
        printf("Pilih opsi: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\n\n1. Tambah Node baru di awal list\n");
                printf("2. Tambah Node baru setelah node dengan nilai tertentu\n");
                printf("3. Tambah Node baru sebelum node dengan nilai tertentu\n");
                printf("4. Tambah Node baru di posisi tertentu\n");
                printf("5. Tambah Node baru di akhir list\n");
                printf("6. Kembali\n");
                printf("=========================================\n");
                printf("Pilih opsi: ");
                scanf("%d", &option);
                switch (option) {
                    case 1:
                        printf("\n\nTambah Node baru di awal list\n");
                        printf("Masukkan nilai node baru: ");
                        scanf("%d", &new_data);
                        insertFirst(&list, new_data);
                        break;
                    case 2:
                        printf("\n\nTambah Node baru setelah node dengan nilai tertentu\n");
                        printf("Masukkan nilai node sebelumnya: ");
                        scanf("%d", &prev_data);
                        printf("Masukkan nilai node baru: ");
                        scanf("%d", &new_data);
                        insertAfterInfo(&list, prev_data, new_data);
                        break;
                    case 3:
                        printf("\n\nTambah Node baru sebelum node dengan nilai tertentu\n");
                        printf("Masukkan nilai node setelahnya: ");
                        scanf("%d", &next_data);
                        printf("Masukkan nilai node baru: ");
                        scanf("%d", &new_data);
                        insertBeforeInfo(&list, next_data, new_data);
                        break;
                    case 4:
                        printf("\n\nTambah Node baru di posisi tertentu\n");
                        printf("Masukkan posisi: ");
                        scanf("%d", &pos);
                        printf("Masukkan data baru: ");
                        scanf("%d", &new_data);
                        insertAtPosition(&list, new_data, pos);
                        break;
                    case 5:
                        printf("\n\nTambah Node baru di akhir list\n");
                        printf("Masukkan nilai node baru: ");
                        scanf("%d", &new_data);
                        insertLast(&list, new_data);
                        break;
                    default:
                        break;
                }
                option = 0;
                break;
            case 2:
                printf("\n\nUbah Nilai Node\n");
                printf("1. Ubah nilai Node di awal list\n");
                printf("2. Ubah nilai Node di posisi tertentu\n");
                printf("3. Ubah nilai Node berdasarkan nilai\n");
                printf("4. Ubah nilai semua Node dengan nilai tertentu\n");
                printf("5. Ubah nilai Node terakhir\n");
                printf("6. Kembali\n");
                printf("=========================================\n");
                printf("Pilih opsi: ");
                scanf("%d", &option);
                switch (option) {
                    case 1:
                        printf("\n\nUbah nilai Node di awal list\n");
                        printf("Masukkan nilai baru: ");
                        scanf("%d", &new_data);
                        updateFirst(list, new_data);
                        break;
                    case 2:
                        printf("\n\nUbah nilai Node di posisi tertentu\n");
                        printf("Masukkan posisi: ");
                        scanf("%d", &pos);
                        printf("Masukkan nilai baru: ");
                        scanf("%d", &new_data);
                        updateAtPosition(list, new_data, pos);
                        break;
                    case 3:
                        printf("\n\nUbah nilai Node berdasarkan nilai\n");
                        printf("Masukkan nilai Node yang akan diubah: ");
                        scanf("%d", &prev_data);
                        printf("Masukkan nilai baru: ");
                        scanf("%d", &new_data);
                        updateByInfo(list, prev_data, new_data);
                        break;
                    case 4:
                        printf("\n\nUbah nilai semua Node dengan nilai tertentu\n");
                        printf("Masukkan nilai Node yang akan diubah: ");
                        scanf("%d", &prev_data);
                        printf("Masukkan nilai baru: ");
                        scanf("%d", &new_data);
                        updateAllByInfo(list, prev_data, new_data);
                        break;
                    case 5:
                        printf("\n\nUbah nilai Node terakhir\n");
                        printf("Masukkan nilai baru: ");
                        scanf("%d", &new_data);
                        updateLast(list, new_data);
                        break;
                    default:
                        break;
                }
                option = 0;
                break;
            case 3:
                printf("\n\n1. Hapus Node pertama\n");
                printf("2. Hapus Node berdasarkan nilai (Node pertama yang ditemukan)\n");
                printf("3. Hapus semua Node dengan nilai tertentu\n");
                printf("4. Hapus Node pada posisi tertentu\n");
                printf("5. Hapus Node terakhir\n");
                printf("6. Hapus semua Node\n");
                printf("7. Kembali\n");
                printf("=========================================\n");
                printf("Pilih opsi: ");
                scanf("%d", &option);
                switch (option) {
                    case 1:
                        printf("\n\nHapus Node pertama\n");
                        deleteFirst(&list);
                        break;
                    case 2:
                        printf("\n\nHapus Node berdasarkan nilai\n");
                        printf("Masukkan nilai Node yang akan dihapus: ");
                        scanf("%d", &new_data);
                        deleteByInfo(&list, new_data);
                        break;
                    case 3:
                        printf("\n\nHapus semua Node dengan nilai tertentu\n");
                        printf("Masukkan nilai Node yang akan dihapus: ");
                        scanf("%d", &new_data);
                        deleteAllByInfo(&list, new_data);
                        break;
                    case 4:
                        printf("\n\nHapus Node pada posisi tertentu\n");
                        printf("Masukkan posisi Node yang akan dihapus: ");
                        scanf("%d", &pos);
                        deleteAtPosition(&list, pos);
                        break;
                    case 5:
                        printf("\n\nHapus Node terakhir\n");
                        deleteLast(&list);
                        break;
                    case 6:
                        printf("\n\nHapus semua Node\n");
                        deleteAll(&list);
                        break;
                    default:
                        break;
                }
                option = 0;
                break;
            case 4:
                exit(1);
            default:
                break;
        }
    } while (option != 4);
}