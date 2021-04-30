#pragma once

#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#include <Digitalv.h>;

MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;
#define BGM "C:\\BGM.mp3" //BGM 경로 지정
#define SHUFFLE "C:\\shuffle.mp3" //효과음 경로 지정

/*
bool IsBGPlaying = false;
bool IsEffectPlaying = false;

System*	pSystem;
Sound* pSound[3];
Channel* pChannel[3];
*/
void Sound_Init()
{
}

void Sound_PlayIngameBGM()
{
	/**
	System_Create(&pSystem);
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	pSystem->createSound("ingame.mp3", FMOD_LOOP_NORMAL | FMOD_HARDWARE, NULL, &pSound[0]);

	pChannel[0]->isPlaying(&IsBGPlaying);

	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[0], false, &pChannel[0]);
	*/
}

void Sound_PlayShootEffect()
{
	/*
	System_Create(&pSystem);
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);
	
	pSystem->createSound("shoot.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[1]);

	pChannel[1]->isPlaying(&IsEffectPlaying);

	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1]);
	*/
}
void Sound_PlayDethEffect()
{
	/*
	System_Create(&pSystem);
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	pSystem->createSound("death.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[2]);

	pChannel[0]->stop();
	pChannel[1]->stop();

	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[0]);
	*/
}
