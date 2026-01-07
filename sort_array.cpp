#include <iostream>

void minToMax(){
    int array[] = {1,5,4,56,6,3,5,3,6,3,2};
    std::cout<<"start program"<<std::endl;
    size_t size = sizeof(array)/sizeof(int);
    int buff = -1;
    bool has_done = false;
   
    std::cout<<"MIN-->>> MAX";
    buff = -1;
    has_done = false;
    while (!has_done){
    bool has_swap = false;
    for (int i =1; i < size; i++){
        buff = array[i];
        if(buff < array[i-1]) {
            array[i] = array[i-1];
            array[i-1] = buff;
            has_swap = true;
        }
    }
    if(!has_swap) has_done = true;
    }
    for (int i =0; i < size ; i++){
        std::cout<<" "<<array[i]<<" ";
    }

}

void maxToMin(){
        int array[] = {1,5,4,56,6,3,5,3,6,3,2};
    std::cout<<"start program"<<std::endl;
    size_t size = sizeof(array)/sizeof(int);
    int buff = -1;
    bool has_done = false;
    std::cout<<"Array Start-->>>";
    for (int i =0; i < size ; i++){
        std::cout<<" "<<array[i]<<" ";
    }

    //=============MAX -> MIN
    while (!has_done){
        bool has_swap = false;
        for (int i =1; i < size; i++){
            buff = array[i];
            if(buff > array[i-1]) {
                array[i] = array[i-1];
                array[i-1] = buff;
                has_swap = true;
            }
        }
        if(!has_swap) has_done = true;
    }
    for (int i =0; i < size ; i++){
        std::cout<<" "<<array[i]<<" ";
    }
}
int main (){
    minToMax();
    maxToMin();
}