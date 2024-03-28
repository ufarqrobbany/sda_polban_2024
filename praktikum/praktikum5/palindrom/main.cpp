#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    char info;
    Node* next;
};

// Class untuk linked list
class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node ke linked list
    void insert(char data) {
        Node* newNode = new Node();
        newNode->info = data;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menghapus seluruh node pada linked list
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    // Fungsi untuk mengecek apakah linked list merupakan palindrom
    bool isPalindrome() {
        Node* slow = head;
        Node* fast = head;
        Node* prev_slow = nullptr;

        // Temukan midpoint linked list menggunakan teknik fast-slow pointer
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        // Jika panjang linked list ganjil, maju ke node selanjutnya
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Balik bagian kedua dari linked list
        Node* prev = nullptr;
        Node* current = slow;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Bandingkan setiap elemen dari kedua bagian linked list
        Node* first = head;
        Node* second = prev;
        while (second != nullptr) {
            if (first->info != second->info) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // Kembalikan true jika linked list merupakan palindrom
        return true;
    }
};

int main() {
    string input;
    cout << "Masukkan kata atau frasa: ";
    getline(cin, input);

    // Inisialisasi linked list
    LinkedList singlyLinkedList;
    LinkedList doublyLinkedList;

    // Memasukkan setiap karakter dari input ke kedua linked list
    for (char c : input) {
        if (c != ' ') {
            singlyLinkedList.insert(tolower(c));
            doublyLinkedList.insert(tolower(c));
        }
    }

    // Mengecek apakah linked list merupakan palindrom
    bool isSinglyPalindrome = singlyLinkedList.isPalindrome();
    bool isDoublyPalindrome = doublyLinkedList.isPalindrome();

    // Menampilkan hasil
    if (isSinglyPalindrome) {
        cout << "Kata atau frasa tersebut adalah palindrom (Singly Linked List)." << endl;
    } else {
        cout << "Kata atau frasa tersebut bukan palindrom (Singly Linked List)." << endl;
    }

    if (isDoublyPalindrome) {
        cout << "Kata atau frasa tersebut adalah palindrom (Doubly Linked List)." << endl;
    } else {
        cout << "Kata atau frasa tersebut bukan palindrom (Doubly Linked List)." << endl;
    }

    // Menghapus linked list
    singlyLinkedList.clear();
    doublyLinkedList.clear();

    return 0;
}

// Perbedaan utama antara program yang menggunakan struktur linear single linked list dan double linked list pada kasus pengecekan palindrom terletak pada kemampuan untuk mengakses elemen dari belakang.

// 1. **Single Linked List**: Pada single linked list, akses ke elemen dari belakang tidak efisien karena setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. Oleh karena itu, untuk menemukan elemen di bagian belakang, perlu dilakukan iterasi dari awal hingga akhir linked list untuk mencapai node terakhir.

// 2. **Double Linked List**: Pada double linked list, setiap node memiliki dua pointer, satu menunjuk ke node sebelumnya dan satu lagi menunjuk ke node berikutnya. Hal ini memungkinkan akses yang lebih efisien ke elemen dari belakang karena kita dapat langsung mengakses node terakhir dan bergerak mundur ke belakang jika diperlukan.

// Dalam kasus pengecekan palindrom, double linked list memberikan keunggulan karena kita perlu membandingkan setiap elemen dari kedua bagian linked list, dan kemampuan untuk mengakses elemen dari belakang secara langsung akan mempercepat proses ini.