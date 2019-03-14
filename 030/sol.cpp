
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int trapedVolume(std::vector<int> &elevations){
  int lm;
  int rm;
  int trapped = 0;
  for (int i=0; i<elevations.size(); i++){
    lm  = *std::max_element(elevations.begin(), elevations.begin()+i+1);
    rm = *std::max_element(elevations.end()-elevations.size()+i, elevations.end());
    // cout << "LM " << lm << " RM " << rm << " ELEV " << elevations[i] << endl;
    trapped = trapped + std::min(lm, rm) - elevations[i];
  }
  return trapped;
}

int main(){
  std::vector<int> elevations;
  elevations = {2, 1, 2};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  elevations  = {3, 0, 1, 3, 0, 5};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  elevations  = {0, 0, 1, 3, 0, 5};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  return 1;
}
