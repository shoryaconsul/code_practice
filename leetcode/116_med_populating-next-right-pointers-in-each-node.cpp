/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (root->left==NULL && root->right==NULL)) return root;
        
        queue<Node*> q;
        Node* node;
        int count_curr = 2, count_next = 0;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            while(count_curr > 0){
                node = q.front();
                q.pop();
                count_curr--;
                if(count_curr > 0) node->next = q.front();
                if(node->left){
                    q.push(node->left);
                    q.push(node->right);
                    count_next = count_next + 2;
                }
            }
            count_curr = count_next;
            count_next = 0;
        }
        return root;
    }
};