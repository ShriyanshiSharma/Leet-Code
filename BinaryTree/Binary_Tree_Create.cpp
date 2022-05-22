#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node* right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildnode(node* root){
    cout<<"Enter the element"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the element to be inserted in the left"<<endl;
    root->left = buildnode(root->left);
    cout<<"Enter the element to be inserted in the right"<<endl;
    root->right  = buildnode(root->right);
    return root;
}

int main() {
    node* root = NULL;
    root = buildnode(root);
    return 0;
}