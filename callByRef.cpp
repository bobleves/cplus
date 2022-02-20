#include <iostream>
using namespace std;
void order(int*, int*);
void order2(int&, int&);
int main(){
	int i = 7, j = 3, a = 5;
	int& ref_a = a; //alias for a
	cout << "ref_a = "<< &ref_a << endl;
	cout << "a = "<< &a << endl;
	cout << i <<'\t' << j << endl;
	//order(&i, &j);
	order2(i,j);
	cout << i <<'\t' << j << endl;
}
void order(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
void order2(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;

}
