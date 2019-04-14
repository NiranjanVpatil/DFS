//============================================================================
// Name        : assignment1.cpp
// Author      : Niranjan patil
// Design and implement a program that will help a salesperson to keep track of customer records.
//============================================================================

#include <iostream>
using namespace std;
class customer
{
public:
	                            //data members
	char name[20];
	long int Customer_id;
	char address[20];
	long int mobile_no;

	void getdata()                //member function
	{
		cout<<"Enter Customer name: "<<endl;
		cin>>name;
		cout<<"Enter Customer ID: "<<endl;
		cin>>Customer_id;
		cout<<"Enter Customer address:"<<endl;
		cin>>address;
		cout<<"Enter mobile Number: "<<endl;
		cin>>mobile_no;
	}

	void display()             // member function
	{
		cout<<"customer ID is :"<<Customer_id<<endl;
		cout<<"Customer name is : "<<name<<endl;
		cout<<"customer address is "<<address<<endl;
		cout<<"customer mobile Number: "<<mobile_no<<endl<<endl<<endl;
	}
};

int main()
{
    customer record[25];          //record is array of type customer with 5 elements
    int i;
    int j;
    int count;
    count=0;
    int choice;
    do
    {
    cout<<"----------------------WELCOME TO CUSTOMER RECORDS------------------"<<endl<<endl;
    cout<<"\n The choices are : "<<endl;
    cout<<"1. Accept customer details "<<endl;
    cout<<"2. Display customer details "<<endl;
    cout<<"3. Search particular customer "<<endl;
    cout<<"4. Update details of customer "<<endl;
    cout<<"5. Exit."<<endl<<endl;
    cout<<" Enter your choice: "<<endl;
    cin>>choice;

    switch(choice)
    {
       case 1:
          do
          {
          	record[count].getdata();
    	   count++;
    	   cout<<"Do you want to add more customer? "<<endl;
    	   cout<<"Yes=1"<<endl;
    	   cout<<"No=any number."<<endl;
    	   cin>>choice;
    	   

		  }while(choice==1);
		  break;
    	   

       case 2:
            for(j=0;j<count;j++)
            {
               	cout<<"The details of customers "<<j+1<<" :"<<endl<<endl;
                record[j].display();
            }
            break;
       case 3:
    	   int sid;
    	   int loc;
    	   int flag;
    	   flag= 0;
    	   cout<<"Enter the customer ID of that customer is to search: "<<endl;
    	   cin>>sid;
    	   for(i=0;i<count;i++)
    	   {
    	    if(sid==record[i].Customer_id )
    	     {
                 flag=1;
                 loc=i;

    	     }

    	   }
    	   if(flag==1)
    	   {
    		   cout<<"Customer ID is found:"<<endl;
    		   record[loc].display();
    		   break;
    	   }
    	   else
    	   {
    		   cout<<"Customer ID is not found:"<<endl<<endl;
    	   }
    	   break;
      case 4:
    	   int usid;
    	   int uchoice;
    	   do
    	   {
		   
    	   cout<<"Enter the customer ID of you want  to update the details : "<<endl;
    	   cin>>usid;
    	   for(i=0;i<count;i++)
    	       	   {
    	       	    if(usid==record[i].Customer_id )
    	       	     {
    	       		   cout<<"Customer ID is found:";
    	       		   cout<<"The details of customer id "<<usid<<"is  "<<endl;
    	       		   record[i].display();
    	       		   break;
    	       	     }
    	       	   }


    	   do
    	   {
    	   cout<<"\n THe choices about Which details is to be updated "<<endl;
    	   cout<<"1. Customer Name. "<<endl;
    	   cout<<"2. Customer ID. "<<endl;
    	   cout<<"3. Customer address."<<endl;
    	   cout<<"4. Customer mobile number."<<endl;
    	   cout<<"5. Exit. "<<endl<<endl;
    	   cout<<"Enter your choices about updated details :"<<endl;
    	   cin>>uchoice;
    	   switch(uchoice)
    	   {
    	   case 1:
		         cout<<"Enter customer name "<<endl;
		         cin>>record[i].name;

		         break;
    	   case 2:
    		   cout<< "Enter customer ID "<<endl;
    		   cin>>record[i].Customer_id;
    		   break;
    	   case 3:
    		   cout<<"Enter customer address "<<endl;
    		   cin>>record[i].address;
    		   break;
    	   case 4:
    		   cout<<"Enter customer mobile number "<<endl;
    		   cin>>record[i].mobile_no;
    		   break;
    	   default:
    	      cout<<" Your choice are invalid"<<endl;
    	      break;
    		
    	   }
    	   }while(uchoice<5);
    	   cout<<"The updated details is : "<<endl;
    	   record[i].display();
    	   cout<<"Do You want to update details of more customers ?"<<endl;
    	   cout<<"Yes=4"<<endl;
    	   cout<<"No= any number."<<endl;
    	   cin>>choice;
         }while(choice==4);
    	break;
      case 5:
    	   cout<<"You are exit from system."<<endl;
    	   break;
      default:
    	      cout<<" Your choice are invalid"<<endl;
    	      break;
    }
    }while(choice<6);
	return 0;
}
