#include "pch.h"
#include "framework.h"
#include "Delivery.h"
#include <iostream>

Delivery::Delivery(vector<unique_ptr<Package>> delivery)
{
	this->delivery = delivery;
	
}

vector<unique_ptr<Package>> Delivery::GetDeliveryVector()
{
	return delivery;
}

