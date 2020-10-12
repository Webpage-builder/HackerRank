#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <string,string> m;
void add(int &c,string t){
    if(!c)return;
string tag,attr,val,temp;
getline(cin,temp);
int i=1,j;
if(temp[i]!='/'){
    while(temp[i]!=' ' && temp[i]!='>')i++;
    tag=temp.substr(1,i-1);
    if(t!="")tag=t+"."+tag;
    while(temp[i]!='>'){
        j=++i;
        while(temp[i]!=' ')i++;
        attr=temp.substr(j,i-j);
        while(temp[i]!='"')i++;
        j=++i;
        while(temp[i]!='"')i++;
        val=temp.substr(j,i-j);
        i++;
        m[tag+"~"+attr]=val;
    }
}
else{
    while(temp[i]!='>')i++;
    if(t.length()>i-2)
        tag=t.substr(0,t.length()-i+1);
    else
        tag="";
}
add(--c,tag);
}

int main() {
    int n,q;
    cin>>n>>q;
 cin.ignore();
 string w;
 add(n,"");
 while(q--){
getline(cin,w);
string value=m[w];
if(value=="")
value="Not Found!";
cout<<value<<endl;
 }
    return 0;
}
