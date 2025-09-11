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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

struct Node{
	Node *links[26];
	bool flag=false;

	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}

	void createNewKey(char ch,Node* node){
		links[ch-'a']=node;
	}

	Node* getNode(char ch){
		return links[ch-'a'];
	}

	void markEnd(){
		flag=true;
	}

	bool isLast(){
		return flag;
	}

};

class Trie{
private: Node* root;

public:
	Trie(){
		root= new Node();
	}

	void insert(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i])){
				node->createNewKey(word[i],new Node());
			}
			node=node->getNode(word[i]);
		}
		node->markEnd();
	}

	bool isWordExist(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i])) return false;
			node=node->getNode(word[i]);
		}
		return node->isLast();
	}

	bool isStartWith(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i])) return false;
			node=node->getNode(word[i]);
		}
		return true;
	}


};


void solve() {
   int n;
   cin>>n;
   Trie trie;

   vector<pair<int,string>> query;
   for(int i=0;i<n;i++){
   	int x;
   	string temp;
   	cin>>x>>temp;
   	query.push_back({x,temp});
   }

   for(int i=0;i<n;i++){
   	 int x=query[i].first;
   	 string word=query[i].second;
   	 if(x==1){
   	 	trie.insert(word);
   	 } else if(x==2){
   	 	cout<<(trie.isWordExist(word)?"Yes":"No")<<endl;
   	 } else{
   	 	cout<<(trie.isStartWith(word)?"Yes":"No")<<endl;
   	 }
   }

}