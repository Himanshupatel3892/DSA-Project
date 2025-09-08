#include <iostream>
using namespace std;

// --------------------- Node Structure ---------------------
class Element {
public:
    int data;        // Holds value
    Element* link;   // Pointer to next element

    // Constructor to initialize
    Element(int d) {
        data = d;
        link = NULL;
    }
};

// --------------------- Linked List Implementation ---------------------
class Chain {
public:
    Element* first;  // Head pointer
    Element* last;   // Tail pointer

    // Constructor
    Chain() {
        first = last = NULL;
    }

    // Insert node at end
    void insertAtEnd(int num) {
        Element* fresh = new Element(num);

        if (first == NULL) {
            first = last = fresh;
        } else {
            last->link = fresh;
            last = fresh;
        }
    }

    // Insert node at any given position
    void insertAtPos(int num, int pos) {
        Element* fresh = new Element(num);
        int counter = 1;

        if (first == NULL || pos <= 1) {
            fresh->link = first;
            first = fresh;

            if (last == NULL) last = fresh;
            return;
        }

        Element* walker = first;
        while (walker->link != NULL && counter < pos - 1) {
            walker = walker->link;
            counter++;
        }

        fresh->link = walker->link;
        walker->link = fresh;

        if (fresh->link == NULL) last = fresh;
    }

    // Print all nodes
    void show() {
        Element* walker = first;
        cout << "Linked List: ";
        while (walker != NULL) {
            cout << walker->data << " ";
            walker = walker->link;
        }
        if (walker == NULL) cout << "NULL";
        cout << endl;
    }
};

// --------------------- Merge Sort ---------------------

// Combine two sorted segments
void join(int nums[], int start, int mid, int end) {
    int lenL = mid - start + 1;
    int lenR = end - mid;

    int left[lenL], right[lenR];

    for (int a = 0; a < lenL; a++)
        left[a] = nums[start + a];
    for (int b = 0; b < lenR; b++)
        right[b] = nums[mid + 1 + b];

    int i = 0, j = 0, k = start;

    while (i < lenL && j < lenR) {
        if (left[i] <= right[j]) {
            nums[k++] = left[i++];
        } else {
            nums[k++] = right[j++];
        }
    }

    while (i < lenL) nums[k++] = left[i++];
    while (j < lenR) nums[k++] = right[j++];
}

// Recursive merge sort
void sortMerge(int nums[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        sortMerge(nums, start, mid);
        sortMerge(nums, mid + 1, end);

        join(nums, start, mid, end);
    }
}

// --------------------- Binary Search ---------------------
void binSearch(int nums[], int length, int key) {
    int low = 0, high = length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == key) {
            cout << "Value found at index: " << mid << "\n";
            return;
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Value not found in array.\n";
}

// --------------------- Quick Sort ---------------------

// Swap function
void swapper(int &x, int &y) {
    int hold = x;
    x = y;
    y = hold;
}

// Partition logic
int partitioning(int nums[], int low, int high) {
    int pivot = nums[high];
    int idx = low - 1;

    for (int z = low; z < high; z++) {
        if (nums[z] < pivot) {
            idx++;
            swapper(nums[idx], nums[z]);
        }
    }

    swapper(nums[idx + 1], nums[high]);
    return idx + 1;
}

// Quick sort recursive
void quickSorter(int nums[], int low, int high) {
    if (low < high) {
        int pos = partitioning(nums, low, high);
        quickSorter(nums, low, pos - 1);
        quickSorter(nums, pos + 1, high);
    }
}

// Print array
void displayArr(int nums[], int len) {
    cout << "Sorted Array: ";
    for (int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl;
}

// --------------------- Main ---------------------
int main() {
    Chain obj;
    int option;

    do {
        cout << "Press 1 to Create LinkedList\nPress 2 to Show LinkedList\nPress 3 for Binary Search\nPress 4 for Merge Sort\nPress 5 for Quick Sort\nPress 0 for EXIT\n";
        cin >> option;

        switch (option) {
            case 1: {
                int cnt, val;
                cout << "How many nodes to insert? ";
                cin >> cnt;

                for (int t = 0; t < cnt; t++) {
                    cout << "Enter value " << t + 1 << ": ";
                    cin >> val;
                    obj.insertAtEnd(val);
                }
                cout << "Linked List created.\n";
                break;
            }

            case 2:
                obj.show();
                break;

            case 3: {
                int len, num;
                cout << "Enter size of array: ";
                cin >> len;

                int nums[100];
                cout << "Enter " << len << " values:\n";
                for (int u = 0; u < len; u++) cin >> nums[u];

                // Bubble sort before binary search
                for (int u = 0; u < len; u++) {
                    for (int v = u + 1; v < len; v++) {
                        if (nums[u] > nums[v]) {
                            int tmp = nums[u];
                            nums[u] = nums[v];
                            nums[v] = tmp;
                        }
                    }
                }

                cout << "\nSorted Array\n";
                for (int u = 0; u < len; u++) cout << nums[u] << " ";
                cout << endl;

                cout << "Enter value to find: ";
                cin >> num;

                binSearch(nums, len, num);
                break;
            }

            case 4: {
                int len;
                cout << "Enter size of array: ";
                cin >> len;

                int nums[100];
                cout << "Enter " << len << " elements:\n";
                for (int u = 0; u < len; u++) cin >> nums[u];

                sortMerge(nums, 0, len - 1);

                cout << "Array after Merge Sort: ";
                for (int u = 0; u < len; u++) cout << nums[u] << " ";
                cout << endl;
                break;
            }

            case 5: {
                int len;
                cout << "Enter number of elements: ";
                cin >> len;

                int nums[100];
                cout << "Enter " << len << " elements:\n";
                for (int u = 0; u < len; u++) cin >> nums[u];

                quickSorter(nums, 0, len - 1);
                displayArr(nums, len);
                break;
            }

            case 0:
                cout << "EXIT\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (option != 0);

    return 0;
}
