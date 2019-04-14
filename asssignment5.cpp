//==================================================================================================
// Name        : asssignment5.cpp
// Author      : Niranjan Patil
// Description : Design and develop a program for implementing a city database
//               using suitable data structure to store the database records.             
//               Each database record contains the name of the city and the
//               coordinates of the city expressed as integer x- and y-coordinates.
//               Your database should allow records to be inserted, deleted by
//               name or coordinate, and searched by name or coordinate.
//               Another operation that should be supported is to print all
//               records within a given distance of a specified point.
//====================================================================================================

#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
class node
{
	public:
	      char city_name[40];
          double lat;
          double lon;
          node *left;
          node *right;
};
class BST
{
	public:
	      node *root;
	      BST()
	      {
		       root=NULL;
          }
	      void create();
	      void insert(node *,node *);
	      void display(node *);
	      void search(node *,char s2[]);
	      void distance(node *,node *,double);

};
void BST::create()
{
	int ch;
	do
	{
	node *temp;
	temp=new node;
	cout<<"Enter City Name : "<<endl;
	cin>>temp->city_name;
	cout<<"Enter Latitude :"<<endl;
	cin>>temp->lat;
	cout<<"Enter Longitude"<<endl;
	cin>>temp->lon;
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
	cout<<"Do you want to add more nodes"<<endl;
	cin>>ch;
	}while(ch==1);
}

void BST::insert(node *root,node *temp)
{
	if((root->lat)<(temp->lat))
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
    if((root->lat)>(temp->lat))
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
    if(root->lat==temp->lat)
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
void BST::display(node *root)
{
	node*temp=root;
	  if(temp!=NULL)
	  {
		  display(temp->left);
          cout<<"City Name : "<<temp->city_name<<endl;
          cout<<"Latitude : "<<temp->lat<<endl;
		  cout<<"Longitude : "<<temp->lon<<endl<<endl;
		  display(temp->right);
	  }
}

void BST::search(node *temp,char s2[20])
{
	int count=0;
	while(root !=NULL)
	{
		if(strcmp(s2,root->city_name)==0)
			{
			cout<<root->city_name<<" City Found."<<endl;
			break;
			count++;
			}
	else
	{
		if(strcmp(root->city_name,s2)<0)
		{
			root=root->left;
		}
		if(strcmp(root->city_name,s2)>0)
				{
					root=root->right;
				}
	}
	}
	if(root==NULL)
	{
		cout<<"Your city name is not found"<<endl;
	}
	double x;
			cout<<"Enter range within you want to find other city : "<<endl;
			cin>>x;
			distance(temp,root,x);
}
void BST::distance(node *root,node *temp,double x)
{
   if(root!=NULL)
   {
	   distance(temp,root->left,x);
	   double dist;
	   dist=sin(temp->lat)*sin(root->lat)+cos(temp->lat)*cos(root->lat)*cos(temp->lon - root->lon);
	   dist=acos(dist);
	   dist=((6371*3.14*dist)/180);
	   if(dist<=x)
	   {
		   if(strcmp(root->city_name,temp->city_name)==0)
		   {
			   if(dist!=0)
				   {cout<<"City : "<<root->city_name<<"Total Distance : "<<temp->city_name<<" : "<<dist<<endl;}
		   }
		   else
		   	   {
		   		   cout<<"Not found. "<<endl;
		   	   		   	   }
	   }

	   }
   distance(temp,root->right,x);

}
int main()
{

	int ch;
	BST b;
	b.root=NULL;
	do
	{
	cout<<"The choices are: "<<endl;
	cout<<"1. create city names. "<<endl;
	cout<<"2. Display city names. "<<endl;
	cout<<"3. Search city name. "<<endl;
	cout<<"Enter your choices : "<<endl<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"Enter city: "<<endl;
		b.create();
		cout<<"City Name is Stored. "<<endl<<endl;
		break;
	case 2:
		cout<<"The City list is : "<<endl;
		b.display(b.root);
		break;
	case 3:
		char s2[20];
		cout<<"Enter City Name you want to be search : "<<endl;
		cin>>s2;
		b.search(b.root,s2);
		break;
	}
	}while(ch<4);
	return 0;
}
