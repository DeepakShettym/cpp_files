#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Heap {
    int arr[100];
    int size;

public:
    Heap() {
        size = 0;
    }

    void insert(int val) {
        arr[size] = val;
        int index = size;
        size++;

        // Move upward until heap property holds
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

    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

 class node{
        public: 
        
        int data;
        int i;
        int j;
        
        
        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
    };
    
    
    class compare{
        public:
        bool operator()(node* a, node* b){
          return a->data > b->data;
      }  
        
    };

// Heapify for 0-based index
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

   int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int size = arr.size();
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push(arr[i]);
        }
        
        while(size > 1){
            int a  = pq.top();
            pq.pop();
            int b  = pq.top();
            pq.pop();
            int sum = a + b;
            pq.push(sum);
            ans += sum;
            size--;
        }
        
        
        return ans;
        
    }

     vector<int> mergeArrays(vector<vector<int>> &mat) {
        
        priority_queue<node* , vector<node*> , compare> minHeap;
        
        for(int i = 0 ; i < mat.size() ; i++){
            node* newNode = new node(mat[i][0],i,0);
            minHeap.push(newNode);
        }
        
        
        vector<int> ans;
        
        
        while(!minHeap.empty()){
            node* tmp = minHeap.top();
            
            ans.push_back(tmp->data);
            minHeap.pop();
            
            int i = tmp->i;
            int j = tmp->j;
            
            if(j+1 < mat[i].size()){
                node* nextNode = new node(mat[i][j+1],i,j+1);
                minHeap.push(nextNode);
            }
        }
        
        return ans;
        
        
    }

int main() {
    int arr[] = {6,7,6,9};
    int n = 4;

    // Build heap (bottom-up)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Max-Heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
