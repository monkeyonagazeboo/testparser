// UserAirspace.h

#pragma once
#ifndef USERAIRSPACE_H
#define USERAIRSPACE_H

#include <QtCore\qglobal.h>
#include <QtCore\qvector.h>
#include <QtCore\qfile.h>
#include <QtCore\qtextstream.h>
#include <QtCore\qlist.h>

#include "Airspace.h"
/*
#ifdef USERAIRSPACE_LIB
# define USERAIRSPACE_EXPORT Q_DECL_EXPORT
#else
# define USERAIRSPACE_EXPORT Q_DECL_IMPORT
#endif
*/
/*!
UserAirspace parser library.

******* OPEN AIR (tm) TERRAIN and AIRSPACE DESCRIPTION LANGUAGE *************
*    Version 1.0
*    December 10, 1998
*    Updated October 15, 1999
*    Send comments to jerryp@winpilot.com
*
*
*  AIRSPACE related record types:
*  ==============================
*
* AC class    ;    class = Airspace Class, see below:
*     R restricted
*     Q danger
*     P prohibited
*     A Class A
*     B Class B
*     C Class C
*     D Class D 
*     GP glider prohibited 
*     CTR CTR
*     W Wave Window
*
*
*  AN string        ;     string = Airspace Name
*  AH string        ;     string = Airspace Ceiling
*  AL string        ;     string = Airspace Floor
*  AT coordinate    ;    coordinate = Coordinate of where to place a name label on the map (optional)
*                     ;     NOTE: there can be multiple AT records for a single airspace segment
*    
*    
*    TERRAIN related record types (WinPilot version 1.130 and newer):
*    ==============================
*
*    TO    {string}                 ; Declares Terrain Open Polygon; string = name (optional)
*    TC    {string}                 ; Declares Terrain Closed Polygon; string = name (optional)
*    SP style, width, red, green, blue    ; Selects Pen to be used in drawing
*    SB red, green, blue                         ; Selects Brush to be used in drawing
*
* 
*    Record types common to both TERRAIN and AIRSPACE
*    =================================================
*
*    V x=n             ;     Variable assignment.
*                     ;     Currently the following variables are supported:
*                     ;     D={+|-}    sets direction for: DA and DB records
*                     ;                     '-' means counterclockwise direction; '+' is the default
*                     ;                     automatically reset to '+' at the begining of new airspace segment    
*                     ;     X=coordinate    : sets the center for the following records: DA, DB, and DC    
*                     ;     W=number        : sets the width of an airway in nm (NYI)
*                     ;      Z=number         : sets zoom level at which the element becomes visible (WP version 1.130 and newer)
*
*    DP coordinate                     ; add polygon pointC
*    DA radius, angleStart, angleEnd    ; add an arc, angles in degrees, radius in nm (set center using V X=...)
*    DB coordinate1, coordinate2         ; add an arc, from coordinate1 to coordinate2 (set center using V X=...)
*    DC radius                         ; draw a circle (center taken from the previous V X=...  record, radius in nm
*    DY coordinate                     ; add a segment of an airway (NYI)



*/

//using namespace System;

namespace Updraft {

	class /*USERAIRSPACE_EXPORT*/ UserAirspace
	{
	public :
		/// UserAirspace class constructor code. 
		/// This takes the filename in Userirspace free format and parses
		/// the data contained into private variables
		UserAirspace::UserAirspace(QString fileName);

		/// Returns the name of the AirSpace
		inline QString UserAirspace::GetName(int i) {return allAirspaces[i].GetName();}

		/// Returns the used airspaces count
		inline size_t UserAirspace::size() { return allAirspaces.size(); }

		/// UserAirspace destructor code here.
		//UserAirspace::~UserAirspace();

	private :
		/// UserAirspace contains several airspaces.
		QList<Airspace> allAirspaces;

		/// Coordinates structure - e.g. 39:29.9 N -119:46.1 E.
		struct Coordinate
		{
			bool valid; // validity flag
			struct ECor{int min; float sec;};
			ECor N;
			ECor E;
		};

		/// Airspace class type.
		/*!   R restricted
		*     Q danger
		*     P prohibited
		*     A Class A
		*     B Class B
		*     C Class C
		*     D Class D 
		*     GP glider prohibited 
		*     CTR CTR
		*     W Wave Window */
		/*enum AC { R, Q, P, A, B, C, D, GP, CTR,	W };

		/// Airspace Name.
		/// Contains the name of the aispace.
		/// Required.
		QString AN; 

		/// Airspace Ceiling
		/// Altitude ciling of the airspace in ft.
		/// AH < AL
		int AH;

		/// Airspace Floor.
		/// Altitude floor of the airspace in ft.
		/// Use -10000 for SFC.
		int AL;

		/// Airspace name label coordinates.
		/// List of coordinates, where to place the airspace name label on the map.
		/// Optional.
		QList<Coordinate> AT; 

		/// Terrain related variables \{
		/// Terrain open polygon name
		QString TO;

		/// \}
		/// Record type - terrain & airspace \{
		/// Centre of the polygon/circle.
		Coordinate X; //NA

		/// Airway width in nm. -1 for not set. 
		int Wi;

		/// Zoom level.
		/// Sets the zoom level at which the airspace become visible.
		float Z; // NA

		/// Add polygon points
		QList<Coordinate> DP;
		
		/// Arc \{
		/// Arc structures
		struct ArcI
		{
			bool valid; // TODO : validity flag
			unsigned int R; // radius in nm
			Coordinate Centre; // centre of the arc
			bool CW; // clockwise flag
			unsigned int Start; // start of the arc in deg
			unsigned int End; // end of the arc in deg
			float Zoom; // zoom /TODO: float vs int
		}
		struct ArcII
		{
			bool valid; // TODO : check if necessary
			Coordinate Centre; // centre of the arc
			Coordinate Start; // Starting coord
			Coordinate End; // Ending coord
			bool CW; // direction
			float Zoom; // zoom /TODO: float vs int
		}
		/// Arcs in airspace
		QList<ArcI> DA;
		QList<ArcII> DB;
		/// \}

		/// Circles in the airspace. \{
		/// Circle structure
		struct Circle
		{
			bool valid; // TODO : check if necessary
			unsigned int R; // radius in nm
			Coordinate Centre; // Centre of the circle in N E
			float Zoom; // zoom /TODO: float vs int
		}
		/// Cisrcles in airspace
		QList<Circle> DC;
		/// \}

		/// \}*/
	};// UserAirspace

}// Updraft


#endif //USERAIRSPACE_H