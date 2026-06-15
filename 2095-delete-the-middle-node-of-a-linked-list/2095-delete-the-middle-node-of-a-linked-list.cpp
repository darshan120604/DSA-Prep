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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list is empty or has only one node, return nullptr
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // Tracks the node right before 'slow'

        // Move fast by 2 steps and slow by 1 step
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'slow' is now pointing to the exact middle node
        // 'prev' is pointing to the node before 'slow'
        prev->next = slow->next; 

        // Free up memory to prevent memory leaks

        return head;
    }
};
