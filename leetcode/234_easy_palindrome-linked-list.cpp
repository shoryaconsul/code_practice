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
    bool isPalindrome(ListNode* head) {
        ListNode* tail = head;
        stack<ListNode*> fw_stack;
        stack<int> bw_stack;
        int rev;
        
        while(tail){  // push all values in list
            bw_stack.push(tail->val);
            tail = tail->next;
        }
        
        for(int i=0, j=bw_stack.size()-1; i<j; i++, j--){
            rev = bw_stack.top();
            bw_stack.pop();
            if(head->val != rev) return false;
            else{
                head = head->next;
            }
        }
        return true;
    }
};