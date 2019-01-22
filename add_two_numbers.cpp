/**
 * 2019-01-22
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* sum = new ListNode(0);
        int carry = 0;
        int digitsum = temp1->val + temp2->val;
        if(digitsum > 9) 
        {
            carry = digitsum / 10;
            digitsum = digitsum % 10;
        }
        sum->val = digitsum;

        if(temp1->next != NULL && temp2->next == NULL)
        {
            sum->next = new ListNode(0);
            recursivesingle(temp1->next, sum->next, carry);
        }
        else if(temp1->next == NULL && temp2->next !=NULL)
        {
            sum->next = new ListNode(0);
            recursivesingle(temp2->next, sum->next, carry);
        }
        else if(temp1->next == NULL && temp2->next ==NULL)
        {
            if(carry > 0)
            {
                sum->next = new ListNode(carry);
            }
        }
        else {
            sum->next = new ListNode(0);
            recursiveboth(temp1->next, temp2->next, sum->next, carry);
        }
        return sum;
    }
    
    void recursiveboth(ListNode* l1, ListNode* l2, ListNode* sum, int carry)
    {
        int digitsum = l1->val + l2->val + carry;
        carry = 0;
        if(digitsum > 9) 
        {
            carry = digitsum / 10;
            digitsum = digitsum % 10;
        }
        sum->val = digitsum;
        if(l1->next == NULL && l2->next == NULL)
        {
            if(carry > 0)
            {
                sum->next = new ListNode(carry);
            }
            return;
        }
        else if(l1->next == NULL && l2->next != NULL)
        {
            sum->next = new ListNode(0);
            recursivesingle(l2->next, sum->next, carry);
        }
        else if(l1->next != NULL && l2->next == NULL)
        {
            sum->next = new ListNode(0);
            recursivesingle(l1->next, sum->next, carry);
        }
        else { 
            sum->next = new ListNode(0);
            recursiveboth(l1->next, l2->next, sum->next, carry);
        }
    }
    
    void recursivesingle(ListNode* l, ListNode* sum, int carry)
    {
        int digitsum = l->val+carry;
        carry = 0;
        if(digitsum > 9) 
        {
            carry = 1;
            digitsum = digitsum % 10;
        }
        sum->val = digitsum;
        if(l->next == NULL)
        {
            if(carry > 0)
            {
                sum->next = new ListNode(carry);
            }
            return;
        }
        else{
            sum->next = new ListNode(0);
            recursivesingle(l->next, sum->next, carry);
        }
    }
};
