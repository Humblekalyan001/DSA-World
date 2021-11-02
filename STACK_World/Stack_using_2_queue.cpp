class MyStack {
public:
    /** Initialize your data structure here. */
  
    queue<int> qu1,qu2;
    MyStack() 
    {

    }
    /** Push element x onto stack. */
    void push(int x) 
    {
        //step 1 : push element into queue-1
        qu1.push(x);
        
        // step 2: Push all elements of queue-2 to queue-1 
        while(!qu2.empty())
        {
            qu1.push(qu2.front());
            qu2.pop();
        }
        
        // step 3: swap queue-1 and queue-2
        swap(qu1,qu2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        // pop will be done from queue-2
        int x = qu2.front();
        qu2.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() 
    {
        return qu2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        if(qu2.size() == 0)
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
