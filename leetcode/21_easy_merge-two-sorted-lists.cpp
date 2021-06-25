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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int val1, val2;
        ListNode* res = NULL;
        ListNode* curr;
        ListNode* tmp;
        
        if(p1 == nullptr){
            return p2;
        }
        if(p2 == nullptr){
            return p1;
        }
        
        while(p1 != nullptr && p2 != nullptr){
            cout<<"Entered loop"<<endl;
            val1 = p1->val;
            cout<< val1 <<endl;
            val2 = p2->val;
            cout << val1 << val2 << endl;
            if(val1 <= val2){
                tmp = new ListNode(val1);
                p1 = p1->next;
            }
            else{
                tmp = new ListNode(val2);
                p2 = p2->next;
            }
            
            if(res == NULL){
                res = tmp;
                curr = tmp;
            }
            else{
                curr->next = tmp;
                curr = tmp;
            }
        }
        if (p1 == nullptr && p2 == nullptr){
            ;
            }
        else if(p1 != nullptr){
            curr->next = p1;
        }
        else{
            curr->next = p2;
        }
        return res;
    }
};