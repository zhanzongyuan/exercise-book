//
//  002_add_two_numbers.cpp
//  
//
//  Created by applecz on 2017/9/4.
//
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//v1.0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tail=new ListNode(0);
        ListNode *pre=tail;
        ListNode *head=tail;
        int addnum=0;
        while(l1!=NULL||l2!=NULL){
            int sum=(l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+addnum;
            tail->val=sum%10;
            addnum=sum/10;
            pre=tail;
            pre->next=new ListNode(0);
            tail=tail->next;
            if (l1!=NULL) l1=l1->next;
            if (l2!=NULL) l2=l2->next;
        }
        while(addnum!=0){
            tail->val=addnum%10;
            addnum=addnum/10;
            pre=tail;
            pre->next=new ListNode(0);
            tail=pre->next;
        }
        if (pre->next!=NULL) delete pre->next;
        pre->next=NULL;
        return head;
    }
};
