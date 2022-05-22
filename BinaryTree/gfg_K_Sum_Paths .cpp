// K Sum Paths 

/*
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.

Example 1:
Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3

Example 2:
Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

Your Task:  
You don't need to read input or print anything. Complete the function sumK() which takes root node and integer K as input parameters and returns the number of paths that have sum K. Since the answer may be very large, compute it modulo 109+7.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)

Constraints:
1 ≤ N ≤ 105
-105 ≤ Node Value ≤ 105
-109 ≤ k ≤ 109*/

class Solution{
  public:
  void solve(Node * root,int k,int &c,vector<int> ans){
      if(root==NULL)  return ;
      ans.push_back(root->data);
      
      solve(root->left,k,c,ans);
      solve(root->right,k,c,ans);
      
      int sum = 0;
      int n = ans.size();
      for(int i = n-1;i>=0;i--){
          sum += ans[i];
          if(sum == k){
              c++;
          }
      }
      ans.pop_back();
      
  }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;
        int c =0;
        solve(root,k,c,ans);
        return c;
    }
};


