#include <iostream>
#include <vector>
#include <string>
//#include <typeinfo>   tried to use typeid().name() to get the subclass name but failed

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class CeilingFan
{
public:
    const static int HIGH = 3;
    const static int MEDIUM = 2;
    const static int LOW = 1;
    const static int OFF = 0;
    int speed;
    CeilingFan() {
        speed = OFF;
    }
    void high() {
        speed = HIGH;
        std::cout << "ceiling fan is on high\n";
    }
    void medium() {
        speed = MEDIUM;
        std::cout << "ceiling fan is on medium\n";
    }
    void low() {
        speed = LOW;
        std::cout << "ceiling fan is on low\n";
    }
    void off() {
        speed = OFF;
        std::cout << "ceiling fan is off\n";
    }
    int getSpeed() {
        return speed;
    }
};

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
    void undo() {
        light -> off();
    }
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
    void undo() {
        light -> on();
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
    void undo() {
        stereo -> off();
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
    void undo() {
        stereo -> on();
        stereo -> setCD();
        stereo -> setVolume(11);
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
    void undo() {
        garageDoor -> down();
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
    void undo() {
        garageDoor -> up();
    }
};

class noCommand : public Command
{
public:
    void execute() {};
    void undo() {};
};

class CeilingFanHighCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanHighCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> high();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanMediumCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanMediumCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> medium();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanLowCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanLowCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> low();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanOffCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanOffCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> off();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class RemoteControl
{
public:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    std::vector<Command*> undoCommands;
    RemoteControl() {
        noCommand* nocommand = new noCommand;
        for (int i = 0; i < 7; i++) {
            onCommands.push_back(nocommand);
            offCommands.push_back(nocommand);
        }
        undoCommands.push_back(nocommand);
    }
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }
    void onButtonWasPushed(int slot) {
        if (onCommands[slot] != nullptr) {
            onCommands[slot] -> execute();
            undoCommands.push_back(onCommands[slot]);
        }
    }
    void offButtonWasPushed(int slot) {
        if (offCommands[slot] != nullptr) {
            offCommands[slot] -> execute();
            undoCommands.push_back(offCommands[slot]);
        }
    }
    void undoButtonWasPushed() {
        if (undoCommands[undoCommands.size() - 1] != nullptr) {
            undoCommands[undoCommands.size() - 1] -> undo();
            undoCommands.pop_back();
        }
    }
};
/*** I cannot put vector<command*>* into vector<command*>
class MacroCommand : public Command
{
public:
    std::vector<Command*> commands;
    MacroCommand(std::vector<Command*> _commands) {
        this -> commands = _commands;
    }
    void execute() {
        for (auto command : commands) {
            command -> execute();
        }
    }
    void undo() {
        for (auto command : commands) {
            command -> undo();
        }
    }
};
***/
int main()
{
    RemoteControl* remoteControl = new RemoteControl; 

    CeilingFan* ceilingFan = new CeilingFan;
    CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
    CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
    CeilingFanLowCommand* ceilingFanLow = new CeilingFanLowCommand(ceilingFan);
    CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);


    remoteControl -> setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl -> setCommand(1, ceilingFanHigh, ceilingFanLow);

    remoteControl -> onButtonWasPushed(0);
    remoteControl -> offButtonWasPushed(0);
    remoteControl -> undoButtonWasPushed();
    remoteControl -> onButtonWasPushed(1);
    remoteControl -> undoButtonWasPushed();
/***
    Light* light = new Light;
    Stereo* stereo = new Stereo;

    LightOnCommand* lightOn = new LightOnCommand(light);
    LightOffCommand* lightOff = new LightOffCommand(light);
    StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
    StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

    std::vector<Command*> partyOn;
    std::vector<Command*> partyOff;
    partyOn.push_back(lightOn);
    partyOn.push_back(stereoOn);
    partyOff.push_back(lightOff);
    partyOff.push_back(stereoOff);
    Command* pPartyOn = &partyOn;
    Command* pPartyOff = &partyOff;

    remoteControl -> setCommand(2, pPartyOn, pPartyOff);
    remoteControl -> onButtonWasPushed(2);
    remoteControl -> offButtonWasPushed(2);
    remoteControl -> undoButtonWasPushed();
***/
}
