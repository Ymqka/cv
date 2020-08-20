#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Variant {
public:
	
private:

	double double_value;
	string string_value;
};


// enum Color {red,green,blue}

int main() {


	string zzz = "zxc";
	string qwe = typeid("zzz").name();
	cout << qwe << endl;
	// vector<val> v = {10,"string"};

	// for(auto it = v.begin(); it != v.end(); it++) {
	// 	cout << *it << endl;
	// }

	return 0;
}
