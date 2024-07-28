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
    int getDecimalValue(ListNode* head) {
        int len = -1;
        ListNode* curr = head;
        while(curr != NULL) {
            curr = curr->next;
            len++;
        }

        int number = 0;

        curr = head;
        while(len >= 0 && curr != NULL) {
            number = number + pow(2, len)*(curr->val);
            curr = curr->next;
            len--;
        }

        return number;
    }
};