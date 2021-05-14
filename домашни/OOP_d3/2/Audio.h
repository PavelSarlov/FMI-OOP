#pragma once

#ifndef AUDIO_H
#define AUDIO_H

#include "File.h"

class Audio : public File
{
public:
	Audio();
	Audio(std::string artist, std::string songName, unsigned int songYear, double size);
	Audio(std::string artist, std::string songName, unsigned int songYear, std::string extension, double size);
	Audio(const Audio& other);
	Audio& operator=(const Audio& other);

	std::string get_artist() const;
	std::string get_songName() const;
	unsigned int get_songYear() const;

	virtual void print() const;

private:
	std::string artist;
	std::string songName;
	unsigned int songYear = 0;
};

#endif