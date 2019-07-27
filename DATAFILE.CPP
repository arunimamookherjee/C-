//DATA FILE HANDLING WRITE A FILE
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<process.h>

class HOSPITAL
{
char name[20];      //VARIABLES FOR THE CLASS
int patient_id;
float TOT_BILL,meds, mediclaim, noofdays, roomservice, OTcharges, consult_fees;
public:
	void input()       //FUNCTION TO TAKE INPUT FOR THE CLASS
	{
	mediclaim=0;
	noofdays=0;
	OTcharges=0;
	consult_fees=0;
	roomservice=0;
	meds=0;
	TOT_BILL=0;
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL COST OF MEDICINE : ";cin>>meds;
	cout<<"\nWas the patient admitted : ";cin>>ch;
	if(ch=='y'||ch=='Y')
	{       cout<<"\nIf the room was general PRESS 1";
		cout<<"\nIf the room was executive PRESS 2\n";
		cin>>ch;
		cout<<"\nNO. OF DAYS ADMITTED : "; cin>>noofdays;
		if(ch=='1')
		roomservice=noofdays*400;
		else if(ch=='2')
		roomservice=noofdays*1500;
		else
		roomservice=0;
	}
		cout<<"\nWas the patient OPERATED : ";cin>>ch;
	if(ch=='y'||ch=='Y')
       {	OTcharges=7000; consult_fees=5000;
		cout<<"\nAny value for mediclaim... if no value press 0 : ";
		cin>>mediclaim;	}
	else
       {	OTcharges=0; consult_fees=500;          }


       }

       void calculate()         //FUNCTION TO CALCULATE FOR THE CLASS
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       if(mediclaim>TOT_BILL)
       TOT_BILL=0;
       else
       TOT_BILL=TOT_BILL-mediclaim;
       }

       void display()		//FUNCTION TO DISPLAY THE DETAILS OF THE CLASS
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
} ;

void main()
{
 clrscr();
 HOSPITAL patient[5],hosp;
 fstream fio;
 fio.open("hospital_record",ios::in|ios::out);
 long pos;

 cout<<"\nEnter Details";
 for(int i=0;i<5;i++)
 {
 patient[i].input();
 patient[i].calculate();

 fio.write((char*)&patient[i],sizeof(patient[i]));

  }
 cout<<"\nFILE CREATED SUCCESSFULLY!!!!";
 fio.close();
 getch();
 }
