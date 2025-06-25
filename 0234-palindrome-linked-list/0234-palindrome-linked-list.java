/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    private ListNode reverseList(ListNode head) {
    ListNode prev = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
}


    public boolean isPalindrome(ListNode head) {
        
    ListNode slow = head;
    ListNode  fast = head;

    if(head==null || head.next==null) return true;

    while(fast.next!=null && fast.next.next!=null){
        slow=slow.next;
        fast=fast.next.next;
    }

    ListNode newhead=reverseList(slow.next);
    ListNode first=head;
    ListNode second=newhead;

    while(second!= null){
        
        if(first.val!=second.val){
            reverseList(newhead);
            return false;
        }
        first=first.next;
        second=second.next;

    }
        return true;
    }
}