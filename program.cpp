#include <iostream>
#include <string>

using namespace std;



class Car{

    private:
    string make;
    string model;
    int topSpeed;

    public:
    void setmake(string _make);
    string getmake();
    void setmodel(string _model);
    string getmodel();
    void settopspeed(int _topSpeed);
    int gettopspeed();
    void printInfo();

};

void Car::printInfo(){
    cout << "Make: " << getmake() << endl;
    cout << "Model: " << getmodel() << endl;
    cout << "Top Speed: " << gettopspeed() << endl;
}

void Car::setmake(string _make){
    if(_make.length() <= 2)
    {
        cout << "Make name length is too small!" << endl;
    }
    else{
        make = _make;
    }
    
}

string Car::getmake(){
    return make;
}

void Car::setmodel(string _model){
    if(_model.length() <= 2)
    {
        cout << "Model name length is too small!" << endl;
    }
    else{
        model = _model;
    }
}


string Car::getmodel(){
    return model;
}

void Car::settopspeed(int _topSpeed){
    if(_topSpeed < 1)
    {
        cout << "Top speed is to small." << endl;
    }
    else{
        topSpeed = _topSpeed;
    }
}

int Car::gettopspeed(){
    return topSpeed;
}

int main()
{

    //cout << "MESSAGE" << endl;

    Car yaris;

    yaris.setmake("Toyota");
    yaris.setmodel("Yaris");
    yaris.settopspeed(100);

    yaris.printInfo();

    return 0;
}

