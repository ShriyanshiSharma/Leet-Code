// 109. Convert Sorted List to Binary Search Tree

// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> ans;

    TreeNode * solve(vector<int> &ans ,int s,int e){
        if(s>e) return NULL;
        int m = s+(e-s)/2;
        TreeNode* node = new TreeNode(ans[m]);
        node->left = solve(ans,s,m-1);
        node->right =  solve(ans,m+1,e);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while(head != NULL) {
            ans.push_back(head->val);
            head = head->next;
        }
        return solve(ans,0,ans.size()-1);
    }
};