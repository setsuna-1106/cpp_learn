#include <iostream>

class a{
    int num;
public:
    a(int n):num(n) {}
    a(const a& other){
        std::cout<<"copy"<<std::endl;
    }
};

void func(a){

}

int main(){
    a b{10};
    std::cout<<"1"<<std::endl;
    a c=b;
    std::cout<<"2"<<std::endl;
    func(b);
}