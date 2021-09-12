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
    
    void node_swap(ListNode* node1, ListNode* node2){
        node1->next = node2->next;
        node2->next = node1;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* next = head->next;
        ListNode* curr = head;
        head = next;
        node_swap(curr, next);
        curr->next = swapPairs(curr->next);
        return head;
    }
};