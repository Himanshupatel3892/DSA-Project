#include <iostream>
using namespace std;

// Function to combine two sorted parts into one sorted section
void combine(int nums[], int start, int midPoint, int end) {
    int len1 = midPoint - start + 1;   // Length of first part
    int len2 = end - midPoint;         // Length of second part

    int leftPart[len1], rightPart[len2];  // Temporary storage for both halves

    // Copy values into left and right parts
    for (int p = 0; p < len1; p++)
        leftPart[p] = nums[start + p];
    for (int q = 0; q < len2; q++)
        rightPart[q] = nums[midPoint + 1 + q];

    int p = 0, q = 0, r = start;

    // Merge two halves into main array
    while (p < len1 && q < len2) {
        if (leftPart[p] <= rightPart[q]) {
            nums[r] = leftPart[p];
            p++;
        } else {
            nums[r] = rightPart[q];
            q++;
        }
        r++;
    }

    // Copy remaining elements of left half if any
    while (p < len1) {
        nums[r] = leftPart[p];
        p++;
        r++;
    }

    // Copy remaining elements of right half if any
    while (q < len2) {
        nums[r] = rightPart[q];
        q++;
        r++;
    }
}

// Recursive sorting function using Merge Sort
void divideAndSort(int nums[], int start, int end) {
    if (start < end) {
        int midPoint = start + (end - start) / 2;

        // Sort first half
        divideAndSort(nums, start, midPoint);

        // Sort second half
        divideAndSort(nums, midPoint + 1, end);

        // Merge both halves
        combine(nums, start, midPoint, end);
    }
}

// Linear search: look for element "target" in array
void linearSearch(int list[], int length, int target) {
    int foundCount = 0;
    for (int m = 0; m < length; m++) {
        if (list[m] == target) {
            cout << "Index is " << m << "\n";
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Item not found\n";
    }
}

// Binary search: search for an element in sorted array
void binarySearchAlgo(int data[], int total, int target) {
    int low = 0;
    int high = total - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;

        if (data[middle] == target) {
            cout << "Index is: " << middle << "\n";
            return;
        } else if (data[middle] < target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    cout << "Value not found\n";
}

int main() {
    int option;

    do {
        // Menu choices
        cout << "Press 1 for Selection Sort\nPress 2 for Merge Sort\nPress 3 for Linear Search\nPress 4 for Binary Search\nPress 0 for EXIT\n";
        cin >> option;

        switch (option) {
            case 1: {
                // Selection Sort
                int n, x, y;
                cout << "Enter size of array for sorting: ";
                cin >> n;

                int values[100];
                cout << "Enter " << n << " values:\n";
                for (x = 0; x < n; x++) {
                    cin >> values[x];
                }

                // Selection sort logic
                for (x = 0; x < n; x++) {
                    for (y = x + 1; y < n; y++) {
                        if (values[x] > values[y]) {
                            int swapper = values[x];
                            values[x] = values[y];
                            values[y] = swapper;
                        }
                    }
                }

                // Output sorted list
                cout << "Sorted Array: ";
                for (x = 0; x < n; x++) {
                    cout << values[x] << " ";
                }
                cout << endl;
                break;
            }

            case 2: {
                // Merge Sort
                int len;
                cout << "Enter size of array: ";
                cin >> len;

                int values[100];
                cout << "Enter " << len << " values:\n";
                for (int u = 0; u < len; u++) {
                    cin >> values[u];
                }

                divideAndSort(values, 0, len - 1);

                cout << "Array after Merge Sort: ";
                for (int u = 0; u < len; u++) {
                    cout << values[u] << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                // Linear Search
                int len, idx, target;
                cout << "Enter size of array: ";
                cin >> len;

                int values[100];
                cout << "Enter " << len << " values: ";
                for (idx = 0; idx < len; idx++) {
                    cin >> values[idx];
                }

                cout << "Find value in array: ";
                cin >> target;

                linearSearch(values, len, target);
                break;
            }

            case 4: {
                // Binary Search
                int sizeArr, a, b, target;
                cout << "Enter size of array for searching value: ";
                cin >> sizeArr;

                int values[100];
                cout << "Enter " << sizeArr << " values: ";
                for (a = 0; a < sizeArr; a++) {
                    cin >> values[a];
                }

                // Sort before binary search (bubble sort)
                for (a = 0; a < sizeArr; a++) {
                    for (b = a + 1; b < sizeArr; b++) {
                        if (values[a] > values[b]) {
                            int tempVal = values[a];
                            values[a] = values[b];
                            values[b] = tempVal;
                        }
                    }
                }

                cout << "\nSorted Array\n";
                for (a = 0; a < sizeArr; a++) {
                    cout << values[a] << " ";
                }
                cout << endl;

                cout << "Enter value to find in array: ";
                cin >> target;

                binarySearchAlgo(values, sizeArr, target);
                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (option != 0);

    return 0;
}
