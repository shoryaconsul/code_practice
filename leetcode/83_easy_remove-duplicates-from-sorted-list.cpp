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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode res = ListNode();  // return
        ListNode* tail = &res;  // pointer to res
        int curr_val = INT_MIN;
        while (head != nullptr){
            if(head->val != curr_val){
                tail->next = new ListNode();
                tail = tail->next;
                tail->val = head->val;
                curr_val = head->val;  // update current value
                head = head->next;  // advance in input list

            }
            else{  // advance in input list
                head = head->next;
            }
        }
        return res.next;
    }
};