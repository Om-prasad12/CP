#include<bits/stdc++.h>
using namespace std;
void solve();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

vector<int> validSequence(string word1,string word2){
    int n=word1.size();
    int m=word2.size();

    vector<int> last(m,-1);

    int i=n-1;
    int j=m-1;

    while(i>=0 && j>=0){
        if(word1[i]==word2[j]){
            last[j]=i;
            --j;
        }

        --i;
    }

    vector<int> ans;
    ans.reserve(m);

    bool canSkip=true;
    j=0;

    for(i=0;i<n && j<m;++i){
        if(word1[i]==word2[j]){
            ans.push_back(i);
            ++j;
        }
        else if(canSkip &&
                (j==m-1 || i<last[j+1])){
            canSkip=false;
            ans.push_back(i);
            ++j;
        }
    }

    if(j==m)
        return ans;

    return {};
}

void solve(){
    string word1,word2;
    cin>>word1>>word2;

    vector<int> ans=validSequence(word1,word2);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}