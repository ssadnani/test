/*----------------------
   GATE version name: gate_v6

   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See GATE/LICENSE.txt for further details
----------------------*/



#ifndef GateVolumeMessenger_h
#define GateVolumeMessenger_h 1

#include "GateClockDependentMessenger.hh"

#ifdef GATE_USE_RTK
# include "rtkThreeDCircularProjectionGeometry.h"
# include "rtkThreeDCircularProjectionGeometryXMLFile.h"
#endif

class GateVVolume;

class GateVisAttributesMessenger;

class GateVolumeMessenger: public GateClockDependentMessenger
{
  public:
    GateVolumeMessenger(GateVVolume* itsCreator, const G4String& itsDirectoryName="");
    virtual ~GateVolumeMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);

    inline GateVVolume* GetVolumeCreator() 
      { return (GateVVolume*) GetClockDependent(); }

  private:
      
    GateVisAttributesMessenger*     pVisAttributesMessenger;
    
    G4UIcmdWithAString*             pSetMaterCmd;
    G4UIcmdWithoutParameter*        pAttachCrystalSDCmd;
    G4UIcmdWithoutParameter*        pAttachPhantomSDCmd;

    G4UIcmdWithAString *            pSetInputGeometryFilenameCmd;

};

#endif
