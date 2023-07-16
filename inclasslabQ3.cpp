#include <iostream>
#include <chrono>
using namespace std;

#define MAX_SIZE 100



class Stack {
    private:
        int arr[MAX_SIZE];
        int top;
    public:
        Stack() {
            top = -1;
        }
        bool isEmpty() {
            return (top == -1);
        }
        bool isFull() {
            return (top == MAX_SIZE - 1);
        }
        void push(int value) {
            if(isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            arr[top] = value;
        }
        int pop() {
            if(isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int value = arr[top];
            top--;
            return value;
        }
        void display() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack: ";
            for(int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void Array() {
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for(int i = 0; i < 5; i++) {
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
}



class Node {
    public:
        int data;
        Node* next;
};

class Linkedlist {
    private:
        Node* top;
    public:
        Linkedlist() {
            top = NULL;
        }
        bool isEmpty() {
            return (top == NULL);
        }
        void push(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }
        int pop() {
            if(isEmpty()) {
                cout << "Linkedlist Underflow" << endl;
                return -1;
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
        void display() {
            if(isEmpty()) {
                cout << "Linkedlist is empty" << endl;
                return;
            }
            cout << "Linkedlist: ";
            Node* temp = top;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

void Linkedlist1() {
    Linkedlist s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for(int i = 0; i < 5; i++) {
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
}





int main() {
    // Measure time for  Array
    auto start1 = chrono::high_resolution_clock::now();
    Array();
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();
    cout << "Time taken by  Array: " << duration1 << " microseconds" << endl;

    // Measure time for Linkedlist1
    auto start2 = chrono::high_resolution_clock::now();
    Linkedlist1();
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    cout << "Time taken by Linkedlist: " << duration2 << " microseconds" << endl;

    return 0;
}
