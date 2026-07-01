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
    void insert(ListNode* &root,ListNode* x){
        if(root==NULL){
            root=x;
            x->next=NULL;
            return;
        }

        if(root->val > x->val){
            x->next=root;
            root=x;
            return;
        }

        ListNode* curr=root;
        while(curr->next!=NULL){
            if(curr->next->val>=x->val) break;
            curr=curr->next;
        }

        ListNode* temp=curr->next;
        curr->next=x;
        x->next=temp;
    }

    ListNode* insertionSortList(ListNode* root) {
        ListNode* ans=NULL;
        ListNode* curr=root;

        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=NULL;
            insert(ans,curr);
            curr=temp;
        }

        return ans;
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
    head=obj.insertionSortList(head);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}