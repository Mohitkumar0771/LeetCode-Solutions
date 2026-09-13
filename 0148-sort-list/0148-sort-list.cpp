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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Count the total length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // 2. Bottom-up merge with step size doubling each round (1, 2, 4, 8, ...)
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                // Split off the first sublist of size `step`
                ListNode* left = curr;
                ListNode* right = split(left, step);

                // Split off the second sublist of size `step`
                curr = split(right, step);

                // Merge the two sorted sublists
                auto [mergedHead, mergedTail] = merge(left, right);

                // Reconnect merged part to the main list
                prev->next = mergedHead;
                prev = mergedTail;
            }
        }

        return dummy.next;
    }

private:
    // Splits the list after `step` nodes and returns the head of the remaining list
    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < step; ++i) {
            head = head->next;
        }
        ListNode* nextPart = head->next;
        head->next = nullptr;
        return nextPart;
    }

    // Merges two sorted lists and returns {head, tail} of the merged list
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        while (tail->next) {
            tail = tail->next;
        }

        return {dummy.next, tail};
    }
};