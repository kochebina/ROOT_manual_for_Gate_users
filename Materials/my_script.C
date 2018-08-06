void my_script() {
  //remove the stat from upper right corner
  gStyle->SetOptStat(0);
  //remove the title
  gStyle->SetOptTitle(0);
  //define fonts sizes
  gStyle->SetTextSize(0.06);
  gStyle->SetLabelSize(0.06,"x");
  gStyle->SetLabelSize(0.06,"y");
  gStyle->SetLabelSize(0.06,"z");
  gStyle->SetTitleSize(0.06,"x");
  gStyle->SetTitleSize(0.05,"y");
  gStyle->SetTitleSize(0.06,"z");
  //define number of divisions on any axis, here is done only for "Y"
  gStyle->SetNdivisions(505,"y");
  gStyle->SetLineWidth(3);

  //define your ROOT file name
  TString filename = "YourOutputFile.root";
  // open the file
  TFile *f = TFile::Open(filename);
  // get the TTree
  TTree *Tree = (TTree*)f->Get("Singles");
  // define the variable(s) of interest, type of variable must be respected
  Float_t energy;
  // define the branch(s) of interest
  TBranch *benergy;
  // Set branch address
  Tree->SetBranchAddress( "energy", &energy, &benergy);
  // Get number of events in the TTree
  const int n=(const int)Tree->GetEntries();
  // Define a histogram with 100 bins, on x from 0 to 0.3
  TH1F* h = new TH1F("h","h",100,0,0.3);
  // Loop over events
  for(int i=0;i<n;i++)
    {
      //get event i
      Tree->GetEntry(i);
      benergy->GetEntry(i);
      //print out the values
      cout<<i<<" "<<energy<<endl;
      //fill histogram
      h->Fill(energy);
    }

  //Define canvas
  TCanvas *can = new TCanvas("can","can",800,600);
  //Define paramters of the canvas
  can->SetFillColor(0);
  can->SetBorderMode(0);
  can->SetBorderSize(3);
  can->SetBottomMargin(0.14);
  can->SetLeftMargin(0.16);
  can->SetFrameBorderMode(0);
  can->SetFrameLineWidth(3);
  can->SetFrameBorderMode(0);

  //Define parameters of the histogram
  h->SetLineWidth(2);
  h->SetLineColor(2);
  h->GetXaxis()->SetTitle("Energy, MeV");
  h->GetYaxis()->SetTitleOffset(1.6); 
  h->GetYaxis()->SetTitle("Arbitrary units");   
  //Draw histogram
  h->Draw();
  //Save cancas as .pdf
  can->SaveAs("energy.pdf");
}
