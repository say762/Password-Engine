#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

bool check_dictionary(const string& password){
    ifstream common_file("common-passwords.txt",ios::in);

    if(!common_file){
        throw runtime_error("common-passwords.txt couldnt be opened!");
        }

        string common_pass;
        while(common_file>>common_pass){
            return true;
        }
        return false;

}

int main(){
   
    string password,username,choice;
    try{
do{
    
    ofstream user_file("passwords.txt",ios::app);

    if(!user_file){
        throw runtime_error("Error! Couldn't write to 'password.txt' file");
    }

    cout<<"Enter your username"<<endl;
    cin>>username;

    cout<<"Enter your password"<<endl;
    cin>>password;

    user_file<<setw(10)<<username<<" "<<setw(10)<<password<<endl;
    user_file.close();

    if(check_dictionary(password)){
        cout<<"\n WEAK PASSWORD (found in the common password list)"<<endl;
    }
    else{
        cout<<"\n Passwrod not foudn int he common password list"<<endl;
        cout<<"\n Checking the stregnth of the password entered"<<endl;
    }
    cout<<"Write yes to recheck your password or anything else to quit"<<endl;
    cin>>choice;

    
    for (char &c:choice){
        c=tolower(c);
    }

  
    common_file.close();
}
}while(choice =="yes");
   return 0; 
}
