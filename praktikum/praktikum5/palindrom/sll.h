// Single Linked List

// Struktur data untuk SLL
struct Node_SLL {
    char info;
    struct Node_SLL* next;
};

// Deklarasi Modul
void Insert_Node_SLL(struct Node_SLL** head, char data);
int Cek_Palindrom_SLL(struct Node_SLL* head);
void Print_List_SLL(struct Node_SLL* head);
void Delete_All_Nodes_SLL(struct Node_SLL** head);