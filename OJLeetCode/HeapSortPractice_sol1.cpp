/*
 * please review your heap practice first: 
 * C:\Users\idfs\Dropbox\ProgrammingPractice\OJLeetCode\HeapPractice_sol1.cpp
 * Heapsort: 
 * http://en.wikipedia.org/wiki/Heapsort
 *     Heapsort is part of the selection sort family;
 *     Although somewhat slower in practice on most machines than a well-implemented quicksort, 
 *     it has the advantage of a more favorable worst-case O(n log n) runtime. 
 *     Heapsort is an in-place algorithm, but it is not a stable sort. It was invented by J. W. J. Williams in 1964.
 * Selection sort:
 * http://en.wikipedia.org/wiki/Selection_sort
 */

#include <help_tool.h>

template <typename Type>
class Solution
{
public:
    // index:
    // if index i starts from 1 (domain1)
    // parent = i -> left child = i*2, and right child = i*2+1
    // ex: 1->(2,3); 2->(4,5); 3->(6,7); 4->(8,9)
    
    // if index k starts from 0, k+1=i, (domain2)
    // parant (domain2) = k -> parent (domain1) = k+1 
    //                -> left child  = (k+1)*2 = 2k+2 -> left child (domain2): 2k+2-1 = 2k+1
    //                -> right child = (k+1)*2+1 = 2k+3 -> right child (domain2): 2k+3-1 = 2k+2
    // domain2 parent k = (child-1)/2
    
    void heapSort(Type arr[], int size);
    //requirement: in-place operation, O(n log n)
    
    //helper functions
    void makeHeap(Type arr[], int size);
    void moveTop2End(Type arr[], int pos);
    void heapBubbleDown(Type arrp[], int max, int seed);
    void SWAP(Type &a, Type &b);
};

//When defining a function as a member of a templated class, it is necessary to define it as a templated function
template <typename Type>
void Solution<Type>::heapSort(Type arr[], int size)
{
    if (size <= 0) return; //size at least 1
        
    makeHeap(arr, size);
    for(int pos = size-1; pos>=1; pos--)
    {
        moveTop2End(arr, pos);
        //corner case: size=1 -> OK
        //corner case: size=2 -> heapBubbleDown(arr, 0, 0); -> OK
    }
}

template <typename Type>
void Solution<Type>::makeHeap(Type arr[], int size)
{
    for (int i=((size-1)-1)/2; i>=0; i--)
    {
        heapBubbleDown(arr, size-1, i);
    }
}

template <typename Type>
void Solution<Type>::moveTop2End(Type arr[], int pos)
{
    SWAP(arr[0], arr[pos]); //1. move top to sorted list 2. move last one to top
    heapBubbleDown(arr, pos-1, 0);
}

#define RECURSIVE 0
#define ITERATIVE 1
#define HEAP_BUBBLE_DOWN_VERSION ITERATIVE // RECURSIVE or ITERATIVE
#if HEAP_BUBBLE_DOWN_VERSION == ITERATIVE
        template <typename Type>
        void Solution<Type>::heapBubbleDown(Type arr[], int max, int seed)
        {
            if (max <= 0) return; //max == 0 means no chance to move
                
            int M, LC, RC;
            for(;;)
            {
                M = seed;
                LC = 2*seed+1;
                RC = 2*seed+2;
                // get max within arr[seed], arr[RC], arr[LC]
                if (LC <= max && arr[LC] > arr[M]) M = LC;
                if (RC <= max && arr[RC] > arr[M]) M = RC;
                
                if (M == seed) break; //stop
                else 
                {
                    SWAP(arr[seed], arr[M]);
                    seed = M;
                }
                
                //error protection:
                //don't have to worry seed > max
                //before seed > max, there exists a iteration that LC & RC both > max, then M will be seed, break
                //corner case: max = seed = 0, return;
            }
        }
#else
        template <typename Type>
        void Solution<Type>::heapBubbleDown(Type arr[], int max, int seed)
        {
            if (max <= 0) return;
            
            // get max within arr[seed], arr[RC], arr[LC]
            int M = seed;
            int LC = 2*seed+1;
            int RC = 2*seed+2;
            if (LC <= max && arr[LC] > arr[M]) M = LC;
            if (RC <= max && arr[RC] > arr[M]) M = RC;
            
            if (M == seed) ; //stop
            else 
            {
                SWAP(arr[seed], arr[M]);
                heapBubbleDown(arr, max, M);
            }
        }
#endif


template <typename Type>
void Solution<Type>::SWAP(Type &a, Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}


int main()
{
    int intArr1[] = {9, 8, 7, 6, 5, 4, 3};
	int intArr2[] = {3, 4, 5, 6, 7, 8, 9};
	int intArr3[] = {1, 100, 2, 4, 3, 9, 2, 1000, 1, -1, 2, 500, 499, 501};
    int intArr4[] = {100};
    int intArr5[] = {100, 0};
	Solution<int> sln;
	sln.heapSort(intArr1, 7);
    printf("intArr1=(%d,%d,%d,%d,%d,%d,%d)\n"
	    , intArr1[0]
	    , intArr1[1]
	    , intArr1[2]
	    , intArr1[3]
	    , intArr1[4]
	    , intArr1[5]
	    , intArr1[6]
        );
	sln.heapSort(intArr2, 7);
    printf("intArr2=(%d,%d,%d,%d,%d,%d,%d)\n"
	    , intArr2[0]
	    , intArr2[1]
	    , intArr2[2]
	    , intArr2[3]
	    , intArr2[4]
	    , intArr2[5]
	    , intArr2[6]
        );
    sln.heapSort(intArr3, 14);
	printf("intArr3=(%d,%d,%d,%d,%d; %d,%d,%d,%d,%d; %d,%d,%d,%d)\n"
	    , intArr3[0]
	    , intArr3[1]
	    , intArr3[2]
	    , intArr3[3]
	    , intArr3[4]
	    , intArr3[5]
	    , intArr3[6]
        , intArr3[7]
        , intArr3[8]
        , intArr3[9]
        , intArr3[10]
        , intArr3[11]
        , intArr3[12]
        , intArr3[13]
        );
	sln.heapSort(intArr4, 1);
    printf("intArr4=(%d)\n"
	    , intArr4[0]
        );
	sln.heapSort(intArr5, 2);
    printf("intArr5=(%d,%d)\n"
	    , intArr5[0]
        , intArr5[1]
        );
    system("pause");
    return 0;
}