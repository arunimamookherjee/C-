//PUSHING IN LINKED STACK

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
class hospital //CLASS DEFINITION
{

char name[20];
int patient_id;
float TOT_BILL;


public:

	hospital * next;

	void input() //FUNCTION  TO GET INPUT
	{
	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL BILL : ";cin>>TOT_BILL;

	}

	void display() //FUNCTION TO DISPLAY
	{
	cout<<"\nNAME : "<<name;
	cout<<"\nPATIENT ID : "<<patient_id;
	cout<<"\nTOTAL BILL : "<<TOT_BILL;



	}

}; //CLASS DEFINITION OVER

hospital *top, *ptr, *newptr;


hospital * create()//TO CREATE A NODE DYNAMICALLY
{
	ptr=new hospital;

	cout<<"Enter Record "<<endl;
	ptr->input();//GET INPUT

	ptr->next=NULL;

	return ptr;

}


void displaylist(hospital *np)//TO DISPLAY STACK
{
       while(np!=NULL)

       {
	  np->display();//DISPLAY RECORD
	  cout<<'\n';
	  np=np->next;
       }

       cout<<'\n';
}


void push (hospital*np)//TO PUSH A NEW NODE IN STACK
{
	if(top==NULL)
	{
		top=np;
	}
	else
	{
		np->next=top;
		top=np;
	}
}



void main()
 {
	clrscr();

	char ch='y';

	top=NULL;//INITIALLY STACK IS EMPTY

	while(ch=='y'|| ch=='Y')

	{

		newptr=create();//CREATE NEW NODE

		if(newptr== NULL)
		{
			cout<<"Cannot create ";
			getch();
			exit(1);
		}

		push(newptr);//PUSH NEW NODE IN STACK

		cout<<endl<<"CURRENT STACK "<<endl;
		displaylist(top);//DISPLAY STACK

		cout<<endl<<" DO YOU WANT TO PUSH MORE NODES ";
		cin>>ch;
	}


	 getch();
 }


