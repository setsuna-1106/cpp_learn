#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string word{"hello world"};
    for(auto c:word){
        cout<<c<<endl;
    }
    return 0;
} 