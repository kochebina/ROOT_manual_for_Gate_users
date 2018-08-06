//to run: root -l  AddShiftedEnergy.C
void AddShiftedEnergy() {

  //Shifts for each of detection heads
  Float_t delta0=0.05; //in MeV
  Float_t delta1=0.07;
  Float_t delta2=0.25;
  Float_t delta3=0.15;

  //Input file definition
  TString path = "";
  TString fname_tmp ="YourOutputFile";


  TString fname;
  fname=path+fname_tmp+".root";
  
  TFile *input = TFile::Open(fname);
   if (!input) {
     cout << "ERROR: could not open data file: " << fname << endl;
     exit(1);
   }

   //Input tree definition
   TString tupleName;
   tupleName="Singles";
   
   TTree* theTree = (TTree*)input->Get(tupleName);
   cout<< theTree->GetEntries()<<endl;

   theTree->SetBranchStatus("*",0);

   theTree->SetBranchStatus("runID",1);
   theTree->SetBranchStatus("eventID",1);
   theTree->SetBranchStatus("sourceID",1);
   theTree->SetBranchStatus("sourcePosX",1);
   theTree->SetBranchStatus("sourcePosY",1);
   theTree->SetBranchStatus("sourcePosZ",1);
   theTree->SetBranchStatus("time",1);
   theTree->SetBranchStatus("energy",1);
   theTree->SetBranchStatus("globalPosX",1);
   theTree->SetBranchStatus("globalPosY",1);
   theTree->SetBranchStatus("globalPosZ",1);
   theTree->SetBranchStatus("headID",1);
   theTree->SetBranchStatus("crystalID",1);
   theTree->SetBranchStatus("pixelID",1);
   theTree->SetBranchStatus("unused3ID",1);
   theTree->SetBranchStatus("unused4ID",1);
   theTree->SetBranchStatus("unused5ID",1);
   theTree->SetBranchStatus("comptonPhantom",1);
   theTree->SetBranchStatus("comptonCrystal",1);
   theTree->SetBranchStatus("RayleighPhantom",1);
   theTree->SetBranchStatus("RayleighCrystal",1);
   theTree->SetBranchStatus("axialPos",1);
   theTree->SetBranchStatus("rotationAngle",1);
   theTree->SetBranchStatus("comptVolName",1);
   theTree->SetBranchStatus("RayleighVolName",1); 




   //Prepare output file
   TString targetName=path+fname_tmp+"_Singles_energyshift.root";
   TFile*target=new TFile(targetName,"recreate");
 
   //Copy the input tree into the output file
   TTree *tempTree=new TTree("tempTree","tempTree");
   tempTree=theTree->CloneTree(0); 
   cout<<tempTree->GetEntries()<<endl; 

   tempTree->GetBranch("runID")->SetFile(targetName);
   tempTree->GetBranch("eventID")->SetFile(targetName);
   tempTree->GetBranch("sourceID")->SetFile(targetName);
   tempTree->GetBranch("sourcePosX")->SetFile(targetName);
   tempTree->GetBranch("sourcePosY")->SetFile(targetName);
   tempTree->GetBranch("sourcePosZ")->SetFile(targetName);
   tempTree->GetBranch("time")->SetFile(targetName);
   tempTree->GetBranch("energy")->SetFile(targetName);
   tempTree->GetBranch("globalPosX")->SetFile(targetName);
   tempTree->GetBranch("globalPosY")->SetFile(targetName);
   tempTree->GetBranch("globalPosZ")->SetFile(targetName);
   tempTree->GetBranch("headID")->SetFile(targetName);
   tempTree->GetBranch("crystalID")->SetFile(targetName);
   tempTree->GetBranch("pixelID")->SetFile(targetName);
   tempTree->GetBranch("unused3ID")->SetFile(targetName);
   tempTree->GetBranch("unused4ID")->SetFile(targetName);
   tempTree->GetBranch("unused5ID")->SetFile(targetName);
   tempTree->GetBranch("comptonPhantom")->SetFile(targetName);
   tempTree->GetBranch("comptonCrystal")->SetFile(targetName);
   tempTree->GetBranch("RayleighPhantom")->SetFile(targetName);
   tempTree->GetBranch("RayleighCrystal")->SetFile(targetName);
   tempTree->GetBranch("axialPos")->SetFile(targetName);
   tempTree->GetBranch("rotationAngle")->SetFile(targetName);
   tempTree->GetBranch("comptVolName")->SetFile(targetName);
   tempTree->GetBranch("RayleighVolName")->SetFile(targetName); 

   tempTree->CopyEntries(theTree, -1, "fast");

   //Define used variables from the input tree
   Float_t energy;
   Int_t headID;

   //Define used branches from the input tree
   TBranch *benergy;
   TBranch *bheadID;
  
   tempTree->SetBranchAddress( "energy"      , &energy,&benergy);
   tempTree->SetBranchAddress( "headID"      , &headID,&bheadID);
   
   //Define new variable and new branch. 
   //In last argument use "/F" for float and "/D" for integer variables
   Float_t energy_shifted;
   TBranch *Benergy_shifted = tempTree-> Branch("energy_shifted",&energy_shifted,"energy_shifted/F");
   
   Float_t energy_temp;
   Int_t nev=tempTree->GetEntries();

   //Loop over events
   for (Long64_t ievt=0; ievt<nev;ievt++) {
     
     if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;
     
     tempTree->GetEntry(ievt);
      
     benergy->GetEntry(ievt);
     bheadID->GetEntry(ievt);
     
      
     //Chech the head ID and assing the corresponging shift
     if(headID==0)
       {
	 energy_temp=energy+delta0;
       }
     
     if(headID==1)
       {
	 energy_temp=energy+delta1;
       }
     
     if(headID==2)
       {
	 energy_temp=energy+delta2;
       }
     
     if(headID==3)
       {
       energy_temp=energy+delta3;
       }
     
     //Fill new branch
     energy_shifted=energy_temp;
     Benergy_shifted->Fill();

   }
   
   //Write tree
   tempTree->Write();

}
