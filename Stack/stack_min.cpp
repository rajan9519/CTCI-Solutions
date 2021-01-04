/*
    ** Note all these function have the same name,so before running the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/

/*
  Q: Stack Min: How would you design a stack which, in addition to push and pop,
    has a function min which returns the minimum element? Push, pop and min should
    all operate in 0(1) time.
*/

#include<iostream>
#include<stack>

using namespace std;

template<class C>
class minStack {
private:
    stack<pair<C, C> > stk;
public:
    void push(C);
    void pop();
    C top();
    C min();
    bool empty();
};
template<class C>
void minStack<C>::push(C other) {
    if (this->empty()) {
        stk.push(make_pair(other, other));
    }
    else {
        stk.push(make_pair(other, stk.top().second > other ? other : stk.top().second));
    }
}

template<class C>
C minStack<C>::top() {
    return stk.top().first;
}

template<class C>
C minStack<C>::min() {
    return stk.top().second;
}

template<class C>
void minStack<C>::pop() {
    if (!this->empty()) {
        stk.pop();
    }
}

template<class C>
bool minStack<C>::empty() {
    return stk.empty();
}

int main() {
    minStack<int> stk;
    for (int i=0;i<10;i++) {
        stk.push(i);
    }
    for (int i=0;i<10;i++) {
        cout<<stk.top()<<","<<stk.min()<<"\n";
        stk.pop();
    }
    return 0;
}