#pragma once
#include <string>

class SongInfo
{
	private:
		std::string song_name;
		int year_created;
		double song_length;

	public:
		SongInfo(std::string = "Unknown", int = 0, double = 0);
		
		void printSong();

		double getTime() { return song_length; }
};

