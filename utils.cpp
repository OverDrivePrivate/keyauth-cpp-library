#include "utils.hpp"
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include<conio.h>
#include <atlsecurity.h> 
#include <string>

std::string GetProcessorId() {
	std::array<int, 4> cpuInfo;
	__cpuid(cpuInfo.data(), 1);
	std::ostringstream buffer;
	buffer
		<< std::uppercase << std::hex << std::setfill('0')
		<< std::setw(8) << cpuInfo.at(3)
		<< std::setw(8) << cpuInfo.at(0);
	return buffer.str();
}

std::string utils::get_hwid() {
	ATL::CAccessToken accessToken;
	ATL::CSid currentUserSid;
	std::string thingie = GetProcessorId();
	if (!thingie.empty())
		return thingie;
	/*if (accessToken.GetProcessToken(TOKEN_READ | TOKEN_QUERY) &&
		accessToken.GetUser(&currentUserSid))
		return std::string(CT2A(currentUserSid.Sid()));*/
	return "none";
}

std::time_t utils::string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10);

	return (time_t)cv;
}

std::tm utils::timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
