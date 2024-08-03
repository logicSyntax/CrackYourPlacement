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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        ListNode* prev = new ListNode(-1);
        ListNode* start = prev;

        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                prev->next = l1;
                prev = l1;
                l1 = l1->next;
                prev->next = NULL;
            } else {
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
                prev->next = NULL;
            }
        }

        if(l1 != NULL) {
            prev->next = l1;
        }

        if(l2 != NULL) {
            prev->next = l2;
        }
        
        return start->next;
    }

    ListNode* findMid(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* mid = findMid(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left, right);

        return result;
    }
};