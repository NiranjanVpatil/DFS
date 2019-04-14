//=========================================================================================================================================
// Name        : assignment2.cpp
// Author      : Niranjan patil
// problem statement : Design and develop a program for an institution having three departments Computer Engineering,
//                     Electronics and mechanical. The institute considers SSC, HSC and entry test marks for
//                     registering a student and calculate an aggregate based on a specific criteria.
//                     The program should find in which dept. a student should be registered, store its record 
//                     and provide facility for adding other departments in the institute and changing admission 
//                     criteria and provide a facility for retrieving a record of particular student.
//==============================================================================================================================================

#include <iostream>
using namespace std;
class node
{
public:
	int stud_id;
	float ssc_marks;
	float hsc_marks;
	float cet_marks;
	node *next;
	void getdata()
	{
		cout<<"Enter student id ="<<endl;
		cin>>stud_id;
		cout<<"Enter student SSC marks = "<<endl;
		cin>>ssc_marks;
		cout<<"Enter student HSC marks = "<<endl;
		cin>>hsc_marks;
		cout<<" Enter student CET marks = "<<endl;
		cin>>cet_marks;

	}
	float avg_marks()
	{
		return((ssc_marks+hsc_marks+cet_marks)/3 );
	}


};
class SLL
{
	node *head;
public:
	SLL()                                                       // constructor
    {
	 head=NULL;
    };
	void insert_node(node s);
	void display();
	void display_search(int id);
	int search(int id);

};

void SLL::insert_node(node s)
{
	node *temp, *p;                                            // initializing pointer temp is new node
	temp =new node;                                            // creating new node
	temp->stud_id=s.stud_id;                                   // keeping new node information in pointer address
	temp->ssc_marks=s.ssc_marks;
	temp->hsc_marks=s.hsc_marks;
	temp->cet_marks=s.cet_marks;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;                                             // if empty list
	}
	else
	{
		p=head;
		while(p->next!=NULL)                                  // traversing
		{
			p=p->next;
		}
		p->next=temp;

	}
};
void SLL::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<" stud_id :"; cout<<p->stud_id<<endl;
									cout<<" SSC marks"; cout<<p->ssc_marks<<endl;
									cout<<" HSC marks"; cout<<p->hsc_marks<<endl;
									cout<<" CET marks"; cout<<p->cet_marks<<endl;
									p=p->next;
	}
}
void SLL::display_search(int id)
	{
		node *p;
			for(p=head;p!=NULL;p=p->next)
			{
				if(p->stud_id==id)
				{
					cout<<endl;
					cout<<"stud_id :"; cout<<p->stud_id<<endl;
							cout<<" SSC marks"; cout<<p->ssc_marks<<endl;
							cout<<" HSC marks"; cout<<p->hsc_marks<<endl;
							cout<<" CET marks"; cout<<p->cet_marks<<endl<<endl;
							cout<<endl;
							p=p->next;
		          break;
				}


	}
};
int SLL::search(int id)

{
	int flag=0;
	node *p;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->stud_id==id)
		{
		  flag=1;
          break;
		}

	}
	return flag;
};
int main()
{
	node s1;
	int ch;
	float avg;
	int choice;
	SLL comp,mech,etx,no_reg;
	cout<<"------------------WELCOMe TO THE MITAOE ADMISSION SYSTEM------------------"<<endl<<endl;

	do
	{
		cout<<" The choices are : "<<endl;
		cout<<" 1.Student Registration. "<<endl;
		cout<<" 2.Display Student list according to department. "<<endl;
		cout<<" 3.Search student in which department"<<endl<<endl;
		cout<<"Enter your choice. "<<endl;
		cin>>ch;

		switch (ch)
		{
		case 1:
			s1.getdata();

			avg=s1.avg_marks();
			if(avg>=90 && avg<100)
				comp.insert_node(s1);
			else
			{
				if(avg>=80&&avg<90)
					mech.insert_node(s1);
					else
					{
						if(avg>=70&&avg<80)
						etx.insert_node(s1);
						else{
							no_reg.insert_node(s1);
							}
					}
			}
				break;
		case 2:
			cout<<"List of computer students registered : "<<endl;
			comp.display();
			cout<<endl;
			cout<<"List of mechanical students registered : "<<endl;
			mech.display();
			cout<<endl;
			cout<<"List of electronics students registered : "<<endl;
			etx.display();
			cout<<endl;
            cout<<"List of students who is not registered in any department: "<<endl;
			no_reg.display();
			cout<<endl;
			break;
		case 3:
			int id;
			                	int f;
			                	f=0;
			                	cout<<"Enter student id"<<endl;
			                	cin>>id;
			                	f=comp.search(id);
			                	if(f==1)
			                	{
			                		cout<<"Student found in computer department"<<endl;
			                		comp.display_search(id);
			                	}
			                	else
			                	{
			                		f=mech.search(id);
			                		if(f==1){

			                			cout<<"Student found in mechanical department"<<endl;
			                			mech.display_search(id);
			                		}
			                		else
			                		{
			                			f=etx.search(id);
			                			if(f==1)
			                			{

			                			  cout<<"Student found in electronics department"<<endl;
			                			  etx.display_search(id);
			                		    }
			                			else
			                				cout<<"Not found in any of the department"<<endl;
			                		}
			                	}


			                 break;
		}
		cout<<"do u want to continue"<<endl<<"Yes=1"<<endl<<"No=0"<<endl;
		cin>>choice;
	}while(choice==1);

	return 0;
}




