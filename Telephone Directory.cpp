//===========================================================================================================================================
// Name        : assignment_4.cpp
// Author      : Niranjan Patil
// Description : Design and implement a program to generate a computerized telephone directory for a 
//               cellular service consisting of name and cell phone number. Present the user with a menu 
//               that allows the user to search the directory for a specified record, insert a new record,
//               delete an existing record, or print the entire phone list.
//==============================================================================================================================================

#include <iostream>
#include<string.h>
using namespace std;
class node
{
public:
	   char name[10];
	   long int sale_no;
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
	cout<<"Enter Customer Name : "<<endl;
	cin>>temp->name;
	cout<<"Enter Customer Mobile Number : "<<endl;
	cin>>temp->sale_no;
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
	cout<<"Do you want to add more phone number ?"<<endl;
	cout<<"Yes=1"<<endl;
	cout<<"No= any number."<<endl;
	cin>>ch;
	}while(ch==1);
}
void bst::insert(node *root,node *temp)
{
    if(strcmp(root->name, temp->name)<0)
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
    if(strcmp(root->name, temp->name)>0)
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
    if(strcmp(root->name, temp->name)==0)
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
}

void bst::display(node *root)
{
  node*temp=root;
  if(temp!=NULL)
  {
	  display(temp->left);
	  cout<<"Customer Name : "<<temp->name<<endl;
	  cout<<"Customer Mobile Number : "<<temp->sale_no<<endl<<endl;
	  display(temp->right);
  }
}
int bst::search(node *root,char k[20])
{
    int c=0;
    while(root!=NULL)
    {
    	c++;
    	if(strcmp(k,root->name)==0)
    	{
    		cout<<"Customer Name : "<<root->name<<endl;
    		cout<<"Customer Mobile Number : "<<root->sale_no<<endl<<endl;
    		cout<<"Number of comparison : "<<c<<endl<<endl;
    		return 1;
    		root=root->right;
    	}
    	else
    	{
    		if(strcmp(k,root->name)<0)
    		    	{
    		    		root=root->left;
    		    	}
    		else
    		{
    			if(strcmp(k,root->name)>0)
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
				cout<<" Mobile number not found phone dictionary is empty."<<endl;
				return root;

			}


    		if(strcmp(k,root->name)<0)
    		    	{
    		    		root->left=del(root->left,k);
    		    		return root;
    		    	}

    		if(strcmp(k,root->name)>0)
    		    	{
    		    		root->right=del(root->right,k);
    		    		return root;
    		    	}
 
            	if(strcmp(k,root->name)==0)
    		    	{
         		if(root->right==NULL && root->left==NULL)
    		{
    			temp=root;
    			delete temp;
    			cout<<"Contact is DELETED."<<endl;
    			return NULL;

    		}
         		if(root->right==NULL)
    		{
    			temp=root;
    			root=root->left;
    			delete temp;
    			cout<<"Contact is DELETED."<<endl;
    			return root;
    		}
    	    	else
    		{
    		     if(root->left==NULL)
    		    		{
    		    			temp=root;
    		    			root=root->right;
    		    			delete temp;
    		    		    cout<<"Contact is DELETED."<<endl;
    		    			return root;
    		    		}
    		}
    		    temp=min(root->right);
    	      	strcpy(root->name,temp->name);
    		    root->right=del(root->right,temp->name);
    		    return root;
    	}
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
	int c;
	bst b;
	b.root=NULL;
	do
	{

	cout<<"------------------WELCOME TO PHONE DIRECTORY-------------------- "<<endl<<endl;
	cout<<"The choices are :  "<<endl<<endl;
	cout<<"1. Create contact . "<<endl;
	cout<<"2. Display contacts. "<<endl;
	cout<<"3. Search contacts. "<<endl;
	cout<<"4. Delete contacts. "<<endl<<endl;
	cout<<"Enter your choice : "<<endl<<endl;
	cin>>ch;

	switch(ch)
	{
	case 1 :
		cout<<"Enter details of number: "<<endl;
		b.create();
		cout<<" Contact is successfully created "<<endl<<endl;
		break;
	case 2 :
		cout<<"The contact list is : "<<endl;
        b.display(b.root);
		break;
	case 3 :
		int flag;
		flag=0;
		char s[30];
		cout<<"Enter  phone name to be search : "<<endl;
		cin>>s;
		flag=b.search(b.root,s);
		if(flag==1)
		{
			cout<<" phone name is found in telephone dictionary."<<endl;


		}
		else
		{
			cout<<" phone name is not found in telephone dictionary."<<endl;
		}
		break;
	case 4 :
		char c[10];
		cout<<"Enter phone name is to be deleted : "<<endl;
		cin>>c;
		flag=b.search(b.root,c);
		if(flag==1)
		{
			cout<<" phone name is found in telephone dictionary."<<endl;
		    b.del(b.root,c);


		}
		else
		{
			cout<<" ooops......phone name is not found in telephone dictionary. so u can not use delete option."<<endl;
		}
	
		break;

	}
	cout<<"Do u want to continue"<<endl<<"Yes=1"<<endl<<"No=0"<<endl<<endl;
    cin>>c;
	}while(c==1);



	return 0;
}
