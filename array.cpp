#include<iostream>
#include<vector>
#include<map>
using namespace std;


int missingNumber(int arr[], int n){
    int sum = n*(n+1)/2;
    int sumN = 0;
    for(int i=0; i<n; i++){
        sumN += arr[i];
    } 
    return sum-sumN;
   
}
void findAllMissingNumber(int arr[], int n){
    int arrnew[n];
    // int resArr[n];

    for(int i=0; i<n; i++){
        arrnew[arr[i]-1] = 1;
    }
    for(int i=0; i<n; i++){
        if (arrnew[i] != 1) cout<< i << " ";
    }
}

vector<int> twoSum(int arr[], int n, int target){
    map<int,int> mpp;
    vector<int> result(2);
    for(int i=0; i<n; i++){
        int num = arr[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()){
             result[0] = mpp[more];
             result[1] = i;
             return result;
        }
        mpp[num] = i;
    }
    return {};
}

vector<int> smallThanCurrent(int arr[],int n){
    vector<int> res(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[i]> arr[j])
            {
                res[i]++;
            }
            
        }
    }
    return res;
}

int minTimeToVisitAllPoints(vector <vector <int> > &points){
    int ans=0, n=points.size();
    for(int i=0; i<n; i++){
        ans += max(abs(points[i][0]-points[i-1][0]),
                    abs(points[i][1]-points[i-1][1]));
    }
    return ans;
}

int maxProfit(vector<int> & prices){
    int maxProfit =0;
    int minPrice = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i]- minPrice);
    }
    return maxProfit;
    
}

int main(){
    int arr[] = {8,1,2,2,3};

    vector<int> result = smallThanCurrent(arr, 5);
    if (!result.empty()) {
        for (int i = 0; i < result.size(); i++)
        {
            cout << "values: " << result[i]  << endl;
        }
        
        
    } else {
        cout << "No two sum solution found" << endl;
    }
    return 0;
}