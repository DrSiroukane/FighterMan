#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void voir_la_vision(int i,int j,int k,char** matrice)
{
  int d1=i+k/2;
  int d2=j+k/2;
  int l=i-k/2;
  int m=j-k/2;
  int c=0;
  int i1;
  int j1;

  for (i1 = l; i1 <= d1; ++i1)
  {
    for (int j1 = m; j1 <= d2; ++j1)
    {
     // cout<<matrice[i1][j1]<<'\n';
      cout <<i1<<'\n';
      cout <<j1<<'\n';
    }
    
    c++;
  }
  cout<<c<<'\n';
}


int main () {
  string line;
  ifstream myfile ("stage2.txt");
  char **matrice=new char* [100];
  int i=0;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      char * writable = new char[line.size() + 1];
      copy(line.begin(), line.end(), writable);
      writable[line.size()] = '\0'; 
      matrice[i]=writable;
      //cout<<writable<<'\n';
     // cout<<matrice[i]<<'\n';
      i++;

    }

    myfile.close();
    matrice[0][0]='>';
    for (int i1 = 0; i1 < i; ++i1)
    {
      cout<<matrice[i1]<<'\n';
    }
        
    cout<<"donne nous la vision"<<'\n';
    
    char myChar  = {0};
    char myChar1 = {0};
    string input = "";
    while (true) {
      cout << "Please enter 1 char: ";
      getline(cin, input);

      if (input.length() == 1) {
        myChar = input[0];
        cout<<myChar<<'\n';
        break;
        cout << "Invalid character, please try again" << endl;
      }
  }
  if ((myChar=='d')||(myChar=='q')||(myChar=='s')||(myChar=='d'))
      {
        cout<<"vous avez choisis une direction"<<endl;
        cout << "si vous vouler marcher envers cette direction repeter le meme char " <<input<< endl;
        while (true) {
      cout << "maintenant voulez vous confirmer: ";
      
      
      getline(cin, input);
      if (input.length() == 1) {
        myChar1 = input[0];
        cout<<myChar1<<'\n';
        break;
        cout << "Invalid character, please try again" << endl;
      }
      
  }
  }
  if (int(myChar1)==int(myChar))
      {
        cout << "Vous vouler continuer par cette direction" << endl;
      }
  voir_la_vision(3,3,3,matrice);
  //cout << matrice[3][3] ;cout<< matrice[3][4]<< endl;
  }




  else cout << "Unable to open file"; 
  return 0;
}