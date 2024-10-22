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

    delete[] arrx;
    delete[] numsx;
    return (0);
}
