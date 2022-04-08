#include "std_lib_facilities.h"

template<typename it1, typename it2>
it2 masol(it1 t1,it1 t2,it2 t3)
{
	while(t1!=t2)
	{
		*t3=*t1;
		t1++;
		t3++;
	}
	return t3; 
}

int main()
{
	array<int,10>tomb={0,1,2,3,4,5,6,7,8,9};
	vector<int>vectorarray;
	for(int i=0;i<10;i++)
	{
        vectorarray.push_back(i);
	}
	list<int>listarray;
	list<int>::iterator it;
	it=listarray.begin();
	for(int i=0;i<10;i++)
	{
        listarray.push_back(i);
	}

	array<int,10>tomb2=tomb;
	vector<int>vectorarray2=vectorarray;
	list<int>listarray2=listarray;

    for(int i=0;i<10;i++)
    {
        tomb[i]=tomb[i]+2;
        vectorarray[i]=vectorarray[i]+3;
    }
    
    
    for(it=listarray.begin();it!=listarray.end();it++)
    {
        *it=*it+5;
    }
    
    masol(listarray.begin(),listarray.end(),listarray2.begin());
    
    cout<<"Masolt listaelemek:"<<endl;	
    it=listarray2.begin();
    while(it!=listarray2.end())
    {
    	cout<<*it<<endl;
    	it++;
    }
    cout<<endl;
    
    vector<int>::iterator vecit;
    int elem=3;
    vecit=find(begin(vectorarray),end(vectorarray),elem);
    if(vecit!=vectorarray.end())
    {
    	cout<<"A(z) "<<elem<<" a(z) "<<distance(vecit,vectorarray.begin())<<". pozicioban talalhato."<<endl; 
    }else
    {
    	cout<<"A(z) "<<elem<<" nem talalhato."<<endl;
    }
    
    elem=321312;
    vecit=find(begin(vectorarray),end(vectorarray),elem);
    if(vecit!=vectorarray.end())
    {
    	cout<<"A(z) "<<elem<<" a(z) "<<distance(vecit,vectorarray.begin())<<". pozicioban talalhato."<<endl; 
    }else
    {
    	cout<<"A(z) "<<elem<<" nem talalhato."<<endl;
    }
}