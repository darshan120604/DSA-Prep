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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                // Link prev to skip the current node
                prev->next = curr->next;
                // In C++, explicitly delete the node to prevent memory leaks
                delete curr; 
            } else {
                // Only move prev forward if we didn't delete a node
                prev = curr;
            }
            // Always move curr forward to the next node in the original sequence
            curr = prev->next;
        }

        // The new head is what dummy points to
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
