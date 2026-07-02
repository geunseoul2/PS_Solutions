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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool over = false;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 || l2 || over) {
            int res = 0;

            if(over) {
                res++;
                over = false;
            }

            if(l1) {
                res += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                res += l2->val;
                l2 = l2->next;
            }
            if(res > 9){
                over = true; 
                res %= 10;
            }

            curr->next = new ListNode(res);
            curr = curr->next;

        }

        return dummy->next;
    }
};
