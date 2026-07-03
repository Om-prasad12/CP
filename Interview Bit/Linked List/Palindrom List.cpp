#include<bits/stdc++.h>
using namespace std;
void solve();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution {
public:
    ListNode* reverse(ListNode* root){
        ListNode* curr=root;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    int lPalin(ListNode* root) {
        ListNode* slow=root;
        ListNode* fast=root->next;

        if(fast==NULL) return 1;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* ans=reverse(slow->next);
        slow->next=NULL;

        ListNode* curr=root;
        while(ans!=NULL){
            if(curr->val!=ans->val) return 0;
            curr=curr->next;
            ans=ans->next;
        }

        return 1;
    }
};

void solve() {
    int n;
    cin>>n;

    if(n==0){
        cout<<1<<"\n";
        return;
    }

    ListNode *head=NULL,*tail=NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode *node=new ListNode(x);

        if(head==NULL){
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }

    Solution obj;
    cout<<obj.lPalin(head)<<"\n";
}