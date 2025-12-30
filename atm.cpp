#include<iostream>
#include<fstream>
using namespace std;
class atm
{
    private:
    int acc;
    char name[100];
    int balance;
    
    public:
    void input()
    {
        cout<<"enter the account number :";
        cin>>acc;
        cin.ignore();
        cout<<"enter your name :";
        cin.getline(name,100);
        cout<<"enter your initial balance :";
        cin>>balance;
    }
    void display()
    {
        cout<<"account number is :"<<acc<<endl;
        cout<<"name is :"<<name<<endl;
        cout<<"balance is :"<<balance<<endl;
    }
    void diposite()
    {
        int y;
        cout<<"enter the ammount to deposite :";
        cin>>y;
        balance = balance + y;
        cout<<"------ammount is successfully deposite------"<<endl;
    }
    void withdraw()
    {
         int  y;
        cout<<"enter the ammount to withdraw :";
        cin>>y;
        if(y<=balance)
        {
            balance = balance-y;
            cout<<"-----ammount is successfully withdraw-----"<<endl;
        }
        else
        {
            cout<<"ammount is not sufficiant to withdraw"<<endl;
        }
    }
    void balanceacc()
    {
        cout<<"balance is :"<<balance;
    }


    int getacc()
    {
        return acc;
    }

};
void create();
void show();
void search(int a);
void dipositewithdrawing(int x,int m) ;
void deleteacc(int b);
void checkbalance(int n);
void create(int n);
int main()
{
    int n;
    int choice;
    do
    {
        cout<<"================================="<<endl;
        cout<<"******WELCOME TO BANK************** "<<endl;
        cout<<"1. create accout "<<endl;
        cout<<"2. show all account "<<endl;
        cout<<"3. search the account "<<endl;
        cout<<"4. deposite ammount "<<endl;
        cout<<"5. withdraw the ammount"<<endl;
        cout<<"6. delete the account "<<endl;
        cout<<"7.cheak balance :"<<endl;
        cout<<"8. exit "<<endl;
        cout<<"enter number you want :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"enter the account number :";
                cin>>n;
                create(n);
                break;
            case 2:
                show();
                break;
            case 3:
                
                cout<<"enter account number :";
                cin>>n;
                search(n);
                break; 
            case 4:
                
                cout<<"enter the account number :";
                cin>>n;
                dipositewithdrawing(n,1) ;
                break; 
            case 5:
                
                cout<<"enter the account number :";
                cin>>n;
                dipositewithdrawing(n,2) ;
                break;
            case 6:
                
                cout<<"enter the account number :";
                cin>>n;
                deleteacc(n);
                break;
            case 7:
                cout<<"enter account number :";
                cin>>n;
                checkbalance(n);
                break;

            case 8:
                cout<<"---thank you see you soon----"<<endl;
                break;
            default:
                cout<<"enter valid point"<<endl;
        }

    }while(choice !=7);
    return 0;
}
void create(int c)
{
    atm s;
    fstream out("atm.dat",ios :: binary | ios ::in | ios :: out);
    while(out.read((char*)&s ,sizeof(s)))
    {
        if(s.getacc()==c)
        {
            cout<<"this account number allready exist"<<endl;
            break;
        }
        else
        {
            ofstream out("atm.dat",ios ::binary |ios :: app);
            s.input();
            out.write((char*)&s , sizeof(s));
            
        }
    } 

    out.close();   
}
void show()
{
    atm s;
    ifstream in("atm.dat",ios :: binary);
    bool found = false;
    while(in.read((char*)&s ,sizeof(s)))
    {
         s.display();
         found=true;
    }
    in.close();
    if(!found)
    {
        cout<<"----EMPATY ACCOUNT---- "<<endl;
    }
}
void search(int a)
{
    atm s;
    ifstream in("atm.dat",ios :: binary);
    bool found = false;
    while(in.read((char*)&s ,sizeof(s)))
    {
        if(s.getacc() ==a)
        {
            s.display();
            found=true;
            break;
        }
    }
    in.close();
    if(!found)
    {
        cout<<"accound is not found"<<endl;
    }
}
void dipositewithdrawing(int x,int m)
{
    atm s;
    fstream out("atm.dat",ios :: binary | ios ::in | ios :: out);
    bool found =false;
    while(out.read((char*)&s , sizeof(s)))
    {
        if(s.getacc()==x)
        {
            if(m==1)
            {
                s.diposite();
            }
            else
            {
                s.withdraw();
            }
            int pos = (-1) * static_cast<int>(sizeof(s));
                out.seekp(pos, ios::cur);
                out.write((char*)&s, sizeof(s));
                found = true;
                break;
        } 
    } 
    out.close();
    if(!found)
    {
        cout<<"account has not been created"<<endl;
    }
}
void deleteacc(int b)
{
    atm s;
    ifstream in("atm.dat",ios :: binary);
    ofstream out("temp.dat",ios :: binary);
    bool found = false;
    while(in.read((char*)&s ,sizeof(s)))
    {
        if(s.getacc()==b)
        {
            found =true;
        }
        else
        {
            out.write((char*)&s , sizeof(s));
        }
    }
    in.close();
    out.close();
    remove("atm.dat");
    rename("temp.dat","atm.dat");
    if(found)
    {
        cout<<"account is successfully deleted"<<endl;
    }
    else
    {
        cout<<"account is not found in system";
    }

}
void checkbalance(int n)
{
    atm s;
    ifstream in("atm.dat",ios ::binary);
    bool found = false;
    while(in.read((char*)&s ,sizeof(s)))
    {
           if(s.getacc()==n)
           {
               s.balanceacc();
               found = true;
               break;
           }
    }
    in.close();
    if(!found)
    {
        cout<<"account is not found "<<endl;
    }
}














