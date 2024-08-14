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

// QUESTION LINK:
// https://leetcode.com/problems/middle-of-the-linked-list/

// OBSERVATION:
// To avoid multiple traversal of LL, we can have a way to reach middle node in one iteration

// if one pointer iterates the LL wih double speed in the same time, lets assume pointer A speed is twice of pointer B,
// Speed of A = distance travelled by A / Time
// Speed of B = speed of A / 2

// as time taken is same, distance travelled by B = distance travelled by A / 2
// So by the time A iterates over entire LL, B will reach the middle node

// APPROACH:
// 1. Take 2 pointers fast and slow
// 2. Move fast pointer 2 times faster than slow pointer
// 3. Now there can be two cases in even number of nodes:
//   a. return the first middle node
//      => Run while loop till fast->next and fast->next->next is not null
//      => You need to handle 0 size LL separately here, as (fast = null)
//   b. return the second middle node
//      => Run while loop till fast and fast->next is not null

// TIME AND SPACE COMPLEXITY:
// Time Complexity: O(N)
//    => fast pointer is jumping 2 steps at a time, but it is going through all the nodes (it can't skip the node and jump to 2nd node)
//    => so each node is traversed atleast once
// Space Complexity: O(1)

// CASE a: If even number of nodes, return the first middle node
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

// CASE b: If even number of nodes, return the second middle node
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
