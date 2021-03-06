/***************************************************************************
 * Copyright (C) gempa GmbH                                                *
 * Contact: gempa GmbH (seiscomp-dev@gempa.de)                             *
 *                                                                         *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 ***************************************************************************/


#ifndef SEISCOMP_FDSNXML_DATAAVAILABILITY_H
#define SEISCOMP_FDSNXML_DATAAVAILABILITY_H


#include <fdsnxml/metadata.h>
#include <fdsnxml/dataavailabilityextent.h>
#include <vector>
#include <seiscomp/core/baseobject.h>
#include <seiscomp/core/exceptions.h>


namespace Seiscomp {
namespace FDSNXML {

DEFINE_SMARTPOINTER(DataAvailabilitySpan);



DEFINE_SMARTPOINTER(DataAvailability);


/**
 * \brief A description of time series data availability. This information
 * \brief should be considered transient and is primarily useful as a guide
 * \brief for generating time series data requests. The information for a
 * \brief DataAvailability:Span may be specific to the time range used in a
 * \brief request that resulted in the document or limited to the
 * \brief availability of data withing the request range. These details may
 * \brief or may not be retained when synchronizing metadata between data
 * \brief centers.
 */
class DataAvailability : public Core::BaseObject {
	DECLARE_CASTS(DataAvailability);
	DECLARE_RTTI;
	DECLARE_METAOBJECT_DERIVED;

	// ------------------------------------------------------------------
	//  Xstruction
	// ------------------------------------------------------------------
	public:
		//! Constructor
		DataAvailability();

		//! Copy constructor
		DataAvailability(const DataAvailability &other);

		//! Destructor
		~DataAvailability();


	// ------------------------------------------------------------------
	//  Operators
	// ------------------------------------------------------------------
	public:
		//! Copies the metadata of other to this
		DataAvailability& operator=(const DataAvailability &other);
		bool operator==(const DataAvailability &other) const;


	// ------------------------------------------------------------------
	//  Setters/Getters
	// ------------------------------------------------------------------
	public:
		//! XML tag: Extent
		void setExtent(const OPT(DataAvailabilityExtent)& extent);
		DataAvailabilityExtent& extent();
		const DataAvailabilityExtent& extent() const;

	
	// ------------------------------------------------------------------
	//  Public interface
	// ------------------------------------------------------------------
	public:
		/**
		 * Add an object.
		 * @param obj The object pointer
		 * @return true The object has been added
		 * @return false The object has not been added
		 *               because it already exists in the list
		 *               or it already has another parent
		 */
		bool addSpan(DataAvailabilitySpan *obj);

		/**
		 * Removes an object.
		 * @param obj The object pointer
		 * @return true The object has been removed
		 * @return false The object has not been removed
		 *               because it does not exist in the list
		 */
		bool removeSpan(DataAvailabilitySpan *obj);

		/**
		 * Removes an object of a particular class.
		 * @param i The object index
		 * @return true The object has been removed
		 * @return false The index is out of bounds
		 */
		bool removeSpan(size_t i);

		//! Retrieve the number of objects of a particular class
		size_t spanCount() const;

		//! Index access
		//! @return The object at index i
		DataAvailabilitySpan* span(size_t i) const;


	// ------------------------------------------------------------------
	//  Implementation
	// ------------------------------------------------------------------
	private:
		// Attributes
		OPT(DataAvailabilityExtent) _extent;

		// Aggregations
		std::vector<DataAvailabilitySpanPtr> _spans;
};


}
}


#endif
