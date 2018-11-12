#ifndef CONNECTION_H
#define CONNECTION_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct rawdata;
class IHistorianData
{
public:
    IHistorianData();

    int getRawData(std::string tagName, tm begin, std::vector<rawdata> &data);

    int getLatestRawData(std::string tagName, rawdata &data);

    std::string getErrorMsg();
};

enum Quality { GOOD = 1, BAD, UNCETRTAIN, NOT_AVAILABLE, REALLY_UNKNOW };
struct rawdata
{
    std::string tag;
    double value;
    tm timestamp;
    Quality quality;
};


#endif // CONNECTION_H
