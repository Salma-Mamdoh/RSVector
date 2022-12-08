#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <iomanip>
using namespace std;

void word_by_word(string filename ){
    fstream file;
    file.open(filename);
    if(file.is_open()) {
        map<string,int> data;
        string word;
        while(file >> word){
            for(int i=0;i<word.length();i++){
                word[i]= tolower(word[i]);
                if(ispunct(word[i])&&word[i]!='-') {
                    word.erase(i);
                }
            }
            if (data.find(word) != data.end() ) {
                data[word]++;
            } else if(word.length()==0)continue;
            else{
                data[word] = 1;
            }
        }
        cout<<setw(15)<<"Words"<<setw(15)<<"Repetition\n\n";
        for (auto it: data) {
            cout << setw(15)<<it.first << " " << setw(7) << it.second << endl;
        }
    }else{
        cout<<"File open error! ";
    }
}
int main(){
    string name;
    cout<<"Enter the file name: "<<endl;
    cin>>name;
    word_by_word(name);
}
