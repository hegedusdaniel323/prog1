#include "std_lib_facilities.h"


struct Person {
    Person() { }
    Person(string ff, string ll, int aa);

    string first_name() const { return first; }
    string last_name() const { return last; }
    int age() const { return a; }

private:
    string first;
    string last;
    int a;
};

Person::Person(string ff, string ll, int aa)
    : first{ff}, last{ll}, a{aa}
{
    if (aa < 0 || 150 < aa) error("invalid age");
    
    string nn = ff + ll;
    for (char c : nn) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("bad char in names");
                break;
            default:
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Person& p) {
    return os << p.first_name() << ' '
              << p.last_name() << ' '
              << p.age() <<endl;
}

istream& operator>>(istream& is, Person& p) {
    string f;
    string l;
    int a;
    
    is >> f >> l >> a;
    p = Person(f, l, a);
    
    return is;
}

int main()
try {
    /*Person p1 { "Goofy", 63 };
    cout << p1.name << ' ' <<p1.age<<endl;*/
    
    /*Person p2;
    cin >>p2;
    cout<<p2;*/

    Person p3;
    vector<Person> vp;

    cout<<"Enter the firstname, the lastname and the age! Set firstname to break to terminate!\n";
    while(cin >> p3){
        if (p3.first_name() == "break") break;
        vp.push_back(p3);
    }
    cout<<"\nThe list of names and ages:\n";
    for (int i = 0; i < vp.size(); i++){
        cout << vp[i];
    }
    
    return 0;
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown error!\n";
    return 2;
}