#include<iostream>
#include <vector>
using namespace std;

vector<int> pie;

void createPie(string p){
    int m = p.length();
    pie.assign(m, 0);
    int k = 0;
    pie[0] = 0;
    for(int q=1; q<m; q++){
        while(k>0 && p[k]!=p[q])
            k = pie[k];
        if(p[k] == p[q])
            k++;
        pie[q] = k;
    }
    for(int i=1; i<m; i++) if(pie[i]>0) pie[i]--;
}

void KMP(string s, string p){
    int n = s.length();
    int m = p.length();
    int  q = -1;
    for(int i=0; i<n; i++){
        while(q>0 && s[i]!=p[q+1])
            q = pie[q];
        if(s[i] == p[q+1]){
            q+=1;
        }
        if(q==m-1){
            cout << "Pattern found at " << i - m + 1<< endl;
            q = pie[q];
        }
    }
}

int main(){
    string s = "bcfbcfbcxbcfbcx";
    string p = "bcfbcx";
    createPie(p);
    for(int i=0; i<p.length(); i++)
        cout << p[i] << " ";
    cout << endl;

    for(int i=0; i<pie.size(); i++)
        cout << pie[i] << " " ;
    cout << endl;
    cout << s << endl;
    cout << p << endl;

    KMP(s, p);
    return 0;
}
