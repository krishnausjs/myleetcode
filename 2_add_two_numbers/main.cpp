//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Example:
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val: 0;
            int sum = carry + x + y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;               
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;        
        }
        if(carry == 1)
        {
            curr->next = new ListNode(1);
        }
        return dummyHead->next;
    }
    ListNode* newNode(int x)
    {
        ListNode* new_node = new ListNode(0);
        new_node->val = x;
        new_node->next = NULL;
        return new_node;
    }
    
    void push(ListNode **head_ref, int new_data)
    {
        ListNode* new_node = newNode(new_data);
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    
    void printLL(ListNode *nodeVal)
    {
        while(nodeVal != NULL)
        { 
            cout << nodeVal->val <<"  ";
            nodeVal = nodeVal->next;
        }
        cout << endl;   
    }
};

int main()
{
    Solution s;
    ListNode *res = NULL;
    ListNode *first = NULL;
    ListNode *second = NULL;
    
    s.push(&first, 3);
    s.push(&first, 4);
    s.push(&first, 2);
    s.printLL(first);
    
    s.push(&second, 4);
    s.push(&second, 6);
    s.push(&second, 5);    
    s.printLL(second);
    res = s.addTwoNumbers(first, second);
    s.printLL(res);
    return 0;
}