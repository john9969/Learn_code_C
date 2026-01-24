#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
            list key of key word:   {0,1,2,4}
                                    {3,5}
                                    {6}
            1. >> length of key in and tag name  
    
        */
       int shift_length= words[0].length();
       int string_length = s.length();
       int word_num = words.size();
       std::unordered_map<string, bool> word_map;
       for (int i = 0; i< word_num; i++){
            word_map.insert({words[i],false});
       }
       auto reset_map = [&](){
            for(int i=0; i < word_num; i++) 
                word_map[words[i]] = false; 
       };
       std::vector<int> output;
       for(int i =string_length; i >= shift_length; i-= shift_length){
        std::string word= s.substr(i - shift_length, shift_length);
            if(!word_map.count(word)) {
                reset_map;
                continue;
            }
            bool is_not_enough = false;
            for(int j =0 ; j < word_num; j++){
                if(!word_map[words[j]]){
                    word_map[words[j]] = true;
                    is_not_enough = true; 
                    break;
                }
            }
            if(!is_not_enough) output.push_back(i);
       }
       return output;
    }

};

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

void runTest(
    int testId,
    const string& s,
    vector<string> words,
    const vector<int>& expected
) {
    Solution sol;
    vector<int> result = sol.findSubstring(s, words);

    sort(result.begin(), result.end());
    vector<int> exp = expected;
    sort(exp.begin(), exp.end());

    cout << "Test " << testId << ": ";
    printVector(result);

    if (result == exp) {
        cout << " ✅ PASS\n";
    } else {
        cout << " ❌ FAIL\nExpected: ";
        printVector(exp);
        cout << "\n";
    }
}

int main() {
    // Example 1
    runTest(
        1,
        "barfoothefoobarman",
        {"foo", "bar"},
        {0, 9}
    );

    // Example 2
    runTest(
        2,
        "wordgoodgoodgoodbestword",
        {"word", "good", "best", "word"},
        {}
    );

    // Example 3
    runTest(
        3,
        "barfoofoobarthefoobarman",
        {"bar", "foo", "the"},
        {6, 9, 12}
    );

    // Edge case: empty result
    runTest(
        4,
        "aaaaaa",
        {"aaa", "bbb"},
        {}
    );

    // Edge case: single word
    runTest(
        5,
        "foobar",
        {"foo"},
        {0}
    );

    // Edge case: repeated words
    runTest(
        6,
        "foofoofoo",
        {"foo", "foo"},
        {0, 3}
    );

    return 0;
}
