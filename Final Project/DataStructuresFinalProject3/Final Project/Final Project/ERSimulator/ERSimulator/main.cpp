// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hospital.h"
#include "WaitingRoomQueue.h"
#include "TreatmentQueue.h"
#include "Resident.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
int main()
{
	srand(time(NULL));
	// Prompt user to enter required data values
	int docs, nurses, days;
	double hourlypatients;
	cout << "Welcome to the Simville Hopsital Simulator!" << endl << "Enter the average number of patients admitted to the hospital per hour: ";
	cin >> hourlypatients;
	cout << endl << "Enter the number of doctors working in the Emergency room: ";
	cin >> docs;
	cout << endl << "Enter the number of nurses working in the emergency room: ";
	cin >> nurses;
	cout << endl;
	cout << "Enter the number of days the hospital will be running: ";
	cin >> days;
	cout << endl;

	// create hospital passing in user input
	Hospital H1(docs, nurses, days);
	WaitingRoomQueue W1(hourlypatients);
	H1.addQueues(W1);
	
	for (int i = 0; i < docs; i++)
	{
		DoctorQueue * DocQ = new DoctorQueue;
		H1.addQueuePtr(DocQ);
	}
	for (int i = 0; i < nurses; i++)
	{
		NurseQueue * NurseQ = new NurseQueue;
		H1.addQueuePtr(NurseQ);
	}




	// check if file with resident names opens correctly
	std::string netfile = "\\\\cs1\\2020\\iblack20\\CS-273-1\\HOMEWORK_AND_PROJECTS\\Final Project\\ERSimulator\\ERSimulator\\residents.txt";
	std::ifstream fin(netfile);
	if (fin.fail()) {
		cout << "Cannot open file." << endl;
		return 0;
	}

	// loop fills vector "Residents" with Resident objects, getting their names from file containing list of names
	std::string word;
	while (fin >> word)
	{
		Resident * R1 = new Resident(word);
		W1.addResident(R1);
	}
	fin.close(); 
	


	H1.Simulate();
	W1.DisplayNames();
	











    return 0;
}

