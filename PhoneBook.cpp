#include "stdafx.h"
#include "PhoneBook.h"

PhoneBook* PhoneBook::instance = NULL;
// c++ �̱��� �ʼ� �ФФФ� ����ü ��...
// c++ ������ cpp ���� ���� ���� ������Ͽ��� ������ static ������ �ʱ�ȭ ���������
// �ٸ� �Լ����� �� ������ ����� �� �ִ�.
// �ƴϸ� ��ŷ ���� ��

PhoneBook::PhoneBook()
{
	this->m_AutoIncId = 1;	
}

PhoneBook* PhoneBook::getInstance()
{
	if (!instance) {
		instance = new PhoneBook();
	}
	return instance;
}

// ��� ���ֱ�
#pragma warning(push)
#pragma warning(disable: 4018)

vector<int> PhoneBook::SearchByName(const CString str)
{
	vector<int> naCountVector;

	for (int i = 0; i < m_CaPerson.size(); i++) {
		if (m_CaPerson.at(i)->GetName().Compare(str) == 0)
		{
			naCountVector.push_back(i);
		}
	}

	return naCountVector;
}
int PhoneBook::SearchById(int nId)
{
	int nIndex = -1;
	for (int i = 0; i < m_CaPerson.size(); i++) {
		if (m_CaPerson.at(i)->GetId() == nId)
		{
			nIndex = i;
			break;
		}
	}
	return nIndex;
}

void PhoneBook::Delete(int nId)
{
	for (int i = 0; i < m_CaPerson.size(); i++)
	{
		if (m_CaPerson.at(i)->GetId() == nId)
		{
			m_CaPerson.erase(m_CaPerson.begin() + i);
		}
	}
}
void PhoneBook::DeleteById(int nId)
{
	int nIdx = SearchById(nId);
	m_CaPerson.erase(m_CaPerson.begin() + nIdx);
}

void PhoneBook::Add(const Person CPerson)
{
	m_CaPerson.push_back(new Person(CPerson));
}
void PhoneBook::Edit(const int idx, const Person CPerson)
{
	m_CaPerson.erase(m_CaPerson.begin() + idx);
	m_CaPerson.insert(m_CaPerson.begin() + idx, new Person(CPerson));
}

int PhoneBook::GetIdByPerson(Person CPerson)
{
	return CPerson.GetId();
}

Person* PhoneBook::GetPersonById(int nId)
{
	Person *CPerson = NULL;

	for (int i = 0; i < m_CaPerson.size(); i++)
	{
		if (m_CaPerson.at(i)->GetId() == nId)
		{
			CPerson = m_CaPerson.at(i);
			break;
		}
	}
	return CPerson;
}

#pragma warning(pop)