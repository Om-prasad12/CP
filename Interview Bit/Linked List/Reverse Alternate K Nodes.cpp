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
    ListNode* reverse(ListNode* root, int len){
        ListNode* curr=root->next;
        ListNode* prev=root;
        prev->next=NULL;
        for(int i=0;i<len-1;i++){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    ListNode* solve(ListNode* root, int B) {

        if(root==NULL || B==1) return root;

        ListNode* curr=root;
        ListNode* prev=NULL;
        bool status=true;

        while(curr!=NULL){

            ListNode* temp=curr;
            int cnt=0;
            while(temp!=NULL && cnt<B){
                temp=temp->next;
                cnt++;
            }
            if(cnt<B) break;

            ListNode* nextBlock=temp;

            ListNode* ans=reverse(curr,B);

            if(status){
                root=ans;
                status=false;
            }
            else{
                prev->next=ans;
            }

            for(int i=0;i<B-1;i++)
                ans=ans->next;

            ans->next=nextBlock;

            prev=ans;
            curr=nextBlock;

            cnt=0;
            while(curr!=NULL && cnt<B){
                prev=curr;
                curr=curr->next;
                cnt++;
            }
        }

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
    head=obj.solve(head,B);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}