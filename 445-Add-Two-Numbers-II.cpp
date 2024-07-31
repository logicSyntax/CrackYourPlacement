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
    ListNode* solve(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* revHead = solve(head->next);
        head->next->next = head;
        head->next = NULL;

        return revHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *tail = NULL;
        ListNode* curr1 = solve(l1), *curr2 = solve(l2);
        int carry = 0;

        while(curr1 != NULL || curr2 != NULL || carry != 0)
        {
            int sum = 0;
            if(curr1 != NULL)
            {
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2 != NULL)
            {
                sum += curr2->val;
                curr2 = curr2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);

            if(head == NULL)
            {
                head = temp;
                tail = head;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        return solve(head);
    }
};