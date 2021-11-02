
TC :  O(n)
SC : O(n)

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> qu1;
    MyStack() 
    {

    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
       // step1: push into queue1
        qu1.push(x);
        
        // step 2: take size of queue-1 and push all size elements again in queue from back
        int size = qu1.size()-1;
        
        while(size--)
        {
            qu1.push(qu1.front());
            qu1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        // pop will be done from queue-2
        int x = qu1.front();
        qu1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() 
    {
        return qu1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        if(qu1.size() == 0)
        {
            return true;
        }
        
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

