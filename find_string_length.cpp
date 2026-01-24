#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
int find_pattern(int index, std::string input,std::vector <std::string>& list_string){
     std::unordered_map<char,int> map;
    for(int i =index ; i< input.size(); i++){
        if(map.find(input[i]) != map.end()){
            int left = map.find(input[i])->second;
            list_string.push_back(input.substr(left,i));
            return i;
        }
        map.insert({input[i], i});
    }
    return 0;
}
int main (){
    std::string input = "abcdabcd";
    std::vector <std::string> list_string;
    int new_pos = 1;
    while(new_pos != 0){
        new_pos = find_pattern(new_pos, input, list_string);
    }
    int max =0;
    std::string string_max = "";
    for (auto it: list_string){
        std::cout<<"string: "<<it<<"\n";
        if(max < it.size()){
            max = it.size();
            string_max = it;
        }
    }
    std::cout<<"string max:"<<string_max<<"\n";
}