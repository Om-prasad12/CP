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
    ListNode* removeNthFromEnd(ListNode* root, int B) {
        int cnt=0;
        ListNode* curr=root;

        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }

        int x=cnt-B-1;
        if(x<0) return root->next;

        curr=root;
        while(x--){
            curr=curr->next;
        }

        curr->next=curr->next->next;
        return root;
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
    head=obj.removeNthFromEnd(head,B);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}