#include "SongInfo.h"
#include <iomanip>
#include <iostream>


//default constructor/3-var constructor/2-var constructor
//default values: name = "Unknown", year = 0, time = 0
SongInfo::SongInfo(std::string name, int year, double time) {
	song_name = name;

	if (year < 0) year_created = 0;
	else year_created = year;

	if (time < 0) song_length = 0;
	else song_length = time;
}

void SongInfo::printSong() {
	//print song name
	std::cout << std::left << "song-"
		<< std::setw(28) << song_name;

	//if both the song length and recording year are known,
	if ((song_length > 0) && (year_created > 0)) {
		std::cout << ": recorded in year " << year_created << ":\n"
			<< "length- " << std::fixed << std::setprecision(2) << song_length << " minutes";
	}

	//if only the song length is known,
	else if (song_length > 0) {
		std::cout<< ": length- " << std::fixed << std::setprecision(2) << song_length << " minutes";
	}

	//if only the recording year is know,
	else if (year_created > 0) {
		std::cout << ": recorded in year " << year_created;
	}

	std::cout << std::endl;	
}