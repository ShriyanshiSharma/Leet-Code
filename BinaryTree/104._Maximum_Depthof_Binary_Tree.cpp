// 104. Maximum Depth of Binary Tree
/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
 
Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int v1 = maxDepth(root->left);
        int v2 = maxDepth(root->right);
        return 1 + max(v1,v2);
    }
};