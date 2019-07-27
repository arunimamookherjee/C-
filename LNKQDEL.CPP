//DELETION IN LINKED QUEUE

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
}*front,*newptr,*save,*ptr,*rear;

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


void ins_node(hospital *np)//FUNCTION TO INSERT NEW NODE
{
	if(rear==NULL)
	{
		front=rear=np;
	}
	else
	{
		rear->next=np;

		rear=np;
	}
}

void del_node()//FUNCTION TO DELETE NODE
{
	if(front==NULL)
	{
		cout<<"UNDERFLOW\n";
		getch();
		exit(1);
	}
	else
	{
		save=front;
		front=front->next;
		delete save;
	}
}


void displaylist(hospital *np)//FUNCTION TO DISPLAY QUEUE
{
       while(np!=NULL)

       {
		display(np);
		cout<<'\n';
		np=np->next;
       }

	cout<<'\n';
}

void main()
{
	clrscr();

	char ch='y';

	front=rear=NULL;//QUEUE IS EMPTY INITIALLY

	while(ch=='y'|| ch=='Y')

	{
		newptr=create();//CREATE NEW NODE

		if(newptr== NULL)
		{
			cout<<"Cannot create new node ";
			getch();
			exit(1);
		}

		ins_node(newptr);//INSERT NODE

		cout<<"\nNOW THE QUEUE CONTAINS:"<<endl;
		displaylist(front);//DISPLAY QUEUE

		cout<<"\nDO YOU WANT TO INSERT MORE NODES ";
		cin>>ch;


	}

	do
	{
		cout<<"DO YOU WANT TO DELETE ";
		cin>>ch;

		if(ch=='y' || ch=='Y')
			del_node();//DELETE NODE

		cout<<"\nNOW THE QUEUE CONTAINS:"<<endl;
		displaylist(front);//DISPLAY QUEUE
	 }
	 while(ch=='y'|| ch=='Y');


	getch();
 }


