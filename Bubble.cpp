#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

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

class Container;

class SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) = 0;	
};



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
		virtual void randHun(int size) = 0;
		
};

class VectorContainer : public  Container {

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
				cout << v.at(i) << " " << flush;
			}
			cout << endl; 
		}
		virtual int size() {
			return v.size();	
		}
		virtual void set_sort(SortAlgorithm* s) {
			this->type = s;	
		}
		virtual void sort() {
			type->sort(this);
		}
		virtual void randHun(int size) {
			for(int i = 0; i < size; i++) {
				v.push_back(rand() % 100 + 1);
			}
		}
};

class ListContainer : public  Container {
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
							
			for(kt = l.begin(); kt != l.end(); kt++)
			{
				if(*kt == i) {
					it = kt;
				}
				else if(*kt == j) {
					jt = kt;
				}			
			}
			swap(*it, *jt);	
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
			this->type = s;
		}
		virtual void sort() {
			type->sort(this);	
		}
		virtual void randHun(int size) {
			for(int i = 0; i < size; i++) {
				l.insert(l.begin(), rand() % 100 + 1);
			}
		}


};


class BubbleSort : public SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) {
			cout << "BUBBLESORT: " << flush;
			int size = c->size();
			for(int i = 0; i < size - 1; i++) {
				for(int j = 0; j < (size - i - 1); j++) {
					if(c->at(j) > c->at(j+1)) {
						c->swap(j, j+1);
					}
				}
			}	
		}
};

class SelectionSort : public SortAlgorithm {
	private:
		
	public:
	
		virtual void sort(Container* c) {
			cout << "SELECTIONSORT: " << flush;
			int n = c->size();
			int pos_min, temp;

			for(int i=0; i< n-1; i++)
			{
				pos_min = i;// set pos_min to the current index

					for(int j = i+1; j< n; j++)
					{
						if(c->at(j) < c->at(pos_min))	
						{
							pos_min = j;
						}
					}
				if(pos_min != i)
				{
					temp = c->at(i);
					c->swap(i,pos_min);
				}
			
			}
		}	
};

class MergeSort : public SortAlgorithm {
	private:
		
	public:
		virtual void sort(Container* c) {
			cout << "MERGESORT: " << flush; //test
		}
};


int main() {
	//
	srand(time(NULL));
	
	//vector bubble sort
	cout << "vector bubble sort" << endl;
	VectorContainer vc;
	SortAlgorithm*  bs = new BubbleSort();
	cout << "BEFORE: ";
	vc.print();	
	vc.set_sort(bs);
	vc.sort();
	vc.print();
	cout << endl;
	
	//vector selection sort
	cout << "vector seleciton sort" << endl;
	VectorContainer vc1;
	SortAlgorithm* ss = new SelectionSort();
	cout << "BEFORE: ";
	vc1.print();
	vc1.set_sort(ss);
	vc1.sort();
	vc1.print();	

	//vector merge sort
	cout << "vector merge sort" << endl;
	VectorContainer vc2;
	SortAlgorithm* ms = new MergeSort();
	cout << "BEFORE: ";
	vc2.print();
	vc2.set_sort(ms);
	vc2.sort();
	vc2.print();
	cout << endl;

	//filled vector bubble sort
	cout << "filled vector bubble sort" << endl;
	VectorContainer vc3;
	SortAlgorithm* bs1 = new BubbleSort();
	cout << "BEFORE: ";
	vc3.randHun(20);
	vc3.print();
	vc3.set_sort(bs1);
	vc3.sort();
	vc3.print();
	cout << endl; 

	//filled vector selection sort
	cout << "filled vector selection sort" << endl;
	VectorContainer vc4;
	SortAlgorithm* ss1 = new SelectionSort();
	cout << "BEFORE: ";
	vc4.randHun(20);
	vc4.print();
	vc4.set_sort(ss1);
	vc4.sort();
	vc4.print();
	cout << endl;


	//filled vector merge sort
	cout << "filled vector merge sort" << endl;
	VectorContainer vc5;
	SortAlgorithm* ms1 = new MergeSort();
	cout << "BEFORE: ";
	vc5.randHun(20);
	vc5.print();
	vc5.set_sort(ms1);
	vc5.print();
	cout << endl;
	
	//list bubble sort
	cout << "list bubble sort" << endl;
	ListContainer lc;
	SortAlgorithm*  bs2 = new BubbleSort();
	cout << "BEFORE: ";
	lc.print();	
	lc.set_sort(bs2);
	lc.sort();
	lc.print();
	cout << endl;


	//list selection sort
	cout << "list seleciton sort" << endl;
	ListContainer lc1;
	SortAlgorithm* ss2 = new SelectionSort();
	cout << "BEFORE: ";
	lc1.print();
	lc1.set_sort(ss2);
	lc1.sort();
	lc1.print();	
	cout << endl;

	//list merge sort
	cout << "list merge sort" << endl;
	VectorContainer lc2;
	SortAlgorithm* ms2 = new MergeSort();
	cout << "BEFORE: ";
	lc2.print();
	lc2.set_sort(ms);
	lc2.sort();
	lc2.print();
	cout << endl;

	//filled list buble sort
	cout << "list bubble sort" << endl;
	ListContainer lc3;
	SortAlgorithm*  bs3 = new BubbleSort();
	cout << "BEFORE: ";
	lc3.randHun(20);
	lc3.print();	
	lc3.set_sort(bs3);
//	lc3.sort();
	lc3.print();
	cout << endl;



	//filled list selection sort
	cout << "list selection sort" << endl;
	ListContainer lc4;
	SortAlgorithm* ss3 = new SelectionSort();
	cout << "BEFORE: ";
	lc4.randHun(20);
	lc4.print();
	lc4.set_sort(ss3);
	lc4.sort();
	lc4.print();
	cout << endl;


	//filled list merge sort
	cout << "list merge sort" << endl;
	ListContainer lc5;
	SortAlgorithm* ms3 = new MergeSort();
	cout << "BEFORE: ";
	lc5.randHun(20);
	lc5.print();
	lc5.set_sort(ms3);
	lc5.sort();
	lc5.print();
	cout << endl;
	
	delete bs;
	delete ms;
	delete ss;
	delete bs1;
//	delete ms1;
//	delete ss1;
	
	return 0; 
}
