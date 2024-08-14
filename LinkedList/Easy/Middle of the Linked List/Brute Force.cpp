// QUESTION LINK:
// https://leetcode.com/problems/middle-of-the-linked-list/

// OBSERVATION & APPROACH:
// 1. Calculate the length of LL
// 2. To get middle node position, there can be two cases:
//     a. return 2nd middle node
//        middle node = n/2 + 1
//     b. return 1st middle node
//        middle node = (n+1)/2

// TIME AND SPACE COMPLEXITY:
// Time Complexity: O(N) + O(N+1/2) ≈ O(N)
//    => O(N) for calculatig ength of LL
//    => O(N+1/2) to reach middle node
// Space Complexity: O(1)

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
    int len(ListNode* head){
        if(head == nullptr){
            return 0;
        }
        return 1 + len(head->next);
    }
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        int n = len(head);

        for(int i=1;i<(n/2)+1;i++){
            head = head -> next;
        }
        return head;
    }
};
