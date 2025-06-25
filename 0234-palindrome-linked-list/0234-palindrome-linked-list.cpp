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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* newHead = reverseList(slow->next);

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != nullptr) {
            if (first->val != second->val) {
                reverseList(newHead); // Optional: Restore original structure
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseList(newHead); // Optional
        return true;
    }

private:
    // Reverse linked list function
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nextTemp = head->next;
            head->next = prev;
            prev = head;
            head = nextTemp;
        }
        return prev;
    }
};
