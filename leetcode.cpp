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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* extra = new ListNode(0);
        ListNode* p1, * p2;
        extra->next = head;
        p1 = extra;
        p2 = head;
        while (n--)
        {
            p2 = p2->next;
        }

        while (p2 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = p1->next->next;


        return extra->next;
    }
};