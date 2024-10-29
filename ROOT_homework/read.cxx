#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <iostream>
#include "DATA.h"  // Ensure DATA.h defines px, py, pz as public members

void drawPxPyHistogram() {
    // Step 1: Initialize a DATA object to hold the data from each entry
    DATA *myObject = new DATA();

    // Step 2: Open the ROOT file that contains the TTree
    TFile *file = new TFile("tree_file.root", "READ");
    if (!file->IsOpen()) {
        std::cerr << "Error: Could not open file tree_file.root" << std::endl;
        return;
    }

    // Step 3: Retrieve the TTree from the file
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cerr << "Error: Could not find TTree 'tree' in file" << std::endl;
        file->Close();
        return;
    }

    // Step 4: Set the branch address to read data into the myObject pointer
    tree->SetBranchAddress("branch", &myObject);

    // Step 5: Create a 2D histogram to fill with px and py values
    TH2F *hist = new TH2F("hist", "px vs py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    // Step 6: Loop over the entries in the tree and fill the histogram
    Int_t nEntries = tree->GetEntries();
    for (Int_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);  // Load the i-th entry into myObject

        // Fill the histogram with px and py values
        hist->Fill(myObject->px, myObject->py);
    }

    // Step 7: Draw the histogram to visualize px vs py
    hist->Draw("COLZ");  // Draw as a colored 2D plot

    // Clean up
    delete myObject;
    file->Close();
}