#include "pch.h"
#include "Packages.h"
#include "PriorityPackage.h"
#include "HeavyPackage.h"
#include "Delivery.h"
#include <iostream>

using namespace std;

int main()
{
    Package p1 = Package("1", 1, 2);
    PriorityPackage prio = PriorityPackage("p1", 1, 2);
    vector<unique_ptr<Package>> deliveryVector = {};
    deliveryVector.push_back(make_unique<Package>("p1", 1, 2));
    deliveryVector.push_back(make_unique<HeavyPackage>("p1", 2, 2, 2));
    Delivery delivery = Delivery(deliveryVector); 
    cout << delivery.TakeOutGivenPackage(prio).GetInfo() << endl ; 
    HeavyPackage heavy = HeavyPackage("h1", 1, 2, 3);
    delivery.AddPackage(heavy);
    cout << delivery.TakeOutGivenPackage(heavy).GetInfo() << endl;
    return 0;
}
