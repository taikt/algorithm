// convert double to binary

#include <bits/stdc++.h>
using namespace std;

string print_binary(string val){
    int pos = val.find('.', 0);
    cout<<pos<<"\n";
    int intpart = atoi(val.substr(0, pos).c_str()); // intpart =19 => 10011
    cout<<intpart<<"\n";
    double decpart = atof(val.substr(pos, val.length()-pos).c_str());
    cout<<decpart<<"\n"; // decpart=0.25 => 0.01

    string intstr = "", decstr = "";
    // convert 19 in decimal type to 10011 in binary type
    while(intpart > 0){
        if(intpart&1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1; // intpart =/ 2

    }
    // convert 0.25 in decimal type to 0.01 in binary type
    while(decpart > 0){
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
    return intstr + "." + decstr;
}

int main(){
    string val = "19.25";
    cout<<print_binary(val)<<endl; // 10011.01
    return 0;
}
