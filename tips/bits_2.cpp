#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bitTransfer(string input, int byte, int bit, int len) {
        int shift,shift1,shift2=0;
        int diff = bit -len;
        if (-1 <= diff && diff <= 6) { // 1byte
            shift = diff + 1;
            string x=convertBin(bit,diff+1);
             cout<<"data["<<byte<<"]="<<"("<<input <<"<<"<< shift<<")"<<"&"<<"0x"<<x<<"\n";
        } else if (-9 <= diff && diff <= -2) // 2 byte {
        {
            shift1 = -diff - 1;
            string x=convertBin(bit,0);
            cout<<"data["<<byte<<"]="<<"("<<input <<">>"<< shift1<<")"<<"&"<<"0x"<<x<<"\n";
            shift2 = 8 - shift1;
            string y=convertBin(7,diff+9);
            cout<<"data["<<byte+1<<"]="<<"("<<input <<"<<"<< shift2<<")"<<"&"<<"0x"<<y<<"\n";
        } else
            cout<<input<<" -- Fail --\n";

    }
    string convertBin(int i, int j) {
        int m=7-i, n=7-j;
        char str[8]={'0','0','0','0','0','0','0','0'};
        for (int i=m;i<=n;i++)
            str[i]='1';
        string out=str;
        int out1=stoi(out,0,2);


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
