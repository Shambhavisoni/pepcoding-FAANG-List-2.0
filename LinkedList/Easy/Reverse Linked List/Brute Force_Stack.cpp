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
// For reversing, we can consider stack to store the nodes and when we will pop the nodes, we will get the nodes in reverse order

// APPROACH
// 1. Add all nodes to stack
// 2. take out nodes from stack one by one and create a new LL from them, stack is LIFO, we will get last node first, which will create reversed LL


// TIME AND SPACE COMPLEXITY
// Time Complexity: O(N)
// Space Complexity: O(N) ==> stack space

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        while(!st.empty()){
            if(newHead == nullptr){
                newHead = st.top();
                tail = st.top();
            }
            else{
                ListNode* newNode = new ListNode(st.top()->val);
                tail->next = newNode;
                tail = newNode;
            }
            st.pop();
        }
        return newHead;
    }
};


