#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define stack_size 20

class Stack {
    private:
        int top;
        int arr[stack_size];
        int size;
    public:
        Stack(int S) {
            top = -1;
            size = S;
        }
        void Push(int x) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
           
           top = top+1;
           arr[top] = x;
        }
        int Pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            
            top = top-1;
            return arr[top+1];
            
        }
        
         bool isEmpty() {
            return top == -1;
        }
        bool isFull() {
            return top == size - 1;
        }
        
        
        int StackTop() {
            if (isEmpty()) {
                cout << "Stack empty" << endl;
                return -1;
            }
            return arr[top];
        }
       
        void Display() {
            if (isEmpty()) {
                cout << "Stack empty" << endl;
                return;
            }
            cout << "Elements in the stack: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main() {
    
    auto start = high_resolution_clock::now(); 
     
    Stack s(stack_size);
    
    
    
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
