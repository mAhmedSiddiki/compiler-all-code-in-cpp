#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int a=0,c=0;

    cout<<"Write a string: ";
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s.at(i)=='a' || s.at(0)==' '){
            a++;
            if(i==s.size()-1){
                break;
            }
        }
        if(s.at(i)=='a' && s.at(i+1)=='b' || s.at(0)==' ' && s.at(i+1)=='b'){
            cout<<"String is accepted -> [ a*b+ ]"<<endl;
            c=1;
            break;
        }
        if(s.at(s.size()-1)=='b' && s.at(s.size()-2)=='b' && s.at(s.size()-3)=='a'){
            cout<<"String is accepted -> [ abb ]"<<endl;
            c=1;
            break;
        }
    }

    if(a==s.size()){
        cout<<"String is accepted -> [ a* ]"<<endl;
    }else if(c==0){
        cout<<"String is not accepted."<<endl;
    }

    return 0;
}
