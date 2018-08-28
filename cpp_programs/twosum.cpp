#include <iostream>
#include <vector>
#include <map>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;

	for (int i = 0; i < numbers.size(); i++) 
	{
		//Get compliment of target
		int numberToFind = target - numbers[i];

		printf("Looking for %d in hash table\n",numberToFind);

        //Look if 7,2 are avilable in the hash table
		if (hash.find(numberToFind) != hash.end()) 
		{
			printf("Match found\n");
            //If available then we found the match
			//push_back(match) in this case its hash[7] = 0
			result.push_back(hash[numberToFind]);
	
			//push_back(current). In this case its 
			result.push_back(i);
			
			//Return the vector			
			return result;
		}
		
		printf("Match not found. Storing %d in hash at index %d\n",numbers[i],i);

        //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}

int main()
{
	vector<int> v;
	vector<int> result;

	int k = 9;

	v.push_back(2);
	v.push_back(11);
	v.push_back(15);
	v.push_back(7);

	result = twoSum(v,k);
	cout << result.at(0) << endl;
	cout << result.at(1) << endl;

	return 0;
}
