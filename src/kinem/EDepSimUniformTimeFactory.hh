#ifndef EDepSim_UniformTimeFactory_hh_seen
#define EDepSim_UniformTimeFactory_hh_seen

#include "kinem/EDepSimVTimeFactory.hh"

namespace EDepSim {class UniformTimeFactory;}
class EDepSim::UniformTimeFactory : public EDepSim::VTimeFactory {
public:
    UniformTimeFactory(EDepSim::UserPrimaryGeneratorMessenger* parent);
    virtual ~UniformTimeFactory();

    /// Return the fixed time generator.
    EDepSim::VTimeGenerator* GetGenerator();

    /// Set the time to be generated.
    void SetTmax(double tmax) {fTmax = tmax;}
    
    // Set tmin of time interval
    void SetTmin(double tmin) {fTmin = tmin;}

    /// Handle messages from the UI processor.
    void SetNewValue(G4UIcommand*, G4String);

private:
    /// The time of particles to generate.
    double fTmax;
    double fTmin;

    G4UIcmdWithADoubleAndUnit* fTmaxCMD;    
    G4UIcmdWithADoubleAndUnit* fTminCMD;
};

#endif
