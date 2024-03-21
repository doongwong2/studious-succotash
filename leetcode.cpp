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
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = new ListNode;
        ListNode* p2 = new ListNode;
        ListNode* p3 = new ListNode;

        p1 = head;
        p2 = head;
        p3 = nullptr;

        while (nullptr != p1)
        {
            p1 = p1->next;
            p2->next = p3;
            p3 = p2;
            p2 = p1;

        }

        return p3;
    }
};