// 102. Binary Tree Level Order Traversal
/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root ==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> a;
            int size = q.size();
            for(int i = 0;i<size;i++){
                root = q.front();
                q.pop();
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                a.push_back(root->val);
             }
        ans.push_back(a);
        }
        return ans;
    }
};