#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void Push(int val) {
        Node* newNode = new Node(val);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }
    int Pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int popvalue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popvalue;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    int StackTop() {
        if (top == nullptr) {
            cout << "Stack empty" << endl;
            return -1;
        }
        return top->data;
    }
    
    void Display() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return;
        }
        cout << "Elements in the stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    
    auto start = high_resolution_clock::now(); 
    
    Stack s;
    
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    
    
    s.Display();
    
    
  
    cout << s.Pop() << " is popped from stack" << endl;
    cout << s.Pop() << " is popped from stack" << endl;
    cout << s.Pop() << " is popped from stack" << endl;
    cout << s.Pop() << " is popped from stack" << endl;
    cout << s.Pop() << " is popped from stack" << endl;
   
   
    s.Display();
    
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    
    s.Display();
    
   auto stop = high_resolution_clock::now();  

   auto duration = duration_cast<microseconds>(stop - start);  

   cout << "Time taken: " << duration.count() << " microseconds" << endl;
   
   
    return 0;
}
