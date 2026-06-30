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
    ListNode* solve(ListNode* root) {
        ListNode* curr=root;
        ListNode *one = NULL, *temp1 = NULL, *temp2 = NULL;
        bool status=true;
        
        while(curr!=NULL){
            if(curr->val==0){
                if(status){
                    root=curr;
                    temp1=root;
                    status=false;
                } else{
                    temp1->next=curr;
                    temp1=curr;
                }
            } else{
                if(one==NULL){
                    one=curr;
                    temp2=curr;
                } else{
                    temp2->next=curr;
                    temp2=curr;
                }
            }
            curr=curr->next;
        }
        
        if(temp2) temp2->next = NULL;
        if(temp1) temp1->next = one;

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

    ListNode* head=NULL;
    ListNode* tail=NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* node=new ListNode(x);
        if(head==NULL){
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }

    Solution obj;
    head=obj.solve(head);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}