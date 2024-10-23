// initialize array
// stored in stack
/*
int	arr[5];
int	nums[5] = {1, 3, 2, 5, 4};
*/
// stored on heap (need to free space manually)
/*
int* arr1 = new int[5];
int* nums1 = new int[5] {1, 3, 2, 5, 4};
*/

#include "../inc/algo.hpp"

class Arrays {
    private:
        int size;
        int* arr;
    public:
        Arrays(int* arrx, int sizex) : size(sizex), arr(new int[sizex]) {
            for (int i = 0; i < size; i++)
                arr[i] = arrx[i];
        }
        ~Arrays() {
            delete[] arr;
        }
        int getSize() const {
            return (size);
        }
        int* getArray() const {
            return (arr);
        }
        int randomAccess() const {
            int randomIndex = rand() % size;
            int randomNum = arr[randomIndex];
            return (randomNum);
        }
        void insert(int num, int index) {
            for (int i = size - 1; i > index; i--)
                arr[i] = arr[i - 1];
            arr[index] = num;
        }
        void remove(int index) {
            for (int i = index; i < size - 1; i++)
                arr[i] = arr[i + 1];
            arr[size - 1] = 0;
        }
        int traverse() {
            int count = 0;
            for (int i = 0; i < size; i++)
                count += arr[i];
            return (count);
        }
        // serach a specified element in the array, return its index
        int find(int target) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == target)
                    return (i);
            }
            return (-1);
        }
        void extend(int enlarge) {
            int newSize = size + enlarge;
            int *res = new int[newSize];
            for (int i = 0; i < size; i++)
                res[i] = arr[i];
            for (int i = size; i < newSize; i++)
                res[i] = 0;
            delete[] arr;
            size = newSize;
            arr = res; 
        }
};

int main() {
    int sizex = 5;
    int *arrx = new int[sizex];
    cout << "Array arr = ";
    Arrays arr1(arrx, sizex);
    printArray(arr1.getArray(), arr1.getSize());
    
    int *numsx = new int[sizex]{1, 3, 2, 5, 4};
    cout << "Array nums = ";
    Arrays nums1(numsx, sizex);
    printArray(nums1.getArray(), nums1.getSize());

    // Random access
    int randomNum = nums1.randomAccess();
    cout << "Get a random element from nums = " << randomNum << endl;

    // insert element
    nums1.insert(6, 3);
    cout << "Insert the number 6 at index 3, resulting in nums = ";
    printArray(nums1.getArray(), nums1.getSize());

    // remove element
    nums1.remove(2);
    cout << "Remove the element at index 2, resulting in nums = ";
    printArray(nums1.getArray(), nums1.getSize());

    //traverse array
    int count = nums1.traverse();
    cout << "Sum of the array = " << count << endl;

    int index =  nums1.find(3);
    cout << "Find element 3 in nums array, index = " << index << endl;

    // length extension
    int enlarge = 3;
    nums1.extend(enlarge);
    cout << "Enlarge the array length to " << nums1.getSize() << ", resulting in arr = ";
    printArray(nums1.getArray(), nums1.getSize());

    return (0);
}
