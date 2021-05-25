
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        vector<int> vec;
        stack<int> stk;
        for(int i=0; i<n;i++)
        {
            // u are pointing last element and stack is zero //
            if(stk.size()==0) 
                vec.push_back(-1);

            //if ur current element is bigger than stack top
            else if(stk.size()>0 && stk.top() < arr[i]) 
                vec.push_back(stk.top());

            // if current element is greater than stack top
            else if(stk.size() > 0 && stk.top() >= arr[i])
            {
                while(stk.size()>0 && stk.top() >= arr[i])
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
       //reverse(vec.begin(), vec.end());
       return vec;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends