// This is the main DLL file.

//#include "stdafx.h"

#include "UserAirspace.h"

namespace Updraft
{
	/// UserAirpace parsing
	UserAirspace::UserAirspace(QString fileName)
	{
		/// Open the file and parse the content.
		QFile file(fileName);

		if (!file.open(QFile::ReadOnly))
			return;

		QTextStream ts(&file);
		QString text("");

		while(text != "AC" && !ts.atEnd())
			ts >> text;

		while (!ts.atEnd())
		{
			if(!ts.atEnd())
				ts.seek(ts.pos() -3);
			Airspace nextairspace(ts);
			this->allAirspaces.push_back(nextairspace);
		}
		
		file.close();
	} // UserAirspace
} // Updraft