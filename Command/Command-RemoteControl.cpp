#include <iostream>
#include <string>
#include <vector>


class Light
{
public:
    void on() {
        std::cout << "Light is on\n";
    }
    void off() {
        std::cout << "Light is off\n";
    }
};

class Stereo
{
public:
    void on() {
        std::cout << "stereo is on\n";
    }
    void off() {
        std::cout << "stereo is off\n";
    }
    void setCD() {
        std::cout << "stereo is set for CD input\n";
    }
    void setVolume(int volume) {
        std::cout << "Stereo volume set to " << volume << "\n";
    }
};

class GarageDoor
{
public:
    void up() {
        std::cout << "Garage Door is Open\n";
    }
    void down() {
        std::cout << "Garage Door is Down\n";
    }
};

class Command
{
public:
    virtual void execute() = 0;
};

class LightOnCommand : public Command
{
public:
    Light* light;
    LightOnCommand(Light* _light) {
        this -> light = _light;
    }
    void execute() {
        light -> on();
    }
};

class noCommand : public Command
{
public:
    void execute() {};
};

class LightOffCommand : public Command
{
public:
    Light* light;
    LightOffCommand(Light* _light) {
        this -> light = _light;
    }
    void execute() {
        light -> off();
    }
};

class StereoOnWithCDCommand : public Command
{
public:
    Stereo* stereo;
    StereoOnWithCDCommand(Stereo* _stereo) {
        this -> stereo = _stereo;
    }
    void execute() {
        stereo -> on();
        stereo -> setCD();
        stereo -> setVolume(11);
    }
};

class StereoOffCommand : public Command
{
public:
    Stereo* stereo;
    StereoOffCommand(Stereo* _stereo) {
        this -> stereo = _stereo;
    }
    void execute() {
        stereo -> off();
    }
};

class GarageDoorUpCommand : public Command
{
public:
    GarageDoor* garageDoor;
    GarageDoorUpCommand(GarageDoor* _garageDoor) {
        this -> garageDoor = _garageDoor;
    }
    void execute() {
        garageDoor -> up();
    }
};

class GarageDoorDownCommand : public Command
{
public:
    GarageDoor* garageDoor;
    GarageDoorDownCommand(GarageDoor* _garageDoor) {
        this -> garageDoor = _garageDoor;
    }
    void execute() {
        garageDoor -> down();
    }
};

class RemoteControl
{
public:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    RemoteControl() {
        noCommand* nocommand = new noCommand;
        for (int i = 0; i < 7; i++) {
            onCommands.push_back(nocommand);
            offCommands.push_back(nocommand);
        }
    }
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }
    void onButtonWasPushed(int slot) {
        onCommands[slot] -> execute();
    }
    void offButtonWasPushed(int slot) {
        offCommands[slot] -> execute();
    }
};


int main()
{
    RemoteControl* remoteControl = new RemoteControl; 

    Light* livingRoomLight = new Light();
    Light* kitchenLight = new Light();
    //CeilingFan* ceilingFan = new CeilingFan("Living Room");
    GarageDoor* garageDoor = new GarageDoor();
    Stereo* stereo = new Stereo();

    LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
    LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
    LightOnCommand* kitchenLightOn = new LightOnCommand(kitchenLight);
    LightOffCommand* kitchenLightOff = new LightOffCommand(kitchenLight);

    GarageDoorUpCommand* garageDoorUp = new GarageDoorUpCommand(garageDoor);
    GarageDoorDownCommand* garageDoorDown = new GarageDoorDownCommand(garageDoor);
    StereoOnWithCDCommand* stereoOnWithCD = new StereoOnWithCDCommand(stereo);
    StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

    remoteControl -> setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl -> setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl -> setCommand(2, stereoOnWithCD, stereoOff);
    remoteControl -> setCommand(3, garageDoorUp, garageDoorDown);

    remoteControl -> onButtonWasPushed(0);
    remoteControl -> offButtonWasPushed(0);
    remoteControl -> onButtonWasPushed(1);
    remoteControl -> offButtonWasPushed(1);
    remoteControl -> onButtonWasPushed(2);
    remoteControl -> offButtonWasPushed(2);
}
