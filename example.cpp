
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "wavfile.h"

void PlayAudioTone(int hz,int msDuration)
{
	if(msDuration == -1)
	{
		PlaySound(NULL,0,0);
	}
	int NUM_SAMPLES = ceil(msDuration*WAVFILE_SAMPLES_PER_SECOND/1000);//it can play max 10 sec tone
	short waveform[WAVFILE_SAMPLES_PER_SECOND*10];//it can play max 10 sec tone
	int frequency = hz;
	int volume= 32000;
	int length = NUM_SAMPLES;
	for(int i=0;i<length;i++)
	{
		double t = (double)i/WAVFILE_SAMPLES_PER_SECOND;
		waveform[i]=volume*sin(frequency*t*2*3.1415926535);
	}
	FILE* f= wavfile_open("sound.wav");
	if(!f)
	{
		return;
	}
	wavfile_write(f,waveform,length);
	PlaySound(L"sound.wav",NULL,SND_ASYNC);
	wavfile_close(f);

}



/*  Example Usage
	PlayAudioTone(4000,10000);
	Sleep(2000);
	PlayAudioTone(4000,-1);
	Sleep(2000);
	PlayAudioTone(15000,5000)*/

