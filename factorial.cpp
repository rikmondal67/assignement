#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector <int> factorialnumber(1,1);


void multiply(vector <int> &number,int multiplier){

    int i = 0;
    int carry = 0;
    int fulldigit = 0;
    int pushElement = 0;
    

    while(i<number.size()){
        fulldigit = ((number[i]*multiplier)+carry);
        pushElement=fulldigit%10;
        carry=fulldigit/10;
        number[i]=pushElement;
        i++;
        // cout<<"pushElement is = "<<pushElement<<",  carry is = "<<carry<<endl;
    }
    while(carry>0){
        number.push_back(carry % 10);
        carry /= 10;
    }
    // cout<<endl<<i<<endl;
    // cout<<endl<<number.size()<<endl;
    // cout<<"=========================================="<<endl;

    

}

void factorial(int i){
    if(i==1){
        return ;
    }
    multiply(factorialnumber,i);
    i--;
    factorial(i);
}

int main(){

    ofstream outputFile("factorial.txt");

    if(!outputFile.is_open()){
        cerr<<"error to open the file"<<endl;
        return 1;
    }

    int fact;
    cout<<"Enter the number whose Factorial to be find"<<endl;

    cin>>fact;
    factorial(fact);
    
    reverse(factorialnumber.begin(),factorialnumber.end());

    cout<<endl;

    for(int i : factorialnumber){
        outputFile<<i;
    }
    outputFile<<endl;
    cout<<"Data written sucessfully"<<endl;

    return 0;
}