/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;  //pointer to next node
        node->val = next->val;  //copy value to node address
        node->next = next->next; // skip next node
        delete(next);  // delete next object
    }
};