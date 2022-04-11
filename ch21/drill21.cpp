#include "std_lib_facilities.h"

struct Item {
    string name;
    int iid;
    double value;
};

void print(vector<Item>& v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i].name<<'\t'<<v[i].iid<<'\t'<<v[i].value<<endl;
    cout<<endl;
}


bool asc_name(Item v1, Item v2){
	return v1.name < v2.name;
}
bool asc_iid(Item v1, Item v2){
	return v1.iid < v2.iid;
}
bool desc_val(Item v1, Item v2){
	return v1.value > v2.value;
}


void erase_name(vector<Item>& v, string s)
{
    for(int i=0; i<v.size(); i++)
        if (v[i].name == s) v.erase(v.begin()+i);
}

void erase_id(vector<Item>& v, int id)
{
    for(int i=0; i<v.size(); i++)
        if (v[i].iid == id) v.erase(v.begin()+i);
}

int main(){
    
    string i_name;
    int i_id;
    double i_value;
    vector<Item>vi;

    ifstream ifile {"data.txt"};

    while(ifile >> i_name >> i_id >> i_value)
        vi.push_back(Item{i_name, i_id, i_value});

    cout<<"Elements of the vector:\n";
    print(vi);

    sort(vi.begin(), vi.end(), asc_name);
    cout<<"Sort by name:\n";
    //print(vi);
    
    sort(vi.begin(), vi.end(), asc_iid);
    cout<<"Sort by id:\n";
    //print(vi);

    sort(vi.begin(), vi.end(), desc_val);
    cout<<"Sort by value(descending):\n";
    //print(vi);

    vi.push_back(Item{"horse shoe",99,12.34});
    vi.push_back(Item{"Canon S400",9988,499.95});
    //print(vi);

    string del_name = "alma";
    int del_id = 3;
    erase_name(vi, del_name);
    erase_id(vi, del_id);
    print(vi);
    

    return 0;
}