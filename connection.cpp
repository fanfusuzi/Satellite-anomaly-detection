#include "connection.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>



IHistorianData::IHistorianData()
{

}
std::string IHistorianData::getErrorMsg()
{
    return "error";
}

int IHistorianData::getLatestRawData(std::string tagName, rawdata &data)
{
    rawdata a;
    a.quality = GOOD;
    a.value = 3;


    return 1;

}

int IHistorianData::getRawData(std::string tagName, tm begin, std::vector<rawdata> &data)
{

   tm a;

   return 1;
}
