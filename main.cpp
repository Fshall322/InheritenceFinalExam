#include <iostream>

using namespace std;

// class object
class Blanket{
protected:
    //protected variables
    string size;
    string color;
    string material;
    float price;

public:
    //Constructor
    Blanket();
    //sets and get prototypes
    void setPrice(float);
    string getSize();
    string getColor();
    string getMaterial();
    float getPrice();

    //display function
    void display(){
        cout<<"The blanket's size is: "<<size<<endl;
        cout<<"The blanket's color is: "<<color<<endl;
        cout<<"The blanket is made out of: "<<material<<endl;
        cout<<"The blanket costs: "<<price<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
    }
};

//default constructor
Blanket::Blanket(){
    size = "twin";
    color = "white";
    material = "cotton";
    setPrice(30.00);//sets the price , we do it this way at this point because we have a mutator for price
}

//Electric Blanket child class
class ElectricBlanket:public Blanket{
protected :
    int heatSettings;
    bool autoShutOff;
public:
    ElectricBlanket();
    void setHeatSettings(int);
    int getHeatSettings();
    void setAutoShutOff(bool);
    bool getAutoShutOff();

    void display(){
        Blanket::display();// beacuse Blanket is our parent class we dont need to create an class object to call the display from Blanket, we can do it like I see here.
        cout<<"The number of heat settings is: "<<heatSettings<<endl;
        cout<<"Does it have an auto shit off feature? "<<autoShutOff<<endl;
    }
};

ElectricBlanket::ElectricBlanket(){
    heatSettings = 1;
    autoShutOff = false;

    price = price + 25.00;

    if(autoShutOff = true){
        price = price + 5.75;
    }
    else{
        price = price;
    }
    setPrice(price);//sets the price , we do it this way at this point because we have a mutator for price
}

//stes and gets
void Blanket::setPrice(float p){
    price = p;
    // help determine the overall price based on size
    if(size == "double")
        price = price + 10.00;
    else if(size == "queen")
        price = price + 25.00;
    else if(size == "king")
        price = price + 40.00;
    //help determine the overall price based on material
    if(material == "wool"){
        price = price + 25.00;
    }
    else if(material == "cashmere"){
        price = price + 45.00;
    }
}
string Blanket::getSize(){
    return size;
}
string Blanket::getColor(){
    return color;
}
string Blanket::getMaterial(){
    return material;
}
float Blanket::getPrice(){
    return price;
}

void ElectricBlanket::setHeatSettings(int hs){
    this->heatSettings = heatSettings;
}
int ElectricBlanket::getHeatSettings(){
    return heatSettings;
}
void ElectricBlanket::setAutoShutOff(bool b){
    autoShutOff = b;
}
bool ElectricBlanket::getAutoShutOff(){
    return autoShutOff;
}
//end sets and gets

int main(int argc, char** argv) {
    Blanket blanket;
    ElectricBlanket electric;
    blanket.display();
    electric.display();
    return 0;
}
