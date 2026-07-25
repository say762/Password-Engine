#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

void Score(int score){
    if(score==40){
        cout<<"PASSWORD RATING: VERY STRONG "<<endl;
    }

    else if(score=20){
        cout<<"PASSWORD RATING: WEAK"<<endl;
    }

    else{
        cout<<"PASSWORD RATING: VERY WEAK (NEEDS TO BE CHANGED)"<<endl;
    }
}

bool check_dictionary(const string& password){
    ifstream common_file("common-passwords.txt",ios::in);

    if(!common_file){
        throw runtime_error("common-passwords.txt couldnt be opened!");
        }

        string common_pass;
        while(common_file>>common_pass){
            if(password==common_pass){
                return true;
            }
        }
        return false;

}

void PasswordStrength(const string& password){

    bool upper=false;
    bool digit=false;
    bool symbol=false;
    int score=0;
    
    if(password.length()<8){
        cout<<"\n Length of the password is less than 8 characters"<<endl;
    }
    else{
        cout<<"Password is 8 or 8+ characters"<<endl;
        score += 10;
    }

    for(char c : password){
        if(isupper(c)){
            upper=true;
        }

         if(isdigit(c)){
            digit=true;
        }

         if(ispunct(c)){
            symbol=true;
        }
    }

    if(!upper){
        cout<<"Password does not have any uppercase characters."<<endl;
    }
     else{
        cout<<"Password has uppercase characters"<<endl;
        score+=10;
    }
   
    if(!digit){
        cout<<"Password does not have any digits"<<endl;
    }
     else{
        cout<<"Password has digits"<<endl;
        score+=10;
    }

    if(!symbol){
        cout<<"Password does not have any symbols"<<endl;
    }
     else{
        cout<<"Password has symbols"<<endl;
        score+=10;
    }
     
    
    Score(score);

    }

int main(){
     
    try{
        string user_input , pass_input , choice_input;
do{

    ofstream user_file("passwords.txt",ios::app);

    if(!user_file){
        throw runtime_error("Error! Couldn't write to 'password.txt' file");
    }

    cout<<"Enter your username"<<endl;
    cin>>user_input;

    cout<<"Enter your password"<<endl;
    cin>>pass_input;

    user_file<<setw(10)<<user_input<<" "<<setw(10)<<pass_input<<endl;
    user_file.close();

    if(check_dictionary(pass_input)){
        cout<<"\n WEAK PASSWORD (found in the common password list)"<<endl;
    }
    else{
        cout<<"\n Password not found in the common password list"<<endl;
        cout<<"\n Checking the stregnth of the password entered"<<endl;
        PasswordStrength(pass_input);
    }
    cout<<"Write yes to recheck your password or anything else to quit"<<endl;
    cin>>choice_input;

    
    for(char &c:choice_input){
        c=tolower(c);
    }

  

}while(choice_input =="yes");
} 

    catch(const exception &e){
        cerr<<"Ensure that the 'common_passwords.txt' exists in the same directory"<<endl;
        return 1;
    }

        cout<<"Exiting the password engine"<<endl;
   return 0; 
}
