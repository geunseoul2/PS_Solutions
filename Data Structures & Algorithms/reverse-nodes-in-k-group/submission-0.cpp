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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        vector<ListNode*> nodes;

        for(int i=0;i<k;i++) {
            if(!curr) return head;
            nodes.push_back(curr);
            curr = curr->next;
        }

        for(int i=k-1;i>0;i--)  nodes[i]->next = nodes[i-1];
        nodes[0]->next = reverseKGroup(curr,k);
        
 
        return nodes[k-1];
    }
};
