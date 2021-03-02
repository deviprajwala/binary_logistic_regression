#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

float male_having_honour = 0, male_not_having_honour = 0, female_having_honour = 0, female_not_having_honour = 0, total_female, total_male, B0, B1, probability;
void read_record( string data_name, vector < vector < int > > &matrix ) 
//read the Data from the file as String Vector
{ 
    ifstream fin;
    string line;
    int idx=0;

    fin.open(data_name);

    while(getline(fin, line))
    {
        stringstream s(line);
        int j=0;
            while (s >> line)
            {
               matrix[idx][j]= stoi(line);
               j++;
              //cout<<line<<" "<<stoi(line);
            }
        
        //cout<<"\n";
        idx++;
    }
} 
void view_matrix( vector< vector < int > > matrix )
//function to view the matrix elements
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}
void make_calculation(vector< vector <int > > matrix)
{
    for(int i = 0; i<matrix.size(); i++)
    {
        if(matrix[i][0] == 1)
        {
            matrix[i][4] == 1 ? female_having_honour += 1 : female_not_having_honour += 1;
        }
        else
        {
            matrix[i][4] == 1 ? male_having_honour += 1 : male_not_having_honour += 1;
        }
    }
    total_female = female_having_honour + female_not_having_honour;
    total_male = male_having_honour + male_not_having_honour;

    float nomi, denomi, male_odd, female_odd;

    nomi = male_having_honour / total_male;
    denomi = male_not_having_honour / total_male;

    
    male_odd = nomi / denomi;
    B0 = log( male_odd );

    nomi = female_having_honour / total_female;
    denomi = female_not_having_honour / total_female;

    female_odd = nomi / denomi;
    B1 = log( female_odd / male_odd );

    //cout<<B0<<" "<<B1;
}
void make_probability (int gender)
{
  float y;
  y = B0 + (B1 * gender);

  probability = exp (y) / ( 1 + exp(y) );
}

int main()
{
    string dataset_name = "sample.csv";
    int rows = 200, cols= 6, gender;
    vector < vector < int > > matrix (rows, vector <int> (cols));
    read_record( dataset_name, matrix ) ;
    //view_matrix(matrix);
    make_calculation(matrix);
    //cout<<female_not_having_honour<<" "<<female_having_honour<<" "<<total_female<<"\n";
    //cout<<male_not_having_honour<<" "<<male_having_honour<<" "<<total_male<<"\n";
    cout<<"Enter 1 to check probability of female securing honours or 0 to check probability male securing honours";
    cin>>gender;
    make_probability(gender);
    cout<<"The probability is "<<probability*100<<"%\n";
    return 0;
}