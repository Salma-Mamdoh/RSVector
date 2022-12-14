#include <iostream>
#include <fstream>
using namespace std;

bool dictionary(string &word)
{
    ifstream file;
    file.open("dictionary.txt");
    if(file.is_open()) {
        string data;
        while (!file.eof()) {
            file >> data;
            if (data.compare(word) == 0)
                return true;
        }
        return false;
    }else cout<<"File open error! ";
}
void sentenceSeparation(string str, int size, string sentence)
{
    for (int i=1; i<=size; i++)
    {
        string prefix = str.substr(0, i);
        if (dictionary(prefix))
        {
            if (i == size)
            {
                sentence += prefix;
                cout << sentence << endl;
                return;
            }
            sentenceSeparation(str.substr(i, size-i), size-i,sentence + prefix + " ");
        }
    }s
}
void sentenceInf(string str)
{
    sentenceSeparation(str, str.size(), "");
}
int main()
{
    cout << "First Test:"<<endl;
    sentenceInf("iwearmyshoes");

    cout << "\nSecond Test:"<<endl;
    sentenceInf("iwillmeetyoutomorrow");

    cout << "\nThird Test:"<<endl;
    sentenceInf("letusplayfootballtonight");
}
