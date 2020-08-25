//Description of the problem - https://leetcode.com/problems/merge-two-sorted-lists/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *finalList = dummy;
        
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                finalList->next = l1;
                l1 = l1->next;
                finalList = finalList->next;
            } else {
                finalList->next = l2;
                l2 = l2->next;
                finalList = finalList->next;    
            }
        }
        
        if (l1) finalList->next = l1;
        else if (l2) finalList->next = l2;
        
        //finalList is pointing at the last element of the List
        //Point finalList at the first element and delete the dummy node.
        finalList = dummy->next;
        delete dummy;
        
        return finalList;
    }
};