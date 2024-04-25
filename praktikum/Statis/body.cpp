#include "nbtrees.h"
#include <stdbool.h>

/*
Nama    : Hasna Fitriyani Khairunissa
NIM     : 221524011
*/
void init_tree(Isi_Tree *X)
{
    int i;
    for (i = 0; i <= jml_maks; i++)
    {
        (*X)[i].info = '\0';
        (*X)[i].ps_fs = -1;
        (*X)[i].ps_nb = -1;
        (*X)[i].ps_pr = -1;
    }
}

/*
Nama    : Muhammad Rama Nurimani
NIM     : 221524021
*/
void Create_tree(Isi_Tree X, int Jml_Node)
{
    int i, nb_idx, pr_idx;
    infotype node_value, parent_value;
    init_tree(X);

    printf("Masukan root: ");
    scanf(" %c", &node_value);
    X[1].info = node_value;
    X[1].ps_fs = 0;
    X[1].ps_nb = 0;
    X[1].ps_pr = 0;

    for (i = 2; i <= Jml_Node + 1; i++)
    {
        printf("Masukan node ke-%d: ", i - 1);
        scanf(" %c", &node_value);
        X[i].info = node_value;
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;

        // relationship
        do
        {
            printf("Masukan parent dari node %c: ", node_value);
            scanf(" %c", &parent_value);
            pr_idx = NSearch(X, parent_value);

            if (pr_idx != -1)
            {
                // check fs nya
                if (X[pr_idx].ps_fs == 0)
                {
                    X[pr_idx].ps_fs = i;
                }
                else
                { // cari brother terakhir
                    nb_idx = X[pr_idx].ps_fs;
                    while (X[nb_idx].ps_nb != 0)
                    {
                        nb_idx = X[nb_idx].ps_nb;
                    }
                    X[nb_idx].ps_nb = i;
                }

                // set parent nya
                X[i].ps_pr = pr_idx;
            }
            else
            {
                printf("Parent node dengan nilai %c tidak ditemukan.\n", parent_value);
            }
        } while (pr_idx == nil);
    }
}

/*
Nama    :
NIM     :
*/
boolean IsEmpty(Isi_Tree P);

/*
Nama    : Rahma Divina
NIM     : 221524026
*/
// implementasi struktur data pohon dengan array,
// biasanya indeks ke-0 tidak digunakan, karena root tree akan berada di indeks ke-1.
// pemanggilan modul pada main program, parameter int idx akan diisi 1 karena
// akan memulai traversal PreOrder dari root tree yang berada di indeks ke-1
void PreOrder(Isi_Tree P, int idx)
{
    if (idx == 0)
    {
        return; // mengakhiri ekskeusi modul saat index = 0
    }
    printf("%c ", P[idx].info);
    PreOrder(P, P[idx].ps_fs);
    PreOrder(P, P[idx].ps_nb);
}

/*
Nama    : Muhammad Fikri Nur Sya'Bani
NIM     : 221524019
*/
void InOrder(Isi_Tree P)
{
    if (P != NULL)
    {
        if (P->ps_fs != NULL)
        {
            InOrder(P->ps_fs);
        }
        printf("%d ", P->info);
        if (P->ps_nb != NULL)
        {
            InOrder(P->ps_nb);
        }
    }
}

/*
Nama    : Farrel Keiza Muhammad Yamin Putra
NIM     : 221524009
*/
void PostOrder(Isi_Tree P)
{
    bool resmi;
    int pcur;

    pcur = 1;
    resmi = true;

    while (pcur != 0)
    {
        if (P[pcur].ps_fs != 0 && resmi)
        {
            pcur = P[pcur].ps_fs;
        }
        else
        {
            printf("%c ", P[pcur].info);
            if (P[pcur].ps_nb != 0)
            {
                pcur = P[pcur].ps_nb;
                resmi = true;
            }
            else
            {
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }
}

/*
Nama    : Adinda Fauzia Puspita
NIM     : 221524001
*/
void Level_order(Isi_Tree X, int Maks_node)
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
{
    int i;
    for (i = 1; i <= Maks_node; i++)
    {
        if (X[i].info != ' ')
        {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

/*
Nama    : Aryo Rakatama
NIM     : 221524003
*/
// Penggunaan pertama pada modul utama adalah
// PrintTree(X, 1, 0);
// Dimana X adalah variabel bertipe Isi_Tree yang menujuk pada Tree yang dimaksud
// 1 adalah index awal yang digunakan, jangan menggunakan 0 karena akan membuat sistem kebingungan antara null dan index ke 0
// 0 adalah initialisasi awal dari level, karena perlu mengunjungi root terlebih dahulu, maka diisi 0
void PrintTree(Isi_Tree p, address P, int level)
{
    if (P != 0)
    {
        for (int i = 1; i <= level; i++)
        {
            if (i < level)
            {
                printf("|  ");
            }
            else
            {
                printf("|--");
            }
        }
        printf("%c\n", p[P].info);
        PrintTree(p, p[P].ps_fs, level + 1);
        PrintTree(p, p[P].ps_nb, level);
    }
}

/*
Nama    :
NIM     :
*/
boolean Search(Isi_Tree P, infotype X);

/*
Nama    : Akmal G. Hartono
NIM     : 221524002
*/
int NSearch(Isi_Tree P, infotype X)
{
    int i;
    for (i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            return i;
            break;
        }
    }
    return nil;
}

/*
Nama    : Naffa Lenteranisa
NIM     : 221524023
*/
int nbElmt(Isi_Tree P)
{
    int count = 0;
    int i;

    for (i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != '\0')
        { // Node tidak kosong
            count++;
        }
    }

    return count;
}

/*
Nama    : Naila Saniyyah Nur'Aini
NIM     : 221524024
*/
int nbDaun(Isi_Tree P)
{
    int daun = 0;
    address i = 1;

    if (i != nil)
    {
        if (P[i].ps_fs == nil && P[i].ps_nb == nil)
        { // Cek apakah node merupakan daun
            daun++;
        }
        else
        { // Jika bukan daun, cari di anak dan saudara kiri
            daun += nbDaun(P + P[i].ps_fs);
            daun += nbDaun(P + P[i].ps_nb);
        }
    }

    return daun;
}

/*
Nama    : Retryanzani Dwi Fauzan
NIM     : 221524028
*/
int Level(Isi_Tree P, infotype X)
{
    if (P == NULL) // Jika P adalah NULL, artinya pohon kosong
    {
        return -1;
    }
    if (P[1].info == X) // Jika akar P memiliki nilai X, artinya P adalah node yang dicari
    {
        return 0;
    }
    int i, level;
    for (i = 2; i <= jml_maks; i++) 
    {
        if (P[i].info == X) // Jika node ke-i memiliki nilai X, hitung levelnya
        {
            level = 0;
            address parent = P[i].ps_pr;
            while (parent != 0) 
            {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1; // Jika X tidak ditemukan dalam pohon
}

/*
Nama    : Rayhan Fanez Fathiadi
NIM     : 221524027
*/
int Depth(Isi_Tree P, address root)
{
    // root = indeks array

    if (root == nil)
    { // Jika tree kosong
        return 0;
    }
    else if (P[root].ps_fs == nil && P[root].ps_nb == nil)
    { // Jika tree hanya memiliki satu node
        return 1;
    }
    else if (P[root].ps_fs == nil)
    { // Jika tree hanya memiliki anak kebawah
        return Depth(P, P[root].ps_nb) + 1;
    }
    else
    { // Jika tree memiliki anak ke samping
        int maksDepth = 0;
        address sibling = P[root].ps_fs;
        while (sibling != nil)
        {
            int siblingDepth = Depth(P, sibling);
            if (siblingDepth > maksDepth)
            {
                maksDepth = siblingDepth;
            }
            sibling = P[sibling].ps_nb;
        }
        return maksDepth + 1;
    }
}

/*
Nama    : Saabiq Muhyiyuddin Aulawi
NIM     : 221524031
*/
int Max(infotype Data1, infotype Data2)
{
    return (Data1 > Data2) ? Data1 : Data2;
}

/*
Nama    :
NIM     :
*/
int Derajat(Isi_Tree P, infotype X);

/*
Nama    : Muhamad Mathar Rizqi
NIM     : 221524014
*/
int Degree(Isi_Tree P, infotype X)
{
    int index, count = 0;
    if (!IsEmpty(P))
    {
        index = NSearch(P, X);
        if (P[index].ps_fs != nil)
        {
            count++;
            index = P[index].ps_fs;
            while (P[index].ps_nb != nil)
            {
                count++;
                index = P[index].ps_nb;
            }
        }
    }
    return count;
}
