#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    map<string,int> m;
    for(int i=0;i<s1.length();i++){
        for(int j=1;j+i<=s1.length();j++){
            string tmp = s1.substr(i,j);
            if(m[tmp]) continue;
            else{
                    m.insert(make_pair(tmp,0));
                    reverse(tmp.begin(),tmp.end());
                    m.insert(make_pair(tmp,1));
            }
        }
    }
    map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
return 0;
}
