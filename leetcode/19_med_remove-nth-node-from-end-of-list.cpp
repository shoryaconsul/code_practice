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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> node_stack;
        ListNode* node;
        ListNode* prev;
        ListNode* curr = head;
        while(curr!=NULL){
            node = curr;
            curr = curr->next;
            node_stack.push(node);
        }
        
        for(int i=0; i<n; i++){
            node = node_stack.top();
            node_stack.pop();
        }
        
        if(node_stack.empty()){
            head = node->next;
        }
        else{
            prev = node_stack.top();
            prev->next = node->next;
        }
        return head;
    }
};