#include <cstdlib>
#include <cstdio>
#include <iostream>


using namespace std;


//Heap implememtation
//according to http://en.wikipedia.org/wiki/Heap_(data_structure)
//Binary heap: http://en.wikipedia.org/wiki/Binary_heap
/*
A binary heap is a heap data structure created using a binary tree. It can be seen as a binary tree with two additional constraints:
[Shape property]
The tree is a complete binary tree; 
that is, all levels of the tree, except possibly the last one (deepest) are fully filled, 
and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.
[Heap property]
All nodes are either [greater than or equal to] or [less than or equal to] each of its children, according to a comparison predicate defined for the heap.

PS:
 there is no implied ordering between siblings or cousins and no implied sequence for an in-order traversal 
 (as there would be in, e.g., a binary search tree). 
 The heap relation mentioned above applies ONLY between nodes and their immediate parents. 
*/

template <typename Type>
class MaxHeap
{
public:
	MaxHeap(int cap) //create-heap: create an empty heap
		: mCap(cap)
		, mEnd(0)
	{
        dataArr = new Type[mCap];
		for (int i=0;i<mCap; i++)
			dataArr[i] = 0;
	}
	MaxHeap()
		: mCap(10)
		, mEnd(0)
	{
        dataArr = new Type[mCap];
		for (int i=0;i<mCap; i++)
			dataArr[i] = 0;
		printf("[default:%s] mCap = %d\n", mCap);
	}
	~MaxHeap()
	{
		delete [] dataArr;
	}
	bool createHeapFromArray(Type arr[], int n) //heapify: create a heap out of given array of elements
	{
		printf("[%s]\n", __FUNCTION__);
        if (mCap < n) return false;
        mEnd = n;
		for (int i=0; i<n; i++)
			dataArr[i] = arr[i];
		for (int i=mEnd/2; i>=0; i--) //mEnd/2 definitely can include LAST set of {i, 2*i+1, 2*i+2}
			MaxHeapify(i);
	}

/* insert: bubble-up operation.
Step1: Add the element to the bottom level of the heap.
Step2: Compare the added element with its parent; if they are in the correct order, stop.
Step3: If not, swap the element with its parent and return to the previous step.
*/
	bool insert(Type ele) //insert: adding a new key to the heap
	{
		printf("[%s] insert %d\n", __FUNCTION__, ele);
		if (mEnd >= mCap) return false;
		dataArr[mEnd] = ele; //step 1
		
		int newEle = mEnd, parent = (mEnd-1)/2; //first iteration

		mEnd++;

		for(;;)
		{ 
			if (dataArr[parent] > dataArr[newEle]) return true; //step 2: done, stop
			
			//step 3
			SWAP(dataArr[parent], dataArr[newEle]);
			newEle = parent;
			parent = (newEle-1)/2;
			if (parent<0 || newEle<1) break; //already reach the top
		}
        return true;
	}
	inline Type findMax() const //find-max or find-min: find the maximum item of a max-heap or a minimum item of a min-heap, respectively (aka, peek)
	{
		return dataArr[0];
	}
/* Delete: bubble-down operation
Step1: Replace the root of the heap with the last element on the last level.
Step2: Compare the new root with its children; if they are in the correct order, stop.
Step3: If not, swap the element with one of its children and return to the previous step. (Swap with its smaller child in a min-heap and its larger child in a max-heap.)
*/
	bool removeMax() //delete-max or delete-min: removing the root node of a max- or min-heap, respectively
	{
		printf("[%s]\n", __FUNCTION__);
		if (mEnd == 0) return false;
		mEnd--;
		dataArr[0] = dataArr[mEnd];
		MaxHeapify();
		return true;
	}
    bool mergeWith(const MaxHeap& rHeap) //merge: joining two heaps to form a valid new heap containing all the elements of both.
	{
		return true;
	}
	void printHeap() const
	{
		printf("[%s]array: [", __FUNCTION__);
		for (int i=0; i<mEnd-1; i++)
			printf("%d, ", dataArr[i]);
		printf("%d]\n", dataArr[mEnd-1]);
	}

protected:
    void MaxHeapify(int i = 0) //default: start from the root
	{
		//dataArr[i]: current node
		//dataArr[2*i+1]: left child
		//dataArr[2*i+2]: right child
		//Note: right > left, and they are NOT interchangeable!!
		//due to the definition of Binary heap: Shape property
		//The tree is a complete binary tree; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, 
		//and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.

		int left = 2*i+1, right = 2*i+2, largest = i;
		if ((right < mEnd) && (dataArr[right] > dataArr[largest]))
			largest = right;
		if ((left < mEnd) && (dataArr[left] > dataArr[largest]))
			largest = left;
		
		if (largest == i) return; //nothing to do, stop
		
		SWAP(dataArr[largest], dataArr[i]);
		MaxHeapify(largest);
	}
	inline void SWAP(Type & A, Type & B) //should be call by reference
	{
		Type temp;
		temp = A;
		A = B;
		B = temp;
	}

private:
	int mCap;
	int mEnd; //the new position to be used, its value is the current size
    Type* dataArr;
	
};


int main(void)
{
	int intArr1[] = {9, 8, 7, 6, 5, 4, 3};
	int intArr2[] = {3, 4, 5, 6, 7, 8, 9};
    int sz = 7;
	MaxHeap<int> heap(20);
	heap.createHeapFromArray(intArr1, sz);
	heap.printHeap();
	heap.createHeapFromArray(intArr2, sz);
	heap.printHeap();
	heap.insert(2);
	heap.printHeap();
	heap.insert(100);
	heap.printHeap();
	heap.insert(1000);
	heap.printHeap();
	heap.insert(500);
	heap.printHeap();
	printf("max = %d\n", heap.findMax());
	heap.removeMax();
	heap.printHeap();
	heap.removeMax();
	heap.printHeap();	
	heap.removeMax();
	heap.printHeap();
	heap.removeMax();
	heap.printHeap();

	system("pause");
	return 0;
}
//Utility test ok, step-by-step verified on paper