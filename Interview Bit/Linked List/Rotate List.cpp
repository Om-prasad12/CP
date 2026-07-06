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
    ListNode* rotateRight(ListNode* root, int B) {
        if(root==NULL || root->next==NULL) return root;

        int n=0;
        ListNode* curr=root;
        ListNode* last=NULL;

        while(curr!=NULL){
            last=curr;
            curr=curr->next;
            n++;
        }

        int x=B%n;
        if(x==0) return root;

        n=n-x-1;
        curr=root;

        while(n){
            curr=curr->next;
            n--;
        }

        ListNode* temp=curr->next;
        curr->next=NULL;
        last->next=root;

        return temp;
    }
};

void solve() {
    int n,B;
    cin>>n>>B;

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
    head=obj.rotateRight(head,B);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}