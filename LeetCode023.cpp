//
//  023_Merge k sorted lists.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/30.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode*> myq;
        for (int i=0; i<lists.size()/2; i++){
            ListNode* temp=merge2Lists(lists[2*i], lists[2*i+1]);
            myq.push(temp);
        }
        if (lists.size()%2==1) myq.push(lists[lists.size()-1]);
        while(myq.size()>1){
            ListNode* l1=myq.front();
            myq.pop();
            ListNode* l2=myq.front();
            myq.pop();
            ListNode* l3=merge2Lists(l1, l2);
            myq.push(l3);
        }
        return myq.front();
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        ListNode* begin;
        ListNode* pre;
        ListNode* next;
        if (l1->val<l2->val) {
            begin=l1;
            next=l2;
        }
        else{
            begin=l2;
            next=l1;
        }
        pre=begin;
        
        while(pre->next!=NULL&&next!=NULL){
            if(pre->next->val<next->val){
                pre=pre->next;
            }
            else{
                ListNode* temp=pre->next;
                pre->next=next;
                pre=next;
                next=temp;
            }
        }
        if (pre->next==NULL) pre->next=next;
        return begin;
    }
};
