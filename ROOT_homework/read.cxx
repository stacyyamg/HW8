#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH2F.h>

void readTree() {
    // Open the ROOT file and get the TTree
    TFile *file = TFile::Open("tree_file.root");
    TTree *tree = (TTree*)file->Get("tree");

    // Use TTree::Draw to create the scatter plot with a condition on the magnitude of p
    TCanvas *c1 = new TCanvas("c1", "Histogram Canvas", 800, 600);
    tree->Draw("pz:px*py", "sqrt(px*px + py*py + pz*pz) < 0.1", "colz");
    c1->Update();
    c1->SaveAs("temp.png");

    // Clean up
    file->Close();
    delete file;
}