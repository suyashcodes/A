#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    typedef map<string,int> mapType;
    mapType statePop;
    statePop["Maharashtra"]=1234;
    statePop["Rajasthan"]=2555;
    statePop["Uttarpradesh"]=9899;
    statePop["Asam"]=546;
    string str;
    cout<<"Enter state name to get population : ";
    cin>>str;
    mapType :: iterator it=statePop.find(str);
    if (it==statePop.end()) {
        cout<<"\nNo State Found\n";
    }
    else{
        cout<<"\nPopulation of state "<<it->first<<" is "<<it->second<<endl;
    }
    return 0;
}