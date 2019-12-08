#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream file;

    file.open("paragraph.txt");

    string word;

    while(file >> word){
        cout<<word<<endl;
    }

    file.close();

    return 0;
}
