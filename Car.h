#ifndef CAR_H
#define CAR_H

const int arraySize = 255;
const int numCars = 5;


class Sensor{

	public:
		Sensor();
		Sensor(char * typ, float xcost, int gps, int cam, int lid, int rad);
		Sensor(Sensor &sen);

		Sensor* operator+(char* typ);

		static char * myStringCopy(char * destination, const char * source);

		void setType(char *typ);
		void setXcost(float xcost);

		char * getType();
		float getXcost() const;

		static int getGps_cnt();
		static int getCam_cnt();
		static int getLid_cnt();
		static int getRad_cnt();

		static void resetGps_cnt();
		static void resetCam_cnt();
		static void resetLid_cnt();
		static void resetRad_cnt();

		//Need to make operator== overload method
    friend class Agency;
	private:
		char m_type[arraySize];
		float m_extraCost;

		static int gps_cnt;
		static int camera_cnt;
		static int lidar_cnt;
		static int radar_cnt;

};

class Car{

	public:


		Car();
		Car(int yr,char * mk, char * mdl, float prc, bool avl, char * ownr, Sensor * snsr);
		Car(Car &carObj);

		void operator+(char* typ);


		static char * myStringCopy(char * destination, const char * source);

		void setYear(int yr);
		void setMake(char * mk);
		void setModel(char * mdl);
		void setPrice(float prc);
		void setAvailable(bool avl);
		void setOwner(char * ownr);
		void addSensor();
		void setSensor(int nmSnsr);

		int getYear();
		char * getMake();
		char * getModel();
		float getPrice();
		float getFinal();
		bool getAvailable();
		char * getOwner();
		Sensor getSensor();
		int getNumSensor();

		void updatePrice();

		void print();

		float estimateCost(Car *car, int days);

		//need to add a method to add an owner/lessee witha a overloaded + opereator    bullshit
    friend class Agency;
  private:

		int m_year;
		char m_make[arraySize];
		char m_model[arraySize];
		float m_basePrice;
		float m_finalPrice;
		bool m_available;
		int m_numSensors;
		char m_owner[arraySize];
		Sensor m_sensors[3];
};

class Agency{

	public:
		Agency();
		Car* operator[](const int &index);
		static char * myStringCopy(char * destination, const char * source);

		void setName(char * nm);
		void setZip(char * zp);
		void setZip(int * zp);
		void inventoryIndex(Car *car_pt);

		char * getName();
		int * getZip();

		void readAllData(char * file);
		void printAllData(Agency * agency);
		void printAvailableCars(Agency * agency);



	private:
		char m_name[arraySize];
		int m_zipcode[5];
    Car m_inventory[5];


};




#endif
