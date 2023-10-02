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
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        ListNode* node2 = head;
        while (node2->next != nullptr && node2->next->next != nullptr) {
            node = node->next;
            node2 = node2->next->next;
        }
        return node2->next == nullptr ? node : node->next;
    }
};