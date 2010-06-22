/**********************************************************************
** This program is part of 'MOOSE', the
** Messaging Object Oriented Simulation Environment.
**           Copyright (C) 2003-2010 Upinder S. Bhalla. and NCBS
** It is made available under the terms of the
** GNU Lesser General Public License version 2.1
** See the file COPYING.LIB for the full notice.
**********************************************************************/

#ifndef _ZOMBIE_MOL_H
#define _ZOMBIE_MOL_H

class ZombieMol: public Stoich
{
	public: 
		ZombieMol();
		~ZombieMol();

		//////////////////////////////////////////////////////////////////
		// Field assignment stuff
		//////////////////////////////////////////////////////////////////

		void setN( Eref e, const Qinfo* q, double v );
		double getN( Eref e, const Qinfo* q ) const;
		void setNinit( Eref e, const Qinfo* q, double v );
		double getNinit( Eref e, const Qinfo* q ) const;
		void setDiffConst( Eref e, const Qinfo* q, double v );
		double getDiffConst( Eref e, const Qinfo* q ) const;

		void setConc( Eref e, const Qinfo* q, double v );
		double getConc( Eref e, const Qinfo* q ) const;
		void setConcInit( Eref e, const Qinfo* q, double v );
		double getConcInit( Eref e, const Qinfo* q ) const;

		//////////////////////////////////////////////////////////////////
		// Dest funcs
		//////////////////////////////////////////////////////////////////

		void process( const ProcInfo* p, const Eref& e );
		void eprocess( Eref e, const Qinfo* q, ProcInfo* p );
		void reinit( const Eref& e, const Qinfo*q, ProcInfo* p );
		void reac( double A, double B );

		//////////////////////////////////////////////////////////////////
		// utility funcs
		//////////////////////////////////////////////////////////////////
		unsigned int convertId ( Id id ) const;
		void zombify( Element* solver, Element* orig );
		void unzombify( Element* zombie ) const;

		static const Cinfo* initCinfo();
	private:
};

#endif	// _ZOMBIE_MOL_H
