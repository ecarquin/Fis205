const Int_t n_sample= 201000;
Double_t data_vector[n_sample];

Double_t f(Double_t *x,Double_t *par)
{
  Double_t a = par[0];
  Double_t b = par[1];
  Double_t c = par[2];
  Double_t d = par[3];
  Double_t e = par[4];

  Double_t exponential = TMath::Exp(-a*x[0])/a;
  //cout << "x[0]= " << x[0] << endl;
  //cout << "Exp: " << exponential << " " << a << endl;
  Double_t gaussian = TMath::Exp(-(x[0]-b)*(x[0]-b)/(2*c*c))/TMath::Sqrt(2*TMath::Pi()*c*c);
  //cout << "Gaus: " << (x[0]-b)*(x[0]-b)/(2*c*c) << " b: " << b << " c: " << c << " d " << d << " e" << e << endl;

  return d*exponential+e*gaussian;
}

void negative_log_likelihood(Int_t &npar, Double_t *gin, Double_t &nll, Double_t *par, Int_t iflag)
{
  Double_t sum=0;

  sum+=-par[3];
  sum+=-par[4];

  for (UInt_t i=0;i<n_sample;i++)
    {
      Double_t fi=f(&data_vector[i],par);
      //cout << fi << endl;
      sum +=  std::log(fi);
    }

  nll = -sum;

  //cout << nll << endl;
}


void exampleEMLFit()
{
  gRandom = new TRandom3();

  TH1D * hist = new TH1D("data_hist", ";x;N",100,2.5,3.5);

  //Fill in the histogram
  for(int i=0;i<1000;++i){
    Double_t rand = gRandom->Gaus(3.1,0.02); 
    hist->Fill(rand);
    data_vector[i]=rand;
  }

  //Fill in the histogram
  for(int i=0;i<200000;++i){
    Double_t rand = gRandom->Exp(1);
    hist->Fill(rand);
    data_vector[i+1000]=rand;
  }

  Int_t nPar = 5;
  TMinuit m(nPar);
  m.SetFCN(&negative_log_likelihood);
  m.SetPrintLevel(0);
  m.SetErrorDef(0.5);
  /*m.DefineParameter(0,"a",1.,0.0,0.95,2.0);
  m.DefineParameter(1,"b",3.1,0.0,2.5,3.5);
  m.DefineParameter(2,"c",0.02,0.0,0.01,0.025);
  m.DefineParameter(3,"d",1.,1e-2,1e+2,2e+3);
  m.DefineParameter(4,"e",5.,1e-2,1.,20.);*/

  //Good parameter set 1000
  m.DefineParameter(0,"a",1.,0.0,0.95,2.1);
  //m.DefineParameter(0,"a",1.1,0.01,0.95,2.1);
  m.DefineParameter(1,"b",3.0,1e-2,2.7,3.5);
  m.DefineParameter(2,"c",1.24,1e-2,0.01,5.);
  m.DefineParameter(3,"d",0.001,1e-2,1.,1e+6);
  m.DefineParameter(4,"e",1e+3,1e-2,0.95e+3,1e+4);

  /*Good parameter set 5000
  m.DefineParameter(0,"a",1.0,1e-2,1.,10.0);
  m.DefineParameter(1,"b",3.1,1e-2,2.5,3.5);
  m.DefineParameter(2,"c",0.015,1e-2,0.01,0.02);
  m.DefineParameter(3,"d",1.,1e-2,0.0,2e+3);
  m.DefineParameter(4,"e",10.,1e-2,0.0,51.);*/

  m.Migrad();
  m.Command("SHOW COV");

  Double_t a,a_err,b,b_err,c,c_err,d,d_err,e,e_err;
  m.GetParameter(0,a,a_err);
  m.GetParameter(1,b,b_err);
  m.GetParameter(2,c,c_err);
  m.GetParameter(3,d,d_err);
  m.GetParameter(4,e,e_err);     

  TF1 *tf = new TF1("tf","0.01*(gaus(0)/TMath::Sqrt(2*TMath::Pi()*[2]**2)+[4]*exp(-[3]*x)/[3])",2.5,3.5);
  
  tf->SetParameters(e,b,c,a,d);
  tf->SetLineColor(kBlue);

  
  TCanvas * c1= new TCanvas("c1", "random",5,5,800,600);
  hist->SetMarkerStyle(8);
  hist->Draw("HIST:E1:P");
  tf->Draw("SAME");
  c1->SaveAs("data.pdf");

  TCanvas * c2= new TCanvas("c2", "random",5,5,800,600);
  //c1->Modified();
  //c1->Clear();
  tf->Draw();
  
  
}
