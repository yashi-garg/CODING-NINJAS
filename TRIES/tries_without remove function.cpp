//trie data structure
#include<iostream>
using namespace std;
class node{
	public:
		char data;
		bool isterminal;
		node *child[26];
		node(char data)
		{
			this->data=data;
			isterminal=false;
			for(int i=0;i<26;i++)
			{
				this->child[i]=NULL;
			}
		}
};
void insert(node *root,string word)
{
	node *p=root;
	for(int i=0;i<word.size();i++)
	{
		int idx=word[i]-'a';
		
		if(p->child[idx]==NULL)
		{
			node *t=new node(word[i]);
			p->child[idx]=t;
		}
		p=p->child[idx];
	}
	p->isterminal=true;
	cout << "inserted"<<endl;
	return;
}
bool find(string word,node *root)
{
	node *p=root;
	for(int i=0;i<word.size();i++)
	{
		int idx=word[i]-'a';
		if(p->child[idx]==NULL)
		return false;
		else
		p=p->child[idx];
	}
	if(p->isterminal)
	return true;
	else
	return false;
}
int main()
{
	node *root=new node('$');
	int n;
	cin >> n;
	while(n-->0)
	{
		string x;
		cin >> x;
		insert(root,x);
	}
	string x;
	cin >> x;
	bool r=find(x,root);
	if(r)
	cout <<"found"<<endl;
	else
	cout << "not found"<<endl;
	return 0;
}