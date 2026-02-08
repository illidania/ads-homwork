#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = NULL;
    }
    
    void insert(int value) {
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
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void deleteNode(int value) {
        if (head == NULL) {
            return;
        }
        
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next != NULL) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};

int main() {
    LinkedList list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    
    cout << "List: ";
    list.display();
    
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();
    
    list.insert(25);
    cout << "After inserting 25: ";
    list.display();
    
    return 0;
}
