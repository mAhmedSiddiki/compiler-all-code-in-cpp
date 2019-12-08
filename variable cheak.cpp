#include<iostream>
#include<string>

using namespace std;

int main()
{
    string   s;
    int c=0;

    cout<<"Enter a variable: ";
    cin>>s;

    if(s.at(0)>='a' && s.at(0)<='z' || s.at(0)>='A' && s.at(0)<='Z' || s.at(0)=='_' || s.at(0)=='$'){
        c++;
    }

    for(int i=1;i<s.size();i++){
        if(s.at(i)>='a' && s.at(i)<='z' || s.at(i)>='A' && s.at(i)<='Z' || s.at(i)>='0' && s.at(i)<='9' || s.at(i)=='_' || s.at(i)=='$'){
            c++;
        }
    }

    if(c==s.size()){
        cout<<"Valid"<<endl;
    }else{
        cout<<"Invalid"<<endl;
    }

    return 0;
}
