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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        if(b==NULL) return a;

        ListNode* root=NULL;

        if(a->val<=b->val){
            root=a;
            a=a->next;
            root->next=NULL;
        }else{
            root=b;
            b=b->next;
            root->next=NULL;
        }

        ListNode* curr=root;

        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                curr->next=a;
                a=a->next;
            }else{
                curr->next=b;
                b=b->next;
            }
            curr=curr->next;
            curr->next=NULL;
        }

        if(a!=NULL) curr->next=a;
        if(b!=NULL) curr->next=b;

        return root;
    }
};

void solve() {
    int n,m;
    cin>>n>>m;

    ListNode *head1=NULL,*tail1=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode *node=new ListNode(x);
        if(head1==NULL){
            head1=tail1=node;
        }else{
            tail1->next=node;
            tail1=node;
        }
    }

    ListNode *head2=NULL,*tail2=NULL;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        ListNode *node=new ListNode(x);
        if(head2==NULL){
            head2=tail2=node;
        }else{
            tail2->next=node;
            tail2=node;
        }
    }

    Solution obj;
    ListNode* head=obj.mergeTwoLists(head1,head2);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}