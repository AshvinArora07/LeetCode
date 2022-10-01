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
    
    ListNode* reverse(ListNode* head){
        ListNode* current=head, *prev=NULL, *forward=NULL;
        while(current!=NULL){
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* current =head, *prev=NULL;
        int count=1;
        while(count!=left){
            prev=current;
            current=current->next;
            count++;
        }
        ListNode* start=current;
        while(count!=right){
            current=current->next;
            count++;
        }
        ListNode* rest=current->next;                                                             //This approach is done by reversing a part of a linked list 
        current->next=NULL;                                                                       //e.g: 1->{2->3->4->5}->6->NULL    [left=2 and right=5]
        ListNode* newhead=reverse(start);                                                         //output will be: 1->5->4->3->2->6->NULL
        if(prev!=NULL){                                                                           
            prev->next=newhead;                                                                                                     
        }
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=rest;
        if(left==1)
            return newhead;
        else 
            return head;
    }
};