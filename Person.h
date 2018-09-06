#pragma once

#include "define.h"

class Person
{
public:
	Person();
	Person(Person *CrPerson);
	Person(int m_id, CString m_Name, CString m_PhoneNumber, CString m_Title, CString m_Job);
	~Person();
	
	bool CompareByName(CString str);

	void SetName(CString m_Name);
	void SetPhoneNumber(CString m_PhoneNumber);
	void SetTitle(CString m_Title);
	void SetJob(CString m_Job);

	CString GetName();
	CString GetPhoneNumber();
	CString GetTitle();
	CString GetJob();
	int GetId();

	CString GetPersonAsListItem();
	CString GetPersonAsJson();
protected:

private:
	CString m_Name;
	CString m_PhoneNumber;
	CString m_Title;
	CString m_Job;
	int m_id;
};