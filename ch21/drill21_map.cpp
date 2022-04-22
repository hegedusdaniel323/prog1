#include "std_lib_facilities.h"

ostream& operator<<(ostream& os,map<string,int> m){
    for(auto map : m)
        cout<<map.first<<'\t'<<map.second<<endl;
    cout<<endl;
    return os;
}
ostream& operator<<(ostream& os,map<int,string> m){
    for(auto map : m)
        cout<<map.first<<'\t'<<map.second<<endl;
    cout<<endl;
    return os;
}

istream& operator>>(istream& is,map<string,int>& m)
{
    string key;
    int val;
    while(cin>>key>>val)
        if(key !="x") m[key] = val;
    return is;
}


int main(){
    map<string,int> msi;
    msi["lecture0"]=20;
    msi["lecture1"]=21;
    msi["lecture2"]=22;
    msi["lecture3"]=23;
    msi["lecture4"]=24;
    msi["lecture5"]=25;
    msi["lecture6"]=26;
    msi["lecture7"]=27;
    msi["lecture8"]=28;
    msi["lecture9"]=29;

    msi.erase(msi.begin(),msi.end());
    cout<<"Enter string,int pairs, set the string to x to terminate!\n";
    cin>>msi;
    cout<<endl<<msi;

    vector<string>keys;
    for(auto map : msi)
        keys.push_back(map.first);
    
    int sum=0;
    for(auto v : keys)
        sum += msi[v];
    cout<<"Sum of values: "<<sum<<endl<<endl;

    
    map<int,string> mis;
    for(auto v : keys)
        mis.insert(pair<int,string>(msi[v],v));
    cout<<mis;
    
    
    return 0;
}