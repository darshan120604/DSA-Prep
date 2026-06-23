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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* st = head;
        ListNode* prev = head;
        if(!st) return head;
        st = st->next;
        while(st){
            if(st->val != prev->val){
                st  = st->next;
                prev = prev->next;
            }else{
                prev->next = st->next;
                st = st->next;
            }
        }
        return head;
    }
};