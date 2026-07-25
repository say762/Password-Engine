#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
   
    string password,username;
    string choice;
do{
    ifstream common_file("common-passwords.txt",ios::in);
    ofstream user_file("passwords.txt",ios::app);

    if(!common_file || !user_file){
        cout<<"Error! Couldn't open the file"<<endl;
        return 1;
    }

    cout<<"Enter your username"<<endl;
    cin>>username;

    cout<<"Enter your password"<<endl;
    cin>>password;

    user_file<<setw(10)<<username<<" "<<setw(10)<<password<<endl;
    user_file.close();

    string common_pass;
    bool weak=false;
    
    while(common_file>>common_pass){
        if(password==common_pass){
            weak= true;
            break;
        }
    }

    if(weak){
        cout<<"Weak password"<<endl;
    }

    else{
        cout<<"Strogn password"<<endl;
    }
    
    cout<<"Write yes to recheck your password or anything else to quit"<<endl;
    cin>>choice;

    
    for (char &c:choice){
        c=tolower(c);
    }

  
    common_file.close();
}while(choice =="yes");
   return 0; 
}
