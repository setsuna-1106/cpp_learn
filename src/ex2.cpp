#include <iostream>

int main() {
    int val=1,sum=0;
    while(val<=10){
        sum+=val;
        val++;
    }
    std::cout<<"the sum is "<<sum<<std::endl;
}
