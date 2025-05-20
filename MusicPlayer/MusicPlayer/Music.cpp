#include "Music.h"

Music::Music() {

}
Music::Music(std::string music_name, std::string artist_name, int release_year, std::string genre) {
	this->music_name = music_name;
	this->artist_name = artist_name;
	this->release_year = release_year;
	this->genre = genre;
}
Music::~Music() {

}
void Music::set_music_name(std::string music_name) {
	this->music_name = music_name;
}
void Music::set_artist_name(std::string artist_name) {
	this->artist_name = artist_name;
}
void Music::set_release_year(int release_year) {
	this->release_year = release_year;
}
void Music::set_genre(std::string genre) {
	this->genre = genre;
}

std::string Music::get_music_name()const {
	return this->music_name;
}
std::string Music::get_artist_name()const {
	return this->artist_name;
}
int Music::get_release_year()const {
	return this->release_year;
}
std::string Music::get_genre()const {
	return this->genre;
}