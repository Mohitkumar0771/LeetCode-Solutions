class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save head of even list to attach later

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; // Connect odd tail to even head
        return head;
    }
};