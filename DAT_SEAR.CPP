//TO MODIFY DATA IN BINARY FILE

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>


class hospital
{
char name[20];
int patient_id;
float TOT_BILL,meds, noofdays, roomservice, OTcharges, consult_fees;
public:
       void calculate()
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       }

	void input()
	{
	char ch;
	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL COST OF MEDICINE : ";cin>>meds;
	cout<<"\nWas the patient admitted : ";cin>>ch;
	if(ch=='y'||ch=='Y')
	{      	cout<<"\nNO. OF DAYS ADMITTED : "; cin>>noofdays;
		roomservice=noofdays*800;

	}
		cout<<"\nWas the patient OPERATED : ";cin>>ch;
	if(ch=='y'||ch=='Y')
       {	OTcharges=7000; consult_fees=5000;	}
	else
       {	OTcharges=0; consult_fees=500;          }

       calculate();
       }


       void display()
       {
       cout<<"\nNAME	   : "<<name;
       cout<<"\tPATIENT ID : "<<patient_id ;
       cout<<"\n\n::::::::::::::::::::BILL::::::::::::::::";
       cout<<"\nMEDICINE	: "<<meds;
       cout<<"\nROOM SERVICE    : "<<roomservice;
       cout<<"\nOT CHARGES	: "<<OTcharges;
       cout<<"\nCONSULTING FEES : "<<consult_fees;
       cout<<"\n		   ------------------";
       cout<<"\nTOTAL BILL	: "<<TOT_BILL;
       }
       int get_id()
       { return patient_id;}
}h1 ;
void main()
{       clrscr();
       fstream fio("hospital_1.dat",ios::in|ios::out|ios::binary)
       char found='f';
       int id ;
       cout<<"\nEnter Patient id to be searched for: ";cin>>id;
       while(!fio.eof())
       {
       fio.read((char*)&h1,sizeof(h1));
       if(h1.get_id()==id)
       {
       h1.display();
       found='t';
       break;
       }
       }

       if(found=='f')
       cout<<"\nRecord not foundin file!!";

       getch();
       }

