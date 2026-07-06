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
    ListNode* reverse(ListNode* root, int n) {
        ListNode* prev = NULL;
        ListNode* curr = root;

        while(n--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        root->next = curr;
        return prev;
    }

    ListNode* reverseList(ListNode* root, int n) {
        if(n==1) return root;

        ListNode* curr=root;
        ListNode* temp=root;
        ListNode* prev=NULL;
        bool status=true;

        while(curr!=NULL){
            int cnt=0;
            temp=curr;
            while(cnt<n){
                temp=temp->next;
                cnt++;
            }

            ListNode* ans=reverse(curr,n);

            if(status){
                root=ans;
                status=false;
            }else{
                prev->next=ans;
            }

            prev=curr;
            curr->next=temp;
            curr=temp;
        }

        return root;
    }
};

void solve() {
    int len,n;
    cin>>len>>n;

    if(len==0){
        cout<<"\n";
        return;
    }

    ListNode *head=NULL,*tail=NULL;

    for(int i=0;i<len;i++){
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
    head=obj.reverseList(head,n);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}