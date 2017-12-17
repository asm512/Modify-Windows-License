// WindowsLicense.cpp : main project file.

#using <Microsoft.VisualBasic.dll>

#include "stdafx.h" 

using namespace System;
using namespace Microsoft::Win32;
using namespace Microsoft::VisualBasic;

void LaunchWinVer() {
	System::Diagnostics::Process::Start("C:\\Windows\\System32\\winver.exe");
}

void ChangeOwnerName() {
	RegistryKey ^ rk = Registry::LocalMachine->OpenSubKey(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", true);
	Console::WriteLine("Current value : {0}", rk->GetValue(L"RegisteredOwner"));
	Console::WriteLine("Enter desired name for Registered Owner");
	rk->SetValue(L"RegisteredOwner", Console::ReadLine());
	Console::WriteLine(L"Windows Registered Owner changed to  {0}", rk->GetValue(L"RegisteredOwner"));
	rk->Close();
	LaunchWinVer();
}

void ChangeOrganisationName() {
	RegistryKey ^ rk = Registry::LocalMachine->OpenSubKey(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", true);
	Console::WriteLine("Current value : {0}", rk->GetValue(L"RegisteredOrganization"));
	Console::WriteLine("Enter desired name for Registered Owner");
	rk->SetValue(L"RegisteredOrganization", Console::ReadLine());
	Console::WriteLine(L"Windows Registered Owner changed to  {0}", rk->GetValue(L"RegisteredOrganization"));
	rk->Close();
	LaunchWinVer();
}

void DisplayMenu() {
	Console::WriteLine("");
	Console::WriteLine(L"Enter 1 to change OwnerName		Enter 2 to change OrganisationName");
	String^ selection = Console::ReadLine();
	if (selection == "1") {
		ChangeOwnerName();
	}
	else if (selection == "2") {
		ChangeOrganisationName();
	}
}

int main(array<System::String ^> ^args)
{
	Console::WriteLine(L"Loading Registry Wizard..."); //Implement admin checks here
	while (true) {
		DisplayMenu();
	}
	Console::ReadLine();
	return 0;
}