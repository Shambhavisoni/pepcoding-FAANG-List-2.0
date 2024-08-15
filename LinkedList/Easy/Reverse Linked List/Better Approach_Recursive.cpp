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

// QUESTION LINK
// https://leetcode.com/problems/reverse-linked-list/

// OBSERVATION
// In recursion, we need to handle one case, rest recursion take care

// APPROACH
// 1. handle first node, rest give recursion to reverse LL
// 2. As recursion reverse the the LL skiiping the head node, put the head node at the end of the reversed LL ( which is actually head->next)
// 3. Also make head->next as null, as it will be the last node


// TIME AND SPACE COMPLEXITY
// Time Complexity: O(N)
// Space Complexity: O(N) ==> recursive stack space

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = nullptr;
        return newHead;
    }
}
