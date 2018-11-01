#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Car.h"
using namespace std;
Car::Car(){

	m_year = 0;
	m_make[0] = '\0';
	m_model[0] = '\0';
	m_basePrice = 0;
	m_available = 0;
	m_finalPrice = 0;
	m_owner[0] = '\0';
	m_sensors[3];
	m_numSensors = 0;

}

Car::Car(int yr, char * mk, char * mdl, float prc, bool avl, char * ownr, Sensor *snsr){

	setYear(yr);
	setMake(mk);
	setModel(mdl);
	setPrice(prc);
	setAvailable(avl);
	setOwner(ownr);
	//sensor number adjust here
	for(int i = 0; i < 3; i++){
		//m_sensors[i] = snsr;
		//snsr++;
	}
}
Car::Car(Car &carObj){

	setYear(carObj.getYear());
	setMake(carObj.getMake());
	setModel(carObj.getModel());
	setPrice(carObj.getPrice());
	setAvailable(carObj.getAvailable());
	setOwner(carObj.getOwner());


}

char* Car::myStringCopy(char * destination, const char * source){

    char temp[255] = {'\0'}, *temp_pt = temp;
    char *dest_pt;
    const char *source_pt;
    dest_pt = destination;
    source_pt = source;
    int  index = 0;

    while ((*(source_pt + index)) != '\0')
    {
        (*(dest_pt + index)) = (*(source_pt + index));
        index++;
    }

    for (index; index < 255; index++)
    {
        (*(dest_pt+index)) = '\0';
    }
	return temp_pt;
}

void Car::setYear(int yr){
	m_year = yr;
}
void Car::setMake(char * mk){
	myStringCopy(m_make, mk);
}
void Car::setModel(char * mdl){
	myStringCopy(m_model, mdl);
}
void Car::setPrice(float prc){
	m_basePrice = prc;
}
void Car::setAvailable(bool avl){
	m_available = avl;
}
void Car::setOwner(char * ownr){
	myStringCopy(m_owner, ownr);
}
void Car::addSensor(){
	m_numSensors++;
}
void Car::setSensor(int nmSnsr){
	m_numSensors = nmSnsr;
}
int Car::getYear(){
	return m_year;
}
char* Car::getMake(){
	char *mk_pt = m_make;
	return mk_pt;
}
char* Car::getModel(){
	char *mdl_pt = m_model;
	return mdl_pt;
}
char* Car::getOwner(){
	char *ownr_pt = m_owner;
	return ownr_pt;
}
float Car::getPrice(){
	return m_basePrice;
}
float Car::getFinal(){
	return m_finalPrice;
}
bool Car::getAvailable(){

	return m_available;
}
int Car::getNumSensor(){
	return m_numSensors;
}
void updatePrice(){
	//insert code here :P
}
void Car::print(){
	/*
	for loop to call updatePrice() for each car object
	this will ensure that the final price displayed below
	will be the current final price
	*/

	cout << m_year << " ";
	cout << m_make << " ";
	cout << m_model << ", ";
	cout << "Cost per Day: " << m_finalPrice << " ";
	cout << boolalpha << m_available << endl;
}
float Car::estimateCost(Car *car, int days){
	float totalCost = (car->m_finalPrice * days);
	return totalCost;
}
void Car::operator+(char* typ){
	this->m_sensors->setType(typ);
	//char* typ_pt = typ;
	if((*typ) == 'g'){
		this->m_sensors->setXcost(5.0);
	}
	if((*typ) == 'c'){
		this->m_sensors->setXcost(10.0);
	}
	if((*typ) == 'l'){
		this->m_sensors->setXcost(15.0);
	}
	if((*typ) == 'r'){
		this->m_sensors->setXcost(20.0);
	}

}

Sensor::Sensor(){
	m_type[0] = '\0';
	m_extraCost = 0;

}
Sensor::Sensor(char * typ, float xcost, int gps, int cam, int lid, int rad){
	myStringCopy(m_type, typ);
	m_extraCost = xcost;
	if(gps > 0){
		gps_cnt++;
	}
	if(cam > 0){
		camera_cnt++;
	}
	if(lid > 0){
		lidar_cnt++;
	}
	if(rad > 0){
		radar_cnt++;
	}
}
Sensor::Sensor(Sensor &sen){

	setType(sen.getType());
	setXcost(sen.getXcost());
}
char* Sensor::myStringCopy(char * destination, const char * source){

    char temp[255] = {'\0'}, *temp_pt = temp;
    char *dest_pt;
    const char *source_pt;
    dest_pt = destination;
    source_pt = source;
    int  index = 0;

    while ((*(source_pt + index)) != '\0')
    {
        (*(dest_pt + index)) = (*(source_pt + index));
        index++;
    }

    for (index; index < 255; index++)
    {
        (*(dest_pt+index)) = '\0';
    }
	return temp_pt;
}
void Sensor::setType(char * typ){
	myStringCopy(m_type, typ);
}
void Sensor::setXcost(float xcost){
	m_extraCost += xcost;
}
char* Sensor::getType(){
	char *typ_pt = m_type;
	return typ_pt;
}
float Sensor::getXcost() const{
	return m_extraCost;
}
int Sensor::getGps_cnt(){
	return gps_cnt;
}
int Sensor::getCam_cnt(){
	return camera_cnt;
}
int Sensor::getLid_cnt(){
	return lidar_cnt;
}
int Sensor::getRad_cnt(){
	return radar_cnt;
}
void Sensor::resetGps_cnt(){
	gps_cnt = 0;
}
void Sensor::resetCam_cnt(){
	camera_cnt = 0;
}
void Sensor::resetLid_cnt(){
	lidar_cnt = 0;
}
void Sensor::resetRad_cnt(){
	radar_cnt = 0;
}
int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

Agency::Agency(){
	m_name[0] = '\0';
	m_zipcode[0] = '\0';
	m_inventory[5];
}
void Agency::setName(char * nm){
	myStringCopy(m_name, nm);
}
void Agency::setZip(int * zp){
	int * zip_pt = m_zipcode;
	for(int i = 0; i < 5; i++){
		zip_pt = zp;
		zip_pt++, zp++;
	}
}
char * Agency::getName(){
	char * nm_pt = m_name;
	return nm_pt;
}
void Agency::setZip(char * zp){
	int * zip_pt = m_zipcode;
	for(int i = 0; i < 5; i++){
		*zip_pt = *(zp + i) - '0';
		zip_pt++;
	}
}
int * Agency::getZip(){
	int * zip_pt = m_zipcode;
	return zip_pt;
}
void Agency::inventoryIndex(Car *car_pt){

}
void Agency::readAllData(char * file){
	Car *car_pt = m_inventory;
	fstream inputFile;
	bool fileSuccess = false;
	do{
		char line[255];
		char * line_pt = line;
		inputFile.open(file);
		if(inputFile.is_open()){
			inputFile >> line;
			myStringCopy(m_name, line);
			inputFile >> line;
			setZip(line_pt);
			for(int carIndex = 0; carIndex < 5; carIndex++){
				Sensor * sensor_pt = car_pt->m_sensors;
				inputFile >> line;
				car_pt[carIndex].setYear(atoi(line));
				inputFile >> line;
				car_pt[carIndex].setMake(line);
				inputFile >> line;
				car_pt[carIndex].setModel(line);
				inputFile >> line;
				car_pt[carIndex].setPrice(atof(line));
				bool cont = true;
				while(cont){
					for(int i = 0; i < 10; i++){
						if((*(line_pt + i)) == 'g'){
							sensor_pt->gps_cnt++;
							//sensor_pt+//add sensor object;
							car_pt[carIndex].addSensor();
						}
						if((*(line_pt + i)) == 'c'){
							sensor_pt->camera_cnt++;
							//add sensor to car using op over
							car_pt[carIndex].addSensor();
						}
						if((*(line_pt + i)) == 'l'){
							sensor_pt->lidar_cnt++;
							//add sensor to car op over
							car_pt[carIndex].addSensor();
						}
						if((*(line_pt + i)) == 'r'){
							if((*(line_pt + (i + 2))) == 'd'){
								sensor_pt->radar_cnt++;
								//add sensor here bruh
								car_pt[carIndex].addSensor();
							}
						}
						if((*(line_pt + i)) == '}'){
							cont = false;
							break;
						}
					}
					inputFile >> line;
				}
				car_pt[carIndex].setAvailable(atoi(line));
				inputFile >> line;
				if(atoi(line) < 1900){
					car_pt[carIndex].setOwner(line);
					inputFile >> line;
					car_pt[carIndex].setYear(atoi(line));
				}
				else{
					car_pt[carIndex].setYear(atoi(line));
				}

			}

		}
		else
		{
			cout << "THERE WAS AN ERROR OPENING THE FILE" << endl;
			fileSuccess = true;
		}


	}while(fileSuccess);

}
Car* Agency::operator[](const int &index)
{
	Car * car_pt = m_inventory;
	car_pt = (car_pt + index);
	return car_pt;
}
char* Agency::myStringCopy(char * destination, const char * source){

    char temp[255] = {'\0'}, *temp_pt = temp;
    char *dest_pt;
    const char *source_pt;
    dest_pt = destination;
    source_pt = source;
    int  index = 0;

    while ((*(source_pt + index)) != '\0')
    {
        (*(dest_pt + index)) = (*(source_pt + index));
        index++;
    }

    for (index; index < 255; index++)
    {
        (*(dest_pt+index)) = '\0';
    }
	return temp_pt;
}

void Agency::printAllData(Agency * agency)
{
  cout << agency->getName() << " " << agency->getZip()
  << ":" << endl;
  Car *car_pt = agency->m_inventory;
  int i = 0;
  int *index_pt = &i;

  for(i; i < 5; i++)
  {
    float priceDifferance;
    priceDifferance = car_pt[*index_pt].getFinal() - car_pt[*index_pt].getPrice();
    cout << car_pt[*index_pt].getYear() << " "
     << car_pt[*index_pt].getMake() << " "
     << car_pt[*index_pt].getModel() << ", $"
     << car_pt[*index_pt].getPrice() << " + $"
     << priceDifferance << " in extra costs for a total cost of"
     << car_pt[*index_pt].getFinal() << ". Sensors included: ";

    //need to figure out printing Sensors
    //especially sensors to determine how many
    //mayby for statement with agency->getNumSensor as
    //parameter
  }

}
void Agency::printAvailableCars(Agency * agency)
{

}
