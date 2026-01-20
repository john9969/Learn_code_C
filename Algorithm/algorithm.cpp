#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
/*
PROBLEM: Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

- k is a positive integer and k <= length of list
- If the number of nodes is not a multiple of k,
  the remaining nodes at the end should stay as-is
- You may NOT change node values, only node links

Examples:
Input:  [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input:  [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

// ---------- Definition for singly-linked list ----------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// ---------- Helper Functions ----------
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

vector<int> listToVector(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << ",";
    }
    cout << "]";
}

bool checkEqual(ListNode* head, const vector<int>& expected) {
    vector<int> actual = listToVector(head);
    return actual == expected;
}

// ---------- Test Framework ----------
struct TestCase {
    vector<int> input;
    int k;
    vector<int> expected;
};



// ---------- Solution Skeleton ----------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ==================================
        // WRITE YOUR SOLUTION HERE
        // ==================================
        std::vector<int> input = listToVector(head);
        size_t size_vector_input = input.size();
        if (k != 1){
            auto reverse = [&](int from){
                for(int i =0 ; i < k /2; i++){
                    swap(input[from + i],input[from + k - 1 - i]);
                }
            };
            int index = 0;
            while (1)
            {
                if((index+k - 1) >= (size_vector_input)) break;
                reverse(index);
                index+=k;
            }
        }
        auto current = head;
        for(int i=0; i < size_vector_input; i ++){
            current->val = input.at(i);
            current = current->next;
        }
        return head;
    }
};

int main() {
    vector<TestCase> tests = {
        {{1,2,3,4,5}, 2, {2,1,4,3,5}},
        {{1,2,3,4,5}, 3, {3,2,1,4,5}},
        {{1,2,3,4,5}, 1, {1,2,3,4,5}},
        {{1,2,3,4},   4, {4,3,2,1}},
        {{1},         1, {1}},
        {{1,2},       3, {1,2}},          // k > remaining nodes
        {{1,2,3,4,5,6}, 2, {2,1,4,3,6,5}},
        {{1,2,3,4,5,6}, 3, {3,2,1,6,5,4}},
        {{1,2,3,4,5,6,7}, 3, {3,2,1,6,5,4,7}},
    };

    Solution sol;
    bool allPassed = true;

    for (int i = 0; i < tests.size(); i++) {
        ListNode* head = buildList(tests[i].input);
        ListNode* result = sol.reverseKGroup(head, tests[i].k);

        cout << "Test " << i + 1 << ": ";
        if (checkEqual(result, tests[i].expected)) {
            cout << "PASSED ";
        } else {
            cout << "FAILED ";
            allPassed = false;
        }

        cout << " | Output: ";
        printList(result);
        cout << " | Expected: [";
        for (int j = 0; j < tests[i].expected.size(); j++) {
            cout << tests[i].expected[j];
            if (j + 1 < tests[i].expected.size()) cout << ",";
        }
        cout << "]\n";
    }

    cout << "\n=============================\n";
    if (allPassed) {
        cout << "🎉 ALL TESTS PASSED 🎉\n";
    } else {
        cout << "❌ SOME TESTS FAILED ❌\n";
    }
    cout << "=============================\n";

    return 0;
}
