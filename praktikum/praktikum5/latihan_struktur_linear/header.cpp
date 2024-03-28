#include "header.h"

// alokasi dan inisiasi kota baru
addressK createKota(infotype kota) {
    // alokasi
    addressK newNode = (addressK)malloc(sizeof(kt));
    if (newNode != NULL) {
        // inisiasi
        strcpy(newNode->kota, kota);
        newNode->next = NULL;
        newNode->next1 = NULL;
    }
    return newNode;
}

// Menambahkan kota baru di akhir list kota
void insertKota(addressK *listKota, infotype info) {
    // alokasi dan inisiasi node kota baru
    addressK newNode = createKota(info);
    // jika alokasi memori gagal
    if (newNode == NULL) {
        printf("\nAlokasi memori gagal\n");
        return;
    }

    // jika list kosong, maka newNode menjadi first
    if (*listKota == NULL) {
        *listKota = newNode;
        return;
    }

    // cari posisi akhir
    addressK current = *listKota;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Mengubah nama kota
void changeNamaKota(addressK listKota, infotype currentName, infotype newName) {
    addressK currentK = listKota;
    while (currentK != NULL) {
        if (strcmp(currentK->kota, currentName) == 0) {
            strcpy(currentK->kota, newName);
            return;
        }
        currentK = currentK->next;
    }
}

// Menghapus kota
void deleteKota(addressK *listKota, infotype kota) {
    addressK currentK = *listKota;
    addressK prevK = NULL;

    // Cari kota
    while (currentK != NULL && strcmp(currentK->kota, kota) != 0) {
        prevK = currentK;
        currentK = currentK->next;
    }

    // Jika kota ditemukan
    if (currentK != NULL) {
        // Hapus warganya
        address currentW = currentK->next1;
        while (currentW != NULL) {
            address temp = currentW;
            currentW = currentW->next;
            free(temp);
        }

        // Jika kota tertentu adalah node awal
        if (prevK == NULL) {
            *listKota = currentK->next;
        } else {
            prevK->next = currentK->next;
        }

        // Dealokasi kota
        free(currentK);
    }
}

// Alokasi dan Inisialisasi Warga
address createWarga(infotype nama) {
    // alokasi
    address newNode = (address)malloc(sizeof(wrg));
    if (newNode != NULL) {
        // inisiasi
        strcpy(newNode->info, nama);
        newNode->next = NULL;
    }
    return newNode;
}

void insertWarga(addressK listKota, infotype kota, infotype nama) {
    // Cari kota
    addressK currentK = listKota;
    while (currentK != NULL && strcmp(currentK->kota, kota) != 0) {
        currentK = currentK->next;
    }

    // Jika kota ditemukan
    if (currentK != NULL) {
        // alokasi dan inisiasi node kota baru
        address newNode = createWarga(nama);

        if (newNode != NULL) {
            // Jika warga di kota tertentu kosong, jadikan node awal
            if (currentK->next1 == NULL) {
                currentK->next1 = newNode;
            } else {
                // Cari warga terakhir dan insert
                address current = currentK->next1;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        } else {
            printf("\nAlokasi memori gagal\n");
        }
    }
}

void changeNamaWarga(addressK listKota, infotype kota, infotype currentName, infotype newName) {
    // Cari kota
    addressK currentK = listKota;
    while (currentK != NULL && strcmp(currentK->kota, kota) != 0) {
        currentK = currentK->next;
    }

    // Jika kota ditemukan
    if (currentK != NULL) {
        // Cari warga
        address currentW = currentK->next1;
        while (currentW != NULL && strcmp(currentW->info, currentName) != 0) {
            currentW = currentW->next;
        }

        // Jika warga ditemukan
        if (currentW != NULL) {
            strcpy(currentW->info, newName);
        } else {
        }
    }
}

void deleteWarga(addressK listKota, infotype kota, infotype nama) {
    // Cari kota
    addressK currentK = listKota;
    while (currentK != NULL && strcmp(currentK->kota, kota) != 0) {
        currentK = currentK->next;
    }

    // Jika kota ditemukan
    if (currentK != NULL) {
        // Cari warga
        address prevW = NULL;
        address currentW = currentK->next1;
        while (currentW != NULL && strcmp(currentW->info, nama) != 0) {
            prevW = currentW;
            currentW = currentW->next;
        }

        // Jika warga ditemukan
        if (currentW != NULL) {
            // Jika warga adalah node awal
            if (prevW == NULL) {
                currentK->next1 = currentW->next;
            } else {
                prevW->next = currentW->next;
            }
            free(currentW);
        }
    }
}

void displayWargaKota(addressK listKota) {
    addressK currentK = listKota;
    // tampilkan setiap kota yang ada
    int jmlKota = 0;
    while (currentK != NULL) {
        printf("\n%s :\n", currentK->kota);
        address currentW = currentK->next1;
        int jmlWarga = 0;
        // tampilkan warga di kota tertentu
        while (currentW != NULL) {
            printf("     %s\n", currentW->info);
            currentW = currentW->next;
            jmlWarga += 1;
        }
        // jika tidak ada warga di kota tertentu
        if (jmlWarga == 0) {
            printf("     Tidak ada warga\n");
        }
        currentK = currentK->next;
        jmlKota += 1;
    }
    // jika tidak ada kota
    if (jmlKota == 0) {
        printf("\nTidak ada kota\n");
    }
}