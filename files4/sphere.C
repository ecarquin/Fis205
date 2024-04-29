void sphere()
{
  auto rndm = new TRandom(0);
  auto rndm2 = new TRandom(0);

  UInt_t n=100000;
  
  float phi[100000]={0.0}, theta[100000]={0.0};

  float x[100000]={0.0}, y[100000]={0.0}, z[100000]={0.0};

  for(UInt_t i=0;i<=100000;i++){
    phi[i]=2*TMath::Pi()*rndm->Uniform();
    theta[i]=TMath::ACos(1-2*rndm2->Uniform());
    //cout << phi[i] << " " << theta[i] << std::endl;
    x[i]=TMath::Sin(theta[i])*TMath::Cos(phi[i]);
    y[i]=TMath::Sin(theta[i])*TMath::Sin(phi[i]);
    z[i]=TMath::Cos(theta[i]);
    float r = TMath::Sqrt(x[i]*x[i]+y[i]*y[i]+z[i]*z[i]);    
    if(r<(1.0-1E-6) or i<100) cout << setprecision(7) << r << endl;
  }

  auto c = new TCanvas("c","c");
  auto g=new TGraph2D(100000,x,y,z);

  g->SetMarkerStyle(20);
  g->Draw("pcol");
  //g->Draw("surf1");

  c->SaveAs("sphere.pdf");
  
}
