#include "Audio.h"

Audio::Audio()
{
	this->artist = "Unknown artist";
	this->songName = "Unknown song";
}
Audio::Audio(std::string artist, std::string songName, unsigned int songYear, double size) : File(artist + "-" + songName, (rand() % 100 + 1) <= 50 ? ".mp3" : ".flac", size, AUDIO)
{
	this->artist = artist;
	this->songName = songName;
	this->songYear = songYear;
}
Audio::Audio(std::string artist, std::string songName, unsigned int songYear, std::string extension, double size) : File(artist + "-" + songName, extension, size, AUDIO)
{
	this->artist = artist;
	this->songName = songName;
	this->songYear = songYear;
}
Audio::Audio(const Audio& other) : File(other)
{
	*this = other;
}
Audio& Audio::operator=(const Audio& other)
{
	if (this != &other)
	{
		File::operator=(other);
		this->artist = other.artist;
		this->songName = other.songName;
		this->songYear = other.songYear;
	}
	return *this;
}

std::string Audio::get_artist() const
{
	return this->artist;
}
std::string Audio::get_songName() const
{
	return this->songName;
}
unsigned int Audio::get_songYear() const
{
	return this->songYear;
}

void Audio::print() const
{
	File::print();
	std::cout << "Artist: " << this->artist << std::endl;
	std::cout << "Song: " << this->songName << std::endl;
	std::cout << "Year: " << this->songYear << std::endl << std::endl;
}