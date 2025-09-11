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
	Node* links[26];
	int ew=0;
	int cp=0;

	bool containKeys(char ch){
		return (links[ch-'a']!=NULL);
	}

	void createNewKey(char ch,Node* node){
		links[ch-'a']=node;
	}

	Node* getNode(char ch){
		return links[ch-'a'];
	}

	void incrementCount(){
		cp++;
	}

	void decrementCount(){
		cp--;
	}

	void incrementEndCount(){
		ew++;
	}

	void decrementEndCount(){
		ew--;
	}

	int getCountPrefix(){
		return cp;
	}

	int getEndCount(){
		return ew;
	}

};

class Trie{
private: Node* root;

public:
	Trie(){
		root=new Node();
	}

	void insert(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containKeys(word[i])){
				node->createNewKey(word[i],new Node());
			}
			node=node->getNode(word[i]);
			node->incrementCount();
		}
		node->incrementEndCount();
	}

	int findNumberOfWords(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containKeys(word[i])){
				return 0;
			}
			node=node->getNode(word[i]);
		}
		return node->getEndCount();
	}


	int findNumberOfWordsStarts(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containKeys(word[i])){
				return 0;
			}
			node=node->getNode(word[i]);
		}
		return node->getCountPrefix();
	}

	void eraseWord(string word){
		Node* node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containKeys(word[i])){
				return;
			}
			node=node->getNode(word[i]);
			node->decrementCount();
		}
		node->decrementEndCount();
	}

};

void solve() {
   Trie trie;
   int n;
   cin>>n;
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
   	 	cout<<trie.findNumberOfWords(word)<<endl;
   	 } else if(x==3){
   	 	cout<<trie.findNumberOfWordsStarts(word)<<endl;
   	 } else{
   	 	trie.eraseWord(word);
   	 }
   }
}