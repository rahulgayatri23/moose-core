/**********************************************************************
** This program is part of 'MOOSE', the
** Messaging Object Oriented Simulation Environment.
**           Copyright (C) 2003-2011 Upinder S. Bhalla. and NCBS
** It is made available under the terms of the
** GNU Lesser General Public License version 2.1
** See the file COPYING.LIB for the full notice.
**********************************************************************/

#ifndef _RANDSPIKE_H
#define _RANDSPIKE_H

#include "global.h"

class RandSpike
{
public:
    RandSpike();

    //////////////////////////////////////////////////////////////////
    // Field functions.
    //////////////////////////////////////////////////////////////////
    void setRate( double rate );
    double getRate() const;

    void setRefractT( double val );
    double getRefractT() const;

    bool getFired() const;

    double mtrand( );

    //////////////////////////////////////////////////////////////////
    // Message dest functions.
    //////////////////////////////////////////////////////////////////

    void process( const Eref& e, ProcPtr p );
    void reinit( const Eref& e, ProcPtr p );

    //////////////////////////////////////////////////////////////////
    static const Cinfo* initCinfo();

private:
    double rate_;
    double realRate_;
    double refractT_;
    double lastEvent_;
    double threshold_;
    bool fired_;

    moose::global::rng_type_ rng;
    moose::global::distribution_type_ dist;

};

#endif // _RANDSPIKE_H
