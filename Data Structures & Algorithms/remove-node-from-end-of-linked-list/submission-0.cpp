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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_size = 0;
        ListNode* temp = head;

        while(temp) {
            total_size++;
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;

        
        int steps = total_size - n;
        for(int i = 0; i < steps; i++) {
            node = node->next;
        }

        
        ListNode* toDelete = node->next;
        node->next = node->next->next;
        delete toDelete; 
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};
