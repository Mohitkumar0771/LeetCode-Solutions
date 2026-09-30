class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // 1. Find length and original tail
        int n = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            n++;
        }

        // 2. Normalize k
        k = k % n;
        if (k == 0) return head;

        // 3. Close the circle
        tail.next = head;

        // 4. Traverse to new tail
        int stepsToNewTail = n - k;
        ListNode newTail = tail;
        while (stepsToNewTail-- > 0) {
            newTail = newTail.next;
        }

        // 5. Sever the link
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}