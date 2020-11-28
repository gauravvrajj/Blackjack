#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class user{
private:
    string name;
    int money;
public:
    void getdata()
	{
    cout<<"Enter your name :"<<endl;
    cin>>name;
    cout<<"Enter the amount of money you have"<<endl;
    cin>>money;
	}
    int checkwager(int x){
    if (x<=money)
        return 1;
    else
        return 0;}
    int updatewager(int a,int b)
	{
    if(a==0)
	{
        money=money-b;
        cout<< "Ohh you lost , it's alright tho,we will check your money to see if you can play"<<endl;
    }
	else
	{
    money=money+b;
    cout<< "CONGRATULATIONS YOU'VE WON!!!The wager has been added to your wager\nthe amount of money you have is: "<<money<<endl;
    }
	}
    int checkmoney()
	{
    if(money>0)
	{
        return 1;
    }
	else
	{
    return 0;
	}
	}
    void greeting(int x)
	{
    cout<<"Hello! "<<name<<" Welcome to our game!"<<" the amount of money you have is: "<< money<<endl;
    cout<<"The current wager is "<<x<<endl;
	}
    };
void showcard(int a)
{
    if(a==2)
	{
            cout<<"you've got a 2"<< endl;
	}
else if(a==3)
    {
    cout<<"you've got a 3"<< endl;
    }
else if(a==4)
    {
    cout<<"you've got a 4"<< endl;
    }
else if(a==5)
    {
    cout<<"you've got a 5"<< endl;
    }
else if(a==6)
    {
    cout<<"you've got a 6"<< endl;
    }
else if(a==7)
    {
    cout<<"you've got a 7"<< endl;
    }
else if(a==8)
    {
    cout<<"you've got an 8"<< endl;
    }
else if(a==9)
    {
    cout<<"you've got a 9"<< endl;
    }
else if(a==10)
    {
    cout<<"you've got a 10"<< endl;
    }
else if(a==11)
    {
    cout<<"you've got a jack"<< endl;
    }
else if(a==12)
    {
    cout<<"you've got a queen"<< endl;
    }
else if(a==13)
    {
    cout<<"you've got a jack"<< endl;
    }
    }
int check21(int x)
    {
if (x>21)
    {
    return 1;
	}
else 
{
    return 0;
}
}

int checkscore(int player,int dealer)
 {
    int z=check21(dealer);
    if(z==1)
	{
        return 1;
    }
	else if(z==0)
	{
            if (player>dealer)
			{
                return 1;
            }
			else if (dealer>player)
			{
                return 0;
            }
            else if(dealer==player)
			{
                return 2;
            }
			}
			}
int dealerrandcard()
   {
    int flag=0,a=rand()%13+1;
    if(a==13||a==11||a==12)
	{
        return 10;
    }
	else if(a==1)
	{
    return 11;
	}
    else
	{
        return a;
    }
	}
int randcard()
    {
    int flag=0,a=rand()%13+1;
    showcard(a);
    if(a==13||a==11||a==12)
	{
        a=10;
    }
	else if(a==1)
	{
    cout<<"You've got an ace what would you like to do?\n";
    cout<<"1-add 1 point\n";
    cout<<"2-add 11 points\n";
    cin>>flag;
	}
    if (flag==1)
	{
        return 1;
	}
        else if (flag==2)
		{
            return 11;
        }
		else return a;
	}
	
class end :public user
{

 public:
 	
 void gameend()   
 {
 cout<<"Thank you for playing!\n Made by:\nGaurav Raj-2K19/IT/052\nGaurav Kanojia- 2K19/IT/050";
 }
 
 
};
int main()
{   
    srand(time(NULL));
    user U1;
    end U2;
    U1.getdata();
    while(1)
	{
        int wager,userscore=0,dealerscore=0,start= 0;
        while(1)
		{
            cout<<"Enter appropiate wager:"<<endl;
            cin>>wager;
            int a=U1.checkwager(wager);
            if(a==1)
                break;
        }
        while(1)
		{
            system("cls");
            U1.greeting(wager);
            int no_of_cards=0;
            int cursor;
            int card;
            static int dealercard=dealerrandcard();
            if(start==0)
            
			{
            dealerscore=dealerscore+dealercard;
            card=dealerrandcard();
            dealerscore=dealerscore+card;
            card=randcard();
            userscore=userscore+card;
            no_of_cards++;
            card=randcard();
            userscore=userscore+card;
            no_of_cards++;
            start++;
            
			}

            cout<< "the dealer first card is "<< dealercard<<endl;
            cout<<"your score is: "<<userscore<<endl;
            cout<<"What would you like to do now?\n";
            cout<<"1-hit\n";
            cout<<"2-stick\n";
            cout<<"3-double\n";
            cout<<"4-fold\n";
            cin>> cursor;
            if(cursor==1)
			{
                card=randcard();
                userscore=userscore+card;
                no_of_cards++;
                int b=check21(userscore);
                if(b==1)
				{
                    cout<<"YOU GOT BUSTED YOU LOSE"<<endl;
                    U1.updatewager(0,wager);
                    break;
                }
				else
				{
                cout<< " Your updated score is: "<<userscore<<endl;
				}
				}
            else if(cursor==2||no_of_cards==5)
			{
            cout<<" The dealer score is: "<<dealerscore<<endl;
            int b=checkscore(userscore,dealerscore);
            if (b==0)
			{
                U1.updatewager(0,wager);
            }
            else if (b==1)
			{
                U1.updatewager(1,wager);
            }
            else if (b==2)
			{
                cout<<"It was a draw"<<endl;
            }
            break;
			}
            else if(cursor==3)
			{
                wager=wager*2;
                card=randcard();
                userscore=userscore+card;
                card=randcard();
                userscore=userscore+card;
                no_of_cards=no_of_cards+2;
                cout<<"your updated score is: "<<userscore<<endl;
                int b=check21(userscore);
                if(b==1)
				{
                    U1.updatewager(0,wager);
                    break;
                }

            }
			else if(cursor==4)
			{
                U1.updatewager(0,wager);
                break;

            }
			else
			{
                cout<<"enter appropriate value of cursor"<<endl;
            }
        }   int m;
            cout<<"Enter 0 if you want to quit, press any no to continue"<<endl;
            cin>>m;
            
            
            if(m==0)
			{   
			    U2.gameend();
                exit(0);
			}
            else
			m=U1.checkmoney();
            }
        
    return 0;
}
