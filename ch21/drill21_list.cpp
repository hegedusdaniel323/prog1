#include "std_lib_facilities.h"

//defining struct
struct Item {
    string name;
    int iid;
    double value;
};

void print(list<Item> li){
    for (auto l : li)
        cout << l.name << "\t\t" << l.iid <<"\t\t"<< l.value << endl;
    cout<<endl;
}

//for sorting (replaces lambda expression)
bool asc_name(Item l1, Item l2){
	return l1.name < l2.name;
}
bool asc_id(Item l1, Item l2){
	return l1.iid < l2.iid;
}
bool desc_val(Item l1, Item l2){
	return l1.value > l2.value;
}

//erase by name/id
void erase_name(list<Item>& li, string s){
    list<Item>::iterator it = li.begin();
    while(it != li.end()){
        if(it->name == s) li.erase(it++);
        else it++;
    }
}
void erase_id(list<Item>& li, int id){
    list<Item>::iterator it = li.begin();
    while(it != li.end()){
        if(it->iid == id) li.erase(it++);
        else it++;
    }
}


int main(){
    
    //filling the list
    string i_name;
    int i_id;
    double i_value;
    list<Item>li;
    ifstream ifile {"data.txt"};
    while(ifile >> i_name >> i_id >> i_value)
        li.push_back(Item{i_name, i_id, i_value});
    cout<<"Elements of the list:\n";
    print(li);

    //sorting
    cout<<"Sort by name:\n";
    li.sort(asc_name);
    print(li);
    cout<<"Sort by id:\n";
    li.sort(asc_id);
    print(li);
    cout<<"Sort by value(desc):\n";
    li.sort(desc_val);
    print(li);

    //inserting
    cout<<"Inserting elements:\n";
    li.push_back(Item{"horse shoe",99,12.34});
    li.push_back(Item{"Canon S400",9988,499.95});
    print(li);

    //erasing
    cout<<"Erasing elements:\n";
    int del_id = 3;
    string del_name = "alma";
    erase_name(li, del_name);
    erase_id(li, del_id);
    print(li);

    return 0;
}