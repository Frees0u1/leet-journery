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
    long long solve(const vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        
        vector<int> indices;
        vector<int> indicesZeros;
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == '1') indices.push_back(i);
            else indicesZeros.push_back(i);
        }
        for(auto&&x : indicesZeros) {
            indices.push_back(x);
        }

        
    }

    long long solveHistgram(const vector<int>&indices, const vector<int>& heights) {
        if(heights.size() == 1) {
            return heights[0];
        }
        int n = heights.size();

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
