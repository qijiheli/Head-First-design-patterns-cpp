#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>


class Observer
{
public:
    virtual void update(float Temperature, float Humidity, float Presssure) = 0;
};

class Subject
{
public:
    virtual void registerObserver(Observer* pObserver) = 0;
    virtual void removeObserver(Observer* pObserver) = 0;
    virtual void notifyObservers() = 0;
};

class DisplayElement
{
public:
    virtual const void display() = 0;
};

class WeatherData : public Subject
{
public:
    void registerObserver(Observer* pObserver) {
        pObservers.insert(pObserver);
    }

    void removeObserver(Observer* pObserver) {
        pObservers.erase(pObserver);
    }

    void notifyObservers() {
        for (auto &observer : pObservers) {
            observer -> update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    void setMeasurements(float Temperature, float Humidity, float Pressure) {
        this -> temperature = Temperature;
        this -> humidity = Humidity;
        this -> pressure = Pressure;
        measurementsChanged();
    }

private:
    std::unordered_set<Observer*> pObservers;
    float temperature;
    float humidity;
    float pressure;

};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    CurrentConditionsDisplay(Subject* pWeatherData) {
        this -> weatherData = pWeatherData;
        weatherData -> registerObserver(this);
    }

    void update(float Temperature, float Humidity, float Pressure) {
        this -> temperature = Temperature;
        this -> humidity = Humidity;
        this -> pressure = Pressure;
        display();
    }

    const void display() {
        std::cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity and " << pressure << "Pa pressure\n";
    }

private:
    float temperature;
    float humidity;
    float pressure;
    Subject* weatherData;
};

class StatisticsDisplay : public Observer , public DisplayElement
{
public:
    StatisticsDisplay(Subject* pWeatherData) {
        pWeatherData -> registerObserver(this);
    }

    void update(float Temperature, float Humidity, float Pressure) {
        this -> temperatures.push_back(Temperature);
        calculate();
        display();

    }
    void calculate() {
        std::sort(temperatures.begin(), temperatures.end());
        MaxTemp = temperatures.back();
        MinTemp = temperatures.front();
        float sum;
        for (auto temp : temperatures) {
            sum += temp;
        }
        AvgTemp = sum/temperatures.size();
    }

    const void display() {
        std::cout << "Avg/Max/Min temperature = " << AvgTemp << "/" <<MaxTemp << "/" << MinTemp << "\n";
    }
private:
    float AvgTemp;
    float MaxTemp;
    float MinTemp;
    std::vector<float> temperatures;
    Subject* weatherData;
};


int main() {
    WeatherData* weatherData = new WeatherData;
    CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay* statisticsDisplay = new StatisticsDisplay(weatherData);

    weatherData -> setMeasurements(80, 65, 30.4f);
    weatherData -> setMeasurements(82, 70, 29.2f);
    weatherData -> setMeasurements(78, 90, 29.2f);
    delete weatherData;
    delete currentDisplay;
    delete statisticsDisplay;
    return 1;
}
