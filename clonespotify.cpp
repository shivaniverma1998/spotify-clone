#include <iostream>
#include <string>
#include <vector>

struct Song {
    std::string title;
    std::string artist;
    std::string album;
    int duration; // in seconds
};

class Spotify {
private:
    std::vector<Song> playlist;
    int currentIndex;

public:
    Spotify() : currentIndex(0) {}

    void addSong(const Song& song) {
        playlist.push_back(song);
    }

    void play() {
        if (playlist.empty()) {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }

        std::cout << "Playing: " << playlist[currentIndex].title << " - " << playlist[currentIndex].artist << std::endl;
    }

    void next() {
        if (currentIndex == playlist.size() - 1) {
            std::cout << "End of playlist reached." << std::endl;
            return;
        }

        currentIndex++;
        std::cout << "Playing next song: " << playlist[currentIndex].title << " - " << playlist[currentIndex].artist << std::endl;
    }

    void previous() {
        if (currentIndex == 0) {
            std::cout << "This is the first song in the playlist." << std::endl;
            return;
        }

        currentIndex--;
        std::cout << "Playing previous song: " << playlist[currentIndex].title << " - " << playlist[currentIndex].artist << std::endl;
    }

    void displayPlaylist() const {
        std::cout << "Playlist:" << std::endl;
        for (const Song& song : playlist) {
            std::cout << "Title: " << song.title << ", Artist: " << song.artist << ", Album: " << song.album << ", Duration: " << song.duration << "s" << std::endl;
        }
    }
};

int main() {
    Spotify spotify;

    // Adding songs to the playlist
    Song song1{"Song 1", "Artist 1", "Album 1", 180};
    Song song2{"Song 2", "Artist 2", "Album 2", 240};
    Song song3{"Song 3", "Artist 3", "Album 3", 200};

    spotify.addSong(song1);
    spotify.addSong(song2);
    spotify.addSong(song3);

    // Displaying the playlist
    spotify.displayPlaylist();

    // Playing songs
    spotify.play();
    spotify.next();
    spotify.previous();

    return 0;
}
