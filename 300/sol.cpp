
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <string>

void generate_vote(std::string file, int num_candidates, int total_votes){
  std::ofstream writer(file);
  std::srand(std::time(nullptr)); //seed by curr. time
  for (int i=0; i<total_votes; i++){
    int voter = rand();
    int cand = rand()%num_candidates;
    writer << voter << ' ' << cand << '\n';
  }
  writer.close();
}

class VoteCounter{
  int num_candidates;
  std::unordered_set<int> voters_already_counted;
  std::unordered_map<int,int> leaderBoard;
public:
  VoteCounter(int n): num_candidates(n){}

  void process(std::string file){
    std::ifstream reader(file);
    std::string line;
    int voter, cand;
    while (std::getline(reader, line)){
      // std::cout << line << '\n';
      std::stringstream st(line);
      st >> voter; st >> cand;
      if (voters_already_counted.find(voter) != voters_already_counted.end()){
        std::cout << "Voter ID " << voter << "has already voted.\n";
        continue;
      }
      voters_already_counted.insert(voter);
      vote
    }

  }

  void topThree(){
    //
  }
};


int main(){
  generate_vote("voting_machine.txt", 10, 100000);
  VoteCounter counter(5);
  counter.process("voting_machine.txt");
  return 0;
}
