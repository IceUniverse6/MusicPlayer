#include "PlayList.h"

PlayList::PlayList() {

}
PlayList::PlayList(std::string play_list_name) {
	this->play_list_name = play_list_name;
}
PlayList::~PlayList() {

}

void PlayList::set_play_list_name(std::string play_list_name) {
	this->play_list_name = play_list_name;
}
void PlayList::add_music(std::shared_ptr<Music> music) {
	this->music_list.push_back(music);
}
void PlayList::remove_music(int index) {
	this->music_list.erase(this->music_list.begin() + index);
}

std::string PlayList::get_play_list_name()const {
	return this->play_list_name;
}
int PlayList::get_number_of_songs()const {
	return this->music_list.size();
}
std::vector<std::shared_ptr<Music>> PlayList::get_all_songs()const {
	return this->music_list;
}

void PlayList::show_songs()const {
	for (size_t i = 0; i < this->music_list.size(); i++) {
		std::cout << this->music_list.at(i)->get_music_name() << std::endl;
		std::cout << this->music_list.at(i)->get_artist_name() << std::endl;
		std::cout << this->music_list.at(i)->get_genre() << std::endl;
		std::cout << this->music_list.at(i)->get_release_year() << std::endl;
	}
}
void PlayList::show_play_list_info()const {
	std::cout << "play list name: " << this->play_list_name << std::endl;
	std::cout << "number of songs: " << this->get_number_of_songs() << std::endl;
}