#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Push element on top of stack
    void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    // Pop element from top of stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Get the top element of stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Display the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack Linkedlist;
    Linkedlist.display();
    Linkedlist.push(1);
    Linkedlist.display();
    Linkedlist.push(2);
    Linkedlist.display();
    Linkedlist.push(3);
    Linkedlist.display();
    Linkedlist.push(4);
    Linkedlist.display(); // 4 3 2 1
    cout << "Top element is " << Linkedlist.peek() << endl; // 4
    cout << "Element is going to pop " << Linkedlist.peek() << endl;
    Linkedlist.pop();
    Linkedlist.display();
    cout << "Element is going to pop " << Linkedlist.peek() << endl;
    Linkedlist.pop();
    Linkedlist.display(); // 2 1
    cout << "Top element is " << Linkedlist.peek() << endl; // 2
    return 0;
}
