//TO DELETE DATA FROM A BINARY FILE

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
} ;


void main()
{
	clrscr();

	hospital hosp;
	char ch='y';
	int flag=0,del_id;
	ifstream fin;
	ofstream fout("hospital_1.dat",ios::out|ios::binary);

	ofstream fout2("temp.dat",ios::out|ios::binary);

	while(ch=='y'||ch=='Y')
	{
		cout<<"Enter Record : "<<endl;
		hosp.input();//GET INPUT FOR RECORD
		cout<<endl;

		fout.write((char*)&hosp,sizeof(hosp));

		cout<<"PRESS 'Y' TO ENTER MORE RECORDS?  ";
		cin>>ch;
	}

	fout.close();

	cout<<"\nEnter patient id to be deleted : ";
	cin>>del_id;

	fin.open("hospital_1",ios::in|ios::binary);


	while(!fin.eof())
	{
		fin.read((char*)&hosp,sizeof(hosp));

		if(fin.eof())//CHECK IF END OF FILE IS REACHED
			break;

		if(del_id==hosp.get_id())

		{
			cout<<"Record to be deleted "<<endl;
			hosp.display();//DISPLAY RECORD TO BE DELETED
			cout<<endl;
			flag=1;//RECORD FOUND

		}
		else
			fout2.write((char*)&hosp,sizeof(hosp));


	}

	fin.close();

	if(flag==0)
		cout<<"Record not found "<<endl;

	fout2.close();

	remove("hospital_1.dat");
	rename("temp.dat","hospital_1.dat");

	fin.open("hsopital_1.dat",ios::in|ios::binary);
	cout<<"\nCONTENTS OF THE FILE : \n";

	while(!fin.eof())//AS LONG AS END OF FILE IS NOT REACHED
	{
		fin.read((char*)&hosp,sizeof(hosp));


		if(fin.eof())//CHECK IF END OF FILE IS REACHED
			break;

		hosp.display();//DISPLAY RECORD
		cout<<endl;
	}

	fin.close();

	getch();
}