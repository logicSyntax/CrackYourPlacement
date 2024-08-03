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
    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == NULL)
            return right;
        
        if(right == NULL)
            return left;
        
        ListNode* end = new ListNode(-1);
        ListNode* start = end;

        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                end->next = left;
                end = left;
                left = left->next;
                end->next = NULL;
            } else {
                end->next = right;
                end = right;
                right = right->next;
                end->next = NULL;
            }
        }

        if(left != NULL) {
            end->next = left;
        }

        if(right != NULL) {
            end->next = right;
        }

        return start->next;
    }
private:
    ListNode* mergeSort(vector<ListNode*> &list, int low, int high) {
        if(low == high)
            return list[low];
        
        int mid = low + (high-low)/2;
        ListNode* left = mergeSort(list, low, mid);
        ListNode* right = mergeSort(list, mid+1, high);

        return merge(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        return mergeSort(lists, 0, n-1);
    }
};