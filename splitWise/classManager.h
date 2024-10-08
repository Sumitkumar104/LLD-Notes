#define CLASSMANAGER_H
#include<bits/stdc++.h>
using namespace std;

class splitWise
{
    vector<vector<int>> store;   // store[x][y]==k means x need to pay k amount to y
    int totalUser;
    enum splitType{
        exact ,
        percentage,
        equal
    };

    public:
    splitWise(int n)
    {
        this->totalUser=n;
        this->store.resize(n,vector<int>(n,0));
    }

   void handleCoreSplit(int amount, string splitType,vector<pair<int,int>> &arr,int ownUser)
   {

   }


};

