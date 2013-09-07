#include <gba.h>

#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

#include "Console.h"

#define SOUND3OUTPUT0		0x0000	// Mute output
#define SOUND3OUTPUT1		0x2000	// Output unmodified
#define SOUND3OUTPUT12		0x4000	// Output 1/2 
#define SOUND3OUTPUT14		0x6000	// Output 1/4 
#define SOUND3OUTPUT34		0x8000  // Output 3/4

#define SOUND3BANK32		0x0000	// Use two banks of 32 steps each

#define SOUND3SETBANK0		0x0000	// Bank to play 0 or 1 (non set bank is written to)
#define SOUND3SETBANK1		0x0040
#define SOUND3PLAY			0x0080	// Output sound


#define REG_WAVE_RAM0  *(vu32*)0x4000090		//???
#define REG_WAVE_RAM1  *(vu32*)0x4000094		//???
#define REG_WAVE_RAM2  *(vu32*)0x4000098		//???
#define REG_WAVE_RAM3  *(vu32*)0x400009C	


#define SOUND3INIT		0x8000	// Makes the sound restart
#define SOUND3PLAYONCE		0x4000	// Play sound once
#define SOUND3PLAYLOOP		0x0000	// Play sound looped

class  A
{
public:
  A();
  int a;
};

A::A()
{}

void init_audio_and_play()
{
  REG_SOUNDCNT_X = 0x80;
  //full volume, enable sound 1 to left and right
  REG_SOUNDCNT_L=0x1177;
  // Overall output ratio - Full
  REG_SOUNDCNT_H = 2;

  REG_SOUND1CNT_L=0x0056; //sweep shifts=6, increment, sweep time=39.1ms
  REG_SOUND1CNT_H=0xf780; //duty=50%,envelope decrement
  REG_SOUND1CNT_X=0x8205; //frequency=0x0400, loop mode


}

int main(void) 
{

  int a;
  int i;
  int j;

  A ca;
  ca.a=1;

  irqInit();
  irqEnable(IRQ_VBLANK);
  consoleDemoInit();

  iprintf("\x1b[00;00H012345678901234567890123456789");
  for (i=0; i<1000;i++)
    {
      for (j=0;j<65535;j++)
	{}
      iprintf("\x1b[10;05HHello World! %d %d",i,j);      
    }
}


