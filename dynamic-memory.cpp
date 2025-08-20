#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
// Append at end
void append(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert at beginning
void insert_at_beginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Search element
void search(int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

// Delete node by value
void delete_node(int key) {
    if (head == NULL) return;

    if (head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;

    Node* t = temp->next;
    temp->next = temp->next->next;
    delete t;
}

// Reverse list
void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Display list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, val;

    do {
        cout << "\n1. Append";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Reverse";
        cout << "\n6. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                append(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insert_at_beginning(val);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> val;
                search(val);
                break;

            case 4:
                cout << "Enter key: ";
                cin >> val;
                delete_node(val);
                break;

            case 5:
                reverse();
                cout << "Reversed!\n";
                break;

            case 6:
                display();
                break;

            case 0:
                cout << "Exit...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 0);

    return 0;
}