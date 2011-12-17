
#include <QtCore/QCoreApplication>
#include <QtCore\qfile.h>
#include <QtCore\qstring.h>
#include <QtCore\qtextstream.h>

#include "UserAirspace.h"
#include "Airspace.h"

using namespace Updraft;

int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);


	QString fileName("testUserAirspace.txt");
	UserAirspace MyAirspace(fileName);
	
	
	


	return 0;//a.exec();
}
