// Next Greater Element == Nearest Greater element from Right
//   Note: loop will go from i=(n-1) to 0,  Start from right side of the array,  Need a stack//


#include<bits/stdc++.h>
using namespace std;

// Function to return Next larger elements

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long int> vec;
        stack<long long int> stk;
        for(int i=n-1; i>= 0;i--)
        {
            // u are pointing last element and stack is zero //
            if(stk.size()==0) vec.push_back(-1);

            //if ur current element is smaller than stack top
            else if(stk.size()>0 && stk.top() > arr[i]) vec.push_back(stk.top());

            // if current element is greater than stack top

            else if(stk.size() > 0 && stk.top() <= arr[i])
            {
                while(stk.size()>0 && stk.top() <= arr[i])
                {
                   stk.pop(); 
                }

                if(stk.size() == 0) 
                {
                    vec.push_back(-1);
                }
                else  // stk.top() > arr[i]
                {
                    vec.push_back(stk.top());
                }
            }
        
        stk.push(arr[i]);  // at last u have to push current element into stack
        }
       reverse(vec.begin(), vec.end());
       return vec;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}