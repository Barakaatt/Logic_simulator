#include "Simulate.h"
#include "ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp)
    : Action(pApp)
{
}

void Simulate::Execute()
{
   for (int i = 0; i < pManager->GetCompCount(); i++)
   {
       Component* comp = pManager->GetComponentAt(i);
       if (comp)
       {
           comp->Operate();
       }
	   pM->UpdateInterface();
   }

}
