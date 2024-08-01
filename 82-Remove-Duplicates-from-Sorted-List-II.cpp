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
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head->next;
        
        if(curr->val == head->val) {
            while(curr != NULL && curr->val == head->val) 
                curr = curr->next;
            return deleteDuplicates(curr);
        } else {
            head->next = deleteDuplicates(curr);
            return head;
        }
    }
};