#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    unordered_map <int, int> umap;
    vector <int> result;
    
    for(int i = 0; i < nums.size(); i++)
        umap[nums[i]]++;
        
    for(int j = 0; j < nums.size(); j++)
    {
        if(umap[nums[j]] == 0)
            result.push_back(nums[j]);
    }
    
        for(int y : result)
        cout << y << " ";
        cout << endl;
    return result;
}

int main(int argc, char **argv)
{
    vector <int> v {4, 3, 2, 7, 8, 2, 3, 1};
    vector <int> result;
    
    int numsArray = v.size();
    
    for(int x : v)
        cout << x << " ";
    cout << endl;
    
    result = findDisappearedNumbers(v);
    for(int y : result)
        cout << y << " ";
        
	return 0;
}
