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
	vector<string> CsvReadRow(istream &file, char cDelimiter);

private:
	string CStringToString(CString cstr);
	CString StringToCString(string str);
};