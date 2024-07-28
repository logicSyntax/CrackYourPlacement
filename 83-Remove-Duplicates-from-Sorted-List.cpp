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
        if(head == NULL)
            return head;
            
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next != NULL) {
            if(curr->val != next->val) {
                curr = curr->next;
                next = next->next;
            } else {
                ListNode* temp = next;
                next = next->next;
                curr->next = next;
                delete(temp);  
            }
        }

        return head;
    }
};