#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Stack {
    private:
        int top;
        int arr[MAX_SIZE];
    
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

        void push(int val) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
            arr[++top] = val;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[top--];
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack elements are:" << endl;
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element is: " << s.peek() << endl;
    s.display();
    return 0;
}
