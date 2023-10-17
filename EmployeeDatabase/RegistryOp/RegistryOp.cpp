#include "RegistryOp.h"
#include<iostream>
#include<winreg.h>
#include<atlstr.h>
#include<string>


HKEY RegistryOp::CreatSubKey(HKEY hKey, HKEY pKey, const char* keyPath)
{
    if(keyPath==nullptr)
    {
        char tempPath[256];
        std::cout << "Enter yout SunKey path ( use \\\\ ) : ";
        //std::cin >> tempPath;
        std::cin.ignore();
        std::cin.getline(tempPath, sizeof(tempPath));
	    keyPath = tempPath;

        DWORD primaryKeyChoice;
        std::cout << "Choose a primary key:" << std::endl;
        std::cout << "1. HKEY_CLASSES_ROOT" << std::endl;
        std::cout << "2. HKEY_CURRENT_CONFIG" << std::endl;
        std::cout << "3. HKEY_CURRENT_USER" << std::endl;
        std::cout << "4. HKEY_LOCAL_MACHINE" << std::endl;
        std::cout << "5. HKEY_USERS" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> primaryKeyChoice;

        switch (primaryKeyChoice) {
        case 1:
            pKey = HKEY_CLASSES_ROOT;
            break;
        case 2:
            pKey = HKEY_CURRENT_CONFIG;
            break;
        case 3:
            pKey = HKEY_CURRENT_USER;
            break;
        case 4:
            pKey = HKEY_LOCAL_MACHINE;
            break;
        case 5:
            pKey = HKEY_USERS;
            break;
        default:
            std::cerr << "Invalid primary key choice." << std::endl;
            return nullptr;
        }
    }

    LONG result = RegCreateKeyExA(
        pKey,
        keyPath,
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        nullptr,
        &hKey,
        nullptr
    );
    if (SUCCEEDED(result)) 
    {
        std::cout << "SubKey is created ." << std::endl;
    }
    return hKey;
}

void RegistryOp::DleteSubKey(HKEY pKey, const char* keyPath)
{
    if (keyPath == nullptr) 
    {

        HKEY pKey;
        char tempPath[256];

        DWORD primaryKeyChoice;
        std::cout << "Choose a primary key:" << std::endl;
        std::cout << "1. HKEY_CLASSES_ROOT" << std::endl;
        std::cout << "2. HKEY_CURRENT_CONFIG" << std::endl;
        std::cout << "3. HKEY_CURRENT_USER" << std::endl;
        std::cout << "4. HKEY_LOCAL_MACHINE" << std::endl;
        std::cout << "5. HKEY_USERS" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> primaryKeyChoice;

        switch (primaryKeyChoice)
        {
        case 1:
            pKey = HKEY_CLASSES_ROOT;
            break;
        case 2:
            pKey = HKEY_CURRENT_CONFIG;
            break;
        case 3:
            pKey = HKEY_CURRENT_USER;
            break;
        case 4:
            pKey = HKEY_LOCAL_MACHINE;
            break;
        case 5:
            pKey = HKEY_USERS;
            break;
        default:
            std::cerr << "Invalid primary key choice." << std::endl;
            return ;
        }

        std::cout << "Enter yout SunKey path ( use \\\\ ) : ";
        std::cin.ignore();
        std::cin.getline(tempPath, sizeof(tempPath));
        //std::cin>>tempPath;
    const char* keyPath = tempPath;
    }
    if (SUCCEEDED(RegDeleteKeyA(pKey, keyPath)))
    {
        std::cout << "Subkey deleted successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error deleting subkey."<< std::endl;
    }

}

void RegistryOp::CreatSubKeyValue(HKEY pKey,const char* parentKeyPath,const char* valueName,std::string newValue,DWORD dataType)
{
    if(parentKeyPath==nullptr)
    {
        HKEY pKey;

        DWORD primaryKeyChoice;
        std::cout << "Choose a primary key:" << std::endl;
        std::cout << "1. HKEY_CLASSES_ROOT" << std::endl;
        std::cout << "2. HKEY_CURRENT_CONFIG" << std::endl;
        std::cout << "3. HKEY_CURRENT_USER" << std::endl;
        std::cout << "4. HKEY_LOCAL_MACHINE" << std::endl;
        std::cout << "5. HKEY_USERS" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> primaryKeyChoice;

        switch (primaryKeyChoice) 
        {
        case 1:
            pKey = HKEY_CLASSES_ROOT;
            break;
        case 2:
            pKey = HKEY_CURRENT_CONFIG;
            break;
        case 3:
            pKey = HKEY_CURRENT_USER;
            break;
        case 4:
            pKey = HKEY_LOCAL_MACHINE;
            break;
        case 5:
            pKey = HKEY_USERS;
            break;
        default:
            std::cerr << "Invalid primary key choice." << std::endl;
            return ;
        }

        char tempPath[256];
        std::cout << "Enter the parent SubKey path (use \\\\ ): ";
        //std::cin >> tempPath;
        std::cin.ignore();
        std::cin.getline(tempPath, sizeof(tempPath));
        const char* parentKeyPath = tempPath;

        char tempValue[256];
        std::cout << "Enter the name of the value you want to create: ";
        std::cin.ignore();
        std::cin.getline(tempValue, sizeof(tempValue));
        //std::cin >> tempValue;
        const char* valueName = tempValue;

        // Prompt for the new value and data type
        std::string newValue;
        std::cout << "Enter the value: ";
        std::cin.ignore();
        std::getline(std::cin,newValue);
        //std::cin >> newValue;

        DWORD dataType;
        DWORD dataSize = 0;

        // Determine the data type based on user input
        std::cout << "Enter the data type (1 for REG_SZ, 2 for REG_DWORD, 3 for REG_MULTI_SZ): ";
        int typeChoice;
        std::cin >> typeChoice;

        switch (typeChoice)
        {
        case 1:
            dataType = REG_SZ;
            dataSize = static_cast<DWORD>(newValue.length() + 1); // Include null terminator
            break;
        case 2:
            dataType = REG_DWORD;
            dataSize = sizeof(DWORD);
            break;
        case 3:
            dataType = REG_MULTI_SZ;
            dataSize = static_cast<DWORD>(newValue.length() + 2); // Include double null terminator
            break;
        default:
            std::cerr << "Invalid data type choice." << std::endl;
            return;
        }
    
    }
    DWORD dataSize = 0;

    HKEY hParentKey;
    if (RegOpenKeyExA(pKey, parentKeyPath, 0, KEY_WRITE, &hParentKey) == ERROR_SUCCESS) {
        // Set the registry value based on its data type
        LONG setResult;
        DWORD dwordValue;

        switch (dataType) 
        {
        case REG_SZ:
            dataSize = static_cast<DWORD>(newValue.length() + 1);
            setResult = RegSetValueExA(hParentKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(newValue.c_str()), dataSize);
            break;
        case REG_DWORD:
            dataSize = sizeof(DWORD);
            dwordValue = std::stoi(newValue);
            setResult = RegSetValueExA(hParentKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(&dwordValue), dataSize);
            break;
        case REG_MULTI_SZ:
            dataSize = static_cast<DWORD>(newValue.length() + 2);
            setResult = RegSetValueExA(hParentKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(newValue.c_str()), dataSize);
            break;
        default:
            std::cerr << "Unsupported registry value data type." << std::endl;
            break;
        }

        if (setResult == ERROR_SUCCESS) {
            std::cout << "Registry value created/modified successfully." << std::endl;
        }
        else {
            std::cerr << "Error creating/modifying registry value. Error code: " << setResult << std::endl;
        }

        RegCloseKey(hParentKey);
    }
    else {
        std::cerr << "Error opening parent registry key. Make sure it exists." << std::endl;
    }
}

void RegistryOp::ReadSubKeyValue(HKEY pKey , const char* keyPath , const char* valueName )
{
    
    if (keyPath == nullptr)
    {

        DWORD primaryKeyChoice;
        std::cout << "Choose a primary key:" << std::endl;
        std::cout << "1. HKEY_CLASSES_ROOT" << std::endl;
        std::cout << "2. HKEY_CURRENT_CONFIG" << std::endl;
        std::cout << "3. HKEY_CURRENT_USER" << std::endl;
        std::cout << "4. HKEY_LOCAL_MACHINE" << std::endl;
        std::cout << "5. HKEY_USERS" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> primaryKeyChoice;

        switch (primaryKeyChoice) 
        {
        case 1:
            pKey = HKEY_CLASSES_ROOT;
            break;
        case 2:
            pKey = HKEY_CURRENT_CONFIG;
            break;
        case 3:
            pKey = HKEY_CURRENT_USER;
            break;
        case 4:
            pKey = HKEY_LOCAL_MACHINE;
            break;
        case 5:
            pKey = HKEY_USERS;
            break;
        default:
            std::cerr << "Invalid primary key choice." << std::endl;
            return ;
        }

        char tempPath[256];
        std::cout << "Enter your SubKey path (use \\\\ ): ";
        //std::cin >> tempPath;
        std::cin.ignore();
        std::cin.getline(tempPath, sizeof(tempPath));
        keyPath = tempPath;

        char tempValue[256];
        std::cout << "Enter your Value name: ";
        //std::cin>> tempValue;
        std::cin.ignore();
        std::cin.getline(tempValue, sizeof(tempValue));
        valueName = tempValue;
    }

    HKEY hKey;
    if (RegOpenKeyExA(pKey, keyPath, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        DWORD dataType;
        DWORD dataSize = 0;

        if (SUCCEEDED(RegQueryValueExA(hKey, valueName, nullptr, &dataType, nullptr, &dataSize))) 
        {
            if (dataType == REG_SZ)
            {
                char* buffer = new char[dataSize];

                if (SUCCEEDED(RegQueryValueExA(hKey, valueName, nullptr, nullptr, reinterpret_cast<LPBYTE>(buffer), &dataSize)))
                {
                    std::cout << "Registry value (REG_SZ) read successfully: " << buffer << std::endl;
                }
                else
                {
                    std::cerr << "Error reading registry value." << std::endl;
                }

                delete[] buffer;
            }
            else if (dataType == REG_DWORD)
            {
                DWORD dwordValue;
                if (SUCCEEDED(RegQueryValueExA(hKey, valueName, nullptr, nullptr, reinterpret_cast<LPBYTE>(&dwordValue), &dataSize)))
                {
                    std::cout << "Registry value (REG_DWORD) read successfully: " << dwordValue << std::endl;
                }
                else 
                {
                    std::cerr << "Error reading registry value." << std::endl;
                }
            }
            else if (dataType == REG_MULTI_SZ) 
            {
                char* buffer = new char[dataSize];
                if (SUCCEEDED(RegQueryValueExA(hKey, valueName, nullptr, nullptr, reinterpret_cast<LPBYTE>(buffer), &dataSize)))
                {
                    std::cout << "Registry value (REG_MULTI_SZ) read successfully: " << buffer << std::endl;
                }
                else
                {
                    std::cerr << "Error reading registry value." << std::endl;
                }
                delete[] buffer;
            }
            else if (dataType == REG_BINARY)
            {
                BYTE* binaryBuffer = new BYTE[dataSize];
                if (SUCCEEDED(RegQueryValueExA(hKey, valueName, nullptr, nullptr, binaryBuffer, &dataSize)))
                {
                    std::cout << "Registry value (REG_BINARY) read successfully." << std::endl;
                }
                else
                {
                    std::cerr << "Error reading registry value." << std::endl;
                }
                delete[] binaryBuffer;
            }
            else
            {
                std::cerr << "Registry value is of an unsupported data type." << std::endl;
            }
        }
        else
        {
            std::cerr << "Error getting registry value data size." << std::endl;
        }

        RegCloseKey(hKey);
    }
    else
    {
        std::cerr << "Error opening registry key." << std::endl;
    }
}

void RegistryOp::ModifySubKeyValue(HKEY pKey, const char* keyPath , const char* valueName , std::string newValue, DWORD dataType)
{
    DWORD dataSize = 0;
    if (keyPath == nullptr)
    {

        DWORD primaryKeyChoice;
        std::cout << "Choose a primary key:" << std::endl;
        std::cout << "1. HKEY_CLASSES_ROOT" << std::endl;
        std::cout << "2. HKEY_CURRENT_CONFIG" << std::endl;
        std::cout << "3. HKEY_CURRENT_USER" << std::endl;
        std::cout << "4. HKEY_LOCAL_MACHINE" << std::endl;
        std::cout << "5. HKEY_USERS" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> primaryKeyChoice;

        switch (primaryKeyChoice) {
        case 1:
            pKey = HKEY_CLASSES_ROOT;
            break;
        case 2:
            pKey = HKEY_CURRENT_CONFIG;
            break;
        case 3:
            pKey = HKEY_CURRENT_USER;
            break;
        case 4:
            pKey = HKEY_LOCAL_MACHINE;
            break;
        case 5:
            pKey = HKEY_USERS;
            break;
        default:
            std::cerr << "Invalid primary key choice." << std::endl;
            return ;
        }

        char tempPath[256];
        std::cout << "Enter your SubKey path (use \\\\ ): ";
        //std::cin >> tempPath;
        std::cin.ignore();
        std::cin.getline(tempPath, sizeof(tempPath));
        const char* keyPath = tempPath;

        char tempValue[256];
        std::cout << "Enter your Value name: ";
        std::cin.ignore();
        std::cin.getline(tempValue, sizeof(tempValue));
        const char* valueName = tempValue;

    
   

        // Prompt for the new value and data type
        std::string newValue;
        std::cout << "Enter the new value: ";
        //std::cin >> newValue;
        std::cin.ignore();
        std::getline(std::cin, newValue);

        // Determine the data type based on user input
        std::cout << "Enter the data type (1 for REG_SZ, 2 for REG_DWORD, 3 for REG_MULTI_SZ): ";
        int typeChoice;
        std::cin >> typeChoice;

        switch (typeChoice) {
        case 1:
            dataType = REG_SZ;
            dataSize = static_cast<DWORD>(newValue.length() + 1); // Include null terminator
            break;
        case 2:
            dataType = REG_DWORD;
            dataSize = sizeof(DWORD);
            break;
        case 3:
            dataType = REG_MULTI_SZ;
            dataSize = static_cast<DWORD>(newValue.length() + 2); // Include double null terminator
            break;
        default:
            std::cerr << "Invalid data type choice." << std::endl;
            return;
        }
    }

    HKEY hKey;
    if (RegOpenKeyExA(pKey, keyPath, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        LONG result = ERROR_SUCCESS;
        DWORD dwordValue;

        // Modify the registry value based on its data type
        switch (dataType) {
        case REG_SZ:
            dataSize = static_cast<DWORD>(newValue.length() + 1);
            result = RegSetValueExA(hKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(newValue.c_str()), dataSize);
            break;
        case REG_DWORD:
            dataSize = sizeof(DWORD);
            dwordValue = std::stoi(newValue);
            result = RegSetValueExA(hKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(&dwordValue), dataSize);
            break;
        case REG_MULTI_SZ:
            dataSize = static_cast<DWORD>(newValue.length() + 2);
            result = RegSetValueExA(hKey, valueName, 0, dataType, reinterpret_cast<const BYTE*>(newValue.c_str()), dataSize);
            break;
        default:
            std::cerr << "Unsupported registry value data type." << std::endl;
            break;
        }

        if (result == ERROR_SUCCESS) {
            std::cout << "Registry value modified successfully." << std::endl;
        }
        else {
            std::cerr << "Error modifying registry value. Error code: " << result << std::endl;
        }

        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Error opening registry key." << std::endl;
    }
}
