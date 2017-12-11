#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void countSort(int Data[], int dataSize);

int main()
{
    ifstream fin;

    fin.open("inputData.txt");

    if (fin.fail()){
        cout << "Input file failed to open." <<endl;
        exit(1);
    }else{
        cout << "Input file opened successfully!" <<endl;
    }

    int dataSize;
    fin >> dataSize;

    int Data[dataSize];

    int i = 0;
    while (!fin.eof()){
        fin >> Data[i];
        i++;
    }

    countSort(Data, dataSize);

    fin.close();

    return 0;
}

void countSort(int Data[], int dataSize){

    ofstream fout1;
    ofstream fout2;

    fout1.open("countData.txt");
    fout2.open("sortedData.txt");

    int count[100] = {0};

    for (int i=0; i<dataSize; i++){
        count[Data[i]]++;
    }

    for (int i=0; i<100; i++){
        fout1 << count[i] << " ";
    }

    for (int j=0; j<=100; j++){
        int count_j = count[j];
        for (int l=0; l<count_j; l++){
            fout2 << j << " ";
        }
    }

    fout1.close();
    fout2.close();
}
