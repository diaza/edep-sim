#ifndef EDepSim_UniformTimeGenerator_hh_seen
#define EDepSim_UniformTimeGenerator_hh_seen

#include <vector>

#include "kinem/EDepSimVTimeGenerator.hh"


namespace EDepSim {class UniformTimeGenerator;}
class EDepSim::UniformTimeGenerator : public EDepSim::VTimeGenerator {
public:
    UniformTimeGenerator(G4String name, double tmin, double tmax);
    virtual ~UniformTimeGenerator();

    /// Return the time of the event to be generated.
    double GetTime(const G4LorentzVector& vertex);


    virtual bool ForceTime();

private:
    double fTmax;
    double fTmin;
};
#endif
