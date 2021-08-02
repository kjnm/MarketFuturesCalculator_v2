#pragma once

#include <vector>
#include <string>


enum DataSet
{
	ETH_1m,
	ETH_20_09_25_1m,
	ETH_20_12_25_1m,
	ETH_21_03_26_1m,
	ETH_21_06_25_1m
};

void compress();

class Data
{
public:


	Data() : unix_step(-1), unix_start(-1), unix_end(-1) {}
	Data(int unix_step) : unix_step(unix_step), unix_start(-1), unix_end(-1) {}
	Data(DataSet ds, bool readCompressed = true);


	void CreateDataSet_ETH_1m();
	void CreateDataSet_ETH_20_09_25_1m();
	void CreateDataSet_ETH_20_12_25_1m();
	void CreateDataSet_ETH_21_03_26_1m();
	void CreateDataSet_ETH_21_06_25_1m();

	void compressToFile(std::string filename);
	void loadCompressedFile(std::string filename, int size, int unix_step, int unix_start, int unix_end);


	int unix_step;
	int unix_start;
	int unix_end;
	
	std::vector<float> data;

	void extend(std::string filename, bool isFut);


};

