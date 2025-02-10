#include "kinem/EDepSimVTimeGenerator.hh"
#include "kinem/EDepSimUniformTimeGenerator.hh"

#include <G4PhysicalConstants.hh>
#include <Randomize.hh>

EDepSim::UniformTimeGenerator::UniformTimeGenerator(
    G4String name, double tmin, double tmax)
    : EDepSim::VTimeGenerator(name), fTmin(tmin), fTmax(tmax) {}

EDepSim::UniformTimeGenerator::~UniformTimeGenerator() {}

double EDepSim::UniformTimeGenerator::GetTime(const G4LorentzVector& /* vtx */) {
    // Generate a uniform time 
    double time = (G4UniformRand() * (fTmax -fTmin) + fTmin);
    return time;
}

bool EDepSim::UniformTimeGenerator::ForceTime() {
    return true;
}
