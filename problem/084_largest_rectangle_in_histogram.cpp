#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class XUnionSet {
public:
    XUnionSet(int n, const vector<int>& heights) {
        for(int i = 0; i < n; i++) {
            left.push_back(i);
            right.push_back(i);
            minHeight.push_back(heights[i]);
        }
    }
    
    int getLeftRoot(int x) {
        if(left[x] == x) return x;
        return left[x] = getLeftRoot(left[x]);
    }

    int getMinHeight(int x)  {
        return minHeight[getLeftRoot(x)];
    }

    long long calcArea(int x, const vector<int>& heights) {
        return (getRightRoot(x) -  getLeftRoot(x) + 1) * getMinHeight(x);
    }

    int getRightRoot(int x) {
        if(right[x] == x) return x;
        return right[x] = getRightRoot(right[x]);
    }

    void unite(int x, int y, const vector<int>&heights) {
        // make sure x < y 
        if(x > y) {
            return unite(y, x, heights);
        }

        left[getLeftRoot(y)] = getLeftRoot(x);
        right[getRightRoot(x)] = getRightRoot(y);


        int leftRoot = getLeftRoot(x);
        minHeight[leftRoot] = min(
            minHeight[leftRoot],
            min(heights[x], heights[y])
        );
    }

    bool isSameRoot(int x, int y) {
        return getLeftRoot(x) == getLeftRoot(y);
    }

    void printUnionSet() {
        for(int i = 0; i < left.size(); i++) {
            printf("(%d)(%d, %d)[%d]\t", i, getLeftRoot(i), getRightRoot(i), getMinHeight(i));
        }
        cout << endl;
    }
private:
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> minHeight;
};

class Solution {
public:
    long long solve(const vector<int>& heights) {
        if(heights.size() == 0) {
            return 0;
        }
        if(heights.size() == 1) {
            return heights[0];
        }
        int n = heights.size();
        vector<int> indices;
        

        /* 计数排序版本 */
        // vector<vector<int>> numMap;
        // numMap.resize(10005);
        // for(int i = 0; i < n; i++) {
        //     numMap[heights[i]].push_back(i);
        // }

        // for(int i = numMap.size() - 1; i >=0 ; i--) {
        //     for(auto&&x : numMap[i]) {
        //         indices.emplace_back(x);
        //     }
        // }

        for(int i = 0; i < n; i++) {
            indices.emplace_back(i);
        }
        
        sort(indices.begin(), indices.end(), [&heights](int lhs, int rhs) {
            return heights[lhs] > heights[rhs];
        });


        for(int i = 0; i < n; i++) {
            printf("(%d, %d) ", heights[indices[i]], indices[i]);
        }
        cout << endl;

        XUnionSet xUnionSet(n, heights);
        unordered_set<int> occured;
        occured.insert(indices[0]);
 
        long long maxArea = heights[indices[0]];
        xUnionSet.printUnionSet();
        for(int i = 1; i < n; i++) {

            if(occured.find(indices[i] - 1) != occured.end()) {
                xUnionSet.unite(indices[i] - 1, indices[i], heights);
            }
            if(occured.find(indices[i] + 1) != occured.end()) {
                xUnionSet.unite(indices[i], indices[i] + 1, heights);
            }

            maxArea = max(
                maxArea,
                xUnionSet.calcArea(indices[i], heights)
            );
            occured.insert(indices[i]);
            xUnionSet.printUnionSet();
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights{2,1,5,6,2,3};

    cout <<  sol.solve(heights) << endl;
    return 0;
}
