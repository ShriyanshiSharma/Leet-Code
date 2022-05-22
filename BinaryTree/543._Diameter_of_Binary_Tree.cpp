// 543. Diameter of Binary Tree

/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

class Solution {
    private:
    pair<int,int> dai(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = dai(root->left);
        pair<int,int> right = dai(root->right);
        int o1 = left.first ;
        int o2 = right.first;
        int o3 = left.second + right.second ;
        pair <int,int> ans;
        ans.first = max(o1,max(o2,o3));
        ans.second = max(left.second,right.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dai(root).first;
    }
};