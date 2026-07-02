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
    ListNode* reverse(ListNode* root,int len){
        if(len==1) return root;

        ListNode* curr=root;
        ListNode* prev=NULL;

        for(int i=0;i<len;i++){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* root, int B, int C) {
        if(root==NULL || B==C) return root;

        ListNode* curr=root;
        ListNode* prev=NULL;
        int cnt=1;

        while(cnt<B){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        ListNode* temp=curr;
        while(cnt<=C){
            temp=temp->next;
            cnt++;
        }

        ListNode* ans=reverse(curr,C-B+1);

        if(prev)
            prev->next=ans;
        else
            root=ans;

        for(int i=0;i<C-B;i++){
            ans=ans->next;
        }

        ans->next=temp;

        return root;
    }
};

void solve() {
    int n,B,C;
    cin>>n>>B>>C;

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
    head=obj.reverseBetween(head,B,C);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}