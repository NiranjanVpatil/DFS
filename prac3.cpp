//===========================================================================================================
// Name        : snakeladder.cpp
// Author      : Niranjan Patil
// Description : Design and develop a game of snake and ladder using appropriate data structure.
//==============================================================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class node
{
public:
    int data;
    node*next;
    node*prev;
};
class game
{
    node*start;

public:
    game()
{
    	start=NULL;
                                          }              // constructor is used to initialized data
    void create(int value)
    {
        node*temp,*s;
        temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(start==NULL)
        {
         temp->prev=NULL;
         start=temp;
        }
        else
        {
            s=start;
            while(s->next!=NULL)
                s=s->next;
            temp->prev=s;
            s->next=temp;
        }
    }
    void display()
    {
    node*m;
    m=start;
    if(m==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
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

    }
    int roll()             //roll function is used for generating random value
    {
        int r;
        srand(time(NULL));
        r=rand()%6+1;
        return r;
    }
    node*forward_shift(int value,node*v)
    {
        int i;
        for(i=1;i<=value;i++)
            v=v->next;
        return v;
    }
    int change_score(int score)
    {
            int fscore;
            switch(score)
            {
            case 27:fscore = 1;
            	        break;
            	case 21: fscore = 9;
            	         break;
            	case 17:fscore = 4;
            		     break;
            	case 19: fscore = 7;
            	         break;
            	case 3: fscore= 22;
            	        break;
            	case 5: fscore =8;
            	        break;
            	case 11: fscore=26;
            	         break;
            	case 20: fscore=29;
            	         break;
            	default: fscore=score;
            }
            return fscore;
    }

    int play()
    {
        int score1=1,score2=1,c,new_s,dice;
        char player1[7],player2[7];
        node*p1=start;
        node*p2=start;
        dice=roll();
        cout<<"Enter player 1 name :"<<endl;
        cin>>player1;
        cout<<"Enter player 2 name : "<<endl;
        cin>>player2;
        while(p1->data<=30 && p2->data<=30)
        {
        cout<<player1<<"  ITS YOUR TURN NOW!!!!!    PRESS 1 TO CONTINUE. "<<endl;
        cin>>c;
        if(c==1)
        {
            dice=roll();
            cout<<"you got "<<dice<<" on dice"<<endl;

            if(score1+dice<100)
            {

             p1=forward_shift(dice,p1);
             score1=p1->data;
             cout<<"Current score : "<<score1<<endl;
            }
            new_s=change_score(p1->data);
            cout<<"Current score is ="<<new_s<<endl;
            if(new_s!=score1)
            {
                if(new_s>score1)
                {
                    cout<<"you found a ladder....."<<endl;
                    while(p1->data!=new_s)
                    {
                        p1=p1->next;
                    }
                }
                else if(new_s<score1)
                {
                    cout<<"you found a snake..."<<endl;
                    while(p1->data!=new_s)
                    {
                        p1=p1->prev;
                    }
                }
            }
        }
        cout<<"Player 2:"<<player2<<"....its your turn, press 1..."<<endl;
        cin>>c;
        if(c==1)
        {
            dice=roll();
            cout<<"You got = "<<dice<<" on dice"<<endl;
            if(score2+dice<100)
            {
                p2=forward_shift(dice,p2);
                score2=p2->data;
                cout<<"your score is ="<<score2<<endl;
            }
            new_s=change_score(p2->data);
            cout<<"your present score is ="<<new_s<<endl;
            if(new_s!=score2)
            {
                if(new_s>score2)
                {
                    cout<<"Yipeee ladder....."<<endl;
                    while(p2->data!=new_s)
                    {
                        p2=p2->next;
                    }
                }
                else if(new_s<score2)
                {
                    cout<<" OOPS snake...."<<endl;
                    while(p2->data!=new_s)
                    {
                        p2=p2->prev;
                    }
                }
            }
         }
        if(p1->data>=30)
            {
             cout<<"---------------------------"<<endl;
             cout<<"Player 1 wins the Game.....hurreyyyy"<<endl;
             cout<<"--------------------------------"<<endl;
             break;
            }
        else if(p2->data>=30)
            {
              cout<<"---------------------------------"<<endl;
              cout<<"player 2 wins the Game.....hureeeyyy"<<endl;
              cout<<"---------------------------------"<<endl;
              break;
            }

        }

        return 0;
    }
};

int main()
{
    int choice,i;
    game l;
    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice:"<<endl;
        cout<<"1.To Begin"<<endl;
        cout<<"2.To Display"<<endl;
        cout<<"3. To play the game"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            for(i=1;i<=30;i++)
                l.create(i);
            cout<<"Game Begins..."<<endl;
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.play();
            break;
        default:
            cout<<"Sorry number does not exist in choice"<<endl;
            break;
        }
    }

        return 0;
}
