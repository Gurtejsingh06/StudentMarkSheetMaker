#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

class report{
private:
    int 	admno;
	char	name[30];
	char	fname[30];
	int	    std;
	char	section;
	int     math;
	int	    hindi;
	int		science;
	int 	punjabi;
	int		eng;
	int		total;
	float	per;
	char	grade[3];

public:

    void main_menu();
	void search_menu();
	void report_menu();
    void read_data();
    void calculate();
	void disp_data();
	void add_record();
	void del_record();
	void modify_record();
	void search_name();
	void search_admno();
   	void search_class();
    void single_report_card();
    void report_single();
    void report_class();
    void report_school();

};

void  report ::main_menu()
{
 int choice;
     do
       {
         system("CLS");
         cout<<"\n\n\n\t\t R e p o r t  C a r d  M e n u\n\n";
         cout<<"\n\n\t\t1. Add New Student ";
         cout<<"\n\n\t\t2. Delete  Student";
         cout<<"\n\n\t\t3. Modify student";
         cout<<"\n\n\t\t4. Search Menu";
         cout<<"\n\n\t\t5. Report Menu ";
         cout<<"\n\n\t\t6. Exit ";
         cout<<"\n\n\t\t   Enter your choice (1..6) : ";
         cin>>choice;
         switch(choice)
         {
            case 1:    add_record();
                       break;
            case 2:    del_record();
                       break;
            case 3:    modify_record();
                       break;
            case 4:    search_menu();
                       break;
            case 5:    report_menu();
                       break;
            case 6:    break;
            default :
                       cout<<"\n Wrong Choice.... Try again";
         }
      }while(choice!=6);

return;
}

void  report ::search_menu()
{
 int choice;
     do
       {
         system("CLS");
         cout<<"\n\n\n\t\t S e a r c h   M e n u \n\n";
         cout<<"\n\n\t\t1. AdmNo Student";
         cout<<"\n\n\t\t2. Student Name";
         cout<<"\n\n\t\t3. Class wise";
         cout<<"\n\n\t\t4. Exit ";
         cout<<"\n\n\n\n\t\t   Enter your choice (1..4) : ";
         cin>>choice;
         switch(choice)
         {

            case 1:    search_admno( );
                       getch();
                       break;

            case 2:    search_name();
                       getch();
                       break;

            case 3:    search_class();
                       getch();
                       break;

            case 4:    break;

            default :
                       cout<<"\n Wrong Choice.... Try agian";
         }
      } while(choice!=4);

return;
}

void  report ::report_menu()
{
 int choice;
     do
       {
         system("CLS");
         cout<<"\n\n\n\t\t R e p o r t   M e n u\n\n";
         cout<<"\n\n\t\t1. Single Student";
         cout<<"\n\n\t\t2. Single class";
         cout<<"\n\n\t\t3. Whole School";
         cout<<"\n\n\t\t4. Exit ";
         cout<<"\n\n\t\t   Enter your choice (1..4) : ";
         cin>>choice;
         switch(choice)
         {
            case 1:    report_single();
                       break;
            case 2:    report_class();
                       break;
            case 3:    report_school();
                       break;
            case 4:    break;
            default :
                       cout<<"\n Wrong Choice.... Try again";
         }
      }while(choice!=4);

return;
}

void report:: read_data( )
 {
   system("CLS");
   cout<<"\n Enter Adm No :";
   cin>>admno;
   cout<<"\n Enter Name : ";
   cin>>name;
   cout<<"\n Enter Father Name : ";
   cin>>fname;
   cout<<"\n Enter class : ";
   cin>>std;
   cout<<"\n Enter Section :";
   cin>>section;
   cout<<"\n Enter marks obtained in Hindi : ";
   cin>>hindi;
   cout<<"\n Enter marks obtained in Science : ";
   cin>>science;
   cout<<"\n Enter marks obtained in Maths  : ";
   cin>>math;
   cout<<"\n Enter marks obtained in Punjabi : ";
   cin>>punjabi;
   cout<<"\n enter marks obtained in English : ";
   cin>>eng;

  return;
 }

 void report::calculate()
 {
  total = hindi+punjabi+math+science+eng;
  per = total/5.0;

  if(per>=95)
             strcpy(grade,"A+");

 if(per<95 &&  per>=90)
             strcpy(grade,"A");

 if(per<90 &&  per>=80)
             strcpy(grade,"B+");

 if(per<80 &&  per>=70)
             strcpy(grade,"B");

 if(per<70 &&  per>=60)
             strcpy(grade,"C+");
 if(per<60)
             strcpy(grade,"C");
  return;
}

void  report::disp_data()
{

 cout<<"\n AdmNo               : "<<admno;
 cout<<"\n Student Name        : "<<name;
 cout<<"\n Father Name         : "<<fname;
 cout<<"\n Class & Section     : "<<std<<"-"<<section;
 cout<<"\n Hindi               : "<<hindi;
 cout<<"\n Punjabi             : "<<punjabi;
 cout<<"\n Maths               : "<<math;
 cout<<"\n Science             : "<<science;
 cout<<"\n English             : "<<eng;
 cout<<"\n Total Marks         : "<<total;
 cout<<"\n Percentage          : "<<per;
 cout<<"\n Grade               : "<<grade;


 return ;
}

void  report::add_record ()
{
   ofstream fout;
   fout.open("report.dat",ios::app);
   read_data();
   calculate();
   fout.write((char*)this, sizeof(report));
   fout.close();
}


void  report::del_record ()
{

 ifstream fin;
 ofstream fout;
 int tadmno;
 int flag =0;
 system("CLS");
 cout<<"\n Enter admno to delete :";
 cin>>tadmno;

 fin.open("report.dat",ios::binary);
 fout.open("temp.dat");

 while(fin.read((char*)this, sizeof(report)))
  {
     if(tadmno!=admno)
         fout.write((char*)this,sizeof(report));
     else
         flag=1;

  }
  fin.close();
  fout.close();

  remove("report.dat");
  rename("temp.dat","report.dat");

  if(flag==1)
     cout<<"\n\n Record Successfully removed ";
  else
     cout<<"\n Admission No :"<<tadmno <<" does not exist...Try again";
  getch();
 return;
}

void report:: modify_record()
{

 ifstream fin;
 ofstream fout;
 int tadmno;
 int flag =0;
 system("CLS");
 cout<<"\n Enter Admno to Modify :";
 cin>>tadmno;

 fin.open("report.dat",ios::binary);
 fout.open("temp.dat");

 while(fin.read((char*)this, sizeof(report)))
  {
     if(tadmno == admno)
        {  read_data(); calculate(); flag=1; }

     fout.write((char*)this,sizeof(report));

  }
  fin.close();
  fout.close();

  remove("report.dat");
  rename("temp.dat","report.dat");

  if(flag==1)
     cout<<"\n\n Record Successfully modified ";
  else
     cout<<"\n Admission No :"<<tadmno <<" does not exist...Try again";
  getch();
 return;

}



void report::search_name( )
{
  ifstream fin;
  fin.open("report.dat");
  char tname[30];
  int flag=0;

  system("CLS");
  cout<<"\n Enter Name to search :";
  cin>>tname;

  while(fin.read((char*)this,sizeof(report)))
    {
        if(strcmpi(tname,name)==0)
           {
              system("CLS");
              cout<<"\n Student Information ";
              cout<<"\n--------------------------------------------------------"<<endl;
              disp_data();
              flag=1;
            }
    }
  fin.close();
  if(flag==0)
    cout<<"\n No such name : "<<strupr(tname)<<" exist in our record... Try again";

  return;
}

void report :: search_admno( )
{
  ifstream fin;
  fin.open("report.dat");

  int tadmno;
  int flag=0;

  system("CLS");
  cout<<"\n Enter Admission Number to search : ";
  cin>>tadmno;

  while(fin.read((char*)this,sizeof(report)))
    {
        if(tadmno == admno)
           {
              system("CLS");
              cout<<"\n Student Information ";
              cout<<"\n--------------------------------------------------------"<<endl;
              disp_data();
              flag = 1;
            }


    }
  fin.close();

  if(flag==0)
     cout<<"\n\n Admission No : "<<tadmno <<" does not exist.... Try again";

  return;

}


void report::search_class()
{
  ifstream fin;
  fin.open("report.dat");
  char tsect;
  int tstd;
  int flag;

  system("CLS");
  cout<<"\n Enter student Class to search :";
  cin>>tstd;
  cout<<"\n Enter student section to search :";
  cin>>tsect;

  system("CLS");
  cout<<"\n Class :"<<tstd<<" - "<<tsect<<endl;
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"AdmNo\t Name\t Fname\t Hindi \t Punjabi\t Math \t Science \t Eng \t Total \t per\n";
  cout<<"-------------------------------------------------------------------------------"<<endl;

  while(fin.read((char*)this,sizeof(report)))
    {
        if(tsect==section && tstd == std)
           {

             cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<hindi<<"\t"<<punjabi<<"\t"<<math<<"\t"<<science<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<endl;
             flag=1;
            }
    }
  cout<<"-------------------------------------------------------------------------------"<<endl;

  fin.close();
  if(flag==0)
      cout<<"\n\n information Not available for class :"<<tstd <<" - "<<tsect;

  return;


}

void report::single_report_card()
{
  system("cls");

  cout<<"\n\t\t Little Star Public School , Chand Nagar ";
  cout<<"\n\t\t Session : 2019-20";
  cout<<"\n-------------------------------------------------------------------------------";
  cout<<"\n\n AdmNo :"<<admno;
  cout<<"\n\n Name  :"<<name <<"\t\t Father Name :"<<fname<<"\t\t class :"<<std<<"-"<<section;
  cout<<"\n\n-------------------------------------------------------------------------------";
  cout<<"\n Subject\tMax Mark\tMin Mark\t Marks Obtained";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n Hindi\t100\t\t33\t\t\t"<<hindi;
  cout<<"\n\n Punjabi\t100\t\t33\t\t\t"<<punjabi;
  cout<<"\n\n Maths\t\t100\t\t33\t\t\t"<<math;
  cout<<"\n\n Science\t100\t\t33\t\t\t"<<science;
  cout<<"\n\n English\t100\t\t33\t\t\t"<<eng;
  cout<<"\n\n-------------------------------------------------------------------------------";
  cout<<"\n Total Marks :\t\t"<<total<<"\t\tPercentage : "<<per<<"\tGrade :"<<grade;
  cout<<"\n---------------------------------------------------------------------------------";

return;
}


void report:: report_single()
{
  int tadmno;
  int flag =0;
  ifstream fin;
  fin.open("report.dat",ios::binary);
  system("CLS");
  cout<<"\n Enter admission No : ";
  cin>>tadmno;

  while(fin.read((char*)this, sizeof(report)))
    {
       if(tadmno ==admno)
            single_report_card();
       else
            flag =1;
     }
  fin.close();
  if(flag==0)
     cout<<"\n\n Admission No :"<<tadmno <<" does not exist.... Try again";
  getch();
return;
}


void report:: report_class()
 {

  int tstd;
  char tsect;

  int row =6;
  int no =0;
  ifstream  fin;
  fin.open("report.dat");

  system("CLS");

  cout<<"n\n Enter Class (1..12)  :";
  cin>>tstd;
  cout<<"\n Enter section :";
  cin>>tsect;

  system("CLS");

  cout<<"\n\t\t Little Star Public School Chand Nagar, New Delhi-18";
  cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2019-20"<<endl;
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"AdmNo\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
  cout<<"-------------------------------------------------------------------------------"<<endl;

  while(fin.read((char*)this, sizeof(report)))
   {
      if(tstd==std && tsect== section )
       {
         row= row+1;
         no++;
         if(row>=30)
          {
            cout<<"\n\n  Press any key to continue ................";
            getch();
              cout<<"\n\t\t Little Star Public School Chand Nagar, New Delhi-18";
              cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2019-20"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<"AdmNo\tName\tFname\t Hindi \t Punjabi\t Math \t Science \t Eng \t Total \t per\n";
              cout<<"-------------------------------------------------------------------------------"<<endl;
            row =6;
           }
         cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<hindi<<"\t"<<punjabi<<"\t"<<math<<"\t"<<science<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<endl;

         }
    }
  fin.close();
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"\n Total Student : "<<no<<" Report prepared By  :"<<" Gurtej Singh ";
  getch();
  return ;

 }



 void report:: report_school()
 {

  int tstd;
  char tsect;

  int row =6;
  int no =0;

  ifstream  fin;
  fin.open("report.dat");

  system("CLS");

  cout<<"\n\t\t Little Star Public School Chand Nagar, New Delhi-18";
  cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2019-20"<<endl;
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"AdmNo\tName\tFname\t Hindi \t Punjabi\t Math \t Science \t Eng \t Total \t per\n";
  cout<<"-------------------------------------------------------------------------------"<<endl;

  while(fin.read((char*)this, sizeof(report)))
   {
         row= row+1;
         no++;
         if(row>=30)
          {
            cout<<"\n\n  Press any key to continue ................";
            getch();
              cout<<"\n\t\t Little Star School Chand Nagar, New Delhi-18";
              cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2019-20"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<"AdmNo\tName\tFname\t Hindi \t Punjabi\t Math \t Science \t Eng \t Total \t per\n";
              cout<<"-------------------------------------------------------------------------------"<<endl;
            row =6;
           }
         cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<hindi<<"\t"<<punjabi<<"\t"<<math<<"\t"<<science<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<endl;
    }
  fin.close();
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"\n Total Student : "<<no<<" Report prepared By  :"<<" Gurtej Singh ";
  getch();
  return ;

 }

int main()
{

    report r;
    r.main_menu();

    return 0;
}
