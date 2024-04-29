void gaussBM()
{
  auto rndm = new TRandom(0);
  auto rndm2 = new TRandom(0);

  UInt_t n=100000;
  
  float phi[100000]={0.0}, rho[100000]={0.0};

  float x[100000]={0.0}, y[100000]={0.0};

  auto hx= new TH1F("hx","",200,-2,2);
  auto hy= new TH1F("hy","",200,-2,2);

  for(UInt_t i=0;i<100000;i++){
    phi[i]=2*TMath::Pi()*rndm->Uniform();
    rho[i]=TMath::Sqrt(-1*TMath::Log(1-rndm2->Uniform()));
    //cout << rho[i] << " " << phi[i] << std::endl;
    x[i]=rho[i]*TMath::Cos(phi[i]);
    y[i]=rho[i]*TMath::Sin(phi[i]);
    hx->Fill(x[i]);
    hy->Fill(y[i]);
  }

  auto c = new TCanvas("c","c");
  
  hx->Draw();
  hx->SetLineColor(2);
  hy->SetLineColor(3);
  //c->SaveAs("hx.pdf");
  
  //c->Modified();
  //c->Update();

  hy->Draw("SAME");

  c->SaveAs("hy.pdf");
  
}
