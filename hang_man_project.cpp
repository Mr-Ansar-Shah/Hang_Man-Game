#include<iostream>
using namespace std;
string message = "WALLAH!! You Can't Win";
void hang_man ();
int size_of_word (char word[]);
int hidden_word (char hid_word[] , int size);
int check_guess (char hid_word[] , int attempts , int size , char guess , char word[] , char hint[]);
int main()
{
	hang_man();
	char hint [200];
	cout<<"\tEnter The Hint You Want To Display :- ";
	cin.get(hint,200);
	char input_word[50];
	cout<<"\tEnter The Word :- ";
	cin>>input_word;
	// store size of word in variable
	int word_length = size_of_word(input_word);
	// store how many attempts a user have to guess the word
	int attempts = word_length ;
	char hidd_word [word_length];
	// call a function to initlize the hidden word
	hidden_word (hidd_word , word_length);
	// syntax for clear screen
	system("cls");
	char guess ;
	check_guess (hidd_word , attempts , word_length , guess , input_word , hint);
	return 0;
}
// function to calculate the size of Word
int size_of_word (char word[])
{
	int count = 0;
	for (int i = 0 ; i < 50; i++)
	{
		if (word[i] == '\0')
		{
			break;
		}
		count++;
	}
	return count;
}
// function to intilize the hidden word
int hidden_word (char hid_word[] , int size)
{
	for ( int i = 0 ; i < size ; i++)
	{
		hid_word[i] = 'X';
	}
	return 0;
}
// function to check guess 
int check_guess (char hid_word[] , int attempts , int size , char guess, char word [] , char hint[])
{
	int found_word  = 0  ;
	bool flag = true ;
	char demo[size];
	demo[0] = ':'+201;
	char check_tray[size];
	for (int i = 1 ; i < size ; i++)
	{
		demo[i] = demo[i-1]; 
	}
    while (true)
    {
    	for ( int i = 0 ; i < attempts ; i++)
    	{
    		sec_done :
    		int  _try = 0 ;
    		hang_man();
    		cout<<"\tHint:-\t\n";
	        cout<<"\t\t"<<hint<<endl;
    		cout<<"\t";
    	    for( int j = 0 ; j < size  ; j++ )
    	    {  
    		cout<<hid_word[j];
		    }
		    cout<<endl;
    		cout<<"\tTotal Attempts You Have :-  "<<attempts<<endl;
    		cout<<"\tEnter The Guess :-  ";
    		cin>>guess;
    		for (int k = 0 ; k < size ; k++ )
		    {
			if (guess == word[k])
			{
				hid_word[k] = word[k];
				check_tray[k] = word[k];
				word[k] = demo[k];
				found_word++;
				flag = true ;
				goto done;
			}
		    }
		    for (int k = 0 ; k < size ; k++ )
		    {
			 if ( check_tray[k] == guess && demo[k] == word[k])
			{
				message = "You Already Guess This Word";
				system("cls");
				goto sec_done;
			}
			else 
			{
				_try++;
				flag = false;
				if ( _try == size)
				{
					attempts--;
				}
			}
		    }
		    done :
		system("cls");
		
		if(!flag)
		  {
		  	
		   if (attempts == 0)
		   {
			message = "IN SHA ALLAH!!  Try Again Next Time";
			hang_man();
			return 0;
		  } 
			message = "ASTAGFIRULLAH!! Try Again";
		  }
		else
		  {
			if (found_word == size )
		    {
			message  ="MA SHA ALLAH! YOU Won The Game ";
			hang_man();
			
			return 0;
		    }
			 message = "WALLAH! Nice Guess";
		   }
		}
		
	}
}
//hang man function to display hang man 
void hang_man ()
{
	cout<<"\t\t\t\t______________"<<endl;
	cout<<"\t\t\t\t      |       |"<<endl;
	cout<<"\t\t\t\t      O       |"<<endl;
	cout<<"\t\t\t\t     / \\      |"<<endl;
	cout<<"\t\t\t\t      |       |"<<"\t            "<< message <<endl;
	cout<<"\t\t\t\t      |       |"<<"\t           /"<<endl;
	cout<<"\t\t\t\t     / \\      |           O"<<endl;
	cout<<"\t\t\t\t   ========   |          / \\"<<endl;
	cout<<"\t\t\t\t  |        |  |           |"<<endl;
	cout<<"\t\t\t\t  |        |  |          / \\"<<endl;
	cout<<"\t\t\t\t================================="<<endl;	
}
