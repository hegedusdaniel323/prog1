#include "std_lib_facilities.h"

ostream& operator<<(ostream& os,vector<double> dd){
    for(auto d : dd) cout<<d<<'\n';
    cout<<endl;
    return os;
}
ostream& operator<<(ostream& os,vector<int> dd){
    for(auto d : dd) cout<<d<<'\n';
    cout<<endl;
    return os;
}

int main(){
    
    vector<double>vd;
    ifstream ifile {"doubles.txt"};
    double d;
    while(ifile >> d)
        vd.push_back(d);
    cout<<vd;

    double d_sum=0;
    int i_sum=0;
    vector<int>vi;
    for(int i=0; i<vd.size(); i++){
        vi.push_back(vd[i]);
        cout<<vd[i]<<"\t\t"<<vi[i]<<endl;
        d_sum += vd[i];
        i_sum += vi[i];
    }
    cout<<endl<<"Sum of vd's elements: "<<d_sum<<endl;
    cout<<"Sum of vi's elements: "<<i_sum<<endl;
    cout<<"Difference of sums: "<<d_sum-i_sum<<endl;

    reverse(vd.begin(),vd.end());
    cout<<endl<<vd;

    double d_avg=d_sum/vd.size();
    cout<<"Mean value of vd: "<<d_avg<<endl;

    vector<double>vd2;
    for(int i=0; i<vd.size(); i++){
        if(vd[i]<d_avg) vd2.push_back(vd[i]);
    }
    cout<<endl<<vd2;



}