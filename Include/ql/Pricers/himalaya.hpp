
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.org/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, please email quantlib-users@lists.sourceforge.net
 * The license is also available at http://quantlib.org/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.org/group.html
*/
/*! \file himalaya.hpp
    \fullpath Include/ql/Pricers/%himalaya.hpp
    \brief Himalayan-type option pricer

*/

// $Id$
// $Log$
// Revision 1.13  2001/08/09 14:59:47  sigmud
// header modification
//
// Revision 1.12  2001/08/08 11:07:49  sigmud
// inserting \fullpath for doxygen
//
// Revision 1.11  2001/08/07 11:25:54  sigmud
// copyright header maintenance
//
// Revision 1.10  2001/07/25 15:47:28  sigmud
// Change from quantlib.sourceforge.net to quantlib.org
//
// Revision 1.9  2001/07/24 08:49:32  sigmud
// pruned redundant header inclusions
//
// Revision 1.8  2001/07/19 16:40:11  lballabio
// Improved docs a bit
//
// Revision 1.7  2001/07/05 15:57:23  lballabio
// Collected typedefs in a single file
//
// Revision 1.6  2001/06/22 16:38:15  lballabio
// Improved documentation
//
// Revision 1.5  2001/06/05 09:35:13  lballabio
// Updated docs to use Doxygen 1.2.8
//
// Revision 1.4  2001/05/24 15:38:08  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#ifndef quantlib_himalaya_h
#define quantlib_himalaya_h

#include "ql/date.hpp"
#include "ql/MonteCarlo/multifactorpricer.hpp"

namespace QuantLib {

    namespace Pricers {

        //! Himalayan-type option pricer
        /*! The payoff of a Himalaya option is computed in the following way:
            Given a basket of N assets, and N time periods, at end of
            each period the option who performed the best is added to the
            average and then discarded from the basket. At the end of the
            N periods the option pays the max between the strike and the
            average of the best performers.
        */
        class Himalaya : public MultiFactorPricer {
        public:
            Himalaya(const Array &underlying,
                const Array &dividendYield,
                const Math::Matrix &covariance,
                Rate riskFreeRate, double strike,
                const std::vector<Time> &timeDelays,
                long samples, long seed = 0);
        };

    }

}


#endif
