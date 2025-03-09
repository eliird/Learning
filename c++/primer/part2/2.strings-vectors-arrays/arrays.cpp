#include <iostream>
#include <string>
#include <array>
#include<vector>

using std::vector;


using std::cin; using std::cout; using std::string; using::std::endl;

int exercise1(){
    /*
    creating array
    - You need to specify the size at compile time
    */
   unsigned cnt = 42;
   constexpr unsigned sz = 32;

   int arr[10];

   int *parr[sz];
   string bad[cnt]; // seems to compile fine here but can be error if there are expressions modifying cnt
   string strs[sz];

   cnt += 1;
   int bad2[cnt]; // seems to compile fine here but can be error if there are expressions modifying cnt

   // initializing vector from array
   int int_arr[] = {0, 1, 2, 3, 4, 5};
   vector<int> vec(std::begin(int_arr), std::end(int_arr));
   return 0;
}

void excercise2(){
    /*
    initializing array

    */
   const unsigned sz =3;
   int ia1[sz] = {0, 1, 2}; //ok
   int a2[]=  {0, 1, 2}; // an array of dimension 3
   int a3[5] = {0, 1, 2}; // array with elements [0, 1, 2, 0, 0]

   string a4[3] = {"hi", "bye"}; // {"hi", "bye", ""}
   // int a5[2] = {0, 1, 2}; // error as try to initialize more than allocated

   // Char ARRAYS are SPECIAL
   // below size of a1 is 3 and all others is 4
   char c1[] = {'c', '+', '+'}; //list initialization non null
   char c2[] = {'c', '+', '+', '\0'}; //list initialization with null
   char c3[] = "c++"; // null added automatically
   // const char a4[6] = "Danie;"; //error no space for null

   // no copy or assignment operator for arrays
   int n1[] = {0, 1, 2};
   // int n2[] = n1; // error 
}

void excercise3(){
    /*
    use pointers to initialize an array to its index
    */
   const unsigned sz = 100;
   int arr[sz];
   int *start = arr;
   int *end = arr + sz;

    while(start < end){
        *start = 1;
        *start++;
    }

    for(int i=0; i < sz; i++){
        cout << arr[i] << " " ;
    }

    cout << endl;
}



bool check_array_equal(int arr1[], int arr2[], int m, int n){
    if (m != n)
        return false;

    for (int i=0; i < n; i++)
        if(arr1[i] != arr2[i])
            return false;
    return true;
}


bool check_vector_equal(const vector<int> &vec1, const vector<int> &vec2){
    return vec1 == vec2;
}

void excercise4(){
    /*
    compare if 2 arrays are equal
    */
   unsigned cnt1 = 10;
   unsigned cnt2 = 10;

   int arr1[cnt1];
   for(int i=0; i < cnt1; i++)
        arr1[i] = 0;

   int arr2[cnt2];
   for(int i=0; i < cnt2; i++)
       arr2[i] = 1;

    auto equal = check_array_equal(arr1, arr2, cnt1, cnt2);

    cout << equal << endl;

    vector<int> vec1(10, 1);
    vector<int> vec2(20, 1);
    equal = check_vector_equal(vec1, vec2);
    cout << equal << endl;

}


void excercise5(){
    /*
    multidimnensional arrays
    */
   int a[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
   }; 

   // same thing as above can be initialized like below, becuase internally everything is stored as linear arrary
   int a2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

   //binds 2nd row of array a to row variable.
   int (&row_)[4] = a[1];

   //looping multidimensional array
   constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt]; // 12 uninitialized elements
    // for each row
    for (size_t i = 0; i != rowCnt; ++i) {
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {
            // assign the element’s positional index as its value
            ia[i][j] = i * colCnt + j;
        }
    }

    // looping using iterators
    int test_arr[3][4] = {0};
    size_t cnt = 0;
    for(auto &row: test_arr)
        for(auto &col: row){
            col = cnt;
            ++cnt;
        }
    
    for(auto &row: test_arr){
        for(auto &col: row)
            cout << col << " ";
        cout << endl;
    }
}
int main(){
    excercise5();
}