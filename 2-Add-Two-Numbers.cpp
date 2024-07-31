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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* head = NULL;
        ListNode* prev = head;

        while(curr1 != NULL && curr2 != NULL) {
            int number = curr1->val + curr2->val + carry;
            ListNode* temp = new ListNode(number%10);
            carry = number/10;

            if(head == NULL) {
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
                prev = temp;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1 != NULL) {
            int number = curr1->val + carry;
            ListNode* temp = new ListNode(number%10);
            carry = number/10;

            prev->next = temp;
            prev = temp;
            curr1 = curr1->next;
        }

        while(curr2 != NULL) {
            int number = curr2->val + carry;
            ListNode* temp = new ListNode(number%10);
            carry = number/10;

            prev->next = temp;
            prev = temp;
            curr2 = curr2->next;
        }

        if(carry > 0) {
            prev->next = new ListNode(carry);
            prev = prev->next;
        }

        return head;
    }
};