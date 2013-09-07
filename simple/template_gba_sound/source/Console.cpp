using namespace std;
#include "Console.h"

Console::Console()
{

}

void Console::init()
{
  irqInit();
  irqEnable(IRQ_VBLANK);  
  consoleDemoInit();
}


