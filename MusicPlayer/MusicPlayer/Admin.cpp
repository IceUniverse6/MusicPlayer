#include"Admin.h"

Admin::Admin(std::string user_name, std::string password)
	:BaseUser(user_name, password) {}
Admin::~Admin() {

}

void Admin::add_song() {
	std::string music_name, artist_name, genre;
	int release_year;

	std::cout << "music name: ";
	std::getline(std::cin, music_name);
	std::cout << "artist name: ";
	std::getline(std::cin, artist_name);
	std::cout << "release year: ";
	std::cin >> release_year;
	std::cin.ignore();
	std::cout << "genre: ";
	std::getline(std::cin, genre);
	std::shared_ptr<Music> new_song = std::make_shared<Music>(music_name, artist_name, release_year, genre);


	// add this to data base
	this->added_songs.push_back(new_song);
}
void Admin::remove_song() {
	int index;

	for (size_t i = 0; i < this->added_songs.size(); i++) {
		std::cout << i + 1 << ") ";
		//this->added_songs.at(i)->show_song_info();
	}

	while (true) {
		std::cout << "enter song that you want to delete, else enter 0 to return: ";
		std::cin >> index;
		std::cin.ignore();

		if ((index >= 1) && (index <= this->added_songs.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

	if (index == 0) {
		return;
	}
	else {
		// first delete that for every one who has taken it, then...
		// then delete it from database
		this->added_songs.erase(this->added_songs.begin() + index - 1);
		
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
		std::cout << i + 1 << ") ";
		this->added_play_lists.at(i)->show_play_list_info();
	}

	while (true) {
		std::cout << "please enter song that you want to delete: ";
		std::cin >> index;
		std::cin.ignore();

		if ((index >= 1) && (index <= this->added_play_lists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

	// remove it for everyone that has taken it
	// remove it from data base
	this->added_play_lists.erase(this->added_play_lists.begin() + index - 1);
	
}

void Admin::add_song_to_play_list(std::shared_ptr<Music> song) {
	int index;

	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_play_lists.at(i)->show_play_list_info();
	}

	while (true) {
		std::cout << "please enter play list that you want to add song to: ";
		std::cin >> index;
		std::cin.ignore();

		if ((index >= 1) && (index <= this->added_play_lists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

	this->added_play_lists.at(index - 1)->add_music(song);
}
void Admin::remove_song_from_play_list() {
	int index1, index2;
	// with search
	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_play_lists.at(i)->show_play_list_info();
	}

	while (true) {
		std::cout << "please enter play list number: ";
		std::cin >> index1;
		std::cin.ignore();

		if ((index1 >= 1) && (index1 <= this->added_play_lists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

	for (size_t i = 0; i < this->added_play_lists.at(index1 - 1)->get_number_of_songs(); i++) {
		// add index
		this->added_play_lists.at(index1 - 1)->show_songs();
	}

	while (true) {
		std::cout << "enter song that you want to delete: ";
		std::cin >> index2;
		std::cin.ignore();

		if ((index2 >= 1) && (index2 <= this->added_play_lists.at(index1 - 1)->get_number_of_songs())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

	this->added_play_lists.at(index1 - 1)->remove_music(index2 - 1);
}

void Admin::add_artist_page() {
	std::string artist_name;
	int number_of_albums, number_of_released_songs;
	int decision;

	std::cout << "artist name: ";
	std::getline(std::cin, artist_name);
	std::cout << "number of albums: ";
	std::cin >> number_of_albums;
	std::cin.ignore();
	std::cout << "number of released songs: ";
	std::cin >> number_of_released_songs;
	std::cin.ignore();
	std::shared_ptr<Artist> new_artist = std::make_shared<Artist>(artist_name, number_of_albums, number_of_released_songs);
	// add to data base
	this->added_artists.push_back(new_artist);

	while (true) {
		std::cout << "do you want to add song(1) or play list(2) for this artist? (if no, enter 0 to return): ";
		std::cin >> decision;
		std::cin.ignore();

		if ((decision == 0) || (decision == 1) || (decision == 2)) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (decision == 0) {
		return;
	}
	else if (decision == 1) {
		this->add_song_for_artist(new_artist);
	}
	else if (decision == 2) {
		this->add_play_list_for_artist(new_artist);
	}

	
	
}
void Admin::remove_artist_page() {
	int index;
	// with search

	for (size_t i = 0; i < this->added_artists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_artists.at(i)->show_artist_info();
	}

	while (true) {
		std::cout << "please enter artist that you want to delete: ";
		std::cin >> index;
		std::cin.ignore();

		if ((index >= 1) && (index <= this->added_artists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	

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
void Admin::add_song_for_artist(std::shared_ptr<Artist> artist) {

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
void Admin::add_play_list_for_artist(std::shared_ptr<Artist> artist) {

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
	for (size_t i = 0; i < this->added_play_lists.size(); i++) {
		this->added_play_lists.at(i)->show_play_list_info();
	}
}
void Admin::show_added_artists()const {
	for (size_t i = 0; i < this->added_artists.size(); i++) {
		this->added_artists.at(i)->show_artist_info();
	}
}