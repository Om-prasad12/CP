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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(a && b){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if(a) tail->next = a;
        else tail->next = b;

        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head, *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(second);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* root) {
        return mergeSort(root);
    }
};

void solve() {
    int n;
    cin>>n;

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
    head=obj.sortList(head);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}