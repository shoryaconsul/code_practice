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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL or head->next == NULL) return head;
        
        ListNode less, more;
        ListNode* less_ptr = &less, * more_ptr = &more;
        while(head){
            // cout<<less_ptr->val<<" "<<more_ptr->val<<" "<<head->val<<endl;
            if(head->val < x){
                less_ptr->next = head;
                head = head->next;
                less_ptr = less_ptr->next;
            }
            else{
                more_ptr->next = head;
                head = head->next;
                more_ptr = more_ptr->next;
            }
        }
        
        less_ptr->next = more.next;  // attach both lists
        more_ptr->next = nullptr;  // end list
        return less.next;
    }
};