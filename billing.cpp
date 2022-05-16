
#include <iostream>
#include<fstream>
using namespace std;

class shopping
{
   private:
       int pcode;
       float price;
       float dis;
       string pname;

   public:
       void menu();
       void administrator();
       void buyer();
       void add();
       void edit();
       void rem();
       void List();
       void receipt();

};

void shopping::menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t ___________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t       SuperMarket Main Menu        \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t ___________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t| 1) Administrator                  \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t  2) Buyer                          \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t Please Select!                     \n";
    cin>>choice;
    switch(choice)
    {
       case 1:
           cout<<"\t\t\t\t Please Login \n";
           cout<<"\t\t\t\t Enter Email  \n";
           cin>>email;
           cout<<"\t\t\t\t Enter Password\n";
           cin>>password;
           if(email=="aivankum@gmail.com" && password=="testcase"){
             administrator();
           }else{
               cout<<"\t\t\t\t Invalid Credentials\n";
           }
           break;
       case 2:
           {
               buyer();
           }
       case 3:
           {

               exit(0);
           }
       default:
           {cout<<"Please select from given options\n";}



    }

    goto m;
}

void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t\ Administrator Menu\n";
    cout<<"\n\t\t\t|___ 1) Add Product________|\n";
    cout<<"\n\t\t\t|                          |\n";
    cout<<"\n\t\t\t|___ 2) Modify Product_____|\n";
    cout<<"\n\t\t\t|                          |\n";
    cout<<"\n\t\t\t|___ 3) Delete Product_____|\n";
    cout<<"\n\t\t\t|                          |\n";
    cout<<"\n\t\t\t|___ 4) Back to main Menu__|\n";

    cout<<"\n\t\t Please Enter Your Choice\n";

    cin>>choice;
    switch(choice)
    {
        case 1:
            add();
        case 2:
            edit();
        case 3:
            rem();
        case 4:
            menu();
        default:
            cout<<"Invalid Choice\n";
    }
    goto m;

  }

  void shopping::buyer(){
  m:
  int choice;

    cout<<"\n\n\n\t\t\t\       Buyer          |\n";
    cout<<"\n\t\t\t|___ 1) Buy Product________|\n";
    cout<<"\n\t\t\t|                          |\n";
    cout<<"\n\t\t\t|___ 2) GO Back       _____|\n";
    cout<<"\n\t\t\t|                          |\n";
    cout<<"\n\t\t Please Enter Your Choice\n";

    cin>>choice;
      switch(choice)
    {
        case 1:
            receipt();
        case 2:
            menu();

        default:
            cout<<"Invalid Choice\n";
    }
    goto m;

  }

  void shopping::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\n\t\t\t\  Add New Product |\n";
    cout<<"\n\t\t\t Product Code of the product\n";
    cin>>pcode;
    cout<<"\n\t\t\t Name Of The Product\n";
    cin>>pname;
    cout<<"\n\t\t\t Price Of The Product\n";
    cin>>price;
    cout<<"\n\t\t\t Discount On The Product\n";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }else{
       data>>c>>n>>p>>d;

       while(!data.eof()){
        if(c==pcode){
            token++;
        }
        data>>c>>n>>p>>d;
       }
       data.close();

    }

    if(token>=1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }

     cout<<"\n\t\t\t Record Inserted\n";

  }

  void shopping::edit(){
  fstream data, data1;
  int pkey;
  int token=0;
  int c;
  float p,d;
  string n;
  cout<<"\n\n\n\t\t\t\  Modify The Product \n";
  cout<<"\n\n\n\t\t\t\  Product Code: \n";
  cin>>pkey;
  data.open("database.txt",ios::in);

  if(!data){
    cout<<"\n File doesn't exist\n";

  }
  else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        if(pkey==pcode){
            cout<<"\n\t\t New Product code :";
            cin>>c;
            cout<<"\n\t\t Name of Product  :";
            cin>>n;
            cout<<"\n\t\t Product price    :";
            cin>>p;
            cout<<"\n\t\t Product discount :";
            cin>>d;
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\n\t\t Record Edited ";
            token++;
        }else{

        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

        }
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0){
        cout<<"\n\t\t Record not found sorry!";
    }
  }

  }
 void shopping::rem(){
 fstream data,data1;
 int pkey;
 int token=0;
  cout<<"\n\n\n\t\t\t\   Delete Product \n";
  cout<<"\n\n\n\t\t\t\  Product Code: \n";
  cin>>pkey;
  data.open("database.txt",ios::in);

  if(!data){
    cout<<"\n File doesn't exist\n";

  }

  else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        if(pkey==pcode){
          cout<<"\n\t\t Record Deleted ";
            token++;

        }else{

        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

        }
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0){
        cout<<"\n\t\t Record not found sorry!";
    }
  }
 }

 void shopping::List(){

  fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n_____________________________________\n\n";
  cout<<"Pcode\t\tPname\t\tPrice\n";
  cout<<"\n\n_____________________________________\n\n";
   data>>pcode>>pname>>price>>dis;
   while(!data.eof()){
    cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;
   }
   data.close();
 }

 void shopping::receipt(){
 fstream data;
 int arrc[100];
 int arrq[100];
 char choice;
 int c=0;
 float amount=0;
 float dis=0;
 float total=0;
 cout<<"\n\n\n\t\t\t\t Reciept ";
 data.open("database.txt",ios::in);
 if(!data){
    cout<<"\n\n Empty DataBase";
 }else{
   data.close();
   List();
   cout<<"\n\n_____________________________________\n\n";
   cout<<"                  Place The Order            ";
   cout<<"\n\n_____________________________________\n\n";
   do{
    m:
    cout<<"\n\nEnter Product Code";
    cin>>arrc[c];
    cout<<"\n\nEnter Product Quantity";
    cin>>arrq[c];
    for(int i=0;i<c;++i){
        if(arrc[c]==arrc[i]){
            cout<<"\n\n Already Selected Product";
            goto m;
        }
    }
    c++;
    cout<<"/n/nWant To Buy another product? if yes press y else n";
   }while(choice=='y');


   cout<<"\n\n\t\t\t       RECEIPT                    ";
   cout<<"\nProduct no\tProduct Name\tProduct Quantity\tProduct Price\tAmount\tAmount with discount\n";

   for(int i=0;i<c;++i){
    data.open("database.txt",ios::in);
     data>>pcode>>pname>>price>>dis;
     while(!data.eof()){
        if(pcode==arrc[i]){
            amount=price*arrq[i];
            dis=amount-(amount*dis/100);
            total=total+dis;
            cout<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\n"<<amount<<"\n"<<dis<<"\n";
        }
        data>>pcode>>pname>>price>>dis;
     }

   }
    data.close();
 }

 cout<<"\n\n_____________________________________\n\n";
   cout<<"Total Amount: "<<total;
   cout<<"\n\n_____________________________________\n\n";

 }
