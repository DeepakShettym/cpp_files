#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* link[2];

    Node() {
        link[0] = link[1] = NULL;
    }

    bool containsKey(int bit) {
        return (link[bit] != NULL);
    }

    Node* get(int bit) {
        return link[bit];
    }

    void put(int bit, Node* node) {
        link[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!temp->containsKey(bit)) {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }

    int getMax(int num) {
        Node* temp = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->containsKey(1 - bit)) {
                maxVal |= (1 << i);
                temp = temp->get(1 - bit);
            } else {
                temp = temp->get(bit);
            }
        }
        return maxVal;
    }
};

int maxXor(vector<int>& arr1, vector<int>& arr2) {
    int maxi = 0;
    Trie* t = new Trie();

    for (int it : arr1)
        t->insert(it);

    for (int it : arr2)
        maxi = max(maxi, t->getMax(it));

    return maxi;
}

int main() {
    vector<int> arr1 = {3, 10, 5, 25, 2, 8};
    vector<int> arr2 = {5, 25};
    cout << "Maximum XOR is: " << maxXor(arr1, arr2) << endl;
    return 0;
}
