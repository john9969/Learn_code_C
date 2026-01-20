#include <iostream>
#include <algorithm>

template<typename T> 
void revert_array(T* array, size_t length){
	T* left = array;
	T* right = array+ length -1;
	for(int i =0; i < (length /2) ; i++){
		std::swap(*left++,*right--);
	}
}

int main()
{
	int array[] ={ 1,2,3,4,5,6};
	int length = sizeof(array)/(sizeof(int));
	std::cout <<"Begin-------------------------:\n";
	for(int i =0 ; i  < length; i++){
		std::cout << array[i] << " ";
	}
	std::cout <<"\n";
	
	revert_array(array, length);
	std::cout <<"After-------------------------:\n";
	for(int i =0 ; i  < length; i++){
		std::cout << array[i] << " ";
	}
	std::cout <<"\n";
	return 1;
}