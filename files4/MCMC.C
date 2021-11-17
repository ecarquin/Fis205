#include <iomanip>
#include <iostream>
#include <TRandom3.h>

double findmin(double x, double y)
{
  return x < y ? x : y; 
}

void MCMC()
{
  //Simple example of the Metropolis-Hastings Algorithm

  //Define our target function (the function we want to sample)

  TF1 *rho = new TF1("r","gaus(0)+gaus(3)",-5.,5.);
  rho->SetParameter(0,1.);
  rho->SetParameter(1,-1.0);
  rho->SetParameter(2,0.5);
  rho->SetParameter(3,1.5);
  rho->SetParameter(4,2.5);
  rho->SetParameter(5,1.0);

  cout << rho->Integral(-10,10) << endl;

  TCanvas *c1 = new TCanvas("c1","Target function",800,600);

  c1->Draw();
  rho->Draw();

  //Define our proposal distribution as a normal distribution
  TF1 *pro = new TF1("p","gaus(0)",-5,5);
  pro->SetParameter(0,1/sqrt(2*TMath::Pi()));
  pro->SetParameter(1,1.0);
  pro->SetParameter(2,3.0);
  pro->SetLineColor(kBlue);
  
  pro->Draw("same");
  TRandom3 *r1 = new TRandom3(0);
  TRandom3 *r2 = new TRandom3(10);
  TRandom3 *r3 = new TRandom3(20);
  
  //We start from a random number in this case
  double x00; for(UInt_t j=0;j<10;j++) x00=r1->Rndm();
  //double x00=0.;
  double x0 = pro->Eval(x00);

  //Define a histogram to store our sampled points
  TH1F *h = new TH1F("h","Sampled distro",50,-5.,5.);

  //Define a histogram to store our sampled points                                                 
  TH1F *p = new TH1F("p","Sample proposal",50,-5.,5.);

  //N trials
  int N = 10000000;
  
  //Let's define a counter for the number of accepted events
  int acc = 0;

  //A TGraph for visualization 
  TGraph *g = new TGraph(); 

  for(UInt_t i = 0; i<N; i++)
  {
     //We generate a value distributed according to our proposal distribution
     //In our case this is a Normal distribution
     double x1 = pro->GetRandom();
     //double x1 = r3->Gaus(x0);
     p->Fill(x1);

     //We evaluate the following probability such that  
     double xi = findmin(1.,rho->Eval(x1)/rho->Eval(x0));

     //cout << " Rho(X'): " << rho->Eval(x1) << endl;
     //cout << " Rho(X): " << rho->Eval(x0) << endl;

     //cout << "x0: " << x0 << " x1: " << x1 << " xi: " << xi << " Rho(X')/Rho(X): " << rho->Eval(x1)/rho->Eval(x0) << endl; 

     bool accept=false;
     //If xi=1 we always accept the state (x1), otherwise we accept it with probability xi
     if(xi>=1.) accept = true;
     else {
       double rand = r2->Rndm();
       //cout << "Throwing a random number: " << rand << endl;
       if(xi>rand) accept = true; 
     }
     
     if(accept){
       //cout << "The state was accepted" << endl;
       h->Fill(x1);
       x0=x1;
       acc++;
       g->SetPoint(g->GetN(),i,x1);
     }//else
       //cout << " The state was rejected, reusing the old state " << endl;     

  }

  cout << std::setprecision(3) << "Acceptance rate is: " << acc/(float)N << endl;

  h->Scale(5*rho->Integral(-5,5)/h->Integral());
  h->Draw("same");
  p->SetLineColor(kGreen);
  p->Scale(1/p->Integral());
  p->Draw("same");

  c1->SaveAs("Distros.png");

  c1->Clear();
  c1->Modified();

  g->Draw();
  c1->SaveAs("Trials.png");
}
