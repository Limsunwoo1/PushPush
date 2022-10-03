#include "Sound.h"

void Sound::Lode()
{

}

void Sound::Play(bool loop)
{
	if (loop)
	{
		// 한번재생
		PlaySound(TEXT("..\\Sound\\SokoSong.wav"), 0, SND_FILENAME | SND_ASYNC);
	}
	else
	{
		// 루프재생
		PlaySound(TEXT("..\\Sound\\SokoSong.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}
