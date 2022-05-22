// Preorder Traversal 
/*
Given a binary tree, find its preorder traversal.

Example 1:
Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 

Example 2:
Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 104
0 <= Data of a node <= 105
*/

vector<int> vi;
void pre(Node* root){
    if(root!=NULL){
        vi.push_back(root->data);
        pre(root->left);
        pre(root->right);
        
    }
    return;
}
vector <int> preorder(Node* root){
    pre(root);
    vector<int> res=vi;
    vi.clear();
    return res;

}