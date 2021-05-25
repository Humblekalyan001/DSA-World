// Nearest graeter to left == Nearest greater to left //
// loop will go from left to right ( 0 t0 n) , 1 stack needed  
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long int> vec;
        stack<long long int> stk;
        for(int i=0; i<n;i++)   // for(int i= n-1; i>=0; i--) -----> it is for nearest greater from right
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
                if(stk.size() == 0) vec.push_back(-1);
                else
                {
                    vec.push_back(stk.top());
                }
            }
        
        stk.push(arr[i]);
        }
       //reverse(vec.begin(), vec.end());    // it is needed in ---> neaerest graeter from right
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
        for (long long i : res) cout << i <<" ";
        cout<<endl;
    }
	return 0;
}

