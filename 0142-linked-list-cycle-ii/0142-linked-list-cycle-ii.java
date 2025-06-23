/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode slow = head;
        ListNode fast = head;

        //Phase 1 : To Detect Cycle 
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) //if cycle detected
            {
                slow = head; //bring the slow pointer back to start--> head

                while (slow != fast) { //Now moving the slow pointer from start 
                    //And fast from meeting point to find the starting point 
                    // slow --> 1 step 
                    // Fast --> 1 step , Once cycle detected

                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;

    }
}