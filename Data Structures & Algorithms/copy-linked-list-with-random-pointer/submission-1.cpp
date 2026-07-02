/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* dummy = new Node(0);
        Node* dummyhead = new Node(0);
        dummyhead->next = head;
        Node* curr = new Node(NULL);
        dummy->next = curr;
        unordered_map<Node*,Node*> hmap;

        while(head) { //make new nodes excpet random
            hmap[head] = curr;

            curr->val = head->val;
            head = head->next;
            if(head) curr->next = new Node(NULL);
            curr = curr->next;
        }

        head = dummyhead->next;
        curr = dummy->next;
        
        while(head) {
            curr->random = hmap[head->random];

            head = head->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
