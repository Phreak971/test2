#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "pch.h"

class Customer
{
private:
    int index;
    std::string customerId;
    std::string firstName;
    std::string lastName;
    std::string company;
    std::string city;
    std::string country;
    std::string phone1;
    std::string phone2;
    std::string email;
    std::string subscriptionDate;
    std::string website;

public:
    Customer(int ind,
             std::string cid,
             std::string fName,
             std::string lName,
             std::string cmpany,
             std::string cty,
             std::string counry,
             std::string ph1,
             std::string ph2,
             std::string emal,
             std::string subsciptionDt,
             std::string web)
    {
        index = ind;
        customerId = cid;
        firstName = fName;
        lastName = lName;
        company = cmpany;
        city = cty;
        country = counry;
        phone1 = ph1;
        phone2 = ph2;
        email = emal;
        subscriptionDate = subsciptionDt;
        website = web;
    }

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer)
    {
        os << std::left << std::setw(8) << customer.index << std::setw(20) << customer.customerId
           << std::setw(15) << customer.firstName << std::setw(15) << customer.lastName << std::setw(20) << customer.company
           << std::setw(22) << customer.city /*<< std::setw(35) << customer.country*/
           << std::setw(25) << customer.phone1 << std::setw(25) << customer.phone2 << std::setw(35) << customer.email
           << std::setw(15) << customer.subscriptionDate << std::setw(25) << customer.website << std::endl;
        return os;
    }
};

#endif