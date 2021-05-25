
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends

/*You are required to complete this method*/

class Solution
{
  public:
  // NSL code
   vector<int>NSLindex(vector<int>& arr, int n)
    {
        vector<int> left;
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
    vector<int>NSRindex(vector<int>& arr, int n)
    {
        vector<int> right;
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
  // Maximum area histogram code
     int MAH(vector<int>& arr1) 
    {
        int n = arr1.size();
        vector<int> left =  NSLindex(arr1, n);
        vector<int> right = NSRindex(arr1, n);
        
        int max_rec = INT_MIN;
        for(int i=0; i<n; i++)
        {
            max_rec = max(max_rec , (right[i] - left[i] -1) * arr1[i]);
        }
        return max_rec;   
    }


     //  Maximum area rectsngle code
     
int maxArea(int M[MAX][MAX], int n, int m) 
    {
        // Your code here
        vector<int> vec;
        for(int j=0; j<m; j++)
        {
            vec.push_back(M[0][j]); // first array insert)
        }
        
        int max_value = MAH(vec);
        
        // next all 1d array insert
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(M[i][j] == 0)
                {
                    vec[j] =0;
                }
                else
                {
                    vec[j] = vec[j] + M[i][j];
                }
            }
        max_value = max(max_value, MAH(vec));
        }
      return max_value;  
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends

  /*
   input :  4 4 
    0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

    output: 8
  */