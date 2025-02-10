#include "kinem/EDepSimVTimeFactory.hh"
#include "kinem/EDepSimUniformTimeFactory.hh"
#include "kinem/EDepSimUniformTimeGenerator.hh"

EDepSim::UniformTimeFactory::UniformTimeFactory(
    EDepSim::UserPrimaryGeneratorMessenger* parent) 
    : EDepSim::VTimeFactory("uniform",parent), 
    fTmax(1.),
    fTmin(0.) {

    fTmaxCMD = new G4UIcmdWithADoubleAndUnit(CommandName("tmax"),this);
    fTmaxCMD->SetGuidance("Set the tmax of events to generate.");
    fTmaxCMD->SetParameterName("time",false);
    fTmaxCMD->SetUnitCategory("Time");

    fTminCMD = new G4UIcmdWithADoubleAndUnit(CommandName("tmin"),this);
    fTminCMD->SetGuidance("Set the tmin of events to generate.");
    fTminCMD->SetParameterName("time",false);
    fTminCMD->SetUnitCategory("Time");

}

EDepSim::UniformTimeFactory::~UniformTimeFactory() {
    delete fTmaxCMD;
    delete fTminCMD;
}

void EDepSim::UniformTimeFactory::SetNewValue(G4UIcommand* command,
                                           G4String newValue) {
    if (command == fTmaxCMD) {
        SetTmax(fTmaxCMD->GetNewDoubleValue(newValue));
    }
    else if (command == fTminCMD){
        SetTmin(fTminCMD->GetNewDoubleValue(newValue));
    }


}

EDepSim::VTimeGenerator* EDepSim::UniformTimeFactory::GetGenerator() {
    EDepSim::VTimeGenerator* time = new EDepSim::UniformTimeGenerator(GetName(),
                                                            fTmin, fTmax);
    return time;
}
