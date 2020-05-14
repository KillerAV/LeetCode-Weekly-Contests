#include <bits/stdc++.h>
using namespace std;

map<pair<string,string>,int> M;
map<pair<string,string>,int> N;
map<int,pair<string,int>> X;
void checkIn(int id, string stationName, int t) {
    X[id]={stationName,t};
}

void checkOut(int id, string stationName, int t) {
    pair<string,int> temp=X[id];
    M[{temp.first,stationName}]+=t-temp.second;
    N[{temp.first,stationName}]++;
}

double getAverageTime(string startStation, string endStation) {
    double ans=double(M[{startStation,endStation}])/N[{startStation,endStation}];
    return ans;
}

int main() 
{
    int Q;
    cin>>Q;
    while(Q--)
    {
        int type;
        cin>>type;
        //Check-in
        if(type==0)
        {
            int id;
            string stationName;
            int t;
            cin>>id>>stationName>>t;
            checkIn(id,stationName,t);
        }
        //Check-out
        else if(type==1)
        {
            int id;
            string stationName;
            int t;
            cin>>id>>stationName>>t;
            checkOut(id,stationName,t);
        }
        else if(type==2)
        {
            string startStation, endStation;
            double ans=getAverageTime(startStation,endStation);
            printf("%0.9lf\n", ans);
        }
    }   
}