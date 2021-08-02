#include "Data.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <assert.h>

void Data::extend(std::string filename, bool isFut = true)
{
    std::ifstream myfile(filename);
    std::vector<std::string> row;
    std::string line, word, temp;

    assert(myfile.is_open());

    bool first = true;
    bool secound = false;
    while (getline(myfile, line))
    {

        std::stringstream s(line);

        row.clear();

        while (std::getline(s, word, ',')) {

            row.push_back(word);
        }


        if ((secound && isFut) || (first && !isFut))
        {
            secound = false;
            first = false;

            if (unix_start == -1)
            {
                unix_start = std::stoll(row[0] ) / unix_step;
            }
            else
            {
                assert(unix_end + 1 == std::stoll(row[0]) / unix_step); //wrong order of files
            }
        }

        if (!first || !isFut)
        {

            data.push_back(std::stof(row[1]));


            unix_end = std::stoll(row[0]) / unix_step;
        }

        if (first)
        {
            first = false;
            secound = true;
        }
    }

    myfile.close();
}

Data::Data(DataSet ds, bool readCompressed) : unix_step(-1), unix_start(-1), unix_end(-1)
{
    if (readCompressed)
    {
        switch (ds)
        {

        case ETH_1m:
            loadCompressedFile("ETH_1m.dat", 394040, 60000, 26559360, 26953919);
            break;

        case ETH_20_09_25_1m:
            loadCompressedFile("ETH_20_09_25_1m.dat", 98935, 60000, 26559360, 26683678);
            break;

        case ETH_20_12_25_1m:
            loadCompressedFile("ETH_20_12_25_1m.dat", 214145, 60000, 26604000, 26814725);
            break;

        case ETH_21_03_26_1m:
            loadCompressedFile("ETH_21_03_26_1m.dat", 262098, 60000, 26648640, 26945761);
            break;

        case ETH_21_06_25_1m:
            loadCompressedFile("ETH_21_06_25_1m.dat", 139176, 60000, 26814744, 26953919);
            break;

        default:
            assert(false);
        }
    }
    else
    {
        switch (ds)
        {

        case ETH_1m:
            CreateDataSet_ETH_1m();
            break;

        case ETH_20_09_25_1m:
            CreateDataSet_ETH_20_09_25_1m();
            break;
        case ETH_20_12_25_1m:
            CreateDataSet_ETH_20_12_25_1m();
            break;
        case ETH_21_03_26_1m:
            CreateDataSet_ETH_21_03_26_1m();
            break;
        case ETH_21_06_25_1m:
            CreateDataSet_ETH_21_06_25_1m();
            break;

        default:
            assert(false);
        }
    }

}

void Data::CreateDataSet_ETH_1m()
{
    unix_step = 60000;

    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-07.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-08.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-09.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-10.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-11.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2020-12.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2021-01.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2021-02.csv", false);
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth\\ETHUSDT-1m-2021-03.csv", false);
}

void Data::CreateDataSet_ETH_20_09_25_1m()
{
    unix_step = 60000;

    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_200925\\ETHUSD_200925-1m-2020-07.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_200925\\ETHUSD_200925-1m-2020-08.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_200925\\ETHUSD_200925-1m-2020-09.csv");

    unix_end = 26683678;
}

void Data::CreateDataSet_ETH_20_12_25_1m()
{
    unix_step = 60000;

    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_201225\\ETHUSD_201225-1m-2020-08.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_201225\\ETHUSD_201225-1m-2020-09.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_201225\\ETHUSD_201225-1m-2020-10.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_201225\\ETHUSD_201225-1m-2020-11.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_201225\\ETHUSD_201225-1m-2020-12.csv");

    unix_end = 26814725;
}

void Data::CreateDataSet_ETH_21_03_26_1m()
{
    unix_step = 60000;

    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2020-09.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2020-10.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2020-11.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2020-12.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2021-01.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2021-02.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210326\\ETHUSD_210326-1m-2021-03.csv");

    unix_end = 26945761;
}

void Data::CreateDataSet_ETH_21_06_25_1m()
{
    unix_step = 60000;

    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210625\\ETHUSD_210625-1m-2020-12.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210625\\ETHUSD_210625-1m-2021-01.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210625\\ETHUSD_210625-1m-2021-02.csv");
    extend("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator_v2\\Debug\\data\\eth_210625\\ETHUSD_210625-1m-2021-03.csv");


}

void Data::compressToFile(std::string filename)
{
    std::ofstream fout(filename, std::ios::out | std::ios::binary);
    fout.write((char*)&data[0], data.size() * sizeof(float));
    fout.close();

}

void Data::loadCompressedFile(std::string filename, int size, int unix_step, int unix_start, int unix_end)
{
    this->unix_step = unix_step;
    this->unix_start = unix_start;
    this->unix_end = unix_end;

    std::ifstream fin(filename, std::ios::out | std::ios::binary);
    data.resize(size);
    fin.read(reinterpret_cast<char*>(&data[0]), size * sizeof(float));
}


void compress()
{
    {
        Data d(ETH_20_09_25_1m);

        std::cout << "ETH_20_09_25_1m " << d.data.size() << " " << d.unix_step << " " << d.unix_start << " " << d.unix_end << std::endl;

        d.compressToFile("ETH_20_09_25_1m.dat");

    }

    {
        Data d(ETH_20_12_25_1m);

        std::cout << "ETH_20_12_25_1m " << d.data.size() << " " << d.unix_step << " " << d.unix_start << " " << d.unix_end << std::endl;

        d.compressToFile("ETH_20_12_25_1m.dat");
    }

    {
        Data d(ETH_21_03_26_1m);

        std::cout << "ETH_21_03_26_1m " << d.data.size() << " " << d.unix_step << " " << d.unix_start << " " << d.unix_end << std::endl;

        d.compressToFile("ETH_21_03_26_1m.dat");
    }
    {
        Data d(ETH_21_06_25_1m, false);

        std::cout << "ETH_21_06_25_1m " << d.data.size() << " " << d.unix_step << " " << d.unix_start << " " << d.unix_end << std::endl;

        d.compressToFile("ETH_21_06_25_1m.dat");
    }

    {
        Data d(ETH_1m, false);

        std::cout << "ETH_1m " << d.data.size() << " " << d.unix_step << " " << d.unix_start << " " << d.unix_end << std::endl;

        d.compressToFile("ETH_1m.dat");
    }

}