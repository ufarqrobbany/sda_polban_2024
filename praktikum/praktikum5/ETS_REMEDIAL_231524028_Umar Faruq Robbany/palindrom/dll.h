// Doubly Linked Lisy

// Struktur node untuk DLL
struct Node_DLL {
    char info;
    struct Node_DLL* next;
    struct Node_DLL* prev;
};

// Deklarasi Modul
void Insert_Node_DLL(struct Node_DLL** head, char data);
int Cek_Palindrom_DLL(struct Node_DLL* head);
void Print_List_DLL(struct Node_DLL* head);
void Delete_All_Nodes_DLL(struct Node_DLL** head);