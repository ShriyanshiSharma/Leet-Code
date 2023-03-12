// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode *curr = head, *next = head->next;
        while (next and next->next)
        {
            swap(curr->val, next->val);
            curr = curr->next->next, next = next->next->next;
        }
        if (curr and next) swap(curr->val, next->val);
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* a = NULL;
        ListNode* b = head;
        ListNode* c = head->next;
        
        while(b!=NULL && c!=NULL){
            if(a==NULL){
                b->next = c->next;
                c->next = b;
                head = c;
            }else{
                a->next = c;
                b->next = c->next;
                c->next = b;
            }
            a = b;
            b = b->next;
            if(b) c = b->next;
        }
        return head;
    }
};