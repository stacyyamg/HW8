#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include "DATA.h"  // Include your DATA class header file

void writeToTree() {  
    DATA *myObject = new DATA();
    TFile *file = new TFile("tree_file.root", "RECREATE");
    TTree *tree = new TTree("tree", "A tree with momentum data");
    tree->Branch("branch", "DATA", &myObject);

    Int_t nEvents = 1000;
    for (Int_t i {0}; i < nEvents; ++i) {
        myObject->px = gRandom->Gaus(0, 0.02);
        myObject->py = gRandom->Gaus(0, 0.02);
        myObject->pz = gRandom->Gaus(0, 0.02);
        tree->Fill();
    }

    tree->Write();
    file->Close();
    delete myObject;
}
