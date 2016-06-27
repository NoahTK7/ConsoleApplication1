// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleApplication1.h"

using namespace std;

int main()
{
	char confirm[4];

	do {
		char str_name[256];

		cout << "Please enter your name: ";
		cin.getline(str_name, 256, '\n');

		cout << "The name you entered was: " << str_name << endl;

		
		cout << "Is this correct? (y/n): ";
		cin.getline(confirm, 4, '\n');

		if (strcmp(confirm, "y") == 0)
		{
			//Get current sytem time
			time_t now = time(0);
			char timestamp[256];
			ctime_s(timestamp, 256, &now);

			char logMessage[512];
			logMessage[0] = '\0';
			strcat_s(logMessage, str_name);
			strcat_s(logMessage, " -- ");
			strcat_s(logMessage, timestamp);

			//Log name to file
			ofstream file_log("log.txt", ios::app);

			file_log << logMessage << "\n";

			cout << "Name successfully logged to file!" << endl;
		}

	} while (strcmp(confirm, "n") == 0);

	system("pause");

}