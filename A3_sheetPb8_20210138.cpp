#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Stack{
    int size,top;
    T *arr;
public:
    Stack(int s);
    void push(T x);
    bool empty();
    void pop();
    int get_size();
    T get_top();
    Stack(const Stack& obj);
    Stack<T>& operator=(const Stack<T>& obj); //assignment operator
    ~Stack();
    class  StackOverflowException{
    public:
        StackOverflowException(){}
        void  OverflowException(){
            cout<<"Stack is already full"<<endl;
        }
    };
    class  StackEmptyException{
    public:
        StackEmptyException(){}
        void  EmptyException(){
            cout<<"Stack is already empty"<<endl;
        }
    };
};
template <typename T>
Stack<T>::Stack(int s){
    size=s;
    arr=new T(size);
    top=-1;
}
template <typename T>
void Stack<T>::push(T x) {
    if(top==(size-1)){
        throw StackOverflowException();
    }
    cout<<"\ninserted element : "<<x<<endl;
    top+=1;
    arr[top]=x;
}
template <typename T>
bool Stack<T>::empty(){
    if(top==-1) {
        return true;
    }else {
        return false;
    }
}
template <typename T>
void Stack<T>::pop(){
    if(empty()){
        throw StackEmptyException();
    }else {
        T pop_element = arr[top];
        top--;
        cout << "popped element: " << pop_element;
    }
}
template <typename T>
int Stack<T>::get_size() {
    cout<< "Size: ";
    return size;
}
template <typename T>
T Stack<T>::get_top() {
    if(empty()){
        throw StackEmptyException();
    }else {
        T element = arr[top];
        cout << "Top element: ";
        return element;
    }
}
template <typename T>
Stack<T>::~Stack(){
    delete[] arr;
}
template <typename T>
Stack<T>::Stack(const Stack& obj){
    cout<<"copy constructor\n";
    size=obj.size;
    top=obj.top;
    arr =new T[size];
    for(int i=0;i<size;i++){
        arr[i]=obj.arr[i];
    }
}
template <typename T>
Stack<T> & Stack<T>:: operator=(const Stack<T>& obj){
    cout<<"assignment operator\n";
    if(this != &obj){
        if(this -> size != obj.size){
            delete[]arr;
            size=obj.size;
            top=obj.top;
            arr=new T[size];
        }
        for(int i=0;i<size;i++){
            arr[i]=obj.arr[i];
        }
    }
    return *this;
}
int manageStack(){
    int option ;
    cout<<"\n1.push"<<endl;
    cout<<"2.pop "<<endl;
    cout<<"3.size "<<endl;
    cout<<"4.top element"<<endl;
    cout<<"5.is the stack empty"<<endl;
    cout<<"6.exit"<<endl;
    cin>> option;
    return option;
}
int main() {
    int op;
    int n;
    cout<<"create a stack \nenter the size you want: "<<endl;
    cin>>n;
    Stack<int>s(n);
    while (op!=6){
        try {
            op = manageStack();
            if (op == 1) {
                int x;
                cin >> x;
                s.push(x);
            }
            if (op == 2)
                s.pop();
            if (op == 3)
                cout << s.get_size() << endl;
            if (op == 4)
                cout << s.get_top() << endl;
            if (op == 5)
                cout << s.empty();
        }
        catch (Stack<int>::StackOverflowException a){
            a.OverflowException();
        }
        catch (Stack<int>:: StackEmptyException b){
            b.EmptyException();
        }
    }
//_______________________
    Stack<int>s1(3);
    Stack<int>s2(4);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s2.push(40);
    s2.push(50);
    s2.push(60);
    s2.push(70);
    s1=s2;                        //assignment operator
    cout<<s1.get_size()<<endl;
    Stack<int>s3=s2;              //copy constructor
    cout<<s3.get_size()<<endl;
}
