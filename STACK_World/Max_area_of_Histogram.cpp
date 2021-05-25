
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<long long>NSLindex(long long arr[], long long n)
    {
        vector<long long> left;
        stack<pair<int, int>> st;
        int pseudo_index = -1;
        
        for(int i=0; i<n; i++)
        {
            if(st.size() == 0)
            {
                left.push_back(pseudo_index);
            }
            
            else if(st.size() > 0 and st.top().first < arr[i])
            {
                left.push_back(st.top().second);
            }
            else if(st.size() > 0 and st.top().first >= arr[i])
            {
                while(st.size() > 0 and st.top().first >= arr[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    left.push_back(-1);
                }
                else
                {
                    left.push_back(st.top().second);
                }
            }
        st.push({arr[i],i});    
        }
        
        return left;
    }


    // NSR code
    vector<long long>NSRindex(long long arr[], long long n)
    {
        vector<long long> right;
        stack<pair<int, int>> stk;
        int pseudo_index = n;
        
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                right.push_back(pseudo_index);
            }
            
            else if(stk.size() > 0 and stk.top().first < arr[i])
            {
                right.push_back(stk.top().second);
            }
            else if(stk.size() >0 and stk.top().first >= arr[i])
            {
                while(stk.size() >0 and stk.top().first >= arr[i])
                {
                    stk.pop();
                }
                if(stk.size()==0)
                {
                    right.push_back(pseudo_index);
                }
                else
                {
                    right.push_back(stk.top().second);
                }
            }
        stk.push({arr[i],i});    
        }
        reverse(right.begin(), right.end());
        return right;
    }



    //Function to find largest rectangular area possible in a given histogram.

    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> left =  NSLindex(arr, n);
        vector<long long> right = NSRindex(arr, n);
        
        long long max_rec = INT_MIN;
        for(long long i=0; i<n; i++)
        {
            max_rec = max(max_rec , (right[i] - left[i] -1) * arr[i]);
        }
        return max_rec;
        //return 0;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
