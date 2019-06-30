#include <iostream>
#include<string.h>

using namespace std;

class node
{
public:
	   char word[100];
	    char mean[100];
	   node *left;
	   node *right;

};
class bst
{
public:
	   node *root;
	   bst()
	   {
		   root=NULL;
	   }
	   void create();
	   void insert(node*,node*);
	   void display(node *);
	   int search(node *,char[]);
	   node *del(node *,char []);
	   node * min(node *);

};
void bst::create()
{
	node *temp; int ch;
	do
	{
	temp=new node;
	char str[100];
	cout<<"Enter word : "<<endl;
	cin>>temp->word;
	cout<<"Enter Meanning of Word : "<<endl;
	cin>>temp->mean;


	temp->left=NULL;
	temp->right=NULL;
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		insert(root,temp);
	}
	cout<<"Do you want to add more words in dictionary ? ";
	cin>>ch;
	}while(ch==1);
}
void bst::insert(node *root,node *temp)
{
    if(strcmp(root->word, temp->word)<0)
    {
       if(root->right == NULL)
       {
    	   root->right = temp;
       }
       else
       {
    	   insert(root->right,temp);
       }
   }
    if(strcmp(root->word, temp->word)>0)
       {
    	   if(root->left == NULL)
    	         {
    	      	   root->left = temp;
    	         }
    	         else
    	         {
    	      	   insert(root->left,temp);
    	         }
       }
}

void bst::display(node *root)
{
  node*temp=root;
  if(temp!=NULL)
  {
	  display(temp->left);
	  cout<<"WORD IS: "<<temp->word<<endl;
       cout<<"MEANNING IS :"<<temp->mean<<endl<<endl;	  
	  display(temp->right);
  }
}
int bst::search(node *root,char k[20])
{
    int c=0;
    while(root!=NULL)
    {
    	c++;
    	if(strcmp(k,root->word)==0)
    	{
    		cout<<"WORDS is NOT FOUND In TECHNICAL DIRECTORY."<<endl;
			cout<<"WORD IS : "<<root->word<<endl;
    	    cout<<"MEANNING IS :"<<root->mean<<endl<<endl;
    		cout<<"Number of comparison : "<<c<<endl;
    		return 1;
    		break;
    	}
    	else
    	{
    		if(strcmp(k,root->word)<0)
    		    	{
    		    		root=root->left;
    		    	}
    		else
    		{
    			if(strcmp(k,root->word)>0)
    			    		    	{
    			    		    		root=root->right;
    			    		    	}
    			else
    			{

    				return 0;
    			}
    		}
    	}

    }
}



node * bst::del(node *root,char k[30])
		{
			node *temp;
			if(root==NULL)
			{
				cout<<"WORD NOT FOUND IN TECHNICAL DICTIONARY........"<<endl;
				return root;

			}


    		if(strcmp(k,root->word)<0)
    		    	{
    		    		root->left=del(root->left,k);
    		    		return root;
    		    	}

    		if(strcmp(k,root->word)>0)
    		    	{
    		    		root->right=del(root->right,k);
    		    		return root;
    		    	}
    		if(root->right==NULL && root->left==NULL)
    		{
    			temp=root;
    			delete temp;
    			return NULL;

    		}
    		if(root->right==NULL)
    		{
    			temp=root;
    			root=root->left;
    			delete temp;
    			return root;
    		}
    		else
    		{
    		if(root->left==NULL)
    		    		{
    		    			temp=root;
    		    			root=root->right;
    		    			delete temp;
    		    			return root;
    		    		}
    		}
    		temp=min(root->right);
    		strcpy(root->word,temp->word);
    		root->right=del(root->right,temp->word);
    		return root;
		}
node * bst:: min(node * q)
{
	while(q->left!=NULL)
	{
		q=q->left;

	}
	return q;

}

int main()
{
	int ch;
	bst b;
	b.root=NULL;
	do
	{

	cout<<"------------------WELCOME TO TECHNICAL DIRECTORY-------------------- "<<endl<<endl;
	cout<<"The choices are :  "<<endl<<endl;
	cout<<"1. INSERT WORDS in TECHNICAL DIRECTORY. "<<endl;
	cout<<"2. Display WORDS from TECHNICAL DIRECTORY. "<<endl;
	cout<<"3. Search WORDS in TECHNICAL DIRECTORY.. "<<endl;
	cout<<"4. Delete WORDS in TECHNICAL DIRECTORY.. "<<endl<<endl;
	cout<<"Enter your choice : "<<endl;
	cin>>ch;

	switch(ch)
	{
	case 1 :
		cout<<"Enter WORDS in TECHNICAL DIRECTORY.: "<<endl;
		b.create();
		cout<<" WORD iS STORED IN TECHNICAL DIRECTORY."<<endl<<endl;
		break;
	case 2 :
		cout<<"The WORDS in TECHNICAL DIRECTORY is : "<<endl;
        b.display(b.root);
		break;
	case 3 :
		int flag;
		flag=0;
		char s[30];
		cout<<"Enter  WORD to be search : "<<endl;
		cin>>s;
		flag=b.search(b.root,s);
		if(flag==0)
		{
			cout<<" WORDS is NOT FOUND In TECHNICAL DIRECTORY. "<<endl;


		}
		break;
	case 4 :
		char c[10];
		cout<<"Enter WORD is to be deleted : "<<endl;
		cin>>c;
		b.del(b.root,c);
		cout<<"WORD is DELETED."<<endl;
		break;	
	}
	cout<<"Do u want to continue"<<endl<<"Yes=1"<<endl<<"No=0"<<endl<<endl;
    cin>>ch;
	}while(ch==1);



	return 0;
}
