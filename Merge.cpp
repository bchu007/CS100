#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Container;

class SortAlgorithm 
{
	private:
		
	public:
		virtual void sort(Container* c) = 0;	
};
 
class Container 
{
	protected:
		SortAlgorithm* type;	
	public:
		virtual int at(int i) = 0;
		virtual void swap(int i, int j) = 0;
		virtual void insert(int element) = 0;
		virtual void replace_at(int element, int pos) = 0;
		virtual void resize(int newsize) = 0;
		virtual void print() = 0;
		virtual int size() = 0;
		virtual void set_sort(SortAlgorithm* c) = 0;
		virtual void sort() = 0;
		
};

class VectorContainer : Container 
{

	private:
		vector<int> v;
		SortAlgorithm* type;	
	public:
		virtual int at(int i) 
		{
			return v.at(i);		
		}
		virtual void swap(int i, int j) 
		{
			int x = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = x;
		}

		virtual void insert(int element) 
		{
			v.push_back(element);
		}

		virtual void replace_at(int element, int pos)
		{
			v.at(pos) = element;
		}
		virtual void print() 
		{
			for(int i = 0; i < v.size(); i++) 
				cout << v.at(i) << " " << flush;
			cout << endl;
		}

		virtual int size() 
		{
			return v.size();	
		}
		virtual void resize(int newsize)
		{
			v.resize(newsize);
		}
		virtual void set_sort(SortAlgorithm* s) 
		{
			type = s;	
		}
		virtual void sort() 
		{
			type->sort(this);
		}
					
};

class ListContainer : Container {
	private:
		list<int> l;	
	public:
		virtual int at(int i) 
		{
			list<int>::iterator it;
			it = l.begin();
			advance(it,i);
			return *it;
		}
		virtual void swap(int i, int j) 
		{
			list<int>::iterator it;
			list<int>::iterator jt;
			list<int>::iterator kt;
			int x;
			int y;
				
			/*
			for(kt = l.begin(); kt != l.end(); kt++)
			{
				
				if(*kt == i) 
				{
					it = kt;
					x = *it;
				}
				else if(*kt == j) 
				{
					jt = kt;
					y = *jt;
				}			
			}
			it* = y;
			jt* = x;		
			*/
		}

		virtual void insert(int element) 
		{
			l.push_back(element);
		}


		virtual void print() 
		{
			list<int>::iterator it;
			for(it = l.begin(); it != l.end(); it++) 
				cout << *it << " " << flush;
			cout << endl;
		}

		virtual void replace_at(int element, int pos)
		{
			list<int>::iterator it;
			it = l.begin();
			advance(it,pos);
			l.insert(it, element);
			it = l.erase(it);
		}

		virtual int size() 
		{
			return l.size();
		}

		virtual void resize(int newsize)
		{
			l.resize(newsize);
		}
		virtual void set_sort(SortAlgorithm* s) 
		{
			type = s;
		}

		virtual void sort() 
		{
			type->sort(this);	
		}

};


class BubbleSort : SortAlgorithm 
{
	private:
		
	public:
		virtual void sort(Container* c) 
		{
			cout << "Bubble Sort" << endl;
			int size = c->size();
			for(int i = 0; i < size - 1; i++)
			{
				for(int j = 0; j < (size - i - 1); j++)
				{
					if(c->at(j) > c->at(j+1))
					{
						c->swap(j, j+1);
					}
				}
			}	
		}
};

class SelectionSort : SortAlgorithm 
{
	private:
		
	public:

		virtual void sort(Container* c) 
		{
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

class MergeSort : public SortAlgorithm 
{
	private:
		
	public:

		virtual void sort(Container* c) 
		{
			int size = c->size();
			int left = 0; 
			int right = size-1;
			VectorContainer tmp;
			tmp.resize(size);

			cout << "Merge Sort" << endl; 
			mergesort(c,tmp,left,right);
		}
		
		void merge(Container* c, VectorContainer tmp, int left, int mid, int right)
		{
			int leftend = mid -1;
			int tmppos = left;
			int size = right - left + 1;

			while(left <= leftend and mid <= right)
				if(c->at(left) <= c->at(mid))
					tmp.replace_at(c->at(left++), tmppos++);
				else
					tmp.replace_at(c->at(mid++), tmppos++);

			while(left <= leftend)
				tmp.replace_at(c->at(left++), tmppos++);

			while(mid <= right)
				tmp.replace_at(c->at(mid++), tmppos++);

			for(int i = 0; i < size; i++)
			{
				c->replace_at(tmp.at(right),right);
				right--;
			}
		}

		void mergesort(Container* c, VectorContainer tmp, int left, int right)
		{
			int size = c->size();
			int half;

			if(left < right)
			{
				half = ((left + right) / 2);
				mergesort(c,tmp,left,half);
				mergesort(c,tmp,half+1,right);
				merge(c,tmp,left,half+1,right);
			}

			return;
		}
};



int main() 
{
	
	VectorContainer vc;
	vc.insert(5);
	vc.insert(9);
	vc.insert(7);
	vc.insert(1);
	vc.insert(1);
	vc.insert(2);
	vc.insert(4);

	cout << "Setting SortAlgoritm type to merge." << endl;
	SortAlgorithm* ms = new MergeSort();
	vc.set_sort(ms);
	vc.sort();
	vc.print();


	ListContainer lc;
	lc.insert(5);
	lc.insert(9);
	lc.insert(7);
	lc.insert(1);
	lc.insert(1);
	lc.insert(2);
	lc.insert(4);

	cout << "Setting SortAlgoritm type to merge." << endl;
	SortAlgorithm* ms2 = new MergeSort();
	lc.set_sort(ms2);
	lc.sort();
	lc.print();
	

	return 0; 
}







