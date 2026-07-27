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
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;

        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }

        if(st.find(endWord)==st.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);

        int cnt=1;

        while(!q.empty()){
            int size=q.size();

            for(int l=0;l<size;l++){
                string front=q.front();
                q.pop();

                string temp=front;

                for(int i=0;i<front.size();i++){
                    temp=front;

                    for(int j=0;j<26;j++){
                        temp[i]=(char)('a'+j);

                        if(st.find(temp)!=st.end() && temp==endWord)
                            return cnt+1;

                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }

            cnt++;
        }

        return 0;
    }
};

void solve() {
    string beginWord,endWord;
    cin>>beginWord>>endWord;

    int n;
    cin>>n;

    vector<string> wordList(n);
    for(int i=0;i<n;i++){
        cin>>wordList[i];
    }

    Solution obj;
    cout<<obj.ladderLength(beginWord,endWord,wordList)<<"\n";
}