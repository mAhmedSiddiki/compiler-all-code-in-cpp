#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector <string> v_g;

    v_g.push_back("E=Te");
    v_g.push_back("e=+Te");
    v_g.push_back("e=#");
    v_g.push_back("T=Ft");
    v_g.push_back("t=*Ft");
    v_g.push_back("t=#");
    v_g.push_back("F=(E)");
    v_g.push_back("F=i");

    cout<<"Grammar ->"<<endl;

    for(int i=0; i!=v_g.size(); i++) {
        cout<<"\t"<<v_g[i]<<"\n";
    }
    cout<<"\n\n";

    int i=0;
start_first:
    while(i!=v_g.size()) {
        if((i>0)&&(v_g[i].at(0)==v_g[i-1].at(0))) {
            i++;
            continue;
        } else {
            cout<<"First("<<v_g[i].at(0)<<") = {";
            for(int j=0; j!=v_g.size(); j++) {
                if(v_g[i].at(2)==v_g[j].at(0)) {
                    //a = v_g[j].at(0);
                    for(int k=0; k!=v_g.size(); k++) {
                        if(v_g[j].at(2)==v_g[k].at(0)) {
                            /*for(int l=0;l!=v_g.size();l++){
                                if(v_g[k].at(2)==v_g[l].at(0)){

                                }
                            }*/cout<<v_g[k].at(2)<<",";
                            if(v_g[k].at(0)==v_g[k+1].at(0)) {
                                cout<<v_g[k+1].at(2);
                            }
                            cout<<"}\n";
                            i++;
                            goto start_first;
                        }
                    }
                    cout<<v_g[j].at(2)<<",";
                    if(v_g[j].at(0)==v_g[j+1].at(0)) {
                        cout<<v_g[j+1].at(2);
                    }
                    cout<<"}\n";
                    i++;
                    goto start_first;
                }
            }
            cout<<v_g[i].at(2)<<",";
            if(v_g[i].at(0)==v_g[i+1].at(0)) {
                cout<<v_g[i+1].at(2);
            }
            cout<<"}\n";
            i++;
            goto start_first;
        }
    }
    cout<<endl<<endl;










    string save,rr,last=",$}";
    vector<string> v_s;
    int a=0,e=0;
start_follow:
    while(a!=v_g.size()) {
        if((a>0)&&(v_g[a].at(0)==v_g[a-1].at(0))) {
            a++;
            continue;
        } else {
            rr = v_g[a].at(0);
            save.append(rr);
            save.append("=");
            cout<<"Follow("<<v_g[a].at(0)<<") = {";
            for(int b=0; b!=v_g.size(); b++) {
                for(int c=2; c!=v_g[b].size(); c++) {
                    if(v_g[a].at(0)==v_g[b].at(c)) {
                        if(v_g[b].at(c)==v_g[b].at(v_g[b].size()-1)) {
                            for(int e=0; e!=v_g.size(); e++) {
                                if(v_g[b].at(0)==v_s[e].at(0)) {
                                    for(int f=2; f!=v_s[e].size(); f++) {
                                        cout<<v_s[e].at(f);
                                        rr = v_s[e].at(f);
                                        save.append(rr);
                                    }
                                    cout<<endl;
                                    a++;
                                    v_s.push_back(save);
                                    save = "";
                                    goto start_follow;
                                }
                            }
                        } else {
                            for(int d=0; d!=v_g.size(); d++) {
                                if(v_g[b].at(c+1)==v_g[d].at(0)) {
                                    cout<<v_g[d].at(2)<<",";
                                    rr = v_g[d].at(2);
                                    save.append(rr);
                                    rr = ",";
                                    save.append(rr);
                                    if(v_g[d].at(0)==v_g[d+1].at(0)) {
                                        if(v_g[d+1].at(2)=='#') {
                                            for(int f=2; f!=v_s[b].size(); f++) {
                                                cout<<v_s[b].at(f);
                                                rr = v_s[b].at(f);
                                                save.append(rr);
                                            }
                                            cout<<endl;
                                            a++;
                                            v_s.push_back(save);
                                            save = "";
                                            goto start_follow;
                                        } else {
                                            cout<<v_g[d+1].at(2);
                                            rr = v_g[d+1].at(2);
                                            save.append(rr);
                                        }
                                    }
                                    cout<<endl;
                                    a++;
                                    v_s.push_back(save);
                                    save = "";
                                    goto start_follow;

                                }
                            }
                            rr = v_g[b].at(c+1);
                            save.append(rr);
                            cout<<v_g[b].at(c+1)<<",$}"<<endl;
                            save.append(last);
                            v_s.push_back(save);
                            save = "";

                            a++;
                            goto start_follow;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
