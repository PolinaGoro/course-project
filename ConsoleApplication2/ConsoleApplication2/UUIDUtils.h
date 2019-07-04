#pragma once
#include <string>
#pragma comment(lib, "rpcrt4.lib")
#include <windows.h>

using namespace std;

class UUIDUtils
{
public:
	static string generateUUID() {
		UUID uuid;
		UuidCreate(&uuid);
		char *result;
		UuidToStringA(&uuid, (RPC_CSTR*)&result);
		return result;
	}
};

