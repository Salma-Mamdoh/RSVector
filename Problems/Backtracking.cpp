// problem 4.cpp : 
#include<iostream>
#include<vector>
using namespace std;
vector<string>vec{ "RED ","GREEN ","YELLOW " };
void fun(int n, string answer,bool Yellow) {
    if (n == 0) {
        cout << answer << endl;
    }
    else {
        if (Yellow==0) {
            fun(n - 1, answer + vec[0],0);
            fun(n - 1, answer + vec[1],0);
        }
        else {
            fun(n - 1, answer + vec[0],1);
            fun(n - 1, answer + vec[1],1);
            fun(n - 1, answer + vec[2],1);
        }
    }
}
int main() {
    cout << "with red & green" << endl;
    fun(3, "", 0);
    cout << endl;
    cout << "with red & green & yellow" << endl;
    fun(3, "", 1);

}