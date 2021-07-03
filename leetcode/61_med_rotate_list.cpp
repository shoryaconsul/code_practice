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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(head->next == NULL) return head;
        
        int k_rem, count=1;
        ListNode* tail = head;
        while(tail->next != NULL){  // find last nodes
            tail = tail->next;
            count++;
        }
        tail->next = head;  // make list circular
        
        k_rem = count - k%count; // left shift by k = right shift by len-k
        while(k_rem > 0){
            head = head->next;
            tail = tail->next;
            k_rem--;
        }
        tail->next = NULL;
        return head;
    }
};