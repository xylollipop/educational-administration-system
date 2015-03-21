#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>           //管理员只有一个
#include<string>
#define M 12              //一个年级12个班级
#define N 60             //班级人数
using namespace std;
string allclasses[N]={"0","1班.txt","2班.txt","3班.txt","4班.txt","5班.txt","6班.txt","7班.txt","8班.txt","9班.txt","10班.txt"};
class Administrator
{
         private:
            string username;
            string cipher;
         public:
            void addnewclass(int n);
            int show();
            void deleteclass(int n);              //删除班级
            int changecipher();                  //fun1  fun2 只要友元给Student
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
          string sex;                   //初始密码默认为学号，后期学生可以改密码
      public:
          Student()
          {
              name="0",cipher="0000",sex="0",number="0";
              rank=0,classnumber=0;
              chinese=0,math=0,english=0;
              sum=0,average=0;
          }
          Student(int n,string name1,string number1,string sex1):     //多个构造函数
          classnumber(n),name(name1),number(number1),sex(sex1)
          {
              rank=0;                               //文件中学生排名按总分排
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
    cout<<"分别输入学生姓名，学号，性别："<<endl;
    cin>>name>>number>>sex;
    cout<<endl;
}
void Student::set_class(int n)
{
    classnumber=n;
}
void Student::set_gra()
{
    cout<<"依次输入对应学生成绩"<<setw(5)<<"语文"<<setw(5)<<"数学"<<setw(5)<<"英语" <<endl;
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
            string usernum;     //使用账号
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
             int tea_play();     //教师登陆后的主界面，显示班级号， 索引可执行操作选项
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

void add(int n)            //n是班级号
{
    fstream file;
    file.open(allclasses[n].c_str(),ios_base::in);
    Student s,a[N];
    int k=1;
    while(!file.eof())
    {
        file>>a[k];
        k++;               //k 得减去 2
    k-=2;
    file.close();
    cout<<"是否继续添加学生信息？     是请按1         否则按0退出"<<endl;
    int x;
    cin>>x;
    while(x)
    {
        k++;
        a[k].set_stu();
        a[k].set_gra();
        a[k].set_class(n);
        cout<<endl<<"是否继续添加学生信息？           是请按1    否则按0退出"<<endl;
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
    cout<<"管理员："<<username<<endl;
    cout<<"查询班级整体学生信息，成绩——请按1"<<endl;
    cout<<"查询单一学生信息——请按2"<<endl;
    cout<<"修改学生信息——请按3"<<endl;
    cout<<"添加学生信息——请按4"<<endl;
    cout<<"导入新班级信息——请按5"<<endl;
    cout<<"删除班级——请按6"<<endl;
    cout<<"修改登录密码——请按7"<<endl;
    cout<<"退出系统——请按8"<<endl;
    int x;
    cin>>x;
    return x;
}


int Teacher::tea_play()
{
    cout<<endl;
    cout<<"教师："<<name<<"               编号："<<usernum<<"            任教班级："<<classnum<<"班";
    cout<<endl<<endl;
    cout<<"该班所有学生成绩——请按1"<<endl;
    cout<<"查询单一学生信息——请按2"<<endl;
    cout<<"修改学生信息——请按3"<<endl;
    cout<<"修改登录密码——请按4"<<endl;
    cout<<"取消-不执行任何操作——请按5"<<endl;
    int x;
    cin>>x;
    return x;
}


void Administrator::addnewclass(int n)   //n是班级号，此函数可导入一个班级的学生信息
{
         cout<<"请先输入该班级总人数： ";
         int p;
         cin>>p;
         Student s[N];
         for(int i=1;i<=p;i++)
         {
             s[i].set_stu();
             s[i].set_class(n);
         }
         cout<<"请输入班主任姓名：";
         string t,c;
         cin>>t;
         cout<<"请输入此教师编号：";
         cin>>c;
         Teacher tea(t,c,n);
         ofstream out;
         out.open("教师档案.txt",ios_base::app);
         out<<tea;
         out.close();
         cout<<"是否继续输入学生成绩?"<<endl<<"添加成绩请按1          否则请按0"<<endl;
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
         cout<<n<<"班级信息导入成功！"<<endl;
         return;
}

void bubblesort1(Student sq[ ],int length)               //总分排序
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
        sq[i].rank=i;                  //只有总分排名存到文件中去
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
void bubblesort4(Student sq[ ],int length)              //按总分排序
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

//这部分做friend函数，传Student类形参，要改待定 在main函数里写掉部分 再传引用
void fun1(Student& a)         //修改学生基本信息  包括成绩  最后保存到文件里
  {
        cout<<a.classnumber<<"班      学生："<<a.name<<"       学号："<<a.number<<"       "<<a.sex
        <<"       语文："<<a.chinese<<"         数学："<<a.math<<"        英语："<<a.english<<"       总分"
        <<a.sum<<"       三门均分："<<a.average<<"      班级名次："<<a.rank<<endl;
        cout<<"请重新输入要改的学生姓名  学号  性别   语文成绩   数学成绩     英语成绩"<<endl;
        string s1,s2,s3;
        double x,y,z;
        cin>>s1>>s2>>s3>>x>>y>>z;
        a.name=s1;      a.number=s2;      a.sex=s3;
        a.chinese=x;         a.math=y;           a.english=z;
        a.sum=x+y+z;         a.average=a.sum/3;
        cout<<endl<<"学生信息修改成功"<<endl;
  }
void fun2(Student a[],int s)
{
    int i=1;
    cout<<"班级："<<a[1].classnumber<<endl;
    cout<<setw(4)<<"排名"<<setw(5)<<"学号"<<setw(7)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"语文"
    <<setw(7)<<"数学"<<setw(7)<<"英语"<<setw(7)<<"总分"<<setw(7)<<"均分";
    for(;i<=s;i++)
    {
        cout<<endl;
        cout<<setw(4)<<a[i].rank<<setw(5)<<a[i].number<<setw(7)<<a[i].name<<setw(7)<<a[i].sex<<setw(7)<<a[i].chinese
        <<setw(7)<<a[i].math<<setw(7)<<a[i].english<<setw(7)<<a[i].sum<<setw(7)<<setprecision(4)<<a[i].average;
    }
    cout<<endl<<endl;
    cout<<"按均分排名——请输入1"<<endl;
    cout<<"查看并按语文成绩排名——请输入2"<<endl;
    cout<<"查看并按数学成绩排名——请输入3"<<endl;
    cout<<"查看并按英语成绩排名——请输入4"<<endl;
    cout<<"退出———请输入0"<<endl;
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
       cout<<"班级："<<a[1].classnumber<<endl;
       cout<<setw(5)<<"名次"<<setw(5)<<"学号"<<setw(7)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"语文"
       <<setw(7)<<"数学"<<setw(7)<<"英语"<<setw(7)<<"总分"<<setw(7)<<"均分";
       for(;i<=s;i++)
       {
           cout<<endl;
           cout<<setw(5)<<i<<setw(5)<<a[i].number<<setw(7)<<a[i].name<<setw(7)<<a[i].sex<<setw(7)<<a[i].chinese
          <<setw(7)<<a[i].math<<setw(7)<<a[i].english<<setw(7)<<a[i].sum<<setw(7)<<setprecision(4)<<a[i].average;
       }
       cout<<endl<<"继续排序：                                         返回——输入0";
       cout<<endl<<"按均分排名——请输入1"<<endl;
       cout<<"查看并按语文成绩排名——请输入2"<<endl;
       cout<<"查看并按数学成绩排名——请输入3"<<endl;
       cout<<"查看并按英语成绩排名——请输入4"<<endl;
       cin>>x;
    }
    return;
}

void display(Student& stu)           //查看函数 a是学号   n是班级号
{
    cout<<endl<<"学生："<<stu.name<<"     班级："<<stu.classnumber<<"       学号："<<stu.number<<"     性别："<<stu.sex
    <<endl<<"语文："<<stu.chinese<<"      数学："<<stu.math<<"       英语："<<stu.english<<"      三门总分："<<stu.sum<<
    "      均分："<<stu.average<<"    名次："<<stu.rank<<endl<<endl;
}


int Student::changecipher()
{
     cout<<"请输入旧密码："<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"请输入新密码：";
        cin>>b;
        cout<<"请再次出入密码：";
        cin>>c;
        while(b!=c)
        {
             cout<<"密码输入不一致 请重新输入：";
             cin>>b;
             cout<<"请再次输入：";
             cin>>c;
        }
        cipher=b;
        cout<<"密码修改成功"<<endl;
        return 0;
     }
     else
         cout<<"密码输入错误，不可修改"<<endl;
     return 0;
}
 int Teacher::changecipher()
{
     cout<<"请输入旧密码："<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"请输入新密码：";
        cin>>b;
        cout<<"请再次出入密码：";
        cin>>c;
        while(b!=c)
        {
             cout<<"密码输入不一致 请重新输入：";
             cin>>b;
             cout<<"请再次输入：";
             cin>>c;
        }
        cipher=b;
        cout<<"密码修改成功"<<endl;
        return 0;
     }
     else
         cout<<"密码输入错误，不可修改"<<endl;
     return 0;
}
int Administrator::changecipher()
{
     cout<<"请先输入旧密码："<<endl;
     string a,b,c;
     cin>>a;
     if(a==cipher)
     {
        cout<<"请输入新密码：";
        cin>>b;
        cout<<"请再次出入密码：";
        cin>>c;
        while(b!=c)
        {
             cout<<"密码输入不一致 请重新输入：";
             cin>>b;
             cout<<"请再次输入：";
             cin>>c;
        }
        cipher=b;
        cout<<"密码修改成功"<<endl;
        return 0;
     }
     else
         cout<<"密码输入错误，不可修改"<<endl;
     return 0;
}



int main()
{
    cout<<"                       大二年级成绩查询系统"<<endl;
    cout<<"                             用户选择"<<endl<<"学生请按(1)            教师请按(2)         管理员请按(3)"<<endl;
    int x;
    string holy="yes";
    while(cin>>x)
    {
        if(x!=1&&x!=2&&x!=3)
            {       cout<<"按键出错，请再次按键"<<endl;       continue;      }
        else
            break;
    }
    switch(x)
    {
       case 1:                       //学生只能看自己的成绩和基本信息  还可以修改登录密码
             {
               cout<<"【学生用户】                    请先输入所在班级号： ";
               int n;
               cin>>n;
               cout<<"用户名（学号）：";
               string a,b;
               cin>>a;
               cout<<"登陆密码：";
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
                    cout<<"用户不存在      请重新登录"<<endl;
               else if(judge!=0&&temp[judge].getcipher()!=b)
                    cout<<"密码输入错误    请重新登陆"<<endl;
               else if(judge!=0&&temp[judge].getcipher()==b)
                {
                    display(temp[judge]);
                    cout<<"修改密码请按1                    返回请按0"<<endl;
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
               cout<<"【教师用户】                      用户名（教师编码）：";
               string c,d;
               cin>>c;
               cout<<"登录密码：";
               cin>>d;
               ifstream in("教师档案.txt");
               Teacher tea[M];
               int k=1,judge2=0;
               while(!in.eof())
               {
                   in>>tea[k];
                   if(tea[k].getusernum()==c)
                       judge2=k;
                   k++;
               }
               k=k-2;                //k:老师总人数
               in.close();
               if(judge2==0)
                    cout<<"用户名不存在   请重新登录";
               else if(judge2!=0&&tea[judge2].getcipher()!=d)
                    cout<<"用户密码输入错误   请重新登录！";
                else if(judge2!=0&&tea[judge2].getcipher()==d)
                {
                     int q,t=1;
                     Student a[N];
                     ifstream fp(allclasses[tea[judge2].getclassnum()].c_str());
                     while(!fp.eof())
                     {
                         fp>>a[t];           //t是总人数，这里排序只是供暂时查看不保存，默认学生排名按均分来（即总分）
                         t++;
                     }
                     t-=2;
                     fp.close();
                     while(holy=="yes")
                     {
                     q=tea[judge2].tea_play();       //返回的q是带操作的选项
                     switch(q)
                     {
                         case 1:
                                 fun2(a,t);
                                 break;
                         case 2:
                          {
                                 cout<<"输入待查学生学号：";
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
                                            cout<<"该班不存在学号为"<<g<<"的学生"<<endl;
                                       else
                                            display(a[tp]);
                                       cout<<endl<<"继续查看学生————请输入学号                    返回————请按0";
                                       cout<<endl;
                                       cin>>g;
                                   }
                                 break;
                            }
                           case 3:
                           {
                                  cout<<"输入待修改学生学号：";
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
                                             cout<<"该班不存在学号为"<<g<<"的学生"<<endl;
                                         else
                                             fun1(a[tp]);
                                         cout<<endl<<"继续修改学生信息——输入学号";
                                         cout<<endl<<"返回———请输入0"<<endl;
                                         cin>>g;
                                  }
                                  bubblesort1(a,t);                   //可能学生成绩被改了 要重新存一遍 保存
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
                                    ff.open("教师档案.txt",ios_base::out);
                                    for(int y=1;y<=k;y++)
                                          ff<<tea[y];
                                     ff.close();
                                     break;
                            }
                            case 5:
                            default:
                                      break;
                        }
                        cout<<endl<<"返回上层目录输入yes         退出系统输入 no"<<endl;
                        cin>>holy;
                        }
                    }
               break;
               }
             case 3:
             {
                    cout<<"【管理员】                               登录账号名：";
                    string y,z;
                    cin>>y;
                    Administrator A;
                    ifstream in3("管理员.txt");
                    in3>>A;
                    in3.close();
                    cout<<"输入登录密码：";
                    cin>>z;
                    cout<<endl;
                    if(A.getusername()!=y)
                         cout<<"用户名错误 无法登入！";
                    else if(A.getusername()==y&&A.getcipher()!=z)
                          cout<<"用户密码输入错误   无法登陆！";
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
                                    cout<<"输入待查看班级号：";
                                    cin>>bjh;
                                    ifstream file3(allclasses[bjh].c_str());
                                    while(!file3.eof())
                                    {
                                        file3>>vb[v];
                                        v++;                             //v是总人数
                                    }
                                    v-=2;
                                    file3.close();
                                    fun2(vb,v);
                                    break;
                               }
                              case 2:
                              {
                                      v=1;
                                      cout<<"输入所在班级号：";
                                      cin>>bjh;
                                      cout<<"输入待查学生学号：";
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
                                              cout<<"该班不存在学号为"<<xh<<"的学生 "<<endl;
                                          else
                                              display(vb[final]);
                                          cout<<endl<<"继续查看该班学生————请输入学号";
                                          cout<<endl<<"返回————请按0"<<endl;
                                          cin>>xh;
                                      }
                                      break;
                              }
                              case 3:
                              {
                                       v=1;
                                       cout<<"输入学生所在班级号：";
                                       cin>>bjh;
                                       cout<<"输入修改学生学号：";
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
                                                cout<<"该班不存在学号为"<<xh<<"的学生 "<<endl;
                                          else
                                                fun1(vb[final]);
                                           cout<<"继续修改学生信息——输入学号";
                                           cout<<endl<<"返回———请输入0"<<endl;
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
                                        cout<<"输入待添加学生所在班级号：";
                                        int hh;
                                        cin>>hh;
                                        add(hh);
                                        break;
                                }
                                case 5:
                                {
                                         cout<<"添加新班级——————请输入新班级号：";
                                         int bb;
                                         cin>>bb;
                                         A.addnewclass(bb);
                                         break;
                                }
                                case 6:
                                {
                                         cout<<"请输入要删除的班级号：";
                                         int del;
                                         cin>>del;
                                         while(del)
                                         {
                                             fstream out6,tch;
                                             out6.open(allclasses[del].c_str(),ios_base::out);
                                             out6.close();
                                             tch.open("教师档案.txt",ios_base::in);
                                             Teacher t[M];
                                             int hu=1,come;
                                             while(!tch.eof())
                                            {
                                                tch>>t[hu];
                                                if(t[hu].getclassnum()==del)
                                                     come=hu;
                                                hu++;             //hu最后成教师总人数
                                            }
                                            tch.close();
                                            hu-=3;                  //减去一个教师后的总人数
                                            for(int y=come;y<=hu;y++)
                                                 t[y]=t[y+1];
                                            tch.open("教师档案.txt",ios_base::out);
                                            for(int y=1;y<=hu;y++)
                                                 tch<<t[y];
                                             tch.close();
                                             cout<<endl<<"该班级已删除"<<endl;
                                             cout<<"继续删除班级请输入班级号：           否则按0退出"<<endl;
                                             cin>>del;
                                         }
                                         break;
                                 }
                                case 7:
                                {
                                         A.changecipher();
                                         ofstream out7("管理员.txt");
                                         out7<<A;
                                         out7.close();
                                         break;
                                }
                                case 8:
                                        cout<<"退出！";
                                        break;
                          }
                          cout<<endl<<"返回上层目录请输入 yes       退出请输入 no"<<endl;
                          cin>>holy;
                          }
                      }
        break;
        }
       }
       system("pause");
       return 0;
}


