#include <iostream>
#include<sstream>
using namespace std;
enum switches
{
	MAIN_SWITCH = 1,				//главный выключатель
	SOCKETS=2,						//розетки
	LIGHTS_INSIDE = 4,				//внутренний свет
	LIGHTS_OUTSIDE = 8,				//наружное освещение
	HEATERS = 16,					//обогреватели
	WATER_PIPE_HEATING = 32,		//обогев водопровода
	CONDITIONER = 64				//кондиционер
};
int main()
{
	string text;
	cout << "Enter the parameters(outside temperature, house temperature, movement in the garden(on/off, lighting in the house(on/off))" << endl;
	getline(cin,text);
	stringstream parameters(text);
	double temperatureOutside=0;			// наружная температура
	double temperatureInside=0;				// температура внутри
	string movement;						// датчик движения
	string lights;							// освещение в доме
	parameters>>temperatureOutside >> temperatureInside >> movement >> lights;
	cout << temperatureOutside << endl;
	cout << temperatureInside << endl;
	cout << movement << endl;
	cout << lights << endl;
}
