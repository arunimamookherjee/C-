//TO APPEND DATA IN A BINARY FILE

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
} ;



void main()
{
	clrscr();

	hospital hosp;
	char ch='y';
	ifstream fin;
	ofstream fout("hospital.dat",ios::binary|ios::app);


	while(ch=='y'||ch=='Y')
	{
		cout<<"Enter Record "<<endl;
		hosp.input();
		cout<<endl;

		fout.write((char*)&hosp,sizeof(hosp));
		cout<<"\nPRESS 'Y' TO ENTER MORE RECORDS? ";cin>>ch;
	}

	fout.close();

	cout<<"\nCONTENTS OF THE FILE "<<endl;

	fin.open("hospital.dat",ios::in|ios::binary);

	while(!fin.eof())
	{
		fin.read((char*)&hosp,sizeof(hosp));

		if(fin.eof())//TO CHECK IF END OF FILE IS REACHED
			break;

		hosp.display();//DISPLAY RECORD
		cout<<endl;
	}

	fin.close();

	getch();
}