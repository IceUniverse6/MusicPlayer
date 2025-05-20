#pragma once
#include<string>
class Music
{
private:
	std::string music_name;
	std::string artist_name;
	int release_year;
	std::string genre;
public:
	Music();
	Music(std::string, std::string, int, std::string);
	~Music();
	void set_music_name(std::string);
	void set_artist_name(std::string);
	void set_release_year(int);
	void set_genre(std::string);

	std::string get_music_name()const;
	std::string get_artist_name()const;
	int get_release_year()const;
	std::string get_genre()const;
};

