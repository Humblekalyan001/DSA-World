void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        int size= q1.size()-1;
        
        while(size--)
        {
            q1.push(q1.front());
            q1.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code
        int answer=-1;
        if(q1.size() == 0)
        {
            return -1;
        }
        else
        {
            answer = q1.front();
            q1.pop();
        }
        return answer;
}

TC :  O(n)
SC : O(n)
