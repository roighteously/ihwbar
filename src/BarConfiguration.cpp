#include <windows.h>
#include "include/BarConfiguration.hpp"
#include "include/Global.hpp"
#include <iostream>

int GetConfigInt(const char* key, int default_value)
{
	if (debug)std::cout << "[CONFIG] Getting " << key << ":int from " << CONFIG_FILE << "\n";
	return GetPrivateProfileInt(GENERAL_SECTION, key, default_value, CONFIG_FILE);
}

int GetConfigColor(const char* key, int default_value)
{
	if (debug)std::cout << "[CONFIG] Getting " << key << ":col from " << CONFIG_FILE << "\n";
	return GetPrivateProfileInt("Color", key, default_value, CONFIG_FILE);
}

const char* GetConfigString(const char* key, const char* default_value)
{
	if (debug)std::cout << "[CONFIG] Getting " << key << ":str from " << CONFIG_FILE << "\n";
	static char buffer[256];
	GetPrivateProfileString(GENERAL_SECTION, key, default_value, buffer, 256, CONFIG_FILE);
	return buffer;
}

BOOL WriteConfigInt(const char* key, int value)
{
	char buffer[10];
	itoa(value, buffer, 10);
	return WritePrivateProfileString(GENERAL_SECTION, key, buffer, CONFIG_FILE);
}

BOOL WriteConfigColor(const char* key, int value)
{
	char buffer[10];
	itoa(value, buffer, 10);
	return WritePrivateProfileString("Color", key, buffer, CONFIG_FILE);
}

BOOL WriteConfigString(const char* key, const char* value)
{
	return WritePrivateProfileString(GENERAL_SECTION, key, value, CONFIG_FILE);
}