#include <iostream>
#include <fstream>

using namespace std;

ifstream in("duom.txt");
ofstream out("rez.txt");

int numberInFile ();
void readLetters(char ArrayChars[], int amountChar);
void orderArray(char ArrayChars[], int amountChar);
void deleteChars (char ArrayChars[], int amountChar, int &amountNumber);
void equalChars (char ArrayChars[], char ArrayChars1[], int ArrayChars2[], int amountChar, int amountNumber);
int minNum(int ArrayChars2[], int amountNumber);
void printText(char ArrayChars[], char ArrayChars1[], int ArrayChars2[], int amountChar, int amountNumber, int mini);
void printArray(char ArrayChars1[], int amountChar);

int main(){
    int amountChar;
    int mini=0;
    int amountNumber;
    amountChar = numberInFile();
    char ArrayChars[amountChar];
    char ArrayNumber [amountChar];
    char ArrayChars1[amountChar];

    readLetters(ArrayChars, amountChar);
    orderArray(ArrayChars, amountChar);
    deleteChars (ArrayChars, amountChar, amountNumber);
    int ArrayChars2[amountNumber];
    readLetters(ArrayChars1, amountChar);
    equalChars (ArrayChars, ArrayChars1, ArrayChars2, amountChar, amountNumber);
    mini=minNum(ArrayChars2, amountNumber);
   // cout<<mini<<"maziausias";
    printArray(ArrayChars1, amountChar);
    printText(ArrayChars, ArrayChars1, ArrayChars2, amountChar, amountNumber, mini);


  in.close();
  out.close();

return 0;
}

int numberInFile (){
  int amount(0);
  char oneSymbol;
  while(in.get(oneSymbol)){
    amount++;
  }
    in.seekg(0);
    in.close();
    return amount;
}

void readLetters(char ArrayChars[], int amountChar){
    char oneSymbol;
    in.open("duom.txt");
    for (int i=0; i<amountChar;i++){
           in.get(oneSymbol);
           ArrayChars[i]=oneSymbol;

    }
     in.seekg(0);
     in.close();
}

void orderArray(char ArrayChars[], int amountChar){
    int mini;
    int temp;
    for (int i=0;  i<amountChar-1;i++){
            mini = i;
            for (int j=i+1; j<amountChar;j++){
                if (ArrayChars[mini]>ArrayChars[j]) {
                    mini=j;
                    }
                temp = ArrayChars[mini]; //
                ArrayChars[mini] = ArrayChars[i];
                ArrayChars[i] = temp;
            }
    }
}

void deleteChars (char ArrayChars[], int amountChar, int &amountNumber){
amountNumber=0;
 for(int i=0; i<amountChar; i++)
        {
            if(ArrayChars[i]==ArrayChars[i-1] || ArrayChars[i]==' ')
                {
                    for(int j=i+1; j<amountChar; j++)
                        {
                            ArrayChars[j-1] = ArrayChars[j];
                        }
                     amountChar--;
                     i--;
                }
        }

   for (int i=0;  i<amountChar;i++){
       // cout<<ArrayChars[i]<<" ";
        amountNumber++;
    }
    // cout<<amountNumber<<" ";
}

void equalChars (char ArrayChars[], char ArrayChars1[], int ArrayChars2[], int amountChar, int amountNumber){

            int numb=0;
          for (int i=0;  i<amountNumber;i++){
                for (int j=0;  j<amountChar;j++){
                    if(ArrayChars[i]==ArrayChars1[j]){
                    numb++;
                    }
                }
            ArrayChars2[i] = numb;
            numb=0;
          }
}

int minNum(int ArrayChars2[], int amountNumber){
    int mini = ArrayChars2[0];
    for (int i=0;  i<amountNumber;i++){
        if (mini>ArrayChars2[i]){
            mini=ArrayChars2[i];
        }
        }


return mini;
}


void printText(char ArrayChars[], char ArrayChars1[], int ArrayChars2[], int amountChar, int amountNumber, int mini){

for (int i=0; i<amountNumber; i++){
    if (mini==ArrayChars2[i]){
        int j=i;
        for(int i=0; i<amountChar;i++){

          if (ArrayChars[j]==ArrayChars1[i]){
            ArrayChars1[i]='*';
            out<<ArrayChars[j]<<" ";
          }
        }
    }
}

    out<<endl<<"kartojasi "<<mini<<" kartu"<<endl;
    for (int i=0; i<amountChar; i++){
        out<<ArrayChars1[i];
    }
    cout<<"ok";
}

void printArray(char ArrayChars1[], int amountChar){
    out<<"Pradinis tekstas: ";
    for (int i=0; i<amountChar; i++){
       out<<ArrayChars1[i];
    }
    out<<endl;
}
