#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
const int size=7;
class hospital
{
char name[20];
int patient_id;
public:

	int get_patientid()//ACECSSOR FUNCTION TO GET patient_id
	{	return patient_id; }

	void get_input()
	{
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	}


}; //CLASS DEFINITION OVER


hospital CQueue[size];
int front=-1,rear=-1;

int Insert_in_CQ(hospital CQueue[],hospital hosp_ele)
{
	if((rear==size-1&&front==0)||(front==rear+1))
	{
		return -1;
	}
	else if(rear==-1)
	{
		rear=front=0;
	}
	else if(rear==size-1)
	{
		rear=0;
	}
	else
		rear=rear+1;
	CQueue[rear]=hosp_ele;
	return 0;
}
void Display(hospital CQueue[],int front,int rear)
{
	int i=0;
	cout<<"(Front shown as >>>,Rear as <<<< AND free space as - )\n";
	if(front==-1)
		return;
	if(rear>=front)
	{
		for(i=0;i<front;i++)
			cout<<"-"<<endl;
		cout<<">>>"<<endl;
		for(i=front;i<rear;i++)
		{
			CQueue[i].display();
			cout<<endl;
		}
		CQueue[rear].display();
		cout<<endl<<"<<<"<<endl;
	}
	else
	{
		for(i=0;i<rear;i++)
		{
			CQueue[i].display();
			cout<<endl;
		}
		CQueue[rear].display();
		cout<<endl<<"<<<"<<endl;
		for(;i<front;i++)
			cout<<"-"<<endl;
		cout<<">>>"<<endl;
		for(i=front;i<size;i++)
		{
			CQueue[i].display();
			cout<<endl;
		}
		cout<<endl<<"\t...wrap around..."<<endl;
	}
}

hospital Del_in_CQ(hospital CQueue[])
{
	hospital hosp_ret;
	if(front==-1)
	{
		cout<<"UNDERFLOW ";
		getch();
		exit(1);
	}
	else
	{
		hosp_ret=CQueue[front];
		if(front==rear)
			front=rear=-1;
		else if(front==size-1)
			front=0;
		else
			front++;
	}
	return hosp_ret;
}
void main()
{
	hospital hosp_Item;

	int res,opt;
	do
	{
		clrscr();
		cout<<"\t\t\t Circular Queue Menu\n";
		cout<<"\t1.Insert\n";
		cout<<"\t2.Delete\n";
		cout<<"\t3.Display\n";
		cout<<"\t4.Exit\n";
		cout<<"Enter your choice(1-4)...";
		cin>>opt;
		switch(opt)
		{
			case 1 : cout<<"\nEnter Record for insertion : "<<endl;
				 hosp_Item.get_input();
				 cout<<endl;
				 res=Insert_in_CQ(CQueue,hosp_Item);
				 if(res==-1)
					cout<<"OVERFLOW!!!\n";
				 else
				 {
					cout<<"\n Now the Cir_Queue is : \n";
					Display(CQueue,front,rear);
					cout<<endl;
				 }
				 getch();
				 break;
			case 2 : comp_Item=Del_in_CQ(CQueue);
				 cout<<"Element deleted is : "<<endl;
				 comp_Item.display();
				 cout<<endl;
				 Display(CQueue,front,rear);
				 cout<<endl;
				 getch();
				 break;
			case 3 : Display(CQueue,front,rear);
				 cout<<endl;
				 getch();
				 break;
			case 4 : break;
			default: cout<<"Valid choices are 1...4 only\n";
				 getch();
				 break;
		}
	}
	while(opt!=4);
}


