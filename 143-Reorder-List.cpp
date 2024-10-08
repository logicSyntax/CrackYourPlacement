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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr != NULL) {
            st.push(curr);
            curr = curr->next;
        }

        curr = head;
        int size = st.size()/2;

        for(int i=0; i<size; i++) {
            ListNode* temp = st.top();
            st.pop();

            temp->next = curr->next;
            curr->next = temp;

            curr = curr->next->next;
        }

        curr->next = NULL;
    }
};