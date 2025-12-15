
#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	

	}while(ActType != EXIT);

	cout << "Program exiting normally\n";

		
	return 0;
}

