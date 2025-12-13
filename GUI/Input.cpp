//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	string input;
	char x;
	while (1)
	{
		pWind->WaitKeyPress(x);
		if (x == 27)	//ESCAPE
		{
			pOut->ClearStatusBar();
			return "";
		}
		if (x == 13)	//ENTER
		{
			pOut->ClearStatusBar();

			return input;
		}
		if ((x == 8) && (input.size() >= 1))	//BackSpace
			input.pop_back();
		else
			input += x;
		if (pOut)
			pOut->PrintMsg(input);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_NOT2: return ADD_INV;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_BUFFER2: return ADD_Buff;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_CONNECTION: return ADD_CONNECTION;
			case ITM_SIM_MODE: return SIM_MODE;
			case ITM_LABEL: return ADD_Label;
			case ITM_EDIT_LABEL: return EDIT_Label;
			case ITM_MOVE: return MOVE;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_VALIDATE: return VALIDATE;
			case ITM_SIM: return Change_Switch;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_PROBE: return PROBE;
			case ITM_DSN_MODE: return DSN_MODE;
			case ITM_EXIT2: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in simulation toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}

}


Input::~Input()
{
}
