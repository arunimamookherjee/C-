//POPPING FROM LINKED STACK

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

struct hospital
{
char name[20];
int patient_id;
float TOT_BILL;
hospital *next;
}*top,*newptr,*save,*ptr;

void input(hospital *hosp)//TO GET INPUT
{
		cout<<"Enter patient id "<<endl;
		cin>>hosp->patient_id;

		cout<<"Enter name"<<endl;
		gets(hosp->name);

		cout<<"Enter the Total Bill "<<endl;
		cin>>hosp->TOT_BILL;

}
void display(hospital *hosp)//TO DISPLAY RECORD
{
		cout<<"NAME OF PATIENT : "<<hosp->name<<endl;
		cout<<"PATIENT ID"<<hosp->patient_id<<endl;
		cout<<"TOTAL BILL "<<hosp->TOT_BILL<<endl;
}





hospital * create()//TO CREATE NODE
{
		ptr=new hospital;

		cout<<"Enter Record "<<endl;
		input(ptr);

		ptr->next=NULL;

		return ptr;
}

void displaylist(hospital *np)//FUNCTION TO DISPLAY STACK
{
       while(np!=NULL)

       {
		display(np);//DISPLAY RECORD
		cout<<'\n';
		np=np->next;
       }

       cout<<'\n';
}


void push (hospital *np) //FUNCTION TO PUSH NEW NODE IN STACK
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

void pop () //FUNCTION TO POP FROM STACK
{
	 if (top==NULL)
	 {
		cout<<" UNDERFLOW " ;
		getch();
		exit(1);
	 }
	 else
	 {
		save=top;
		top=top->next;
		delete save;
	 }
}



void main()
 {
	clrscr();

	char ch='y';

	top=NULL;//STACK IS EMPTY INITIALLY

	while(ch=='y'|| ch=='Y')

	{

		newptr=create();//CREATE NEW NODE

		if(newptr== NULL)
		{
			cout<<"Cannot create ";
			getch();
			exit(1);
		}

		push(newptr);//PUSH NEW NODE INTO STACK

		cout<<endl<<"CURRENT STACK "<<endl;
		displaylist(top);//DISPLAY STACK

		cout<<endl<<" DO YOU WANT TO INSERT MORE ";
		cin>>ch;
	}

	do
	{

		cout<<endl<<" DO YOU WANT TO DELETE ? ";
		cin>>ch;

		if(ch=='y'||ch=='Y')
			pop();//POP

		cout<<"CURRENT STACK "<<endl;
		displaylist(top);//DISPLAY STACK

	 }
	 while(ch=='y'|| ch=='Y');



	 getch();
 }


