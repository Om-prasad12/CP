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
    ListNode* detectCycle(ListNode* root) {
        ListNode* slow=root;
        ListNode* fast=root;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                slow=root;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

void solve() {
    int n,pos;
    cin>>n>>pos;

    if(n==0){
        cout<<-1<<"\n";
        return;
    }

    vector<ListNode*> nodes;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nodes.push_back(new ListNode(x));
    }

    for(int i=0;i<n-1;i++){
        nodes[i]->next=nodes[i+1];
    }

    if(pos!=-1){
        nodes[n-1]->next=nodes[pos];
    }

    Solution obj;
    ListNode* ans=obj.detectCycle(nodes[0]);

    if(ans) cout<<ans->val<<"\n";
    else cout<<-1<<"\n";
}