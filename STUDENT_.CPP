#include<iostream.h>
#include<conio.h>
#include<fstream.h>

class Student
{
public:
int rollNo;
char name[50];
int age;
float marks;
};

void saveStudents(Student s[],int count)
{
ofstream
outfile("student.dat");
for(int i=0;i<count;i++)
{
outfile.write((char *)&s[i], sizeof(Student));
}
outfile.close();
}

int loadStudents(Student s[])
{
ifstream infile("student.dat");
int count=0;
while(infile.read((char *)&s[count], sizeof(Student)))
{
count++;
if(count>=100)
{
break;
}
}
infile.close();
return count;
}
void main()
{
Student s[100];
int count=0;
count=loadStudents(s);
int choice;
int i;
int searchRoll;
int found;

do
{
clrscr();
cout<<"------------------------------------"<<endl;
cout<<"Student Management System"<<endl;
cout<<"--------------------------------------"<<endl;
cout<<"1.ADD Student"<<endl;
cout<<"2.Display Student"<<endl;
cout<<"3.Search Student"<<endl;
cout<<"4.Update Student"<<endl;
cout<<"5.Delete Student"<<endl;
cout<<"6.Calculate Grade"<<endl;
cout<<"7.Exit"<<endl;

cout<<"Enter your choice :";
cin>>choice;

switch(choice)
{
case 1:
if(count<100)
{
cout<<"Enter RollNo. ";
cin>>s[count].rollNo;
cout<<"Enter Name: ";
cin>>s[count].name;
cout<<"Enter Age: ";
cin>>s[count].age;
cout<<"Enter Marks: ";
cin>>s[count].marks;
count++;
saveStudents(s,count);
ofstream outfile("student.dat");
outfile.write((char *)&s[count-1], sizeof(Student));
outfile.close();
cout<<"\n Student added Successfully!";
}
else
{
cout<<"\nStudent Limit Reached!";
}
getch();
break;

case 2:
clrscr();
if(count==0)
{
cout<<"\nNo Student Available!";
}
else
{
cout<<"------------------------------"<<endl;
cout<<"All Students"<<endl;
cout<<"------------------------------"<<endl;
for(i=0;i<count;i++)
{
cout<<"\nStudent"<<i+1<<endl;
cout<<"Enter RollNo."<<s[i].rollNo<<endl;
cout<<"Enter Name: "<<s[i].name<<endl;
cout<<"Enter Age: "<<s[i].age<<endl;
cout<<"Enter Marks: "<<s[i].marks<<endl;
cout<<"\n--------------------------------";
}
}
getch();
break;

case 3:
clrscr();
if(count==0)
{
cout<<"No student available";
}
else
{
cout<<"\nEnter RollNo. to search";
cin>>searchRoll;
found=0;
for(i=0;i<count;i++)
{
if(s[i].rollNo==searchRoll)
{
cout<<"\nStudent Found!"<<endl;
cout<<"----------------------------------"<<endl;
cout<<"Roll No. :"<<s[i].rollNo<<endl;
cout<<"Name : "<<s[i].name<<endl;
cout<<"Age :"<<s[i].age<<endl;
cout<<"Marks :"<<s[i].marks<<endl;
found=1;
break;
}
}
if(found==0)
{
cout<<"\nStudent Not Found!";
}
}
getch();
break;

case 4:
clrscr();
if(count==0)
{
cout<<"\nNo student available!";
}
else
{
cout<<"Enter RollNo. to update";
cin>>searchRoll;
found=0;
for(i=0;i<count;i++)
{
if(s[i].rollNo==searchRoll)
{
cout<<"\nStudent Found!";
cout<<"\n\nEnter New Name: ";
cin>>s[i].name;
cout<<"\nEnter New Age: ";
cin>>s[i].age;
cout<<"\nEnter New Marks: ";
cin>>s[i].marks;
saveStudents(s,count);
found=1;
cout<<"\nStudent Updated Successfully!";
break;
}
}
if(found==0)
{
cout<<"\nStudent not found!";
}
}
getch();
break;

case 5:
clrscr();
if(count==0)
{
cout<<"\nNo Student Available!";
}
else
{
cout<<"Enter Roll Number to delete: ";
cin>>searchRoll;
found=0;
for(i=0;i<count;i++)
{
if(s[i].rollNo==searchRoll)
{
for(int j=i;j<count-1;j++)
{
s[j]=s[j+1];
}
count--;
found=1;
saveStudents(s,count);
cout<<"\nStudent Deleted Successfully!";
break;
}
}
if(found==0)
{
cout<<"\nStudent not Found!";
}
}
getch();
break;

case 6:
clrscr();
if(count==0)
{
cout<<"\nNo Students available!";
}
else{
cout<<"Enter Roll Number:";
cin>>searchRoll;
found=0;
for(i=0;i<count;i++)
{
if(s[i].rollNo==searchRoll)
{
cout<<"\nStudent Found!"<<endl;
cout<<"\nName :"<<s[i].name;
cout<<"\nMarks :"<<s[i].marks;
cout<<"\nPercentage :"<<s[i].marks<<"%";
if(s[i].marks>=75)
{
cout<<"\nGrade :A";
}
else if(s[i].marks>=60)
{
cout<<"\nGrade :B";
}
else if(s[i].marks>=50)
{
cout<<"\nGrade :C";
}
else if(s[i].marks>=35)
{
cout<<"\nGrade :D";
}
else
{
cout<<"\nGrade :F";
}
found =1;
break;
}
}
if(found==0)
{
cout<<"\nStudent not found!";
}
}
getch();
break;

case 7:
cout<<"\nThank You For Using My Program!";
getch();
break;

default:
cout<<"\nInvalid Choice!";
getch();
}
}while(choice !=7);
}

