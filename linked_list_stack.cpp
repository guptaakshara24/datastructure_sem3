#include <iostream> 
using namespace std; 
 
//Node class 
class Node{ 
    public: 
    int data; 
    Node *next; 
    Node(int val){ 
        data = val; 
        next = NULL; 
    } 
}; 
 
//class for stack implementation and operation 
class stack{ 
    private: 
    Node *top; 
    int count; 
 
    public: 
    stack(){ 
        top = NULL; 
        count = 0; 
    } 
 
    //INSERT 
    void push(int val){ 
        Node *newNode = new Node (val); 
        newNode -> next = top; 
        top = newNode; 
        cout << "Pushed "<< val<< " into the stack"<< endl; 
        count ++;     
    } 
 
    //DELETE 
    void pop(){ 
        if(isempty()){ 
            cout << "Stack underfloww!!"<< endl; 
        }else{ 
            Node *temp = top; 
            int value = temp -> data; 
            top = temp -> next; 
            delete temp; 
            count --; 
            cout << "Popped "<< value<< " from the stack"<< endl; 
        } 
    } 
 
    //CHECKING EMPTY OR NOT 
    int isempty(){ 
        return (top==NULL); 
    } 
 
    //FINDING TOP DATA 
    int peek(){ 
        if(isempty()){ 
            cout << "Stack is empty!!"<< endl; 
            return -1; 
        }else{ 
            return top->data; 
        } 
    } 
 
    //SIZE 
    int size(){ 
        return count; 
    } 
}; 
 
int main(){ 
    stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout <<"Size of the stack is " << s.size() << endl; 
    s.pop(); 
    s.pop(); 
    cout << "The data at the top is "<< s.peek() << endl; 
    s.pop(); 
    s.pop(); 
    return 0; 
}