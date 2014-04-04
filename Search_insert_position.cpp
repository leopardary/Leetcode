#include<iostream>
using namespace std;
class Solution {
public:
    int binarySearch(int A[], int start, int end, int target){
        int mid=(start+end)/2;
        if (end==start) {
            if (A[start]<target) return start+1; 
            if (A[start]>target) return start;
        }
        if (A[mid]==target) return mid;
        else {
            if (A[mid]<target) return binarySearch(A,mid+1,end,target);
            else return binarySearch(A,start, mid,target);
            
        }
    }
    int searchInsert(int A[], int n, int target) {
        return binarySearch(A,0,n-1,target);
    }
};

int main(){
	int a[10];
	int temp;
	int n;
	cin>>n;
	int i=0;
	while(i<n){
		cin>>temp;
		a[i]=temp;
		i++;
	}
	int target;
	cin>>target;
	Solution calculate;
	int index=calculate.searchInsert(a,i,target);
	return index;
}