//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: LXeRunAction.cc 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/LXe/src/LXeRunAction.cc
/// \brief Implementation of the LXeRunAction class
//
//
#include "LXeRunAction.hh"
#include "LXeRecorderBase.hh"
#include "LXeAnalysis.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeRunAction::LXeRunAction(LXeRecorderBase* r) : fRecorder(r) {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeRunAction::~LXeRunAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::BeginOfRunAction(const G4Run* aRun){
  if(fRecorder)fRecorder->RecordBeginOfRun(aRun);

  //G4AnalysisManager* man = G4AnalysisManager::Instance();
  G4AnalysisManager* man2 = G4AnalysisManager::Instance();

  //man->OpenFile("tuples");
  man2->OpenFile("histo");

  man2->CreateH1("0","PMT 1", 100, 0., 1000);
  man2->CreateH1("1","PMT 2", 100, 0., 1000);
  //man->CreateH1("2","PMT 3", 100, 0., 1000);
  //man->CreateH1("3","PMT 4", 100, 0., 1000);
  man2->CreateH1("3","Energy Deposition", 100, 4., 10*MeV);
  man2->CreateH1("4","Ratio",100,0,2);

  //man->CreateNtuple("LXe","PMTs");
  //man->CreateNtupleDColumn("0");
  //man->CreateNtupleDColumn("1");
  //man->CreateNtupleDColumn("PMT 3");
  //man->CreateNtupleDColumn("PMT 4");
  //man->CreateNtupleDColumn("Energy Deposition");
  //man->CreateNtupleDColumn("Ratios");
  //man->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::EndOfRunAction(const G4Run* aRun){
  if(fRecorder)fRecorder->RecordEndOfRun(aRun);
  G4cout << 1 << G4endl;
  //G4AnalysisManager* man = G4AnalysisManager::Instance();
  G4AnalysisManager* man2 = G4AnalysisManager::Instance();
  //man->Write();
  man2->Write();
  //man->CloseFile();
  man2->CloseFile();
}
