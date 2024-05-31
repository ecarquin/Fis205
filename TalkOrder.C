void TalkOrder()
{
  TRandom *rand=new TRandom3();

  rand->SetSeed(666);

  cout << rand->Uniform() << endl;

  vector<string> names = {"Amelie","Benjamin","Carlos","Constanza","Cristobal","Cristopher","Enzo","Francisco","Ignacia","Karime","Kevin","Marcelo","Matias","MatiasJ","Tomas"};

  vector<string> ordered_names;

  for(auto i: names) {
    cout << i << endl;
  }

  vector<int> values;
  
  while(ordered_names.size()<15)
  {
    float virtual_dice = floor(15*rand->Uniform());
    for(unsigned int i=0;i<15;i++)
    {
      if (virtual_dice == i)
	{
	  //cout << "virtual dice" << virtual_dice << endl;
	  bool skip=false;
	  for(auto v: values)
	    {
	      if(v == i) skip=true;
	    }
	  if(skip) continue;
	  ordered_names.push_back(names.at(i));
	  values.push_back(i);	  
	}
    }
    cout << "Size: " << ordered_names.size() << endl;
  }
  for(auto i: ordered_names) {
    cout << i << endl;
  }
} 
