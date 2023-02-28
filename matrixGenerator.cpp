#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
class matrixGenerator
{
    using timeMatrix = vector<vector<int>>;
    public:
    int timeLimit = 100;
    int minTime = 5;
    int maxTime = 30;
    void fillMatrix(int delivery, int charging, timeMatrix &ev, timeMatrix &uv, timeMatrix &evCharge, timeMatrix &uvCharge)
    {
        vector<int> uvDeliveryPoint;
        vector<int> evDeliveryPoint;
        vector<int> evChargingPoint;
        vector<int> uvChargingPoint;
        for(int i=0;i<delivery;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                if(i==j)
                {
                    uvDeliveryPoint.push_back(0);
                    evDeliveryPoint.push_back(0);
                }
                else
                {
                    uvDeliveryPoint.push_back(minTime + rand() % maxTime);
                    evDeliveryPoint.push_back(minTime + rand() % maxTime);
                }
            }
            uv.push_back(uvDeliveryPoint);
            ev.push_back(evDeliveryPoint);
            uvDeliveryPoint.clear();
            evDeliveryPoint.clear();
        }
        for(int i=0;i<charging;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                evChargingPoint.push_back(minTime + rand() % maxTime);
                uvChargingPoint.push_back(minTime + rand() % maxTime);
            }
            evCharge.push_back(evChargingPoint);
            uvCharge.push_back(uvChargingPoint);
            evChargingPoint.clear();
            uvChargingPoint.clear();
        }
    }
    void getMatrix(timeMatrix &ev, timeMatrix &uv, timeMatrix &evCharge, timeMatrix &uvCharge, int delivery, int charging)
    {
        cout<<"Time matrix for EV"<<endl;
        for(int i=0;i<delivery;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                cout<<(ev.at(i)).at(j)<<"  ";
            }
            cout<<endl;
        }
        cout<<"Time matrix for UV"<<endl;
        for(int i=0;i<delivery;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                cout<<(uv.at(i)).at(j)<<"  ";
            }
            cout<<endl;
        }
        cout<<"Time matrix for EV charging"<<endl;
        for(int i=0;i<charging;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                cout<<(evCharge.at(i)).at(j)<<"  ";
            }
            cout<<endl;
        }
        cout<<"Time matrix for UV charging"<<endl;
        for(int i=0;i<charging;i++)
        {
            for(int j=0;j<delivery;j++)
            {
                cout<<(uvCharge.at(i)).at(j)<<"  ";
            }
            cout<<endl;
        }
    }
    void findRoute(int delivery, int charging, timeMatrix &ev, timeMatrix &uv, timeMatrix &evCharge, timeMatrix &uvCharge)
    {
        int totalTime = 0;
        int deliveryPoint = 0;
        vector<int> uvDepoTime;
        vector<int> evDepoTime;
        vector<int> route;
        for(int j=0;j<delivery;j++)
        {
            uvDepoTime.push_back(minTime + rand() % maxTime);
            evDepoTime.push_back(minTime + rand() % maxTime);
        }
        cout<<"Depo"<<endl;
        for(int j=0;j<delivery;j++)
        {
            cout<<evDepoTime.at(j)<<" ";
            cout<<uvDepoTime.at(j)<<" ";
        }
        cout<<endl;
        auto it = std::min_element(std::begin(depoTime), std::end(depoTime));
        int nearestDelivery = std::distance(std::begin(depoTime), it);
        cout<<nearestDelivery;
        totalTime += depoTime.at(nearestDelivery);
        route.push_back(nearestDelivery + 1);
        if (totalTime <= timeLimit)
        {
            auto uvTime = std::min_element(std::begin(uv.at(nearestDelivery)), std::end(uv.at(nearestDelivery)));
            auto evTime = std::min_element(std::begin(ev.at(nearestDelivery)), std::end(ev.at(nearestDelivery)));
            int minTime = std::min(*uvTime, *evTime);
            cout<<minTime<<endl;
        }
    }
};
int main()
{
    int charging;
    int delivery;
    cout<<"Enter number of delivery points"<<endl;
    cin>>delivery;
    cout<<"Enter number of charging stations"<<endl;
    cin>>charging;
    vector<vector<int>> ev;
    vector<vector<int>> uv;
    vector<vector<int>> evCharge;
    vector<vector<int>> uvCharge;
    matrixGenerator generator;
    generator.fillMatrix(delivery, charging, ev, uv, evCharge, uvCharge);
    generator.getMatrix(ev, uv, evCharge, uvCharge, delivery, charging);
    generator.findRoute(delivery, charging, ev, uv, evCharge, uvCharge);
}
