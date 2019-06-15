#include <iostream>

template<typename T, size_t n>
void print_array(T const(& arr)[n]){
  for (size_t i=0; i<n;i++){
    std::cout << arr[i]<<' ';
  }
}
void swap_element (int&a, int&b){
  int t=a;a=b;b=t;
}

void quick_sort(int*A, int n, int minLength=1){
  if(n>minLength){
    int pivotPos = n/2;
    swap_element(A[pivotPos], A[n-1]);
    pivotPos=n-1;
    int pivot= A[pivotPos];
    int i=0;
    int j = n-2;

    do{
      while(i<n && A[i]<pivot){i++;}
      //beginning from the left, search for an element larger or equal to pivot. If found, it is equal to i.
      while(j>0 && A[j] >=pivot){j--;}
      //beginning from the right, search for an element smaller than pivot. If found, it is equal to j.
      if(i<j){swap_element(A[i], A[j]);}
    }while(i<j); 
    swap_element(A[i],A[pivotPos]);
    int split_point = i;

    quick_sort(A, split_point, minLength);
    quick_sort(A + split_point+1, n-split_point-1,minLength);
  }
}int main() {
  int n=10;
  std::cout << "Unsorted Array is \n";
  int a[10]={8,22,6,3,4,1,9,2,12,7};
  print_array(a);
  printf("\n");
  std::cout << "Sorted Array is: \n";
  quick_sort(a, n);
  print_array(a);

}
 


