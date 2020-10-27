#include<iostream>
using namespace std;
template <typename T>
class stack {
	const int n;
	int top_ind;
	T* data;
public:
	stack(const int& s = 0) : n(s) {
		top_ind = -1;
		data = new T[n];
	}
	~stack(){
		delete[] data;
	}
	void push(const T& val) {
		top_ind++;
		data[top_ind] = val;
	}
	T top() const {
		return data[top_ind];
	}
	void pop() {
		top_ind--;
	}
	bool empty() const {
		return top_ind == -1;
	}
	void make_empty() {
		top_ind = -1;
	}
	bool full() const {
		return top_ind == n - 1;
	}
};
int main() {
	stack<int> s(5);
	int i = 2;
	cout << "Data is entered in this sequence:" << endl;
	while (!s.full()) {
		s.push(i);
		cout << s.top() << "\t";
		i *= i;
	}
	cout << endl << "Data can be retrieved in this sequence:" << endl;
	while (!s.empty()) {
		cout << s.top() << "\t";
		s.pop();
	}
	return 0;
}