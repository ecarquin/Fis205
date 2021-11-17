#include "TRandom2.h"
#include "TGraph.h"
#include "TCanvas.h"

#include <iostream>
#include <iomanip>

//using namespace std;

void Pi(){

  double Pi=0;
  long long N=100000;
  TRandom3 *r1=new TRandom3(1);
  TRandom3 *r2=new TRandom3(20);

  TCanvas *c1=new TCanvas("c1","My Canvas",800,600);

  long long int i=0;

  long long int Acc=0;

  long long int n = 0;

  TGraph *g2=new TGraph();
  TGraph *g1=new TGraph();

  while(i<N){
    
    double x=r1->Rndm();
    double y=r2->Rndm();
    double radius=sqrt(x*x+y*y);
    
    if(radius<1.0) {Acc++;
      g1->SetPoint(g1->GetN(),x,y);
    }
    i++;
    if(4*float(Acc)/float(i)<4. && 4*float(Acc)/float(i)>2.5)
    {
      g2->SetPoint(g2->GetN(),i,4*float(Acc)/float(i));
    }
    if(i%10000==0) std::cout << std::setprecision(20) << "Accepted points: " << Acc << " Pi: "<< 4*Acc/float(i) << " error: " << pow(i,-0.5) << std::endl;
  } 

  c1->Draw();
  g1->Draw("AC*");

  c1->SaveAs("AcceptedEvents.png");

  c1->Update();
  c1->Clear();

  TLine *l=new TLine(1.0,TMath::Pi(),100000,TMath::Pi());

  TLegend *leg=new TLegend(0.5,0.3,0.8,0.5);
  
  g2->GetHistogram()->SetMaximum(3.5);
  g2->GetHistogram()->SetMinimum(2.9);
  g2->GetHistogram()->GetXaxis()->SetTitle("Number of iteration");
  g2->GetHistogram()->GetYaxis()->SetTitle("arb.units");
  g2->SetMarkerStyle(kFullCircle);
  g2->SetMarkerSize(0.4);
  g2->Draw();
  leg->AddEntry(g2,"#pi estimations");
  leg->AddEntry(l,"#pi real number");
  l->SetLineColor(kRed);
  l->Draw();
  leg->Draw();
  c1->SetLogx();
  c1->SaveAs("Pi.png");
  
 
}
