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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;
        ListNode* ptr_last = head;
        while (ptr != nullptr) {
            if (ptr->val == val) ptr_last->next = ptr->next;
            else ptr_last = ptr;
            ptr = ptr->next;
        }
        if (head != nullptr && head->val == val) return head->next;
        return head;
    }
};