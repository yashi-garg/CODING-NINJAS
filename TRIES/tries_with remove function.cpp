#include<iostream>
using namespace std;
class node
{
	public:
		char data;
		int count;
		node *child[26];
		node(char data)
		{
			this->data=data;
			count=0;
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
	p->count++;
}
//searching
bool search(string word,node *root)
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
	if(p->count>0)
	return true;
	else
	return false;
}
void remove(string word,node *root)
{
node *p=root;
for(int i=0;i<word.size();i++)
{
	int idx=word[i]-'a';
	if(p->child[idx]==NULL)
	return;
	p=p->child[idx];
	}	
	p->count--;
}
int main()
{
	node *root=new node('$');
	int n;
	 cin >> n;
	 //insertion
	 while(n-->0)
	 {
	 	string w;
	 	cin >> w;
	 	insert(root,w);
	 }
	 //search bat before removal shows yes
	 if(search("bat",root))
	 cout <<"yes"<<endl;
	 else
	 cout << "no"<<endl;
	 //removing the word bat
	 remove("bat",root);
	 //searching the word bat after removing it once
	 if(search("bat",root))
	 cout <<"yes"<<endl;
	 else
	 cout << "no"<<endl;
	 /*
	 case 1 (duplicate input)
	 if insertion is
	 5
	 bat
	 art
	 arc
	 bat
	 that
	 
	 since here bat was inserted 2 times and removed only once so even after removal it shows yes
	 */
	 
	  /*
	  case 2(no duplicate input) in no duplicate input even isterminal is ok
	 if insertion is
	 5
	 bat
	 art
	 arc
	 the
	 that
	 
	 since here bat was inserted 1 times and removed only once so after removal it shows no
	 */
}