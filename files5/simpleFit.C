void simpleFit()
{
  gRandom = new TRandom3();

  TH1D * hist = new TH1D("data_hist", ";x;N",100,2.5,3.5);

  //Fill in the histogram                                                                                                                      
  for(int i=0;i<5000;++i){
    Double_t rand = gRandom->Gaus(3.1,0.02);
    hist->Fill(rand);
  }

  hist->Fit("gaus");
  TCanvas * c1= new TCanvas("c1", "random",5,5,800,600);
  hist->Draw();
  
}
