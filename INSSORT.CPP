//INSERTION SORT IN ARRAY

#include<iostream.h>
#include<conio.h>
#include<limits.h>
#include<stdio.h>

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

	void set_minpatientid()
	//FUNCTION TO GIVE MIN POSSIBLE INTEGRAL VALUE TO 'patient_id'
	{
		patient_id=INT_MIN;
	}
}; //CLASS DEFINITION OVER






void inssort(hospital hosp[],int size)
{
      hospital tmp;

      int j;

      hosp[0].set_minpatientid();
      //TO GIVE MIN POSSIBLE INTEGRAL VALUE TO patient_id OF 0th ELEMENT

      for(int i=1;i<=size;i++)
      {
		tmp=hosp[i];
		j=i-1;

		while(tmp.get_patientid()<hosp[j].get_patientid())
		/*AS LONG AS 'patient_id' OF 'tmp' < 'patient_id' OF Jth ELEMENT SHIFT
		  Jth ELEMENT FORWARD */
		{
			hosp[j+1]=hosp[j];
			j--;
		}
		/*WHILE LOOP TERMINATES WHEN 'patient_id' OF 'TMP' >= 'patient_id' OF
		  Jth ELEMENT */

		hosp[j+1]=tmp;//INSERT 'TMP' IN J+1 th INDEX

		cout<<endl<<"Array after pass-" <<i<<"-is"<<endl;

		for (int k=1;k<=size;k++)
		{
			hosp[k].display();//DISPLAY ELEMENT
			cout<<endl;
		}
		cout<<endl;
	 }
}

void main()
{
	    clrscr ();

	    hospital hos[50];
	    /*ARRAY OF OBJECTS OF CLASS 'HOAPITAL'
	      ( CAN HOLD MAX 50 ELEMENTS ) */
	    int n,index;

	    cout<<"Enter array size ";
	    cin>>n;

	    cout<<endl<<"Enter array elements"<<endl<<endl;

	    for(int i=1;i<=n;i++)
	    {
		hos[i].get_input();//GET INPUT
	    }

	     inssort(hos,n);//PERFORM INSERTION SORT

	    cout<<"\n\n Sorted array is\n";

	    for(i=1;i<=n;i++)
	    {
		hos[i].display();//DISPLAY ELEMENT
		cout<<endl;
	    }

	      getch();
}



