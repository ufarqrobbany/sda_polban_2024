#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struktur data SLL
typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
    address prev;
} wrg;

// struktur data array
typedef struct kotaList *addressK;
typedef struct kotaList {
    infotype kota;
    addressK next;
    address next1;
} kt;

// deklarasi modul
addressK createKota(infotype kota);
void insertKota(addressK *listKota, infotype info);
void changeNamaKota(addressK listKota, infotype currentName, infotype newName);
void deleteKota(addressK *listKota, infotype kota);

address createWarga(infotype nama);
void insertWarga(addressK listKota, infotype kota, infotype nama);
void changeNamaWarga(addressK listKota, infotype kota, infotype currentName, infotype newName);
void deleteWarga(addressK listKota, infotype kota, infotype nama);

void displayWargaKota(addressK listKota);