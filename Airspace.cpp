#include "UserAirspace.h"

namespace Updraft
{
	Airspace::Airspace(QTextStream &ts)
	{
		QString text("");

		this->validAN = false;
		this->validAL = false;
		this->validAH = false;
		this->validTO = false;
		this->validX = false;
		this->CW = true;
		this->Wi = -1;
		this->validZ = false;

		ts >> text;
		if (text != "AC") return;
		
		ts >> text;
		if (text == "R") this->AC = R;
		else if (text == "Q") this->AC = Q;
		else if (text == "P") this->AC = P;
		else if (text == "A") this->AC = A;
		else if (text == "B") this->AC = B;
		else if (text == "C") this->AC = C;
		else if (text == "D") this->AC = D;
		else if (text == "GP") this->AC = GP;
		else if (text == "CTR") this->AC = CTR;
		else if (text == "W") this->AC = W;
		else return;

		while (!ts.atEnd()) 
		{
			ts >> text;

			QString parse;
			ts.skipWhiteSpace();
			parse = ts.readLine();

			if (text == "*")
				continue;

			else if (text == "AC")
			{
				// Return the stream before AC and exits
				ts.seek(ts.pos() -3);
				return;
			}
			
			else if (text == "AN")
			{
				this->AN = parse;
			}

			else if (text == "AL")
			{
				this->AL = parse; // !!! can be text e.g. Ask on 122.8 !!!
			}

			else if (text == "AH")
			{
				this->AH = parse; // !!! can be text e.g. Ask on 122.8 !!!
			}

			else if (text == "AT")
			{
				AT.push_back(ParseCoord(parse)); 
			}

			else if (text == "V")
			{
				QChar ch = parse.at(0);
				parse = parse.right(parse.size() - parse.indexOf('=') -1);
				if (ch == 'X')
				{
					X = ParseCoord(parse);
				}
				else if (ch == 'D')
				{
					if (parse.trimmed().at(0) == '-')
						this->CW = false;
					else
						this->CW = true;
				}
				else if (ch == 'W')
				{
					this->Wi = parse.toInt();
				}
				else if (ch == 'Z')
				{
					this->Z = parse.toFloat();
					this->validZ = true;
				}
				
			} // V
			
			else if (text == "DP")
			{
				this->DP.push_back(ParseCoord(parse));
			}
			
			else if (text == "DA")
			{
				ArcI arc;
				arc.Zoom;//TODO : zoom not initialised
				parse.indexOf(',');
				ArcI arc;
				arc.
				this->DA.push_back(arc);
			}

			else if (text == "DP")
			{

			}

			else if (text == "DP")
			{

			}

			else if (text == "DP")
			{

			}

			else if (text == "DP")
			{

			}
		}
	}

	Airspace::Coordinate Airspace::ParseCoord(QString& text)
	{
		Coordinate cor;
		QString parse = text;
		int i = 0, j = 0;
		while (text.at(i) != 'N' && text.at(i) != 'S' && i < text.size()) ++i;
		while (text.at(j) != 'E' && text.at(j) != 'W' && j < text.size()) ++j;
		if (i == text.size() || j == text.size()) qFatal("Error parsing coordinates in UserAirspace file");
		parse = text.left(i);
		cor.N.min = parse.section(':',0,0).toInt();
		cor.N.sec = parse.section(':',1,1).toFloat();
		if (text.at(i) == 'S') cor.N.min *= -1;
		parse = text.mid(i+1, j - i - 1);
		cor.E.min = parse.section(':',0,0).toInt();
		cor.E.sec = parse.section(':',1,1).toFloat();
		if (text.at(j) == 'W') cor.E.min *= -1;
		cor.valid = true;
		return cor;
	}
} // Updraft