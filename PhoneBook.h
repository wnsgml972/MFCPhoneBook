#pragma once

#include "Person.h"
#include "FileManager.h"
#include "define.h"

class PhoneBook
{
public:

	static PhoneBook* getInstance();

	void PhoneBook::DeleteById(int nId);
	void Delete(int nId);
	void Add(const Person CPerson);
	void Edit(const int idx, const Person CPerson);
	int GetIdByPerson(Person CPerson);
	Person* GetPersonById(int nId);
	int PhoneBook::SearchById(int nId);


	vector<int> SearchByName(const CString str);
	vector<Person*> m_CaPerson;
	int m_AutoIncId;

protected:

private:
	PhoneBook();
	FileManager m_CFileManager;
	static PhoneBook *instance;
};