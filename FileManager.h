#pragma once

#include "define.h"

class FileManager
{
public:
	FileManager();
	~FileManager();

	void SaveAsJson();
	void LoadAsJson();
	boolean SaveAsCsv();
	boolean LoadAsCsv();
	vector<string> csv_read_row(istream &file, char delimiter);

private:

};