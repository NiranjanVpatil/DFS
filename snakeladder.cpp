//===========================================================================================================
// Name        : snakeladder.cpp
// Author      : Niranjan Patil
// Description : Design and develop a game of snake and ladder using appropriate data structure.
//==============================================================================================================

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void showboard();
int roll();
int changescore(int);
class node
{
	public:
	        int data;
	        node *next;
	        node *prev;

};
class game
{
	node *head;
    public:
		void generate(int);
		void play();
		node *movef(int,node *);
		void playerinfo();
		game()
		{
			head=NULL;
		}

};

void game::generate(int value)
{
    node *temp;
    node *s;
    temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
     {
     	temp->prev=NULL;
        head=temp;
     }
     else
     {
     	s=head;
     	while(s->next!=NULL);
     	{
     		s=s->next;
     	}
         s->next=temp;
         temp->prev=s;
     }


}
void showboard()
     {
         	 cout<<"30 |29 |28 |27 |26 "<<endl<<"21 |22 |23 |24 |25 "<<endl<<"20 |19 |18 |17 |16 "<<endl<<"11 |12 |13 |14 |15 "<<endl<<"10 |09 |08 |07 |06  "<<endl<<"01 |02 |03 |04 |05 "<<endl;
         	 cout<<"\n\t SNAKE WILL LOWER YOUR SCORE. "<<endl;
         	 cout<<" From 27 to 1. "<<endl;
         	 cout<<" From 21 to 9. "<<endl;
         	 cout<<" From 17 to 4. "<<endl;
         	 cout<<" From 19 to 7. "<<endl;
         	 cout<<"\n\t LADDER WILL HIGHER YOUR SCORE. "<<endl;
         	 cout<<" From 3 to 22. "<<endl;
         	 cout<<" From 5 to 8. "<<endl;
         	 cout<<" From 11 to 26. "<<endl;
         	 cout<<" From 20 to 29. "<<endl;

      }
int roll()
     {
    	 int d;
    	 d=rand()%6+1;
    	 return d;
     }
int changescore(int score)
{
	int new_score;
	int s=score;
	switch(s)
	{
	case 27:new_score = 1;
	        break;
	case 21: new_score = 9;
	         break;
	case 17:new_score = 4;
		     break;
	case 19: new_score = 7;
	         break;
	case 3: new_score= 22;
	        break;
	case 5: new_score =8;
	        break;
	case 11: new_score=26;
	         break;
	case 20: new_score=29;
	         break;
	default: new_score=score;

	}

    return(new_score);
}

node * game::movef(int d1,node *p)
{
	for(int i=1;i<=d1; i++)
	{
		p=p->next;
	}
	return p;
}


void game::play()
{
	int score1=1,score2=2,k,dice,new_score;
	node *p1=head;
	node *p2=head;
	char name1[20];
	char name2[20];
	showboard();
	while (p1->data !=30 && p2->data !=30)
	{
		cout<<name1<<"ITS YOUR TURN NOW!!!!! PRESS 1 TO CONTINUE. "<<endl;
		cin>>k;
		if(k==1)
		{
			dice= roll();
			cout<<endl<<"HEY...YOU ROLLED "<<dice<<endl;
			if(dice+score1<=30)
			{
				p1= movef(dice,p1);
				score1 = p1->data;
				cout<<name1<<"!! YOUR SCOR IS "<<endl;
				if(p1->data ==30)
				{
					cout<<"OMG!!!! "<<name1<<"YOU ARE THE WINNEER"<<endl;
				}
				new_score=changescore(p1->data);
				cout<<endl<<new_score;
                if(new_score !=score1)
                {
                	if(new_score < score1)
                	{
                		cout<<"OOOOPS!!! SNAKE JUST ATE AND DROPED YOU DOWN!!!"<<endl;
                		while(p1->data !=new_score)
                		{
                			p1=p1->prev;
                		}
                	}
                	if(new_score >score1)
                			{
                				cout<<"GOOD NEWS.....YOU GOT A LADDER AND"<<endl;
                				while(p1->data !=new_score)
                				      {
                				        p1=p1->next;
                				       }
                			}

               	}
           }
    }
			cout<<name2<<"ITS YOUR TURN NOW!!!!! PRESS 1 TO CONTINUE. "<<endl;
		    cin>>k;
			if(k==1)
			{
				dice= roll();
				cout<<endl<<"HEY...YOU ROLLED "<<dice<<endl;
				if(dice+score2<=30)
				{
					p2= movef(dice,p2);
					score1 = p2->data;
					cout<<name2<<"!! YOUR SCOR IS "<<endl;
					if(p2->data ==30)
					{
						cout<<"OMG!!!! "<<name2<<"YOU ARE THE WINNEER"<<endl;
					}
					new_score=changescore(p2->data);
					cout<<endl<<new_score;
	                if(new_score !=score2)
	                {
	                	if(new_score < score2)
	                	{
	                		cout<<"OOOOPS!!! SNAKE JUST ATE AND DROPED YOU DOWN!!!"<<endl;
	                		while(p2->data !=new_score)
	                		{
	                			p2=p2->prev;
	                		}
	                	}
	                	if(new_score >score2)
	                			{
	                				cout<<"GOOD NEWS.....YOU GOT A LADDER AND"<<endl;
	                				while(p2->data !=new_score)
	                				      {
	                				        p2=p2->next;
	                				       }
	                			}

	               	}
	           }
	       }

}
}

int main()
		{

			int choice;
			game g;
			do
			{
			cout<<" !!!!!!!!!!! WELCOME TO SNAKE LADDER GAME !!!!!!!!!! "<<endl;
			cout<<" 1. Generate the board. "<<endl;
			cout<<" 2. Display Showboard. "<<endl;
			cout<<" 3. Play Game. "<<endl;
			cout<<" Enter your choice : "<<endl;
			cin>> choice;
			switch(choice)
			{
				case 1 :
					for(int i=1;i<30;i++)
					{
						g.generate(i);
					}
					break;
				case 2 :
					showboard();
					break;
				case 3 :
					g.playerinfo();
					g.play();
					break;

			}
			}while(choice<4);

			return 0;
		}



