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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        if(b==NULL) return a;

        ListNode* root=a;
        int carry=0;
        ListNode* curr=NULL;

        while(a!=NULL && b!=NULL){
            int sum=a->val+b->val+carry;
            curr=a;
            curr->val=sum%10;
            carry=sum/10;
            a=a->next;
            b=b->next;
        }

        ListNode* temp=curr;
        int status=true;

        while(a!=NULL){
            int sum=a->val+carry;
            curr=a;
            if(status){
                temp->next=curr;
                status=false;
            }
            curr->val=sum%10;
            carry=sum/10;
            a=a->next;
        }

        while(b!=NULL){
            int sum=b->val+carry;
            curr=b;
            if(status){
                temp->next=curr;
                status=false;
            }
            curr->val=sum%10;
            carry=sum/10;
            b=b->next;
        }

        if(carry!=0){
            ListNode* extra=new ListNode(carry);
            curr->next=extra;
        }

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
    ListNode* head=obj.addTwoNumbers(head1,head2);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}