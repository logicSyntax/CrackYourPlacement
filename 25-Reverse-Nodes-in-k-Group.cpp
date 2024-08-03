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
private:
    int countNode(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = countNode(head);

        if(n < k) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        for(int i=0; i<k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};