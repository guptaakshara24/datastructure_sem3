#include <iostream>
using namespace std;
int count =0;
class arrStack{
    private:
    int size;
    int *arr;
    int top;

    public:
    arrStack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }                                    
    bool isFull(){                                  //IF THE STACK IS FULL 
        return (top==size-1);
    }
    
    void push(int val){                             //INSERT
        if(isFull()){
            cout << "condition of overflow!!!"<<endl;
        }else{
            top++;
            arr[top] = val;
            cout << "pushed "<<val<<" into the stack"<< endl;
            count ++;
        }
    }

    int isEmpty(){                                 //CHECK THE STACK IS EMPTY?
        return(top == -1);
    }

    void pop(){                                      //DELETE
        if(isEmpty()){
            cout << "condition of underflow!!"<<endl;
        }else{
            int temp = arr[top];
            top--;
            cout<< "Popped "<< temp <<" from the stack"<< endl;
            count --;
        }
    }
    
    int peek(){                                     //DISPLAY TOP ELEMENT
        if(top==-1){
            cout<< "Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    int stackSize(){
        return count;
    }
};
int main(){
    
    arrStack s(5);
    s.push(5);
    s.push(4);
    s.push(2);
    cout << "The size of stack is: "<< s.stackSize()<< endl;
    cout << "The top element is : "<< s.peek()<< endl;
    s.pop();
    s.pop();
    s.pop();
    cout << "The size of stack is: "<< s.stackSize() << endl;
    return 0;
}


