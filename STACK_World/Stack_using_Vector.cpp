//************************ Stack using Vector(Dynamic Array) ************//
#include <iostream>
#include<vector>

using namespace std;

struct MyStack
{
    vector<int> v1; // Dynamic Array == vector.. NO need to specify size of array initially .

    void push(int x)
    {
        v1.push_back(x);
    }
    int pop()
    {
        int res = v1.back(); // copy the last element/ top element  from stack
        v1.pop_back();  // remove top element from vector
        return res;
    }
    int peek()
    {
        return v1.back();
    }
    int size()
    {
        return v1.size();
    }
    bool isEmpty()
    {
        return v1.empty();
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<"Popping element is : "<<s.pop()<<endl;
    cout<<"Size of the size : "<< s.size()<<endl;
    cout<<"Peek element is : "<<s.peek()<<endl;
    if(s.isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Not Empty";

    }

    return 0;

}
