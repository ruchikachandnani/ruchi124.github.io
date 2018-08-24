#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
static int no=0;
void stud2();
void admin2();
class Book
{
    int bkid,st;
    char bkname[50];
    char auname[50];
    char publ[50];
    char cat[50];
public:
    void setdata()
    {
        //cout<<"Enter book_id:"<<endl;
        //cin>>bkid;
        cout<<"Enter book_name:"<<endl;
        cin>>bkname;
        cout<<"Enter author_name:"<<endl;
        cin>>auname;
        cout<<"Enter publication:"<<endl;
        cin>>publ;
        cout<<"Enter book_category:"<<endl;
        cin>>cat;
    }
    void display()
    {
        cout<<bkid<<"\t"<<bkname<<"\t"<<auname<<"\t"<<publ<<"\t"<<cat<<"\t"<<st;
    }
    void setid(int n)
    {
        bkid=n;
    }
    int getid()
    {
        return bkid;
    }
    char* getbkname()
    {
        return bkname;
    }
    char* getauname()
    {
        return auname;
    }
    char* getpubl()
    {
        return publ;
    }
    char* getcategory()
    {
        return cat;
    }
    void setstatus(int a)
    {
        st=a;
    }
    int getstatus()
    {
        return st;
    }
};
class Student
{   int enroll,cnt,status;
    char name[50],branch[50],sem[50];
    public:
    void setdata()
    {
        cout<<"Enter Enrollment no:"<<endl;
        cin>>enroll;
        cout<<"Enter Student name:"<<endl;
        cin>>name;
        cout<<"Enter branch:"<<endl;
        cin>>branch;
        cout<<"Enter semester:"<<endl;
        cin>>sem;
        //cout<<"Enter books issued:"<<endl;
        //cin>>cnt;
    }
    void display()
    {
        cout<<enroll<<" "<<name<<" "<<branch<<" "<<sem<<" "<<cnt<<" "<<status;
    }
    int getenroll()
    {
        return enroll;
    }
    int getcount()
    {
        return cnt;
    }
    void setcount(int c)
    {
         cnt=c;
    }
    void setstatus(int s)
    {
        status=s;
    }
    int getstatus()
    {
        return status;
    }

};
class Notification
{
    int enno,id,notify;
public:
    void setno(int a)
    {
        enno=a;
    }
    void setidn(int b)
    {
        id=b;
    }
    void setnotify(int a)
    {
        notify=a;
    }
    int getnotify()
    {
        return notify;
    }
    int getno()
    {
        return enno;
    }
    int getidn()
    {
        return id;
    }
    void disp()
    {
        cout<<notify<<" "<<enno<<" "<<id;
    }
};
class Password
{   int enroll,k=0;
char stpwd[50];
    public:
    void setrno(int m)
    {
        enroll=m;
    }
    void setpwd(char *a,int l)
    {
        for(int i=0;i<l;i++)
        {
            stpwd[k++]=a[i];
        }
        stpwd[k++]='\0';
    }
    char *getpwd()
    {
        return stpwd;
    }
    void display()
    {
        cout<<enroll<<" "<<stpwd;
    }
    int getenroll()
    {
        return enroll;
    }
};
class Password1
{
    int k=0;
    char stpwd[50],uname[50];
    public:
    void setpwd(char *a,int l)
    {
        for(int i=0;i<l;i++)
        {
            stpwd[k++]=a[i];
        }
        stpwd[k++]='\0';
    }
    char *getpwd()
    {
        return stpwd;
    }
    void display()
    {
        cout<<uname<<" "<<stpwd;
    }
    void setuname(char *u,int n)
    {
        strcpy(uname,u);
    }
    char *getuname()
    {
        return uname;
    }
};
/*class Status
{   int no;
    char *st;
    public:
    void setno(int n)
    {
        no=n;
    }
    void setst(char *s)
    {
        st=s;
    }
    void disp()
    {
        cout<<no<<" "<<st;
    }
};*/
char fname[]={"book.dat"};
char f1name[]={"student.dat"};
char f2name[]={"notification.dat"};
char f3name[]={"password.dat"};
char f4name[]={"password1.dat"};
//char f3name[]={"status.dat"};
int rno;
void createBookRecord()
{
    /*Book b;
    fstream f(fname,ios::out|ios::app);
    b.setdata();
    b.display();
    f.write((char *)&b,sizeof(b));
    b.display();
    f.close();*/
    Book b;
    fstream f(fname,ios::out|ios::app);
    //t.setid(getId());
    int n;
    cin>>n;
    b.setid(n);
    b.setdata();
    b.setstatus(0);
    f.write((char *)&b,sizeof(b));
    f.close();
}
int getfilesize()
{
    int size,total;
    Notification n;
    ifstream f(f2name);
    f.seekg(0,ios::end);
    total=f.tellg();
    f.close();
    size=total/sizeof(n);
    return(size);
}
int getsize()
{
    int size,total;
    Book b;
    ifstream f(fname);
    f.seekg(0,ios::end);
    total=f.tellg();
    f.close();
    size=total/sizeof(b);
    return(size);
}
int getfilesize1()
{
    int size,total;
    Student s;
    ifstream f(f1name);
    f.seekg(0,ios::end);
    total=f.tellg();
    f.close();
    size=total/sizeof(s);
    return(size);
}

int getfilesize2()
{
    int size,total;
    Password pd;
    ifstream f(f3name);
    f.seekg(0,ios::end);
    total=f.tellg();
    f.close();
    size=total/sizeof(pd);
    return(size);
}

int getfilesize3()
{
    int size,total;
    Password1 pd;
    ifstream f(f4name);
    f.seekg(0,ios::end);
    total=f.tellg();
    f.close();
    size=total/sizeof(pd);
    return(size);
}

void modifyBookRecord()
{
    Book b;
    int size=getsize();
    fstream f(fname,ios::in|ios::out|ios::ate);
    f.seekg(0);
    int id,c=0;
    cout<<"Enter id of book to be modified:";
    cin>>id;
    if(!f)
        cout<<"\nNO RECORD";
    else{
        for(int i=0;i<size;i++)
        {
            f.read((char *)&b,sizeof(b));
            if(id==b.getid())
            {
                int size=f.tellg();
                size=size-sizeof(b);
                f.seekp(size,ios::beg);
                Book b1=b;
                b1.setdata();
                b1.setstatus(b1.getstatus());
                f.write((char *)&b1,sizeof(b1));
                c=1;
                break;
            }
            cout<<"\n";
        }
    }
    f.close();
    if(c==0)
        cout<<"\nNo such record";
    else if(c==1)
        cout<<"\nRecord updated";
}
void deleteBookRecord()
{
    Book b;
    int size=getsize();
    ifstream fin(fname);
    ofstream fout("temp.dat");
    int id,c=0;
    cout<<"\nEnter id of book to be deleted:";
    cin>>id;
    if(!fin)
        cout<<"\nNO record";
    else
    {
        for(int i=0;i<size;i++)
        {
            fin.read((char *)&b,sizeof(b));
            if(id==b.getid())
            {
                c=1;
            }
            else
            {

                fout.write((char *)&b,sizeof(b));
            }
        }
    }
    fin.close();
    fout.close();
    if(c==0)
        cout<<"\nNo such record";
    else
    {

        fin.open("temp.dat");
        fout.open(fname);
        for(int i=0;i<size-1;i++)
        {
            fin.read((char *)&b,sizeof(b));
            fout.write((char *)&b,sizeof(b));
        }
        fin.close();
    fout.close();

    }
}
void dispBookRecord()
{
    Book b;
    int size=getsize();
    ifstream fin(fname);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"Book details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&b,sizeof(b));
            b.display();
            cout<<endl;
        }
    }
    fin.close();
}

void dispNotification()
{
    Notification n;
    int size=getfilesize();
    ifstream fin(f2name);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&n,sizeof(n));
            n.disp();
            cout<<endl;
        }
    }
    fin.close();
}

/*void dispStatus()
{
    Status st;
    int size=getfilesize2();
    ifstream fin(f3name);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&st,sizeof(st));
            st.disp();
            cout<<endl;
        }
    }
    fin.close();
}*/

void searchBkid()
{   int id,c=0;
    cout<<"\nenter book id to be searched:";
    cin>>id;
    Book b;
    int size=getsize();
    ifstream f(fname);
    if(!f)
        cout<<"NO";
    else {
    for(int i=0;i<size;i++)
    {
        f.read((char *)&b,sizeof(b));
        if(id==b.getid())
        {

            b.display();
            c=1;
        }
        cout<<"\n";
    }
    if(c==0)
        cout<<"\nno record";
    else {
            char ch;
    do
    {   cout<<"Enter id of book want to issue"<<endl;
        int issue;
        cin>>issue;
        Notification n;
        n.setno(rno);
        n.setidn(issue);
        n.setnotify(0);
        fstream f1(f2name,ios::out|ios::app);
        f1.write((char *)&n,sizeof(n));
        f1.close();
        cout<<"Want to issue more:Y|y?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    }
    f.close();
}

void searchBkname()
{   int c=0;
    string name;
    cout<<"\nenter book name to be searched:";
    cin>>name;
    Book b;
    int size=getsize();
    ifstream f(fname);
    if(!f)
        cout<<"NO";
    else {
    for(int i=0;i<size;i++)
    {
        f.read((char *)&b,sizeof(b));
        if(name==b.getbkname())
        {

            b.display();
            c=1;
        }
        cout<<"\n";
    }
    if(c==0)
        cout<<"\nno record";
    else {
            char ch;
    do
    {   cout<<"Enter id of book want to issue"<<endl;
    int issue;


        cin>>issue;
        Notification n;
        n.setno(rno);
        n.setidn(issue);
        n.setnotify(0);
        fstream f1(f2name,ios::out|ios::app);
        f1.write((char *)&n,sizeof(n));
        f1.close();
        cout<<"Want to issue more:Y|y?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    }
    f.close();
}
void searchAuthorName()
{   int c=0;
    string name;
    cout<<"\nenter book author name to be searched:";
    cin>>name;
    Book b;
    int size=getsize();
    ifstream f(fname);
    if(!f)
        cout<<"NO";
    else {
    for(int i=0;i<size;i++)
    {
        f.read((char *)&b,sizeof(b));
        if(name==b.getauname())
        {

            b.display();
            c=1;
        }
        cout<<"\n";
    }
    if(c==0)
        cout<<"\nno record";
    else {
            char ch;
    do
    {   cout<<"Enter id of book want to issue"<<endl;
    int issue;


        cin>>issue;
        Notification n;
        n.setno(rno);
        n.setidn(issue);
        n.setnotify(0);
        fstream f1(f2name,ios::out|ios::app);
        f1.write((char *)&n,sizeof(n));
        f1.close();
        cout<<"Want to issue more:Y|y?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    }
    f.close();
}

void searchPublication()
{   int c=0;
    string name;
    cout<<"\nenter publication of book to be searched:";
    cin>>name;
    Book b;
    int size=getsize();
    ifstream f(fname);
    if(!f)
        cout<<"NO";
    else {
    for(int i=0;i<size;i++)
    {
        f.read((char *)&b,sizeof(b));
        if(name==b.getpubl())
        {

            b.display();
            c=1;
        }
        cout<<"\n";
    }
    if(c==0)
        cout<<"\nno record";
    else {
            char ch;
    do
    {   cout<<"Enter id of book want to issue"<<endl;
        int issue;

        cin>>issue;
        Notification n;
        n.setno(rno);
        n.setidn(issue);
        n.setnotify(0);
        fstream f1(f2name,ios::out|ios::app);
        f1.write((char *)&n,sizeof(n));
        f1.close();
        cout<<"Want to issue more:Y|y?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    }
    f.close();
}

void searchBkCategory()
{   int c=0;
    string name;
    cout<<"\nenter category of book to be searched:";
    cin>>name;
    Book b;
    int size=getsize();
    ifstream f(fname);
    if(!f)
        cout<<"NO";
    else {
    for(int i=0;i<size;i++)
    {
        f.read((char *)&b,sizeof(b));
        if(name==b.getcategory())
        {

            b.display();
            c=1;
        }
        cout<<"\n";
    }
    if(c==0)
        cout<<"\nno record";
    else {
            char ch;
    do
    {   cout<<"Enter id of book want to issue"<<endl;
    int issue;


        cin>>issue;
        Notification n;
        n.setno(rno);
        n.setidn(issue);
        n.setnotify(0);
        fstream f1(f2name,ios::out|ios::app);
        f1.write((char *)&n,sizeof(n));
        f1.close();
        cout<<"Want to issue more:Y|y?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    }

    }
    f.close();
}

void issue()
{
    Book b;
    int size1=getsize();
    fstream f1(fname,ios::in|ios::out|ios::ate);
    f1.seekg(0);
    Student s;
    int size2=getfilesize1();
    fstream f2(f1name,ios::in |ios::out|ios::ate);
    f2.seekg(0);
    Notification n;
    int size3=getfilesize();
    fstream f3(f2name,ios::in|ios::out|ios::ate);
    f3.seekg(0);
    for(int k=0;k<size3;k++)
    {
        f3.read((char *)&n,sizeof(n));
        if(n.getnotify()==0){
        for(int i=0;i<size2;i++)
        {
            f2.read((char *)&s,sizeof(s));
            if(s.getenroll()==n.getno())
            {
                if(s.getcount()<=3)
                {
                    for(int m=0;m<size1;m++)
                    {
                        f1.read((char *)&b,sizeof(b));
                        if(n.getidn()==b.getid())
                        {
                            if(b.getstatus()==0)
                            {
                                int si=f2.tellg();
                                si=si-sizeof(s);
                                f2.seekp(si,ios::beg);
                                Student s1=s;
                                s1.setcount(s.getcount()+1);
                                s1.setstatus(1);
                                f2.write((char *)&s1,sizeof(s1));
                                cout<<"issued"<<endl;
                                int si1=f1.tellg();
                                si1=si1-sizeof(b);
                                f1.seekp(si1,ios::beg);
                                Book b1=b;
                                b1.setstatus(1);

                                f1.write((char *)&b1,sizeof(b1));
                            }
                            else
                            {
                                cout<<"cannot be issued"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"book not found"<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"account is full"<<endl;
                }
                break;
            }
            else
            {
                cout<<"create record"<<endl;
            }
        }
        int si3=f3.tellg();
        si3=si3-sizeof(n);
        f3.seekp(si3,ios::beg);
        Notification n1=n;
        n1.setnotify(n.getnotify()+1);
        f3.write((char *)&n1,sizeof(n1));
        }

    }
    f1.close();
    f2.close();
    f3.close();

}

void bkreturn()
{
    Book b;
    int size1=getsize();
    fstream f1(fname,ios::in|ios::out|ios::ate);
    f1.seekg(0);
    Student s;
    int size2=getfilesize1();
    fstream f2(f1name,ios::in |ios::out|ios::ate);
    f2.seekg(0);
    Notification n;
    int size3=getfilesize();
    fstream f3(f2name,ios::in|ios::out|ios::ate);
    f3.seekg(0);
    cout<<"enter id of book to be returned:"<<endl;
    int bid;
    cin>>bid;
    for(int i=0;i<size2;i++)
    {
        f2.read((char *)&s,sizeof(s));
        if(s.getenroll()==rno)
        {
            for(int j=0;j<size1;j++)
            {
                f1.read((char *)&b,sizeof(b));
                if(b.getid()==bid)
                {
                                int si=f2.tellg();
                                si=si-sizeof(s);
                                f2.seekp(si,ios::beg);
                                Student s1=s;
                                s1.setcount(s.getcount()-1);
                                s1.setstatus(0);
                                f2.write((char *)&s1,sizeof(s1));
                                cout<<"returned"<<endl;
                                int si1=f1.tellg();
                                si1=si1-sizeof(b);
                                f1.seekp(si1,ios::beg);
                                Book b1=b;
                                b1.setstatus(0);
                                f1.write((char *)&b1,sizeof(b1));

                }
            }
        }
    }
}
void createStudentRecord()
{
    Student s;
    fstream f(f1name,ios::out|ios::app);
    s.setdata();
    s.setcount(0);
    s.setstatus(0);
    f.write((char *)&s,sizeof(s));
    f.close();
}

void modifyStudentRecord()
{
    Student s;
    int size=getfilesize1();
    fstream f(f1name,ios::ate|ios::out|ios::in);
    f.seekg(0);
    int id,c=0;
    cout<<"Enter id of student to be modified:";
    cin>>id;
    if(!f)
        cout<<"\nNO RECORD";
    else{
        for(int i=0;i<size;i++)
        {
            f.read((char *)&s,sizeof(s));
            if(id==s.getenroll())
            {
                int size=f.tellg();
                size=size-sizeof(s);
                f.seekp(size,ios::beg);
                Student s1=s;
                s1.setdata();
                s1.setcount(s1.getcount());
                s1.setstatus(s1.getstatus());
                f.write((char *)&s1,sizeof(s1));
                c=1;
                break;
            }
            cout<<"\n";
        }
    }
    f.close();
    if(c==0)
        cout<<"\nNo such record";
    else if(c==1)
        cout<<"\nRecord updated";
}
void deleteStudentRecord()
{
    Student s;
    int size=getfilesize1();
    ifstream fin(f1name);
    ofstream fout("temp2.dat");
    int id,c=0;
    cout<<"\nEnter id of student to be deleted:";
    cin>>id;
    if(!fin)
        cout<<"\nNO record";
    else
    {
        for(int i=0;i<size;i++)
        {
            fin.read((char *)&s,sizeof(s));
            if(id==s.getenroll())
            {
                c=1;
            }
            else
            {

                fout.write((char *)&s,sizeof(s));
            }
        }
    }
    fin.close();
    fout.close();
    if(c==0)
        cout<<"\nNo such record";
    else
    {

        fin.open("temp2.dat");
        fout.open(f1name);
        for(int i=0;i<size-1;i++)
        {
            fin.read((char *)&s,sizeof(s));
            fout.write((char *)&s,sizeof(s));
        }
        fin.close();
    fout.close();

    }
}
void dispStudentRecord()
{
    Student s;
    int size=getfilesize1();
    ifstream fin(f1name);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"Student details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&s,sizeof(s));
            s.display();
            cout<<endl;
        }
    }
    fin.close();
}

void dispStudentStatus()
{
    Student s;
    int size=getfilesize1();
    ifstream fin(f1name);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"Student details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&s,sizeof(s));
            if(rno==s.getenroll())
            {
            s.display();
            break;
            }
            cout<<endl;
        }
    }
    fin.close();
}

void studsignup()
{
    cout<<"enter password:";
    char pwd[50];
    char pwd1[50];
    scanf("%s",pwd);
    int l,l1=0,b;
    l=strlen(pwd);
    for(int i=0;i<l;i++)
    {
        b=int(pwd[i]);
        b+=4;
        pwd1[l1++]=char(b);
    }
    pwd1[l1++]='\0';
    Password p;
    fstream f(f3name,ios::out|ios::app);
    p.setrno(rno);
    p.setpwd(pwd1,l);
    f.write((char *)&p,sizeof(p));
    f.close();

}

int studlogin()
{
    cout<<"enter password:";
    char pwd[50];
    char pwd1[50],temp[50];
    scanf("%s",pwd);
    int l,l1=0,b,c=0;
    l=strlen(pwd);
    Password p;
    int size=getfilesize2();
    ifstream f(f3name);
    if(!f)
        cout<<"NO";
    else
    {
        for(int i=0;i<size;i++)
        {
            f.read((char *)&p,sizeof(p));
            if(rno==p.getenroll())
            {
                strcpy(pwd1,p.getpwd());
                for(int j=0;j<l;j++)
                {
                    b=int(pwd[j]);
                    b+=4;
                    temp[l1++]=char(b);
                }
                temp[l1++]='\0';
                if(strcmp(temp,pwd1)==0)
                {
                    cout<<"login successfully"<<endl;
                    c=1;
                }
                else
                {
                    cout<<"enter correct pwd"<<endl;
                }
            }
        }
    }
    f.close();
    return c;
}

void dispStudentPwd()
{
    Password p;
    int size=getfilesize2();
    ifstream fin(f3name);
    if(!fin)
        cout<<"\nNO";
    else
    {
        cout<<"Student details\n";
        for(int i=0;i<size;i++)
        {

            fin.read((char *)&p,sizeof(p));
            p.display();
            cout<<endl;
        }
    }
    fin.close();
}

void adminsignup()
{
    char un[50],pwd[50],pwd1[50];
    cout<<"enter username:"<<endl;
    scanf("%s",un);
    cout<<"enter password:"<<endl;
    scanf("%s",pwd);
    int u,l,l1=0,b;
    u=strlen(un);
    l=strlen(pwd);
    for(int i=0;i<l;i++)
    {
        b=(int)pwd[i];
        b+=4;
        pwd1[l1++]=(char)b;
    }
    pwd1[l1++]='\0';
    Password1 p;
    fstream f(f4name,ios::out|ios::app);
    p.setuname(un,u);
    p.setpwd(pwd1,l);
    f.write((char *)&p,sizeof(p));
    f.close();

}

int adminlogin()
{
        char un[50],pwd[50],pwd1[50],temp[50];
        cout<<"enter username:"<<endl;
        scanf("%s",un);
        cout<<"enter password"<<endl;
        scanf("%s",pwd);
        int u,l,b,l1=0,c=0;
        u=strlen(un);
        l=strlen(pwd);
        Password1 p;
        int size=getfilesize3();
        ifstream f(f4name);
        if(!f)
        cout<<"NO";
        else
        {
            for(int i=0;i<size;i++)
            {
                f.read((char *)&p,sizeof(p));
                if(strcmp(un,p.getuname())==0)
                {
                    strcpy(pwd1,p.getpwd());
                    for(int j=0;j<l;j++)
                    {
                    b=int(pwd[j]);
                    b+=4;
                    temp[l1++]=char(b);
                    }
                    temp[l1++]='\0';
                    if(strcmp(temp,pwd1)==0)
                    {
                        cout<<"login successful"<<endl;
                        c=1;
                    }
                    else{
                        cout<<"enter correct pwd"<<endl;
                    }
                }
            }
        }
    f.close();
    return c;
}

void dispAdminPwd()
{
    Password1 p;
    int size=getfilesize3();
    ifstream fin(f4name);
    if(!fin)
        cout<<"\nNO";
    else
    {

        for(int i=0;i<size;i++)
        {

            fin.read((char *)&p,sizeof(p));
            p.display();
            cout<<endl;
        }
    }
    fin.close();
}

void loginasstudent()
{   int ch1,a;
    do
    {
        cout<<"1 NEW USER? SIGN UP:"<<endl;
        cout<<"2 LOGIN:"<<endl;
        cout<<"3 EXIT"<<endl;
        cout<<"ENTER CHOICE"<<endl;

        cin>>ch1;
        switch(ch1)
        {
        case 1:
            studsignup();
            stud2();
            break;
        case 2:
             a=studlogin();
            if(a==1)
            {
                stud2();
            }

            break;
            case 3:
                exit(0);
                break;
        }

    }while(ch1<=3);
}

void stud2()
{   int ch2,ch3;
        do
        {
            cout<<"1 SEARCH BOOK"<<endl;
            cout<<"2 RETURN BOOK"<<endl;
            cout<<"3 BACK"<<endl;
            cout<<"ENTER YOUR CHOICE"<<endl;

            cin>>ch2;
            switch(ch2)
            {
            case 1:
                    do
                    {
                        cout<<"1 SEARCH BY BOOK ID"<<endl;
                        cout<<"2 SEARCH BY BOOK NAME"<<endl;
                        cout<<"3 SEARCH BY AUTHOR NAME"<<endl;
                        cout<<"4 SEARCH BY BOOK CATEGORY"<<endl;
                        cout<<"5 SEARCH BY PUBLICATION"<<endl;
                        cout<<"6 BACK"<<endl;
                        cout<<"ENTER YOUR CHOICE"<<endl;

                        cin>>ch3;
                        switch(ch3)
                        {
                        case 1:
                            searchBkid();
                            break;
                            case 2:
                                searchBkname();
                                break;
                            case 3:
                                searchAuthorName();
                                break;
                            case 4:
                                searchBkCategory();
                                break;
                            case 5:
                                searchPublication();
                                break;
                            case 6:
                                stud2();
                                break;

                        }
                    }while(ch3<=6);
                break;
                case 2:

                    bkreturn();

                    break;
                case 3:

                    loginasstudent();

                    break;
            }

        }while(ch2<=3);
}

void loginasadmin()
{   int ch4,b;
    do
    {
        cout<<"1 SIGN UP:"<<endl;
        cout<<"2 LOGIN:"<<endl;
        cout<<"3 EXIT"<<endl;
        cout<<"ENTER CHOICE"<<endl;

        cin>>ch4;
        switch(ch4)
        {
        case 1:
            adminsignup();
            admin2();
            break;
        case 2:
            b=adminlogin();
            if(b==1)
            {
                admin2();
            }

            break;
            case 3:
                exit(0);
                break;
        }

    }while(ch4<=3);
}

void admin2()
{   int ch5,ch6,ch7;
    do
    {
        cout<<"1 BOOK FILE SYSTEM"<<endl;
        cout<<"2 STUDENT FILE SYSTEM"<<endl;
        cout<<"3 BACK"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;

        cin>>ch5;
        switch(ch5)
        {
        case 1:
                do{
                        cout<<"1 CREATE RECORD"<<endl;
                        cout<<"2 UPDATE RECORD"<<endl;
                        cout<<"3 DELETE RECORD"<<endl;
                        cout<<"4 VIEW ALL RECORDS"<<endl;
                        cout<<"5 ISSUE BOOK"<<endl;
                        cout<<"6 BACK"<<endl;
                        cout<<"ENTER YOUR CHOICE"<<endl;

                        cin>>ch6;
                        switch(ch6)
                        {
                        case 1:
                            createBookRecord();
                            break;
                        case 2:
                            modifyBookRecord();
                            break;
                        case 3:
                            deleteBookRecord();
                            break;
                        case 4:
                            dispBookRecord();
                            break;
                        case 5:
                            issue();
                            break;
                        case 6:
                            admin2();
                            break;

                        }
                }while(ch6<=6);

            break;
        case 2:
            do{
                        cout<<"1 CREATE RECORD"<<endl;
                        cout<<"2 UPDATE RECORD"<<endl;
                        cout<<"3 DELETE RECORD"<<endl;
                        cout<<"4 VIEW ALL RECORDS"<<endl;
                        cout<<"5 BACK"<<endl;
                        cout<<"ENTER YOUR CHOICE"<<endl;

                        cin>>ch7;
                        switch(ch7)
                        {
                        case 1:
                            createStudentRecord();
                            break;
                        case 2:
                            modifyStudentRecord();
                            break;
                        case 3:
                            deleteStudentRecord();
                            break;
                        case 4:
                            dispStudentRecord();
                            break;
                        case 5:
                            admin2();
                            break;

                        }
                }while(ch7<=5);


            break;
        case 3:
            loginasadmin();
            break;
        }

    }while(ch5<=3);
}
int main()
{   int ch;
    do
    {
        cout<<"--LIBRARY MANAGEMENT SYSTEM--"<<endl;
        cout<<"1 LOGIN AS ADMIN"<<endl;
        cout<<"2 LOGIN AS STUDENT"<<endl;
        cout<<"ENTER CHOICE"<<endl;

        cin>>ch;
        switch(ch)
        {
        case 1://login as admin

            loginasadmin();
            break;
        case 2: //login as student
            cout<<"ENTER ENROLLMENT:"<<endl;
            cin>>rno;
            loginasstudent();

            break;
        case 3:
            exit(0);

        }

    }while(ch<=3);//end of main switch while

    return 0;
}
