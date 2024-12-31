#include <iostream>
#include <climits>
using namespace std; 
class MinHeap {
    int* harr;      // pointer to array of elements in heap 
    int capacity;   // maximum possible size of min heap  
    int heap_size;  // Current number of elements in min heap 
public:     // Constructor   
    MinHeap(int cap) {       
        heap_size = 0;    
        capacity = cap;    
        harr = new int[cap]; 
}

// Get parent, left, and right child indices  
 
 int parent(int i) { return (i - 1) / 2; }  
 int left(int i) { return (2 * i + 1); }  
 int right(int i) { return (2 * i + 2); } 

// Swap utility  
   void swap(int* x, int* y) {         int temp = *x;         *x = *y; 
*y = temp;
    }

        void insertKey(int k)
        {         if (heap_size == capacity)
        {             cout << "Overflow: Could not insertKey\n";  
        return; 
        }

           heap_size++;     
           int i = heap_size - 1; 
           harr[i] = k; 

              while (i != 0 && harr[parent(i)] > harr[i])
              {             swap(&harr[i], &harr[parent(i)]); 
              i = parent(i); 
        }
    }

       void decreaseKey(int i, int new_val) {  
           harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    {
        swap(&harr[i], &harr[parent(i)]);      
        i = parent(i);
    }
    }

   int extractMin()
   {         if (heap_size <= 0)  
       return INT_MAX;     
   if (heap_size == 1) 
   {             heap_size--;   
   return harr[0]; 
        }

                 int root = harr[0];  
                 harr[0] = harr[heap_size - 1]; 
        heap_size--;    
        MinHeapify(0);

        return root;
    }

       void deleteKey(int i) {  
           decreaseKey(i, INT_MIN); 
           extractMin(); 
    }

void MinHeapify(int i) 
{         int l = left(i);   
int r = right(i);       
int smallest = i; 

    if (l < heap_size && harr[l] < harr[smallest])             smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])             smallest = r;         if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
    }

     int getMin()
     { return harr[0]; } 
    };  int main() {
        MinHeap h(10);
    h.insertKey(3); 
        h.insertKey(1);
        h.insertKey(6);
        h.insertKey(5);
        h.insertKey(2);
        h.insertKey(4);
        cout << "Min-Heap Root: " << h.getMin() << endl;      // Task 1 (2): Delete 2 and print root 
        h.deleteKey(1); // Assuming 2 is at index 1 after insertion     cout << "Min-Heap Root after deleting 2: " << h.getMin() << endl; 

        return 0;
    }
