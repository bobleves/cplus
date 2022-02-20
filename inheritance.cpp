#include <iostream>
using namespace std;

class Progression {
	Progression(long f = 0)						//ctor
		: first(f), cur(f) { }
//	virtual ~Progression() { };				//destructor
	void printProgression(int n);			//print first n values
	protected:
		virtual long firstValue();			//reset
		virtual long nextValue();				//advance
	protected:
		long first;
		long cur;
};

// member function printProgression is public
void Progression::printProgression(int n) {
	cout << firstValue();
	for (int i = 2; i <= n; i++)
		cout << ' ' << nextValue();
	cout << endl;
}
//firstValue & nextValue are used within the class only hence protected
//both are virtual because will be overriden by different progressions
long Progression::firstValue(){				//reset
	cur = first;
	return cur;
}	
long Progression::nextValue() {				//advance
	return ++cur;
}

// Arithmetic Progression Class
// new member inc provides the value to be added to each new elt of progression
class ArithProgression : public Progression {
public:
	ArithProgression(long i = 1);					//constructor
protected:
	virtual long nextValue();							//advance
protected:
	long inc;															//increment
};
//ctor invokes base class ctor and also initialize inc
ArithProgression::ArithProgression(long i)	//ctor
	: Progression(), inc { }

long ArithProgression::nextValue() {			//advance by adding
	cur += inc;
	return cur;
}

/** Test program for the progression classes */
int main() {
	Progression* prog;
	// test ArithProgression
	cout << "Arithm Progression with default increment: \n";
	prog = new ArithProgression();
	prog->printProgression(10);
	return EXIT_SUCCESS;


}
