#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bitTransfer(string input, int byte, int bit, int len) {
        int shift,shift1,shift2=0;
        if(bit+1 >= len){ //one byte
            shift = bit-len+1;
            string hexa = convert(bit,len);
            cout<<"data["<<byte<<"]="<<"("<<input <<"<<"<< shift<<")"<<"&"<<hexa<<"\n";
        } else {//two bytes
            shift1 = len-bit-1;
            string hexa1 = convert2(bit,bit+1);
            shift2 = 9-len+bit;
            string hexa2=convert3(9-len+bit,len-bit-1);
            cout<<"data["<<byte<<"]="<<"("<<input <<">>"<< shift1<<")"<<"&"<<hexa1<<"\n";
            cout<<"data["<<byte+1<<"]="<<"("<<input <<"<<"<< shift2<<")"<<"&"<<hexa2<<"\n";
        }


    }
    string convert(int bit, int len) {
        //cout<<"test"<<bit<<len<<"\n";
        char str[8]={'0','0','0','0','0','0','0','0'};
        for (int i=0;i<=len-1;i++)
            str[7-bit+i]='1';
        string out=str;
        int out1=stoi(out,0,2);


        stringstream stream;
        stream << hex << out1;
        string result( stream.str() );
        return result;
    }
    string convert3(int bit, int len) {
        //cout<<"test"<<bit<<len<<"\n";
        char str[8]={'0','0','0','0','0','0','0','0'};
        for (int i=0;i<=len-1;i++)
            str[i]='1';
        string out=str;
        int out1=stoi(out,0,2);


        stringstream stream;
        stream << hex << out1;
        string result( stream.str() );
        return result;
    }
    string convert2(int bit, int len) {
        //cout<<bit<<len<<"\n";
        char str[8]={'0','0','0','0','0','0','0','0'};
        for (int i=0;i<=len-1;i++)
            str[7-bit+i]='1';
        string out=str;
        int out1=stoi(out,0,2);
        //cout<<out1;

        stringstream stream;
        stream << hex << out1;
        string result( stream.str() );
        return result;
    }
};

int main() {
    freopen("bits.inp","r",stdin);
    freopen("bits.out","w",stdout);
    int n,i;
    char str[100];
    int byte, bit, len;
    Solution aws;
    scanf("%d\n",&n);
    for (i=0;i<n;i++) {
        scanf("%100s %d %d %d\n",str,&byte,&bit,&len);
        string inp = str;
        aws.bitTransfer(inp,byte,bit,len);
    }



return 0;
}
