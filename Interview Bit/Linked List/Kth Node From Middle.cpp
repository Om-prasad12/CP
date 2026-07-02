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
    int solve(ListNode* root, int B) {
        ListNode* slow=root;
        ListNode* fast=root->next;
        int cnt=0;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }

        if(fast!=NULL) cnt++;

        ListNode* ans=root;
        cnt=cnt-B;

        if(cnt<0) return -1;

        while(cnt){
            ans=ans->next;
            cnt--;
        }

        return ans->val;
    }
};

void solve() {
    int n,B;
    cin>>n>>B;

    if(n==0){
        cout<<-1<<"\n";
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
    cout<<obj.solve(head,B)<<"\n";
}