
class SelectionSort : public SortAlgorithm {
	private:
		
	public:

		virtual void sort(Container* c) 
		{

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

