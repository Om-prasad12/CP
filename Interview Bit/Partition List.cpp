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
    ListNode* partition(ListNode* root, int B) {
        ListNode *curr=root,*small=NULL,*big=NULL,*root2=NULL;
        bool status=true;
        while(curr!=NULL){
            if(curr->val<B){
                if(status){
                    root=curr;
                    small=curr;
                    status=false;
                } else{
                    small->next=curr;
                    small=curr;
                }
            } else{
                if(root2==NULL){
                    root2=curr;
                    big=curr;
                } else{
                    big->next=curr;
                    big=curr;
                }
            }
            curr=curr->next;
        }

        if(big) big->next=NULL;
        if(small) small->next=root2;
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
    head=obj.partition(head,B);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}