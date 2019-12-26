/*Question - Range Sum Queries. Two operations on an array - 
1. Print the sum of an array within index L to R
2. Update ith index to a new value.
*/
#include <bits/stdc++.h>
using namespace std;


//Gives sum of elements within L to R
int query(int *blocks,int *a,int L, int R, int rn){
    int ans = 0;
    //Left Part
    while(L<R && L!=0 && L%rn!=0){
        ans += a[L];
        L++;
    }
    //Middle Part
    while(L + rn <= R){
        int block_id = L/rn;
        ans += blocks[block_id];
        L += rn;
    }
    //Right Part
    while(L<=R){
        ans += a[L];
        L++;
    }
    return ans;
}

//Updates ith value to a new val
void update(int *blocks,int *arr,int i, int val,int rn){
    int block_id = i/rn;
    blocks[block_id] += (val - arr[i]);
    arr[i] = val;
}

int main() {
    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(a)/sizeof(int);
    int rn = sqrt(n);
    int *blocks = new int[rn+1]{0};
    
    //Build a Blocks Array
    int block_id = -1;
    for(int i=0; i<n; i++){
        if(i%rn == 0){
            block_id++;
        }
        blocks[block_id] += a[i];
    }
    //Printing the blocks array
    for(int i=0; i<=rn; i++)
        cout<<blocks[i]<<"  ";
    cout<<endl;

    //Query for sum and update
    update(blocks,a,2,15,rn);
    cout<<query(blocks,a,2,8,rn)<<endl;
}
