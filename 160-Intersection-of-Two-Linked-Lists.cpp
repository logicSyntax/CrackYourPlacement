/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* curr = headA;
        while(curr != NULL) {
            len1++;
            curr = curr->next;
        }

        curr = headB;
        while(curr != NULL) {
            len2++;
            curr = curr->next;
        }

        curr = headA;
        ListNode* curr2 = headB;
        if(len1>len2) {
            int diff = len1-len2;
            while(diff--) {
                curr = curr->next;
            }
        } else {
            int diff = len2-len1;
            while(diff--) {
                curr2 = curr2->next;
            }
        }

        while(curr != NULL || curr2 != NULL) {
            if(curr == curr2)
                return curr;
            
            curr = curr->next;
            curr2 = curr2->next;
        }

        return NULL;
    }
};