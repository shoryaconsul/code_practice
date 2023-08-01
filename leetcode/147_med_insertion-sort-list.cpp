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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* sort_head, * sort_next;
        ListNode* curr = head->next;
        
        while(curr){
            sort_head = dummy;
            sort_next = dummy->next;
            while(sort_next && sort_next->val < curr->val){
                cout<<curr->val<<" "<<sort_next->val<<endl;
                sort_next = sort_next->next;
                sort_head = sort_head->next;
            }
            cout<<"OUT: "<<sort_head->val<<" "<<curr->val<<" "<<sort_next->val<<endl;
            sort_head->next = curr;
            curr = curr->next;
            sort_head->next->next = sort_next;
        }
        cout<<"Return "<<dummy->val<<" "<<dummy->next->val<<endl;
        return dummy->next;
    }
};