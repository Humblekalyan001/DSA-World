// ********************** STACK USING ARRAY *******************//

#include<iostream>
using namespace std;

struct Mystack
{
public:
    int *arr; // Stack using Array//
    int cap; // initially we have to say the size of array == size of stack, and it is fixed, not dynamic rising of stack/array size.
    int top;
    Mystack(int capacity)  // It is a constructor , It will create My Stack//
    {
        cap = capacity;
        arr = new int[cap]; // creating stack using array
        top = -1;            // initially top = -1
    }
void push(int x)
{
    //check overflow condition//
    if(top == cap -1)
    {
        cout<<"Stack is Overflowing ";
    }
    else
    {
        top++; // first we increment top position
        arr[top] = x;  // then we put x value in that arr[top] position
    }
}

int pop()
{
    // First check Underflow condition
    if(top == -1)
    {
        cout<<"Stack is Underflowing ";
    }
    else
    {
        int res = arr[top]; // first take top value from array and store any variable
        top--;              // then decrement top position
        return res;         // return deleted value
    }
}

int peek()
{
    if(top == -1)
    {
        cout<<"Stack underflow, There is no Peak Value ";
    }
    else
    {
        return arr[top];
    }
}

int size()
{

    return (top + 1);
}
bool isEmpty()
{
    return (top == -1);
}
};
int main()
{
   Mystack s(5);
    // cout<<s.pop()<<endl;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
}
