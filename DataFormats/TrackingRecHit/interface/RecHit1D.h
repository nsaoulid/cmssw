#ifndef TrackingRecHit_RecHit1D_H
#define TrackingRecHit_RecHit1D_H

/** \class RecHit1D
 *
 * Base class for 1-dimensional recHits
 *  
 *
 * To be used as base class for all 1D positional TrackingRecHits.
 * The coordinate measured is assumend to be the local "x"
 *
 *  $Date: $
 *  $Revision: $
 *  \author S. Lacaprara, G. Cerminara
 */

#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "Geometry/Surface/interface/LocalError.h"
#include "Geometry/Vector/interface/LocalPoint.h"


class RecHit1D : public TrackingRecHit {
 public:

  /// Destructor
  virtual ~RecHit1D() {}


  /// Return just the x
  virtual AlgebraicVector parameters() const;


  /// Return just "(sigma_x)^2"
  virtual AlgebraicSymMatrix parametersError() const;


  ///Return the projection matrix
  virtual AlgebraicMatrix projectionMatrix() const {
    if ( !isInitialized) initialize();
    return theProjectionMatrix;
  }


  /// Return the RecHit dimension
  virtual int dimension() const {
    return 1;
  }


  /// Local position
  virtual LocalPoint localPosition() const = 0;


  /// Error on the local position
  virtual LocalError localPositionError() const = 0;


 private:

  static bool isInitialized;

  static AlgebraicMatrix theProjectionMatrix;

  void initialize() const;

};
#endif





