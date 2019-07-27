//DELETION IN ARRAY QUEUE

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>


const int size=50;

class hospital
{
char name[20];
int patient_id,bill;
public:

	int get_patientid()//ACECSSOR FUNCTION TO GET patient_id
	{	return patient_id; }

	void input()
	{
	char ch;

	cout<<"\nNAME	    : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nBILL	    :";cin>>bill;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	cout<<"\nBILL	    : "<<bill ;
	}


}; //CLASS DEFINITION OVER


hospital Queue[size];//ARRAY QUEUE OF OBJECTS OF CLASS 'hospital' ( CAN HOLD MAX 50 ELEMENTS )

int front=-1,rear=-1;//TO ASSIGN -1 TO REAR AND FRONT AS QUEUE IS EMPTY INITIALLY

int Insert_in_Q(hospital Queue[],hospital hosp_ele)//FUNCTION TO INSERT ELEMENT IN QUEUE
{
	if(rear==size-1)//TO CHECK IF QUEUE IS FULL ( OVERFLOW )
	{
		return -1;
	}
	else if(rear==-1)//TO CHECK IF QUEUE IS EMPTY AND ASSIGN 0 TO REAR AND FRONT
	{
		rear=front=0;//REAR AND FRONT UPDATED
	}
	else
		rear++;//REAR UPDATED

	Queue[rear]=hosp_ele;//TO INSERT NEW ELEMENT

	return 0;//INSERTION IS SUCCESSFUL
}

void Display(hospital Queue[],int front,int rear)//TO DISPLAY QUEUE
{

	if(front==-1)//TO CHECK IF QUEUE IS EMPTY AND TERMINATE FUNCTION
		return;

	for(int i=front;i<=rear;i++)
	{
		Queue[i].display();//TO DISPLAY RECORD
		cout<<endl;
	}


	cout<<endl;


}

hospital Del_in_Q(hospital Queue[])//TO DELETE ELEMENT FROM QUEUE
{
	hospital hosp_ret;

	if(front==-1)//TO CHECK IF QUEUE IS EMPTY AND TERMINATE PROGRAM
	{
		cout<<"UNDERFLOW...";
		getch();
		exit(1);
	}

	else
	{
		hosp_ret=Queue[front];//TO GET ELEMENT TO BE DELETED

		if(front==rear)//TO CHECK IF QUEUE HAS SINGLE ELEMENT
			front=rear=-1;//REAR AND FRONT UPDATED
		else
			front++;//FRONT UPDATED

	}

	return hosp_ret;//TO RETURN ELEMENT TO BE DELETED
}

void main()
{
	clrscr();

	hospital hosp_Item,hosp_res;
	int res;
	char ch='y';

	while(ch=='y'||ch=='Y')
	{
		cout<<"\nEnter Record for insertion : "<<endl<<endl;
		hosp_Item.input();//TO GET INPUT
		cout<<endl;

		res=Insert_in_Q(Queue,hosp_Item);//TO INSERT ELEMENT IN QUEUE AND CHECK IF INSERTION IS SUCCESSFUL

		if(res==-1) //UNSUCCESSFUL INSERTION
		{
			cout<<"OVERFLOW!!! Aborting!!\n";
			exit(1);
		}

		cout<<"\n Now the Queue (Front...to...Rear ) is : \n"<<endl;

		Display(Queue,front,rear);//TO DISPLAY QUEUE

		cout<<"Want to insert more elements ? (y/n)...";
		cin>>ch;
	}
	cout<<"Now deletion of elements begins...\n";
	ch='y';

	while(ch=='y'||ch=='Y')
	{
		hosp_res=Del_in_Q(Queue);//TO GET ELEMENT TO BE DELETED

		cout<<"\n Element deleted is : "<<endl<<endl;

		hosp_res.display();//TO DISPLAY RECORD TO BE DELETED
		cout<<endl;

		cout<<"Now the Queue (Front...to...Rear ) is :\n"<<endl;

		Display(Queue,front,rear);//TO DISPLAY QUEUE
		cout<<endl;

		cout<<"Want to delete more elements ? (y/n)...";
		cin>>ch;
	}
	getch();

}


