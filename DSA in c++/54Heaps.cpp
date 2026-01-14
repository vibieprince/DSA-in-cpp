#include<iostream>
#include<algorithm> // for swap
#include<queue> // For priority queue 
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

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] <arr[left]) largest = left;
    if(right <= n && arr[largest] < arr[right]) largest = right;

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }    
}

void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        // Step 1 : Swap
        swap(arr[size],arr[1]);

        // Step 2 
        size--;

        // Step 3
        heapify(arr,size,1);
    }
}
int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deleteFromHeap();
    h.print();  // Output should be: 55 52 53 50 54 or similar (Max-Heap)

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--)
        heapify(arr,n,i);
    
    cout<<"Printing the array"<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    // Heapsort
    heapSort(arr,n);
    cout<<"Printing the Sorted array"<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"Using Priority Queue here"<<endl;
    // MaxHeap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at the top "<<pq.top()<<endl;
    pq.pop();

    cout<<"Element at top "<<pq.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;
    if(pq.empty()) cout<<"Pq is empty";
    else cout<<"Pq is not empty";

    // MinHeap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"Element at the top "<<minHeap.top()<<endl;
    minHeap.pop();

    cout<<"Element at top "<<minHeap.top()<<endl;
    cout<<"Size is "<<minHeap.size()<<endl;
    if(minHeap.empty()) cout<<"Pq is empty";
    else cout<<"Pq is not empty";

}
