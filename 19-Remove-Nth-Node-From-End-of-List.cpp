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
        if(head == NULL)
            return head;
            
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }

        if(len == n)
            return head->next;

        curr = head;
        int step = len-n;
        int jump = 0;

        while(curr != NULL) {
            jump++;

            if(jump == step) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }

            curr = curr->next;
        }

        return head;
        
    }
};