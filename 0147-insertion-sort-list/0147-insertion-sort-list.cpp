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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = head->next;
        ListNode* lastSorted = head;

        while (curr != nullptr) {
            // If the current element is already in the right place, simply move forward
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                // Find the insertion location starting from the dummy head
                ListNode* prev = &dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                // Splice 'curr' out of its current position and insert it after 'prev'
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            // Move to the next unsorted node
            curr = lastSorted->next;
        }

        return dummy.next;
    }
};