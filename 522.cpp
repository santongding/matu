#include <iostream>

using namespace std;

template<typename T>
T get_sum(T* ptr,unsigned int len){
    T ans=T(0);
    for(unsigned int i=0;i<len;i++){
        ans=ans+ptr[i];
    }
    return ans;
}

int main()

{

  int arr_int[6] = { 1, 2, 3, 4, 5, 6 };

  double arr_double[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

  cout << get_sum(arr_int, 6) << endl;

  cout << get_sum(arr_double, 6) << endl;

  return 0;

}
