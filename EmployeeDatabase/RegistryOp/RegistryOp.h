#pragma once
#include <Windows.h>
#include<winreg.h>
#include<string>
class RegistryOp
{
public:
	HKEY CreatSubKey(HKEY hKey = nullptr, HKEY pKey = nullptr, const char* keyPath = nullptr);
	void DleteSubKey(HKEY pKey=nullptr, const char* keyPath=nullptr);
	void CreatSubKeyValue(HKEY pKey = nullptr,const char* parentKeyPath = nullptr,
		const char* valueName = nullptr,std::string newValue = "",DWORD dataType = 0);
	void ReadSubKeyValue(HKEY pKey=nullptr, const char* keyPath=nullptr, const char* valueName=nullptr);
	void ModifySubKeyValue(HKEY pKey = nullptr, const char* keyPath = nullptr, const char* valueName=nullptr, std::string newValue="", DWORD dataType = 0);
};

