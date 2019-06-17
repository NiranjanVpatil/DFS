#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define pi 3.14
class node
{
public:
	char city_name[23];
	float lang;
	float latt;
	int distance_ofcity;
	node*left=NULL;
	node*right=NULL;
};
class BST
{
public:
	node*root;
	BST()
	{
		root=NULL;

	}
	void create();
	void insert(node*root,node* temp);
	void search(node*,char s[20]);
	void display(node*);
	void distance(node*temp,node*root, double x);
};
void BST::create()
{
	node* temp;
	temp=new node;
	cout<<"enter city name ::"<<endl;
	cin>>temp->city_name;
	cout<<"enter longitudinal value ::"<<endl;
	cin>>temp->lang;
	cout<<" enter latitude value ::  " <<endl;
	cin>>temp->latt;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		insert(root,temp);
	}
}
void BST::insert(node*root,node*temp)
{

	if(temp->lang<root->lang)
	{
		if(root->left==NULL)
		{
			root->left=temp;

		}
		else
		{
			insert(root->left,temp);
		}
    }
	else
	{
		if(root->right==NULL)
		{
			root->right=temp;
		}
		else
		{
			insert(root->right,temp);
		}
	}
}
void BST:: display(node*root)
{
    if(root!=NULL)                                                     // inorder
	{
		display(root->left);
		cout<<"city name ::  "<<root->city_name<<endl;
		cout<<" longitudinal value ::  "<<root-> lang<<endl;
		cout<<" latitude value ::  "<<root-> latt<<endl;
		display(root->right);


	}
}
void BST:: search(node*temp,char s[20])
{
	int count=0;
    while(root!=NULL)
    {

    if(strcmp(s,root->city_name)==0)
    {
       cout<<" yessss...found...."<<endl;
       cout<<"city name :"<<root->city_name<<endl<<"longitudinal value:"<<endl<<root->lang<<endl<<"latitude value"<<root->latt;
       break;
       count++;
    }
    else
    {
	  if (strcmp(s,root->city_name)<0)
	  {
		 root=root->left;
	  }
	  if (strcmp(s,root->city_name)>0)
	  {
		root=root->right;
	  }
    }

    }
 if (root==NULL)
 {
	 cout<<" your city is not found"<<endl;
 }

double x;
cout<<"enter range you want to find"<<endl;
cin>>x;

distance(temp,root,x);

}
void BST::distance(node*temp,node*root,double x)
{
 if (root!=NULL)
 {
	 distance(temp,root->left,x);
	 double dist;
	 dist=sin(temp->latt)*sin(root->latt)+cos(temp->latt)*cos(root->latt)*cos(temp->lang-root->lang);
	 dist=acos(dist);
	 dist=(637)*pi*dist/180;
     if(dist<=x)
     {
    	 if(strcmp(root->city_name,temp->city_name)==0)
    	 {
    		 if(dist!=0)
    		 {
    		   cout<<"CITY="<<root->city_name<<endl<<"TOTAL distance of "<<temp->city_name<<"="<<dist<<endl;
    		 }
    		 else
    		 {

    			     	 cout<<"not found"<<endl;

    	     }
    	 }
     }


     distance(temp,root->right,x);
}
}

int main()
{
	BST b;
	int choice;
	char search_name[25];
	b.root=NULL;
	cout<<".....==Welcome to city travel system==....."<<endl;
	do
	{
	  cout<<"1=insert city , 2=display city , 3= search "<<endl;
	  cout<<"enter your choice ::"<<endl;
	  cin>>choice;
	  switch(choice)
	  {
	 	case 1:
	 	  b.create();
	 	  break;
	 	case 2:
	 	  b.display(b.root);
	 	  break;
	 	case 3:
	 	 cout<<"enter name you want to search "<<endl;
	 	  cin>>search_name;
	 	  b.search(b.root,search_name);
	 	  break;
	 	case 4 :
	 	  cout<<"exit from system"<<endl;
	 	  break;
	   }
	 }while(choice!=4);
	return 0;
}
