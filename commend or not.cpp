#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int c=0;

    cout<<"Enter a line: ";

    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s.at(i)=='/' && s.at(i+1)=='/'){
            cout<<"This line has a comment."<<endl;
            c++;
            break;
        }
    }

    if(c==0){
        cout<<"This line has not a comment."<<endl;
    }


    return 0;
}
