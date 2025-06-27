#include<iostream>
#include<algorithm> // for swap
using namespace std;

class heap {
public:
    int arr[1000];
    int size;

    heap() {
        size = 0; // Start from 0
    }

    void insert(int val) { // TC : O(logN)
        if (size >= 1000) {
            cout << "Heap is full!" << endl;
            return;
        }
        int index = size;
        arr[index] = val;
        size++;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            } 
        }
    }

    void deleteFromHeap(){
        if(size<0){
            cout<<"Heap underflow";
            return;
        }

        // Step 1 : put last element into first index
        arr[0] = arr[size-1];

        // Step 2 : remove last element
        size--;

        // Step 3 : take root node to its correct position

        int i = 0;
        while(i<size){
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else return;
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deleteFromHeap();
    h.print();  // Output should be: 55 52 53 50 54 or similar (Max-Heap)
}
