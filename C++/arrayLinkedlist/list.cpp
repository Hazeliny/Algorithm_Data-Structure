/*
// initialize list
vector<int> nums1;
vector<int> nums = {1, 3, 2, 5, 4};
// visit element
int num = nums[i];
nums[1] = 0;
// clear list
nums.clear();
//add element at the end
nums.push_back(1);
nums.push_back(3);
// insert element
nums.insert(nums.begin() + 3, 6);
// delete element
nums.erase(nums.begin() + 3);
// iterate list through index
int count = 0;
for (int i = 0; i < nms.size(); i++)
    count += nums[i];
// iterate directly
count = 0;
for (int num : nums)
    count += num;
// catenate two lists
vector<int> nums1 = {6, 8, 7, 10, 9};
nums.insert(nums.end(), nums1.begin(), nums1.end());
// sort list
sort(nums.begin(), nums.end());
*/

#include "../inc/algo.hpp"

class mList {
    private:
        int *arr;
        int arrCapacity = 10;
        int arrSize = 0;
        int extendRatio = 2;

    public:
        mList() {
            arr = new int[arrCapacity];
        }
        ~mList() {
            delete[] arr;
        }
        int size() {
            return (arrSize);
        }
        int capacity() {
            return (arrCapacity);
        }
        int get(int index) {
            if (index < 0 || index >= size())
                throw (out_of_range("Index out of bounds"));
            return (arr[index]);
        }
        // update element
        void set(int index, int num) {
            if (index < 0 || index >= size())
                throw (out_of_range("Index out of bounds"));
            arr[index] = num;
        }
        void add(int num) {
            if (size() == capacity())
                extendCapacity();
            arr[size()] = num;
            arrSize++;
        }
        void insert(int index, int num) {
            if (index < 0 || index >= size())
                throw (out_of_range("Index out of bounds"));
            if (size() == capacity())
                extendCapacity();
            for (int i = size() - 1; i >= index; i--)
                arr[i + 1] = arr[i];
            arr[index] = num;
            arrSize++;
        }
        int remove(int index) {
            if (index < 0 || index >= size())
                throw (out_of_range("Index out of bounds"));
            int num = arr[index];
            for (int i = index; i < size() - 1; i++)
                arr[i] = arr[i + 1]; 
            arrSize--;
            return (num);
        }

        void extendCapacity() {
            int newCapacity = capacity() * extendRatio;
            int *tmp = arr;
            arr = new int[newCapacity];
            for (int i = 0; i < size(); i++)
                arr[i] = tmp[i];
            delete[] tmp;
            arrCapacity = newCapacity;
        }
        // convert the list into a vector to print
        vector<int> toVector() {
            vector<int> vec(size());
            for (int i = 0; i < size(); i++)
                vec[i] = arr[i];
            return (vec);
        }
};

int main() {
    mList *nums = new mList();
    nums->add(1);
    nums->add(3);
    nums->add(2);
    nums->add(5);
    nums->add(4);
    cout << "List nums = ";
    vector<int> vec = nums->toVector();
    printVector(vec);
    cout << "Capacity = " << nums->capacity() << ", length = " << nums->size() << endl;

    nums->insert(3, 6);
    cout << "Insert the number 6 at index 3, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);

    nums->remove(3);
    cout << "Remove the element at index 3, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);
    
    int num = nums->get(1);
    cout << "Access the element at index 1, obatained num = " << num << endl;

    nums->set(1, 0);
    cout << "Update the element at index 1 to 0, resulting in nums = ";
    vec = nums->toVector();
    printVector(vec);

    for (int i = 0; i < 10; i++)
        nums->add(i);
    cout << "After extending, list nums = ";
    vec = nums->toVector();
    printVector(vec);
    cout << "Capacity = " << nums->capacity() << ", length = " << nums->size() << endl;
    delete nums;
    return (0);
}