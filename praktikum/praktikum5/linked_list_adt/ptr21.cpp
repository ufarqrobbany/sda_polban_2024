#include "ptr21.h"

void initList(linkedList **list) {
    first(*list) = Nil;
    last(*list) = Nil;
}

address createNode(infotype info) {
    // alokasi
    address new_node = (address)malloc(sizeof(ElmtList));
    if (new_node != Nil) {
        info(new_node) = info;
        next(new_node) = Nil;
    }
    return new_node;
}

void insertFirst(linkedList **list, infotype info) {
    // buat node baru
    address new_node = createNode(info);
    // jika gagal membuat node baru
    if (new_node == Nil) {
        printf("Alokasi memori gagal\n");
        return;
    }

    // insert node di awal list
    next(new_node) = first(*list);
    first(*list) = new_node;

    // jika last tidak menunjuk ke node manapun (linked list awalnya kosong)
    if (last(*list) == Nil) {
        last(*list) = new_node;
    }
}

void insertAfterInfo(linkedList **list, infotype prev_info, infotype new_info) {
    // cari node berdasarkan nilai info
    address prev_node = searchByInfo(*list, prev_info);
    // jika node tidak ditemukan
    if (prev_node == Nil) {
        printf("Node dengan info = %d tidak ditemukan\n", prev_info);
        return;
    }

    // buat node baru
    address new_node = createNode(new_info);
    // jika gagal membuat node baru
    if (new_node == Nil) {
        printf("Alokasi memori gagal\n");
        return;
    }

    // insert node baru setelah node dengan nilai info == prev_info
    next(new_node) = next(prev_node);
    next(prev_node) = new_node;

    // jika node sebelumnya adalah node akhir
    if (prev_node == last(*list)) {
        last(*list) = new_node;
    }
}

void insertBeforeInfo(linkedList **list, infotype next_info, infotype new_info) {
    // cari node berdasarkan nilai info
    address next_node = searchByInfo(*list, next_info);

    if (next_node == Nil) {
        printf("Node dengan info = %d tidak ditemukan\n", next_info);
        return;
    }

    // jika node yang dicari adalah node awal, tentukan node baru sebagai node awal
    if (first(*list) == next_node) {
        insertFirst(list, new_info);
        return;
    }

    // cari node sebelumnya
    address prev_node = first(*list);
    while (next(prev_node) != next_node) {
        prev_node = next(prev_node);
    }

    // buat node baru
    address new_node = createNode(new_info);
    // jika gagal membuat node baru
    if (new_node == Nil) {
        printf("Alokasi memori gagal\n");
        return;
    }

    // sisipkan node
    next(prev_node) = new_node;
    next(new_node) = next_node;
}

void insertAtPosition(linkedList **list, infotype info, int pos) {
    // jika posisi kurang dari 1
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    // jika posisi = 1
    if (pos == 1) {
        insertFirst(list, info);
        return;
    }

    // cari node sebelumnya
    address prev_node = searchAtPosition(*list, pos - 1);
    // jika node sebelumnya tidak ditemukan
    if (prev_node == Nil) {
        printf("Node tidak ditemukan\n");
        return;
    }
    // buat node baru
    address new_node = createNode(info);
    // jika gagal membuat node baru
    if (new_node == Nil) {
        printf("Alokasi memori gagal\n");
        return;
    }

    // insert node di posisi yang ditentukan
    next(new_node) = next(prev_node);
    next(prev_node) = new_node;

    // jika node sebelumnya adalah node akhir
    if (prev_node == last(*list)) {
        last(*list) = new_node;
    }
}

void insertLast(linkedList **list, infotype info) {
    // jika last tidak menunjuk ke node manapun (linked list awalnya kosong), tetapkan sebagai node awal
    if (last(*list) == Nil) {
        insertFirst(list, info);
        return;
    }

    // buat node baru
    address new_node = createNode(info);
    // jika gagal membuat node baru
    if (new_node == Nil) {
        printf("Alokasi memori gagal\n");
        return;
    }

    // insert node di akhir list
    next(last(*list)) = new_node;
    last(*list) = new_node;
}

void deleteFirst(linkedList **list) {
    // cek jika linked list kosong
    if (first(*list) == Nil) {
        printf("Linked list kosong, Tidak ada yang dihapus\n");
        return;
    }

    // tampung node yang akan dihapus ke alamat sementara
    address temp = first(*list);
    // ubah node awal
    first(*list) = next(temp);
    // bebaskan memori node
    free(temp);
}

void deleteAtPosition(linkedList **list, int pos) {
    // cek jika linked list kosong
    if (first(*list) == Nil) {
        printf("Linked list kosong, Tidak ada yang dihapus\n");
        return;
    }

    // cek apakah posisi valid
    if (pos <= 0) {
        printf("Posisi harus lebih besar dari 0\n");
        return;
    }

    address current_node = first(*list);
    address prev_node = Nil;
    int count = 1;

    while (current_node != Nil && count < pos) {
        prev_node = current_node;
        current_node = next(current_node);
        count++;
    }

    // cek apakah posisi valid
    if (current_node == Nil) {
        printf("Posisi tidak valid\n");
        return;
    }

    if (prev_node == Nil) {
        // jika node yang dihapus adalah node pertama
        first(*list) = next(current_node);
        if (next(current_node) == Nil) {
            last(*list) = Nil;
        }
    } else {
        // jika node yang dihapus adalah node di tengah atau akhir
        next(prev_node) = next(current_node);
        if (next(current_node) == Nil) {
            last(*list) = prev_node;
        }
    }

    // bebaskan memori node yang dihapus
    free(current_node);
}

void deleteLast(linkedList **list) {
    // cek jika linked list kosong
    if (first(*list) == Nil) {
        printf("Linked list kosong, Tidak ada yang dihapus\n");
        return;
    }

    address current_node = first(*list);
    address prev_node = Nil;

    // iterasi sampai node terakhir
    while (next(current_node) != Nil) {
        prev_node = current_node;
        current_node = next(current_node);
    }

    if (prev_node == Nil) {
        // jika hanya ada satu node
        first(*list) = Nil;
        last(*list) = Nil;
    } else {
        // jika ada lebih dari satu node
        next(prev_node) = Nil;
        last(*list) = prev_node;
    }

    // bebaskan memori node terakhir
    free(current_node);
}

void deleteAll(linkedList **list) {
    address current_node = first(*list);
    address next_node;

    // iterasi dan hapus semua node
    while (current_node != Nil) {
        next_node = next(current_node);
        free(current_node);
        current_node = next_node;
    }

    // atur first dan last ke Nil
    first(*list) = Nil;
    last(*list) = Nil;
}

void deleteByInfo(linkedList **list, infotype info) {
    // cek jika linked list kosong
    if (first(*list) == Nil) {
        printf("Linked list kosong, Tidak ada yang dihapus\n");
        return;
    }

    address current_node = first(*list);
    address prev_node = Nil;

    while (current_node != Nil && info(current_node) != info) {
        prev_node = current_node;
        current_node = next(current_node);
    }

    if (current_node == Nil) {
        printf("Node dengan info = %d tidak ditemukan\n", info);
        return;
    }

    if (prev_node == Nil) {
        // jika node yang dihapus adalah node pertama
        first(*list) = next(current_node);
        if (next(current_node) == Nil) {
            last(*list) = Nil;
        }
    } else {
        // jika node yang dihapus ada di tengah list
        next(prev_node) = next(current_node);
        if (next(current_node) == Nil) {
            last(*list) = prev_node;
        }
    }

    // bebaskan memori node
    free(current_node);
}

void deleteAllByInfo(linkedList **list, infotype info) {
    // cek jika linked list kosong
    if (first(*list) == Nil) {
        printf("Linked list kosong, Tidak ada yang dihapus\n");
        return;
    }

    address current_node = first(*list);
    address prev_node = Nil;

    while (current_node != Nil) {
        // jika node ditemukan
        if (info(current_node) == info) {
            if (prev_node == Nil) {
                // jika node yang ditemukan adalah node awal
                first(*list) = next(current_node);
                if (next(current_node) == Nil) {
                    last(*list) = Nil;
                }
            } else {
                // jika node yang ditemukan ada di tengah list
                next(prev_node) = next(current_node);
                if (next(current_node) == Nil) {
                    last(*list) = prev_node;
                }
            }

            // tampung node yang akan dihapus di alamat sementara
            address temp = current_node;
            current_node = next(current_node);
            // bebaskan memori
            free(temp);
        } else {
            prev_node = current_node;
            current_node = next(current_node);
        }
    }
}

void updateFirst(linkedList *list, infotype new_info) {
    // cek jika linked list kosong
    if (first(list) == Nil) {
        printf("Linked list kosong, Tidak dapat melakukan pembaruan\n");
        return;
    }

    info(first(list)) = new_info;
}

void updateAtPosition(linkedList *list, infotype new_info, int pos) {
    // cek jika linked list kosong
    if (first(list) == Nil) {
        printf("Linked list kosong, Tidak dapat melakukan pembaruan\n");
        return;
    }

    // cek apakah posisi valid
    if (pos <= 0) {
        printf("Posisi harus lebih besar dari 0\n");
        return;
    }

    address current_node = searchAtPosition(list, pos);

    // cek apakah posisi valid
    if (current_node == Nil) {
        printf("Posisi tidak valid\n");
        return;
    }

    info(current_node) = new_info;
}

void updateByInfo(linkedList *list, infotype target_info, infotype new_info) {
    // cek jika linked list kosong
    if (first(list) == Nil) {
        printf("Linked list kosong, Tidak dapat melakukan pembaruan\n");
        return;
    }

    address current_node = searchByInfo(list, target_info);

    // jika node dengan nilai info tertentu ditemukan
    if (current_node != Nil) {
        info(current_node) = new_info;
    } else {
        printf("Node dengan nilai info %d tidak ditemukan\n", target_info);
    }
}

void updateAllByInfo(linkedList *list, infotype target_info, infotype new_info) {
    // cek jika linked list kosong
    if (first(list) == Nil) {
        printf("Linked list kosong, Tidak dapat melakukan pembaruan\n");
        return;
    }

    address current_node = first(list);

    while (current_node != Nil) {
        if (info(current_node) == target_info) {
            info(current_node) = new_info;
        }
        current_node = next(current_node);
    }
}

void updateLast(linkedList *list, infotype new_info) {
    // cek jika linked list kosong
    if (first(list) == Nil) {
        printf("Linked list kosong, Tidak dapat melakukan pembaruan\n");
        return;
    }

    info(last(list)) = new_info;
}

address searchByInfo(linkedList *list, infotype info) {
    address current_node = first(list);
    while (current_node != Nil) {
        if (info(current_node) == info) {
            // jika node ditemukan
            return current_node;
        }
        current_node = next(current_node);
    }
    // jika node tidak ditemukan
    return Nil;
}

address searchAtPosition(linkedList *list, int pos) {
    // jika posisi kurang dari 1
    if (pos <= 0) {
        printf("Invalid position\n");
        return Nil;
    }

    address current_node = first(list);
    int count = 1;

    // cari node berdasarkan posisi
    while (current_node != Nil && count < pos) {
        current_node = next(current_node);
        count++;
    }

    // jika posisi yang dicari tidak ditemukan node
    if (current_node == Nil) {
        printf("Node tidak ditemukan\n");
        return NULL;
    }

    return current_node;
}

void displayList(linkedList *list) {
    address current_node = first(list);
    if (first(list) == NULL) {
        printf("Linked list kosong\n");
    } else {
        printf("First = %d, Last = %d\n", info(first(list)), info(last(list)));
        while (current_node != Nil) {
            printf("%d -> ", info(current_node));
            current_node = next(current_node);
        }
        printf("Nil\n");
    }
}