#include"Admin.h"

Admin::Admin(std::string user_name, std::string password)
	:BaseUser(user_name, password) {}
Admin::~Admin() {

}

void Admin::add_song() {
	// get song datas
	std::shared_ptr<Music> new_song = std::make_shared<Music>(/*song datas*/);
	// add this to data base
	this->added_songs.push_back(new_song);
}
void Admin::remove_song() {
	int index;

	for (size_t i = 0; i < this->added_songs.size(); i++) {
		// show songs
	}
	std::cout << "enter song that you want to delete, else enter 0 to return: ";
	std::cin >> index;
	if (index == 0) {
		return;
	}
	else {
		// first delete that for every one who has taken it, then...
		this->added_songs.erase(this->added_songs.begin() + index - 1);
		// then delete it from database
	}
}

void Admin::add_play_list() {
	std::string name;
	std::cout << "please enter play list name: ";
	std::getline(std::cin, name);
	std::shared_ptr<PlayList> new_play_list = std::make_shared<PlayList>(name);

	this->added_play_lists.push_back(new_play_list);
}
void Admin::remove_play_list() {
	int index;

	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		// show songs
	}
	std::cout << "please enter song that you want to delete: ";
	std::cin >> index;
	std::cin.ignore();

	// remove it for everyone that has taken it
	// remove it from data base
	this->added_play_lists.erase(this->added_play_lists.begin() + index - 1);
	
}

void Admin::add_song_to_play_list(std::shared_ptr<Music> song) {
	int index;
	// show play lists
	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		//
	}
	std::cout << "please enter play list that you want to add song to: ";
	std::cin >> index;
	std::cin.ignore();

	//this->added_play_lists.at(index - 1)->add_music(song);
}
void Admin::remove_song_from_play_list() {
	int index1, index2;
	// with search
	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		// show play lists
	}
	std::cout << "please enter play list number: ";
	std::cin >> index1;
	std::cin.ignore();

	for (size_t i = 0; i < this->added_play_lists.at(index1 - 1)->get_number_of_songs(); i++) {
		// sshow songs;
	}
	std::cout << "enter song that you want to delete: ";
	std::cin >> index2;
	std::cin.ignore();

	this->added_play_lists.at(index1 - 1)->remove_music(index2);
}

void Admin::add_artist_page() {
	// get artist data
	std::shared_ptr<Artist> new_artist = std::make_shared<Artist>();
	// add to data base
	this->added_artists.push_back(new_artist);

	std::cout << "do you want to add song or play list for this artist?: ";
	// get decision
}
void Admin::remove_artist_page() {
	int index;
	// with search

	for (size_t i = 0; i < this->added_artists.size(); i++) {
		// show artists
	}
	std::cout << "please enter artist that you want to delete: ";
	std::cin >> index;
	std::cin.ignore();

	// remove from data base
	this->added_artists.erase(this->added_artists.begin() + index - 1);

}

void Admin::add_song_for_artist() {
	// find artist
	int index, command;
	std::cout << "new song or existing one?: ";
	std::cin >> command;
	// ask if do you want to add it to one of artusi playlists
	if (command == 1) {
		std::shared_ptr<Music> new_music = std::make_shared<Music>(/*song datas*/);
		// add it to artist songs and admin added si=ongs and sata base
	}
	else if (command == 2) {
		// show all songs
		//choose song
		//check if artist names are the same
		//add it
	}
}
void Admin::remove_song_for_artist() {
	// find artist
	// show its songs
	// choosesong and delete it
}

void Admin::add_play_list_for_artist() {
	int command;
	std::cout << "new play list or existing one?:";

	// its like adding songs

}
void Admin::remove_play_list_for_artist() {
	// find artist
	// choose play list
	// delete it
}

void Admin::show_added_songs()const {
	for (size_t i = 0; i < this->added_songs.size(); i++) {
		// show song info
	}
}
void Admin::show_play_lists()const {
	for (size_t i = 0; i < this->added_songs.size(); i++) {
		// show playlist info
	}
}
void Admin::show_added_artists()const {
	for (size_t i = 0; i < this->added_songs.size(); i++) {
		// show artist info
	}
}