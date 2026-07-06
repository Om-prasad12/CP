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
    ListNode* swapPairs(ListNode* root) {
        if(root==NULL || root->next==NULL) return root;

        ListNode* prev=NULL;
        ListNode* curr=root;
        ListNode* temp=root->next;
        root=temp;

        while(curr!=NULL && curr->next!=NULL){
            ListNode* next=temp->next;
            temp->next=curr;
            curr->next=next;

            if(prev!=NULL) prev->next=temp;

            prev=curr;
            curr=next;

            if(curr!=NULL) temp=curr->next;
        }

        return root;
    }
};

void solve() {
    int n;
    cin>>n;

    if(n==0){
        cout<<"\n";
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
    head=obj.swapPairs(head);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}