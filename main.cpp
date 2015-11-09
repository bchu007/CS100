#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*
int at(int i);
void swap(int i, int j);
void insert(int element);
void print();
int size();
void set_sort(SortAlgorithm* s);
void sort();
*/
class SortAlgorithm; 
 
class Container {
	protected:
		SortAlgorithm* type;	
	public:
		virtual int at(int i) = 0;
		virtual void swap(int i, int j) = 0;
		virtual void insert(int element) = 0;
		virtual void print() = 0;
		virtual int size() = 0;
		virtual void set_sort(SortAlgorithm* c) = 0;
		virtual void sort() = 0;
		
};

class VectorContainer : Container {

	private:
		vector<int> v;
		SortAlgorithm* type;	
	public:
		virtual int at(int i) {
			return v.at(i);		
		}
		virtual void swap(int i, int j) {
			int x = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = x;
		}
		virtual void insert(int element) {
			v.push_back(element);
		}
		virtual void print() {
			for(int i = 0; i < v.size(); i++) {
				cout << v.at(i);
			}
			cout << endl; 
		}
		virtual int size() {
			return v.size();	
		}
		virtual void set_sort(SortAlgorithm* s) {
			this->type = type;	
		}
		virtual void sort() {
			SortAlgorithm::sort();
		}
					
};

class ListContainer : Container {
	private:
		list<int> l;	
	public:
		virtual int at(int i) {
			list<int>::iterator it;
			for(it = l.begin(); it != l.end(); it++)
			{
				if(*it == i)
				{
					return *it;
				}
			}	
		}
		virtual void swap(int i, int j) {
			list<int>::iterator it;
			list<int>::iterator jt;
			list<int>::iterator kt;
			int x;
			int y;
				
			for(kt = l.begin(); kt != l.end(); kt++)
			{
				if(*kt == i) {
					it = kt;
					x = *it;
				}
				else if(*kt == j) {
					jt = kt;
					y = *jt;
				}			
			}
			it* = y;
			jt* = x;		
		}
		virtual void insert(int element) {
			l.insert(l.begin(), element);
		}
		virtual void print() {
			list<int>::iterator it;
			for(it = l.begin(); it != l.end(); it++) {
				cout << *it << " " << flush;
			}
			cout << endl;
		}
		virtual int size() {
			return l.size();
		}
		virtual void set_sort(SortAlgorithm* s) {
			type = s;
		}
		virtual void sort() {
			
		}

};

class SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) = 0;	
};

class BubbleSort : SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) {
			cout << "Bubble Sort" << endl;
			for(int i = 0; i ) {
				for(int j = 0; j < 
		}
};

class SelectionSort : SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) {
			cout << "Selection Sort" << endl;
		}	
};

class MergeSort : SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) {
			cout << "Merge Sort" << endl; //test
		}
};



int main() {
	VectorContainer vc;
	MergeSort ms;	
	vc.set_sort(ms);
	vc.sort();
	
	return 0; 
}
