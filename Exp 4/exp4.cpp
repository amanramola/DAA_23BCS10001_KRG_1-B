#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void deleteFromEnd() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "X\n";
    }
};

class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromBeginning() {
        if (!tail) return;
        Node* head = tail->next;
        if (tail == head) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void deleteFromEnd() {
        if (!tail) return;
        Node* head = tail->next;
        if (head == tail) {
            delete tail;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }

    void display() {
        if (!tail) {
            cout << "CLL is empty\n";
            return;
        }
        Node* temp = tail->next;
        cout << "CLL: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)\n";
    }
};

int main() {
    // Doubly Linked List
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.display();

    dll.deleteFromBeginning();
    dll.display();

    dll.deleteFromEnd();
    dll.display();

    cout << "\n";

    // Circular Linked List
    CircularLinkedList cll;
    cll.insertAtBeginning(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.display();

    cll.deleteFromBeginning();
    cll.display();

    cll.deleteFromEnd();
    cll.display();

    return 0;
}
