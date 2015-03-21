#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>           //����Աֻ��һ��
#include<string>
#define M 12              //һ���꼶12���༶
#define N 60             //�༶����
using namespace std;
string allclasses[N]={"0","1��.txt","2��.txt","3��.txt","4��.txt","5��.txt","6��.txt","7��.txt","8��.txt","9��.txt","10��.txt"};
class Administrator
{
         private:
            string username;
            string cipher;
         public:
            void addnewclass(int n);
            int show();
            void deleteclass(int n);              //ɾ���༶
            int changecipher();                  //fun1  fun2 ֻҪ��Ԫ��Student
            string getcipher(){
                   return cipher;  }
            string getusername(){
                   return username; }
            friend ostream&operator <<(ostream&,const Administrator&);
            friend istream&operator >>(istream&,Administrator&);
};
ostream&operator <<(ostream& output,const Administrator& s)
{
    output<<s.username<<s.cipher;
    return output;
}

istream&operator>>(istream& input,Administrator& s)
{
    input>>s.username>>s.cipher;
    return input;
}



class Student
{
      private:
          int rank;
          int classnumber;
          double chinese,math,english;
          double average;
          double sum;
          string name;
          string number;
          string cipher;
          string sex;                   //��ʼ����Ĭ��Ϊѧ�ţ�����ѧ�����Ը�����
      public:
          Student()
          {
              name="0",cipher="0000",sex="0",number="0";
              rank=0,classnumber=0;
              chinese=0,math=0,english=0;
              sum=0,average=0;
          }
          Student(int n,string name1,string number1,string sex1):     //������캯��
          classnumber(n),name(name1),number(number1),sex(sex1)
          {
              rank=0;                               //�ļ���ѧ���������ܷ���
              cipher="0000";
              chinese=0,math=0,english=0;
              sum=0,average=0;
          };
          void set_stu();
          void set_gra();
          void set_class(int n);
          string getcipher(){
               return cipher;  };
          string getnumber(){
               return number;  };
          int changecipher();
          friend void display(Student& stu);
          friend void fun1(Student& a);
          friend void fun2(Student a[],int s);
          friend void Administrator::addnewclass(int n);
          friend void bubblesort1(Student sq[ ],int length);
          friend void bubblesort2(Student sq[ ],int length);
          friend void bubblesort3(Student sq[ ],int length);
          friend void bubblesort4(Student sq[ ],int length);
          friend void add(int n);
          friend ostream&operator <<(ostream&,const Student&);
          friend istream&operator >>(istream&,Student&);
};

ostream&operator <<(ostream& output,const Student& s)
{
    output<<s.name<<"   "<<s.number<<"   "<<s.classnumber<<"    "<<s.sex<<"   "<<s.chinese
    <<"   "<<s.math<<"   "<<s.english<<"   "<<s.sum<<"    "<<s.average<<"    "<<s.rank<<"    "<<s.cipher<<endl;
    return output;
}
istream&operator >>(istream& input,Student& s)
{
    input>>s.name>>s.number>>s.classnumber>>s.sex>>s.chinese>>s.math>>s.english>>s.sum>>s.average>>s.rank>>s.cipher;
    return input;
}

void Student::set_stu()
{
    cout<<"�ֱ�����ѧ��������ѧ�ţ��Ա�"<<endl;
    cin>>name>>number>>sex;
    cout<<endl;
}
void Student::set_class(int n)
{
    classnumber=n;
}
void Student::set_gra()
{
    cout<<"���������Ӧѧ���ɼ�"<<setw(5)<<"����"<<setw(5)<<"��ѧ"<<setw(5)<<"Ӣ��" <<endl;
    cin>>chinese>>math>>english;
    sum=chinese+math+english;
    average=sum/3;
    cout<<endl;
}
class Teacher
{
      private:
            int classnum;
            string name;
            string usernum;     //ʹ���˺�
            string cipher;
      public:
             Teacher()
             {
                 classnum=0;
                 name="0",usernum="0",cipher="0000";
             }
             Teacher(string a,string b,int n)
             {
                 name=a;
                 usernum=b;
                 cipher="0000";
                 classnum=n;
             }
             int tea_play();     //��ʦ��½��������棬��ʾ�༶�ţ� ������ִ�в���ѡ��
             int changecipher();
             string getcipher(){
                    return cipher;  }
             string getusernum(){
                    return usernum;  }
             int getclassnum(){
                    return classnum; }
             friend ostream&operator <<(ostream&,const Teacher&);
             friend istream&operator >>(istream&,Teacher&);
};

ostream&operator <<(ostream& output,const Teacher& s)
{
    output<<s.name<<"   "<<s.usernum<<"    "<<s.classnum<<"     "<<s.cipher<<endl;
    return output;
}

istream&operator>>(istream& input,Teacher& s)
{
    input>>s.name>>s.usernum>>s.classnum>>s.cipher;
    return input;
}

void add(int n)            //n�ǰ༶��
{
    fstream file;
    file.open(allclasses[n].c_str(),ios_base::in);
    Student s,a[N];
    int k=1;
    while(!file.eof())
    {
        file>>a[k];
        k++;               //k �ü�ȥ 2
    k-=2;
    file.close();
    cout<<"�Ƿ�������ѧ����Ϣ��     ���밴1         ����0�˳�"<<endl;
    int x;
    cin>>x;
    while(x)
    {
        k++;
        a[k].set_stu();
        a[k].set_gra();
        a[k].set_class(n);
        cout<<endl<<"�Ƿ�������ѧ����Ϣ��           ���밴1    ����0�˳�"<<endl;
        cin>>x;
    }
    bubblesort1(a,k);
    fstream file2;
    file2.open(allclasses[n].c_str(),ios_base::out);
    for(int i=1;i<=k;i++)
    {
        a[i].rank=i;
        file2<<a[i];
    }
    file2.close();
}

int Administrator::show()
{
    cout<<"����Ա��"<<username<<endl;
    cout<<"��ѯ�༶����ѧ����Ϣ���ɼ������밴1"<<endl;
    cout<<"��ѯ��һѧ����Ϣ�����밴2"<<endl;
    cout<<"�޸�ѧ����Ϣ�����밴3"<<endl;
    cout<<"���ѧ����Ϣ�����밴4"<<endl;
    cout<<"�����°༶��Ϣ�����밴5"<<endl;
    cout<<"ɾ���༶�����밴6"<<endl;
    cout<<"�޸ĵ�¼���롪���밴7"<<endl;
    cout<<"�˳�ϵͳ�����밴8"<<endl;
    int x;
    cin>>x;
    return x;
}


int Teacher::tea_play()
{
    cout<<endl;
    cout<<"��ʦ��"<<name<<"               ��ţ�"<<usernum<<"            �ν̰༶��"<<classnum<<"��";
    cout<<endl<<endl;
    cout<<"�ð�����ѧ���ɼ������밴1"<<endl;
    cout<<"��ѯ��һѧ����Ϣ�����밴2"<<endl;
    cout<<"�޸�ѧ����Ϣ�����밴3"<<endl;
    cout<<"�޸ĵ�¼���롪���밴4"<<endl;
    cout<<"ȡ��-��ִ���κβ��������밴5"<<endl;
    int x;
    cin>>x;
    return x;
}


void Administrator::addnewclass(int n)   //n�ǰ༶�ţ��˺����ɵ���һ���༶��ѧ����Ϣ
{
         cout<<"��������ð༶�������� ";
         int p;
         cin>>p;
         Student s[N];
         for(int i=1;i<=p;i++)
         {
             s[i].set_stu();
             s[i].set_class(n);
         }
         cout<<"�����������������";
         string t,c;
         cin>>t;
         cout<<"������˽�ʦ��ţ�";
         cin>>c;
         Teacher tea(t,c,n);
         ofstream out;
         out.open("��ʦ����.txt",ios_base::app);
         out<<tea;
         out.close();
         cout<<"�Ƿ��������ѧ���ɼ�?"<<endl<<"��ӳɼ��밴1          �����밴0"<<endl;
         int j;
         cin>>j;
         switch(j)
         {
             case 0:
                    {
                        ofstream file;
                        file.open(allclasses[n].c_str(),ios_base::out);
                        for(int i=1;i<=p;i++)
                           file<<s[i];
                        file.close();
                        break;
                    }
             case 1:
                    {
                      for(int i=1;i<=p;i++)
                      {
                          cout<<setw(5)<<s[i].name<<"        ";
                          s[i].set_gra();
                      }
                      bubblesort1(s,p);
                      for(int i=1;i<=p;i++)
                           s[i].rank=i;
                      ofstream file;
                      file.open(allclasses[n].c_str(),ios_base::out);
                      for(int i=1;i<=p;i++)
                            file<<s[i];
                       file.close();
                    }
         }
         cout<<n<<"�༶��Ϣ����ɹ���"<<endl;
         return;
}

void bubblesort1(Student sq[ ],int length)               //�ܷ�����
{
    int i,j;
    Student temp;
    int exchanged=1;
    for(i=1;i<=length&&exchanged;i++)
    {
       exchanged=0;
       for(j=1;j<=length-i;j++)
           if(sq[j].average<sq[j+1].average)
           {
               temp=sq[j];
               sq[j]=sq[j+1];
               sq[j+1]=temp;
               exchanged=1;
            }
    }
    for(i=1;i<=length;i++)
        sq[i].rank=i;                  //ֻ���ܷ������浽�ļ���ȥ
}
void bubblesort2(Student sq[ ],int length)
{
    int i,j;
    Student temp;
    int exchanged=1;
    for(i=1;i<=length&&exchanged;i++)
    {
       exchanged=0;
       for(j=1;j<=length-i;j++)
           if(sq[j].chinese<sq[j+1].chinese)
           {
               temp=sq[j];
               sq[j]=sq[j+1];
               sq[j+1]=temp;
               exchanged=1;
            }
    }
}
void bubblesort3(Student sq[ ],int length)
{
    int i,j;
    Student temp;
    int exchanged=1;
    for(i=1;i<=length&&exchanged;i++)
    {
       exchanged=0;
       for(j=1;j<=length-i;j++)
           if(sq[j].math<sq[j+1].math)
           {
               temp=sq[j];
               sq[j]=sq[j+1];
               sq[j+1]=temp;
               exchanged=1;
            }
    }
}
void bubblesort4(Student sq[ ],int length)              //���ܷ�����
{
    int i,j;
    Student temp;
    int exchanged=1;
    for(i=1;i<=length&&exchanged;i++)
    {
       exchanged=0;
       for(j=1;j<=length-i;j++)
           if(sq[j].english<sq[j+1].english)
           {
               temp=sq[j];
               sq[j]=sq[j+1];
               sq[j+1]=temp;
               exchanged=1;
            }
    }
}

//�ⲿ����friend��������Student���βΣ�Ҫ�Ĵ��� ��main������д������ �ٴ�����
void fun1(Student& a)         //�޸�ѧ��������Ϣ  �����ɼ�  ��󱣴浽�ļ���
  {
        cout<<a.classnumber<<"��      ѧ����"<<a.name<<"       ѧ�ţ�"<<a.number<<"       "<<a.sex
        <<"       ���ģ�"<<a.chinese<<"         ��ѧ��"<<a.math<<"        Ӣ�"<<a.english<<"       �ܷ�"
        <<a.sum<<"       ���ž��֣�"<<a.average<<"      �༶���Σ�"<<a.rank<<endl;
        cout<<"����������Ҫ�ĵ�ѧ������  ѧ��  �Ա�   ���ĳɼ�   ��ѧ�ɼ�     Ӣ��ɼ�"<<endl;
        string s1,s2,s3;
        double x,y,z;
        cin>>s1>>s2>>s3>>x>>y>>z;
        a.name=s1;      a.number=s2;      a.sex=s3;
        a.chinese=x;         a.math=y;           a.english=z;
        a.sum=x+y+z;         a.average=a.sum/3;
        cout<<endl<<"ѧ����Ϣ�޸ĳɹ�"<<endl;
  }
void fun2(Student a[],int s)
{
    int i=1;
    cout<<"�༶��"<<a[1].classnumber<<endl;
    cout<<setw(4)<<"����"<<setw(5)<<"ѧ��"<<setw(7)<<"����"<<setw(7)<<"�Ա�"<<setw(7)<<"����"
    <<setw(7)<<"��ѧ"<<setw(7)<<"Ӣ��"<<setw(7)<<"�ܷ�"<<setw(7)<<"����";
    for(;i<=s;i++)
    {
        cout<<endl;
        cout<<setw(4)<<a[i].rank<<setw(5)<<a[i].number<<setw(7)<<a[i].name<<setw(7)<<a[i].sex<<setw(7)<<a[i].chinese
        <<setw(7)<<a[i].math<<setw(7)<<a[i].english<<setw(7)<<a[i].sum<<setw(7)<<setprecision(4)<<a[i].average;
    }
    cout<<endl<<endl;
    cout<<"��������������������1"<<endl;
    cout<<"�鿴�������ĳɼ���������������2"<<endl;
    cout<<"�鿴������ѧ�ɼ���������������3"<<endl;
    cout<<"�鿴����Ӣ��ɼ���������������4"<<endl;
    cout<<"�˳�������������0"<<endl;
    int x;
    cin>>x;
    while(x!=0)
    {
        switch(x)
        {
        case 1:
                 bubblesort1(a,s);
                 break;
        case 2:
                 bubblesort2(a,s);
                 break;
        case 3:
                 bubblesort3(a,s);
                 break;
        case 4:
                 bubblesort4(a,s);
                 break;
        default:  break;
        }
        i=1;
       cout<<"�༶��"<<a[1].classnumber<<endl;
       cout<<setw(5)<<"����"<<setw(5)<<"ѧ��"<<setw(7)<<"����"<<setw(7)<<"�Ա�"<<setw(7)<<"����"
       <<setw(7)<<"��ѧ"<<setw(7)<<"Ӣ��"<<setw(7)<<"�ܷ�"<<setw(7)<<"����";
       for(;i<=s;i++)
       {
           cout<<endl;
           cout<<setw(5)<<i<<setw(5)<<a[i].number<<setw(7)<<a[i].name<<setw(7)<<a[i].sex<<setw(7)<<a[i].chinese
          <<setw(7)<<a[i].math<<setw(7)<<a[i].english<<setw(7)<<a[i].sum<<setw(7)<<setprecision(4)<<a[i].average;
       }
       cout<<endl<<"��������                                         ���ء�������0";
       cout<<endl<<"��������������������1"<<endl;
       cout<<"�鿴�������ĳɼ���������������2"<<endl;
       cout<<"�鿴������ѧ�ɼ���������������3"<<endl;
       cout<<"�鿴����Ӣ��ɼ���������������4"<<endl;
       cin>>x;
    }
    return;
}

void display(Student& stu)           //�鿴���� a��ѧ��   n�ǰ༶��
{
    cout<<endl<<"ѧ����"<<stu.name<<"     �༶��"<<stu.classnumber<<"       ѧ�ţ�"<<stu.number<<"     �Ա�"<<stu.sex
    <<endl<<"���ģ�"<<stu.chinese<<"      ��ѧ��"<<stu.math<<"       Ӣ�"<<stu.english<<"      �����ܷ֣�"<<stu.sum<<
    "      ���֣�"<<stu.average<<"    ���Σ�"<<stu.rank<<endl<<endl;
}


int Student::changecipher()
{
     cout<<"����������룺"<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"�����������룺";
        cin>>b;
        cout<<"���ٴγ������룺";
        cin>>c;
        while(b!=c)
        {
             cout<<"�������벻һ�� ���������룺";
             cin>>b;
             cout<<"���ٴ����룺";
             cin>>c;
        }
        cipher=b;
        cout<<"�����޸ĳɹ�"<<endl;
        return 0;
     }
     else
         cout<<"����������󣬲����޸�"<<endl;
     return 0;
}
 int Teacher::changecipher()
{
     cout<<"����������룺"<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"�����������룺";
        cin>>b;
        cout<<"���ٴγ������룺";
        cin>>c;
        while(b!=c)
        {
             cout<<"�������벻һ�� ���������룺";
             cin>>b;
             cout<<"���ٴ����룺";
             cin>>c;
        }
        cipher=b;
        cout<<"�����޸ĳɹ�"<<endl;
        return 0;
     }
     else
         cout<<"����������󣬲����޸�"<<endl;
     return 0;
}
int Administrator::changecipher()
{
     cout<<"������������룺"<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"�����������룺";
        cin>>b;
        cout<<"���ٴγ������룺";
        cin>>c;
        while(b!=c)
        {
             cout<<"�������벻һ�� ���������룺";
             cin>>b;
             cout<<"���ٴ����룺";
             cin>>c;
        }
        cipher=b;
        cout<<"�����޸ĳɹ�"<<endl;
        return 0;
     }
     else
         cout<<"����������󣬲����޸�"<<endl;
     return 0;
}



int main()
{
    cout<<"                       ����꼶�ɼ���ѯϵͳ"<<endl;
    cout<<"                             �û�ѡ��"<<endl<<"ѧ���밴(1)            ��ʦ�밴(2)         ����Ա�밴(3)"<<endl;
    int x;
    string holy="yes";
    while(cin>>x)
    {
        if(x!=1&&x!=2&&x!=3)
            {       cout<<"�����������ٴΰ���"<<endl;       continue;      }
        else
            break;
    }
    switch(x)
    {
       case 1:                       //ѧ��ֻ�ܿ��Լ��ĳɼ��ͻ�����Ϣ  �������޸ĵ�¼����
             {
               cout<<"��ѧ���û���                    �����������ڰ༶�ţ� ";
               int n;
               cin>>n;
               cout<<"�û�����ѧ�ţ���";
               string a,b;
               cin>>a;
               cout<<"��½���룺";
               cin>>b;
               fstream file;
               file.open(allclasses[n].c_str(),ios_base::in);
               Student temp[N];
               int i,judge;
               i=1;
               judge=0;
               while(!file.eof())
               {
                     file>>temp[i];
                     if(temp[i].getnumber()==a)
                        judge=i;
                     i++;
               }
               i-=2;
               file.close();
               if(judge==0)
                    cout<<"�û�������      �����µ�¼"<<endl;
               else if(judge!=0&&temp[judge].getcipher()!=b)
                    cout<<"�����������    �����µ�½"<<endl;
               else if(judge!=0&&temp[judge].getcipher()==b)
                {
                    display(temp[judge]);
                    cout<<"�޸������밴1                    �����밴0"<<endl;
                    int h;
                    cin>>h;
                    if(h==0)
                       break;
                    else if(h==1)
                    {
                        temp[judge].changecipher();
                        ofstream out;
                        out.open(allclasses[n].c_str(),ios_base::out);
                        for(int k=1;k<=i;k++)
                            out<<temp[k];
                    }
                  }
                break;
                }
        case 2:
           {
               cout<<"����ʦ�û���                      �û�������ʦ���룩��";
               string c,d;
               cin>>c;
               cout<<"��¼���룺";
               cin>>d;
               ifstream in("��ʦ����.txt");
               Teacher tea[M];
               int k=1,judge2=0;
               while(!in.eof())
               {
                   in>>tea[k];
                   if(tea[k].getusernum()==c)
                       judge2=k;
                   k++;
               }
               k=k-2;                //k:��ʦ������
               in.close();
               if(judge2==0)
                    cout<<"�û���������   �����µ�¼";
               else if(judge2!=0&&tea[judge2].getcipher()!=d)
                    cout<<"�û������������   �����µ�¼��";
                else if(judge2!=0&&tea[judge2].getcipher()==d)
                {
                     int q,t=1;
                     Student a[N];
                     ifstream fp(allclasses[tea[judge2].getclassnum()].c_str());
                     while(!fp.eof())
                     {
                         fp>>a[t];           //t������������������ֻ�ǹ���ʱ�鿴�����棬Ĭ��ѧ�������������������ܷ֣�
                         t++;
                     }
                     t-=2;
                     fp.close();
                     while(holy=="yes")
                     {
                     q=tea[judge2].tea_play();       //���ص�q�Ǵ�������ѡ��
                     switch(q)
                     {
                         case 1:
                                 fun2(a,t);
                                 break;
                         case 2:
                          {
                                 cout<<"�������ѧ��ѧ�ţ�";
                                 string g;
                                 cin>>g;
                                 int tp,final;
                                 while(g!="0")
                                 {
                                       final=0;
                                       for(tp=1;tp<=t;tp++)
                                           if(a[tp].getnumber()==g)
                                           {
                                               final=tp;
                                               break;
                                           }
                                           else
                                                continue;
                                       if(final==0)
                                            cout<<"�ð಻����ѧ��Ϊ"<<g<<"��ѧ��"<<endl;
                                       else
                                            display(a[tp]);
                                       cout<<endl<<"�����鿴ѧ����������������ѧ��                    ���ء��������밴0";
                                       cout<<endl;
                                       cin>>g;
                                   }
                                 break;
                            }
                           case 3:
                           {
                                  cout<<"������޸�ѧ��ѧ�ţ�";
                                  string g;
                                  cin>>g;
                                  int tp,final;
                                  while(g!="0")
                                  {
                                        final=0;
                                        for(tp=1;tp<=t;tp++)
                                           if(a[tp].getnumber()==g)
                                           {
                                                 final=tp;
                                                 break;
                                            }
                                           else
                                              continue;
                                         if(final==0)
                                             cout<<"�ð಻����ѧ��Ϊ"<<g<<"��ѧ��"<<endl;
                                         else
                                             fun1(a[tp]);
                                         cout<<endl<<"�����޸�ѧ����Ϣ��������ѧ��";
                                         cout<<endl<<"���ء�����������0"<<endl;
                                         cin>>g;
                                  }
                                  bubblesort1(a,t);                   //����ѧ���ɼ������� Ҫ���´�һ�� ����
                                  fstream file2;
                                  file2.open(allclasses[tea[judge2].getclassnum()].c_str(),ios_base::out);
                                  for(int ip=1;ip<=t;ip++)
                                       file2<<a[ip];
                                  file2.close();
                                  break;
                              }
                            case 4:
                            {
                                    tea[judge2].changecipher();
                                    fstream ff;
                                    ff.open("��ʦ����.txt",ios_base::out);
                                    for(int y=1;y<=k;y++)
                                          ff<<tea[y];
                                     ff.close();
                                     break;
                            }
                            case 5:
                            default:
                                      break;
                        }
                        cout<<endl<<"�����ϲ�Ŀ¼����yes         �˳�ϵͳ���� no"<<endl;
                        cin>>holy;
                        }
                    }
               break;
               }
             case 3:
             {
                    cout<<"������Ա��                               ��¼�˺�����";
                    string y,z;
                    cin>>y;
                    Administrator A;
                    ifstream in3("����Ա.txt");
                    in3>>A;
                    in3.close();
                    cout<<"�����¼���룺";
                    cin>>z;
                    cout<<endl;
                    if(A.getusername()!=y)
                         cout<<"�û������� �޷����룡";
                    else if(A.getusername()==y&&A.getcipher()!=z)
                          cout<<"�û������������   �޷���½��";
                    else if(A.getusername()==y&&A.getcipher()==z)
                      {
                         while(holy=="yes")
                         {
                           int r=A.show();
                           Student vb[N];
                           int bjh,v=1,final=0;
                           string xh;
                           switch(r)
                           {
                               case 1:
                               {
                                    v=1;
                                    cout<<"������鿴�༶�ţ�";
                                    cin>>bjh;
                                    ifstream file3(allclasses[bjh].c_str());
                                    while(!file3.eof())
                                    {
                                        file3>>vb[v];
                                        v++;                             //v��������
                                    }
                                    v-=2;
                                    file3.close();
                                    fun2(vb,v);
                                    break;
                               }
                              case 2:
                              {
                                      v=1;
                                      cout<<"�������ڰ༶�ţ�";
                                      cin>>bjh;
                                      cout<<"�������ѧ��ѧ�ţ�";
                                      cin>>xh;
                                      ifstream f4(allclasses[bjh].c_str());
                                      while(!f4.eof())
                                      {
                                          f4>>vb[v];
                                          v++;
                                      }
                                      v-=2;
                                      f4.close();
                                      while(xh!="0")
                                      {
                                          final=0;
                                          for(int b=1;b<=v;b++)
                                               if(vb[b].getnumber()==xh)
                                                {
                                                    final=b;
                                                    break;
                                                }
                                                else
                                                   continue;
                                          if(final==0)
                                              cout<<"�ð಻����ѧ��Ϊ"<<xh<<"��ѧ�� "<<endl;
                                          else
                                              display(vb[final]);
                                          cout<<endl<<"�����鿴�ð�ѧ����������������ѧ��";
                                          cout<<endl<<"���ء��������밴0"<<endl;
                                          cin>>xh;
                                      }
                                      break;
                              }
                              case 3:
                              {
                                       v=1;
                                       cout<<"����ѧ�����ڰ༶�ţ�";
                                       cin>>bjh;
                                       cout<<"�����޸�ѧ��ѧ�ţ�";
                                       cin>>xh;
                                       ifstream f5(allclasses[bjh].c_str());
                                       while(!f5.eof())
                                       {
                                          f5>>vb[v];
                                          v++;
                                       }
                                       v-=2;
                                       f5.close();
                                       while(xh!="0")
                                       {
                                          final=0;
                                          for(int b=1;b<=v;b++)
                                           {
                                               if(vb[b].getnumber()==xh)
                                                {
                                                    final=b;
                                                    break;
                                                }
                                                else
                                                   continue;
                                           }
                                           if(final==0)
                                                cout<<"�ð಻����ѧ��Ϊ"<<xh<<"��ѧ�� "<<endl;
                                          else
                                                fun1(vb[final]);
                                           cout<<"�����޸�ѧ����Ϣ��������ѧ��";
                                           cout<<endl<<"���ء�����������0"<<endl;
                                           cin>>xh;
                                        }
                                        bubblesort1(vb,v);
                                        fstream f6;
                                        f6.open(allclasses[bjh].c_str(),ios_base::out);
                                        for(int pp=1;pp<=v;pp++)
                                            f6<<vb[pp];
                                        f6.close();
                                        break;
                                }
                                case 4:
                                {
                                        cout<<"��������ѧ�����ڰ༶�ţ�";
                                        int hh;
                                        cin>>hh;
                                        add(hh);
                                        break;
                                }
                                case 5:
                                {
                                         cout<<"����°༶�������������������°༶�ţ�";
                                         int bb;
                                         cin>>bb;
                                         A.addnewclass(bb);
                                         break;
                                }
                                case 6:
                                {
                                         cout<<"������Ҫɾ���İ༶�ţ�";
                                         int del;
                                         cin>>del;
                                         while(del)
                                         {
                                             fstream out6,tch;
                                             out6.open(allclasses[del].c_str(),ios_base::out);
                                             out6.close();
                                             tch.open("��ʦ����.txt",ios_base::in);
                                             Teacher t[M];
                                             int hu=1,come;
                                             while(!tch.eof())
                                            {
                                                tch>>t[hu];
                                                if(t[hu].getclassnum()==del)
                                                     come=hu;
                                                hu++;             //hu���ɽ�ʦ������
                                            }
                                            tch.close();
                                            hu-=3;                  //��ȥһ����ʦ���������
                                            for(int y=come;y<=hu;y++)
                                                 t[y]=t[y+1];
                                            tch.open("��ʦ����.txt",ios_base::out);
                                            for(int y=1;y<=hu;y++)
                                                 tch<<t[y];
                                             tch.close();
                                             cout<<endl<<"�ð༶��ɾ��"<<endl;
                                             cout<<"����ɾ���༶������༶�ţ�           ����0�˳�"<<endl;
                                             cin>>del;
                                         }
                                         break;
                                 }
                                case 7:
                                {
                                         A.changecipher();
                                         ofstream out7("����Ա.txt");
                                         out7<<A;
                                         out7.close();
                                         break;
                                }
                                case 8:
                                        cout<<"�˳���";
                                        break;
                          }
                          cout<<endl<<"�����ϲ�Ŀ¼������ yes       �˳������� no"<<endl;
                          cin>>holy;
                          }
                      }
        break;
        }
       }
       system("pause");
       return 0;
}


