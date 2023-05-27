//----------------------------------PROJECT NAME:CAR DEALERSHIP MANAGEMENT SYSTEM------------------
//
//
//---------------------------------------SUBMITTERD BY:MD.TANJIMUL HASAN---------------------------
//
//
//------------------------------------------------ROLL;2007081-------------------------------------
//
//
//OVERVIEW OF THE PROGRAM:
//                  A SIMPLE PROGRAM TO MANAGE THE WHOLE OPERATIONS OF A CAR DEALERSHIP STORE LIKE:
//                                   MANAGING PRODUCT STOCKS,MANAGING INFORMATION OF EMPLOYEES,HANDLING ORDERS ETC.
//SPECIAL INSTRUCTION:
//           FOR LOGIN:
//             USE \\\\\\\\\\\\ admin@gmail.com \\\\\\\\\\\\\\ AS EMAIL
//             USE  \\\\\\\\\\\\      1234       \\\\\\\\\\\\\\ AS PASSWORD
#include <bits/stdc++.h>
#define ll long long
#define vardclr ll i,j,k,n,m,p,q,r,x,y,z;
using namespace std;

class product
{
    protected:
    ll price;
public:
    ll productstck;
    ll units_sold;
    virtual void sell()=0;
};
class car:public product
{
    string brand_name;
    string model;
    public:
    static ll carsold;
    car(string name="TOYOTA",string mdl="PREMIO F",ll prc=4000000,ll qntt=10)
    {
        brand_name=name;
        model=mdl;
        price=prc;
        productstck=qntt;
        units_sold=0;
    }
    ~car()
    {

    }
    void sell()
    {
        carsold++;
        (this->productstck)--;
        (this->units_sold)++;
    }
    void invoice(string c_name)
    {
          cout<<"\t\t\t\t\t    CUSTOMER'S NAME: "<<c_name<<endl<<"\t\t\t\t\t    "<<this->brand_name<<endl<<"\t\t\t\t\t    model:"<<this->model<<endl<<"\t\t\t\t\t    price:"<<this->price<<endl<<endl;
    }
    friend ostream& operator<<(ostream& os,const car& c)
    {
        os<<"\t\t\t\t\t    "<<c.brand_name<<endl<<"\t\t\t\t\t    model:"<<c.model<<endl<<"\t\t\t\t\t    price:"<<c.price<<endl<<"\t\t\t\t\t    productstock:"<<c.productstck<<"\t\t\t\t    units sold:"<<c.units_sold<<endl<<endl;
        return os;
    }
};
ll car::carsold=0;
class spare_parts:public product
{
    string type;
    string model;
public:
    static ll spsold;
    void setval(string s,string mdl,ll prc,ll qntt)
    {
        type=s;
        model=mdl;
        price=prc;
        productstck=qntt;
        units_sold=0;
    }
     void sell()
     {
         spsold++;
         (this->productstck)--;
         (this->units_sold)++;
     }
    void invoice(string c_name)
    {
          cout<<"\t\t\t\t\t    CUSTOMER'S NAME: "<<c_name<<endl<<"\t\t\t\t\t    "<<this->type<<endl<<"\t\t\t\t\t    model:"<<this->model<<endl<<"\t\t\t\t\t    price:"<<this->price<<endl<<endl;
    }
    friend ostream& operator<<(ostream& os,const spare_parts& sp)
    {
        os<<"\t\t\t\t\t    "<<sp.type<<endl<<"\t\t\t\t\t    model:"<<sp.model<<endl<<"\t\t\t\t\t    price:"<<sp.price<<endl<<"\t\t\t\t\t    product stock:"<<sp.productstck<<"\t\t\t\t    units sold:"<<sp.units_sold<<endl<<endl;
        return os;
    }
};
ll spare_parts::spsold=0;

template<class T>
void showdetails(T& v)
{
    for(ll i=0;i<v.size();i++)
    {
        cout<<"\t\t\t\t    ("<<i+1<<")"<<endl;
        cout<<v[i];
    }
}
void detect(product* p,string nm)
{
    car* cr;
    cr=dynamic_cast<car*>(p);
    spare_parts* spr;
    spr=dynamic_cast<spare_parts*>(p);
    if(cr==nullptr)
        (*spr).invoice(nm);
    else
        (*cr).invoice(nm);
}
class orders
{
    public:
    vector<string>pending_customer_list;
    vector<string>completed_customer_list;
    vector<product*>pending;
    vector<product*>completed;
    void show()
    {
        cout<<"\t\t\t\t\t      PENDING ORDERS"<<endl<<endl;
        if(pending.size()==0)
            cout<<"\t\t\t\t\t    NOTHING  TO  SHOW"<<endl<<endl;
        else
        {
            for(ll i=0;i<pending.size();i++)
                  {
                      cout<<"\t\t\t\t    ("<<i+1<<")"<<endl;
                      detect(pending[i],pending_customer_list[i]);
                  }
        }
        cout<<"\t\t\t\t\t      COMPLETED ORDERS"<<endl<<endl;
        if(completed.size()==0)
            cout<<"\t\t\t\t\t    NOTHING  TO  SHOW"<<endl<<endl;
        else
        {
            for(ll i=0;i<completed.size();i++)
                  {
                      cout<<"\t\t\t\t    ("<<i+1<<")"<<endl;
                      detect(completed[i],completed_customer_list[i]);
                  }
        }
    }
    void showpending()
    {
        cout<<"\t\t\t\t\t      PENDING ORDERS"<<endl<<endl;
        if(pending.size()==0)
            cout<<"\t\t\t\t\t    NOTHING  TO  SHOW"<<endl<<endl;
        else
        {
            for(ll i=0;i<pending.size();i++)
                  {
                      cout<<"\t\t\t\t    ("<<i+1<<")"<<endl;
                      detect(pending[i],pending_customer_list[i]);
                  }
        }
    }

};
void main_menu()
{
    cout<<"\t\t\t\t\t\t    ___________"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     MAIN MENU "<<endl;
    cout<<"\t\t\t\t\t\t    ___________"<<endl<<endl;
    cout<<"\t\t\t\t\t\t1) PRODUCT STOCKS"<<endl;
    cout<<"\t\t\t\t\t\t2) ORDERS"<<endl;
    cout<<"\t\t\t\t\t\t3) EMPLOYEE DETAILS"<<endl;
    cout<<"\t\t\t\t\t\t4) EXIT"<<endl<<endl;
    cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
}
int main()
{
    vardclr
    string s,str,email,pass;
    ll prc,qntt;
    orders ord;
    vector<car>carvect;
    vector<spare_parts>spvect;
    car c1("HYUNDAI","ACCENT",2250000,15),c2;
    carvect.push_back(c1);carvect.push_back(c2);
    spare_parts sp1,sp2;
    sp1.setval("TYRE","APOLLO",11000,8);
    sp2.setval("HEADLIGHTS","N/A",4000,12);
    spvect.push_back(sp1);spvect.push_back(sp2);
    cout<<"\t\t\t\t\t|__________TELIGATI MOTORS__________|"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t    ADMIN LOGIN"<<endl;
    again:
    cout<<endl;
    cout<<"\t\t\t\t\tENTER MAIL:";
    cin>>email;
    cout<<endl;
    cout<<"\t\t\t\t\tENTER PASSWORD:";
    cin>>pass;
    cout<<endl;
    if(email=="admin@gmail.com"&&pass=="1234")
    {
        cout<<"\t\t\t\t\t\t~LOGIN SUCCESSFUL~"<<endl<<endl;
    }
    else
    {
        cout<<"\t\t\t\t\t   ~INCORRECT INFORMATION!!PLEASE TRY AGAIN~"<<endl;
        goto again;
    }
    menu:
    main_menu();
    option:
    cin>>x;
    cout<<endl;
    switch(x)
    {
        case 1:
              {
                product:
                 cout<<"\t\t\t\t\t\tPRODUCT STOCKS:"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  1) CARS"<<endl;
                 cout<<"\t\t\t\t\t\t  2) SPARE PARTS"<<endl;
                 cout<<"\t\t\t\t\t\t  3) GO TO MENU"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                 cin>>y;
                 cout<<endl;
                 if(y==1)
                 {
                     caropt:
                     cout<<"\t\t\t\t\t\tCARS:"<<endl<<endl;
                     cout<<"\t\t\t\t\t\t  1) ADD NEW COLLECTIONS"<<endl;
                     cout<<"\t\t\t\t\t\t  2) SHOW LIST"<<endl;
                     cout<<"\t\t\t\t\t\t  3) GO TO PRODUCT STOCKS"<<endl<<endl;
                     cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                     cin>>z;
                     cout<<endl;
                     if(z==1)
                     {
                         cout<<"\t\t\t\t\t\t  ENTER BRAND NAME:";
                         cin.ignore();getline(cin,s);
                         cout<<"\t\t\t\t\t\t  ENTER MODEL NAME:";
                         getline(cin,str);
                         cout<<"\t\t\t\t\t\t  ENTER PRICE:";
                         cin>>prc;
                         cout<<"\t\t\t\t\t\t  ENTER PRODUCT STOCK:";
                         cin>>qntt;
                         car cx(s,str,prc,qntt);
                         carvect.push_back(cx);
                         cout<<endl;
                         cout<<"\t\t\t\t\t\t  ADDED SUCCESSFULLY"<<endl;
                         goto caropt;
                     }
                    else if(z==2)
                     {
                         cout<<endl<<"\t\t\t\t\t\t  ALL COLLECTIONS:"<<endl;
                         showdetails(carvect);
                         goto caropt;
                     }
                    else
                     {
                        goto product;
                     }
                 }
                 else if(y==2)
                 {
                     spopt:
                     cout<<"\t\t\t\t\t\tSPARE PARTS:"<<endl<<endl;
                     cout<<"\t\t\t\t\t\t  1) ADD NEW ITEMS"<<endl;
                     cout<<"\t\t\t\t\t\t  2) SHOW LIST"<<endl;
                     cout<<"\t\t\t\t\t\t  3) GO TO PRODUCT STOCKS"<<endl<<endl;
                     cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                     cin>>z;
                     cout<<endl;
                     if(z==1)
                     {
                         cout<<"\t\t\t\t\t\t  ENTER PRODUCT TYPE:";
                         cin.ignore();getline(cin,s);
                         cout<<"\t\t\t\t\t\t  ENTER MODEL NAME:";
                         getline(cin,str);
                         cout<<"\t\t\t\t\t\t  ENTER PRICE:";
                         cin>>prc;
                         cout<<"\t\t\t\t\t\t  ENTER PRODUCT STOCK:";
                         cin>>qntt;
                         spare_parts spx;
                         spx.setval(s,str,prc,qntt);
                         spvect.push_back(spx);
                         cout<<endl;
                         cout<<"\t\t\t\t\t\t  ADDED SUCCESSFULLY"<<endl;
                         goto spopt;
                     }
                    else if(z==2)
                     {
                         cout<<endl<<"\t\t\t\t\t\t  LIST OF ITEMS:"<<endl;
                         showdetails(spvect);
                         goto spopt;
                     }
                    else
                     {
                        goto product;
                     }
                 }
                 else
                 {
                     goto menu;
                 }
              }
              break;
        case 2:
              {
                  orders:
                 cout<<"\t\t\t\t\t\tORDERS:"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  1) ADD NEW ORDER"<<endl;
                 cout<<"\t\t\t\t\t\t  2) CLEAR PENDING ORDER"<<endl;
                 cout<<"\t\t\t\t\t\t  3) LIST OF ORDERS"<<endl;
                 cout<<"\t\t\t\t\t\t  4) GO TO MENU"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                 cin>>y;
                 cout<<endl;
                 if(y==1)
                 {
                       cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:1)CAR  2)SPARE PARTS=>";
                       cin>>p;
                       cout<<endl;
                       if(p==1)
                       {
                           showdetails(carvect);
                           cout<<endl;
                           cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                           cin>>q;
                           cout<<endl<<"\t\t\t\t\t\t  ENTER CUSTOMER'S NAME: ";
                           cin.ignore();getline(cin,s);
                           carvect[q-1].sell();
                           ord.pending.push_back(&carvect[q-1]);
                           ord.pending_customer_list.push_back(s);
                           if(carvect[q-1].productstck==0)carvect.erase(carvect.begin()+q-1);
                       }
                       else
                       {
                           showdetails(spvect);
                           cout<<endl;
                           cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                           cin>>q;
                           cout<<endl<<"\t\t\t\t\t\t  ENTER CUSTOMER'S NAME: ";
                           cin.ignore();getline(cin,s);
                           spvect[q-1].sell();
                           ord.pending.push_back(&spvect[q-1]);
                            ord.pending_customer_list.push_back(s);
                           if(spvect[q-1].productstck==0)spvect.erase(spvect.begin()+q-1);
                       }
                      cout<<endl<<"\t\t\t\t\t\tORDER ADDED SUCCESSFULLY"<<endl;
                      goto orders;
                 }
                 else if(y==2)
                 {
                      ord.showpending();
                      cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                      cin>>p;
                      ord.completed.push_back(ord.pending[p-1]);ord.completed_customer_list.push_back(ord.pending_customer_list[p-1]);
                      ord.pending.erase(ord.pending.begin()+p-1);ord.pending_customer_list.erase(ord.pending_customer_list.begin()+p-1);
                      goto orders;
                 }
                 else if(y==3)
                 {
                     cout<<endl<<"\t\t\tCARS SOLD: "<<car::carsold<<"\t\t\t\t      SPARE PARTS SOLD: "<<spare_parts::spsold<<endl<<endl;
                     ord.show();
                     goto orders;
                 }
                 else
                 {
                     goto menu;
                 }
              }
              break;
        case 3:
              {
                  employee:
                 cout<<"\t\t\t\t\t\tEMPLOYEE DETAILS:"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  1) ADD EMPLOYEE"<<endl;
                 cout<<"\t\t\t\t\t\t  2) EMPLOYEE LIST"<<endl;
                 cout<<"\t\t\t\t\t\t  3) GO TO MENU"<<endl<<endl;
                 cout<<"\t\t\t\t\t\t  CHOOSE AN OPTION:";
                 cin>>y;
                 cout<<endl;
                 if(y==1)
                 {
                     string empname,desig,age,salary;
                     char ch='*';
                     ofstream file("employee.txt",ios::out|ios::app);
                     cout<<"\t\t\t\t\t\tENTER EMPLOYEE NAME: ";
                     cin.ignore();getline(cin,empname);
                     cout<<"\t\t\t\t\t\tENTER EMPLOYEE AGE: ";
                     getline(cin,age);
                     cout<<"\t\t\t\t\t\tENTER EMPLOYEE DESIGNATION: ";
                     getline(cin,desig);
                     cout<<"\t\t\t\t\t\tENTER EMPLOYEE SALARY: ";
                     getline(cin,salary);
                     file<<ch<<endl<<empname<<endl<<age<<endl<<desig<<endl<<salary<<endl;
                     file.close();
                     goto employee;
                 }
                 else if(y==2)
                 {
                     string temp;
                     ll cnt=0;
                     ifstream filee("employee.txt");
                     while(getline(filee,temp))
                     {
                         if((cnt%5)==0)
                           cout<<"\t\t\t\t\t\t   "<<temp<<endl;
                         else if((cnt%5)==1)
                            cout<<"\t\t\t\t\t\t   NAME: "<<temp<<endl;
                         else if((cnt%5)==2)
                            cout<<"\t\t\t\t\t\t   AGE: "<<temp<<endl;
                        else if((cnt%5)==3)
                            cout<<"\t\t\t\t\t\t   DESIGNATION: "<<temp<<endl;
                        else if((cnt%5)==4)
                            cout<<"\t\t\t\t\t\t   SALARY: "<<temp<<endl;
                        cnt++;
                     }
                     goto employee;
                 }
                 else
                 {
                     goto menu;
                 }
              }
              break;
        case 4:
              {
                 return 0;
              }
              break;
        default:
            {
                cout<<"\t\t\t\t\t\t  INVALID OPTION->CHOOSE ANOTHER OPTION:";
                goto option;
            }
    }
}
