#include <iostream>
#include <string>

class DvdPlayer;
class Cdplayer
{
public:

};

class Amplifier
{
public:
    void on() {
        std::cout << "Top-O-Line Amplifier on\n";
    }
    void setDvd(DvdPlayer* dvd) {
        std::cout << "Top-O-Line Amplifier setting DVD player to Top-O-Line DVD player\n";
    }
    void setSurroundSound() {
        std::cout << "Top-O-Line Amplifier surround sound on (5 speakers, 1 subwoofer)\n";
    }
    void setVolume(int volume) {
        std::cout << "Top-O-Line Amplifier setting volume to " << volume << "\n";
    }
    void off() {
        std::cout << "Top-O-Line Amplifier off\n";
    }
};

class Tuner
{
public:

};

class DvdPlayer
{
public:
    void play(std::string movie) {
        std::cout << "Top-O-Line DVD Player playing " << movie << "\n";
    }
    void on() {
        std::cout << "Top-O-Line DVD Player on\n";
    }
    void off() {
        std::cout << "Top-O-Line DVD Player off\n";
    }
    void stop() {
        std::cout << "Top-O-Line DVD Player stop\n";
    }
    void eject() {
        std::cout << "Top-O-Line DVD Player eject\n";
    }
};

class Projector
{
public:
    void on() {
        std::cout << "Top-O-Line Projector on\n";
    }
    void wideScreenMode() {
        std::cout << "Top-O-Line Projector in widesceen mode (16x9 aspect ratio)\n";
    }
    void off() {
        std::cout << "Top-O-Line Projector off";
    }
};

class TheaterLights
{
public:
    void dim(int lhs) {
        std::cout << "Theater Ceiling Lights dimming to " << lhs << "%\n";
    }
    void on() {
        std::cout << "Theater Ceiling Lights on\n";
    }
};

class Screen
{
public:
    void down() {
        std::cout << "Theater Screen going down\n";
    }
    void up() {
        std::cout << "Theater Screen going up\n";
    }
};

class PopcornPopper
{
public:
    void on() {
        std::cout << "Popcorn Popper on\n";
    }
    void pop() {
        std::cout << "Popcorn Popper popping popcorn\n";
    }
    void off() {
        std::cout << "Popcorn Popper off\n";
    }
};

class HomeTheaterFacade
{
public:
    Amplifier* amp;
    Tuner* tuner;
    DvdPlayer* dvd;
    Cdplayer* cd;
    Projector* projector;
    TheaterLights* lights;
    Screen* screen;
    PopcornPopper* popper;
    
    HomeTheaterFacade(Amplifier* amp, Tuner* tuner, DvdPlayer* dvd, Cdplayer* cd, Projector* projector, Screen* screen, TheaterLights* lights, PopcornPopper* popper) {
        this -> amp = amp;
        this -> tuner = tuner;
        this -> dvd = dvd;
        this -> cd = cd;
        this -> projector = projector;
        this -> screen = screen;
        this -> lights = lights;
        this -> popper = popper;
    }
    void watchMovie(std::string movie) {
        std::cout << "Get ready to watch a movie...\n";
        popper -> on();
        popper -> pop();
        lights -> dim(10);
        screen -> down();
        projector -> on();
        projector -> wideScreenMode();
        amp -> on();
        amp -> setDvd(dvd);
        amp -> setSurroundSound();
        amp -> setVolume(5);
        dvd -> on();
        dvd -> play(movie);
    }
    void endMovie() {
        std::cout << "Shutting movie theater down...\n";
        popper -> off();
        lights -> on();
        screen -> up();
        projector -> off();
        amp -> off();
        dvd -> stop();
        dvd -> eject();
        dvd -> off();
    }
};

int main() {
    Amplifier* amp = new Amplifier;
    Tuner* tuner = new Tuner;
    DvdPlayer* dvd = new DvdPlayer;
    Cdplayer* cd = new Cdplayer;
    Projector* projector = new Projector;
    TheaterLights* lights = new TheaterLights;
    Screen* screen = new Screen;
    PopcornPopper* popper = new PopcornPopper;

    HomeTheaterFacade* homeTheater = new HomeTheaterFacade(amp, tuner, dvd, cd, projector, screen, lights, popper);
    homeTheater -> watchMovie("Raiders of The Lost Ark");
    homeTheater -> endMovie();
}
