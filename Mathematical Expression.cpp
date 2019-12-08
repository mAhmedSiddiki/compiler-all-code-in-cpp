#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string equ,load,s;
    char c;
    int sl;
    vector <int> v_num;
    vector <char> v_oprt;

    cout<<"Enter mathematical equation: ";
    cin>>equ;

    for(int i=0;i<=equ.size();i++){
        if(equ[i]>='0' && equ[i]<='9'){
            s = equ[i];
            load = load.append(s);
        }else{

            sl = stoi(load);
            v_num.push_back(sl);
            load = "";
        }
        if(equ[i]=='+' || equ[i]=='-' || equ[i]=='*' || equ[i]=='/'){
            c = equ[i];
            v_oprt.push_back(c);
        }
    }

    cout<<equ<<endl<<endl;

    int num1,num2,save,i=0;
    vector <char> sample;

    sample.push_back('*');
    sample.push_back('/');
    sample.push_back('+');
    sample.push_back('-');

    start:
        if(v_oprt.empty()){
            goto endd;
        }else{
            while(i<sample.size()){
                for(int l=0;l<v_oprt.size();l++){
                    if(sample[i] == v_oprt[l]){
                        num1 = v_num[l];
                        num2 = v_num[l+1];

                        if(sample[i] == '*'){
                            save = num1 * num2;
                        }else if(sample[i] == '/'){
                            save = num1 / num2;
                        }else if(sample[i] == '+'){
                            save = num1 + num2;
                        }else if(sample[i] == '-'){
                            save = num1 - num2;
                        }

                        v_num[l] = save;

                        if(v_num[l+1]==v_num[v_num.size()-1]){
                            v_num.pop_back();
                        }else{
                            for(int j=l+1;j<v_num.size()-1;j++){
                                v_num[j] = v_num[j+1];
                            }
                            v_num.pop_back();
                        }
                        if(v_oprt[l+1]=='+' || v_oprt[l+1]=='-' || v_oprt[l+1]=='*' || v_oprt[l+1]=='/'){
                            for(int j=l;j<v_oprt.size()-1;j++){
                                v_oprt[j] = v_oprt[j+1];
                            }
                            v_oprt.pop_back();
                        }else{
                            v_oprt.pop_back();
                        }
                        l--;
                    }
                }
                i++;
            }
            i=0;
            goto start;
        }
        endd:

    cout<<"Result = "<<v_num[0]<<endl;


    return 0;
}
