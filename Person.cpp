#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}

Person::Person(Person *CrPerson)
{
	this->m_id = CrPerson->GetId();
	this->m_PhoneNumber = CrPerson->GetPhoneNumber();
	this->m_Title = CrPerson->GetTitle();
	this->m_Name = CrPerson->GetName();
	this->m_Job = CrPerson->GetJob();
}

Person::Person(int m_id, CString m_Name, CString m_PhoneNumber, CString m_Title, CString m_Job)
{
	this->m_id = m_id;
	this->m_PhoneNumber = m_PhoneNumber;
	this->m_Title = m_Title;
	this->m_Name = m_Name;
	this->m_Job = m_Job;
}


Person::~Person()
{
}

bool Person::CompareByName(CString str)
{
	if (this->m_Name.Compare(str) == 0)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void Person::SetName(CString m_Name)
{
	this->m_Name = m_Name;
}

void Person::SetPhoneNumber(CString m_PhoneNumber)
{
	this->m_PhoneNumber = m_PhoneNumber;
}


void Person::SetTitle(CString m_Title)
{
	this->m_Title = m_Title;
}

void Person::SetJob(CString m_Job)
{
	this->m_Job = m_Job;
}

CString Person::GetName()
{
	return m_Name;
}

CString Person::GetPhoneNumber()
{
	return m_PhoneNumber;
}


CString Person::GetTitle()
{
	return m_Title;
}

CString Person::GetJob()
{
	return m_Job;
}

int Person::GetId()
{
	return m_id;
}

CString Person::GetPersonAsListItem()
{
	CString str;
	str.Format(L"%-15d .%-15s .%-20s .%-15s .%-15s", m_id, m_Name, m_PhoneNumber, m_Title, m_Job);
	return str;
}

CString Person::GetPersonAsJson()
{
	return CString();
}
