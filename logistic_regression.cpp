//program to implement the simple binary logistic regression

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

void read_record( string data_name, vector < vector < int > > &matrix ); 
//read the Data from the file as matrix elements

void view_matrix( vector< vector < int > > matrix );
//function to view the matrix elements

void make_calculation(vector< vector <int > > matrix);
//function to calculate the odds and coeffecients of the data set needed to calculate the probability

void make_probability (int gender);
//function to calculate the final probability given gender as an argument

float male_having_honour = 0, male_not_having_honour = 0, female_having_honour = 0, female_not_having_honour = 0, total_female, total_male, B0, B1, probability;
//variable required to perform calculation

void read_record( string data_name, vector < vector < int > > &matrix ) 
//read the Data from the file as String Vector
{ 
    ifstream fin;
    //file pointer

    string line;
    int idx=0;

    fin.open(data_name);
    //open the file with name data_name

    while(getline(fin, line))
    //fetches a complete line
    {
        stringstream s(line);
        //line is broken into words
        int j=0;
            while (s >> line)
            {
               matrix[idx][j]= stoi(line);
               //each value is stored as vector element
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
            //matrix element is printed
        }
        cout<<"\n";
    }

}

void make_calculation(vector< vector <int > > matrix)
//function to calculate the odds and coeffecients of the data set needed to calculate the probability
{
    for(int i = 0; i<matrix.size(); i++)
    {
        if(matrix[i][0] == 1)
        //if the gender attribute is female calculate values based on thier honours
        {
            matrix[i][4] == 1 ? female_having_honour += 1 : female_not_having_honour += 1;
        }
        else
        //if the gender attribute is male calculate values based on thier honours
        {
            matrix[i][4] == 1 ? male_having_honour += 1 : male_not_having_honour += 1;
        }
    }
    total_female = female_having_honour + female_not_having_honour;
    total_male = male_having_honour + male_not_having_honour;

    float nomi, denomi, male_odd, female_odd;

    nomi = male_having_honour / total_male;
    //probability of male securing honours

    denomi = male_not_having_honour / total_male;
    //probability of female securing honours
    
    male_odd = nomi / denomi;
    //odd of male honour

    B0 = log( male_odd );
    // log of odd of male honours Bo coeffecient

    nomi = female_having_honour / total_female;
    //probability of female securing honours

    denomi = female_not_having_honour / total_female;
    //probability of female not securing honours

    female_odd = nomi / denomi;
    //odd of female honour

    B1 = log( female_odd / male_odd );
    //coeffecient B1 is calculated
    //cout<<B0<<" "<<B1;
}
void make_probability (int gender)
//function to calculate the final probability given gender as an argument
{
  float y;
  y = B0 + (B1 * gender);
  // y is calculated based on the gender value

  probability = exp (y) / ( 1 + exp(y) );
  //probability is calculated
}

int main()
{
    string dataset_name = "sample.csv";
    //name of the csv file

    int rows = 200, cols= 6, gender;
    vector < vector < int > > matrix (rows, vector <int> (cols));

    read_record( dataset_name, matrix );
    //function call to read the Data from the file as matrix elements

    //view_matrix(matrix);
    //function call to view the matrix elements

    make_calculation(matrix);
    //function call to calculate the odds and coeffecients of the data set needed to calculate the probability

    //cout<<female_not_having_honour<<" "<<female_having_honour<<" "<<total_female<<"\n";
    //cout<<male_not_having_honour<<" "<<male_having_honour<<" "<<total_male<<"\n";
    cout<<"Enter 1 to check probability of female securing honours or 0 to check probability male securing honours\n";
    cin>>gender;

    make_probability(gender);
    //function call to calculate the final probability given gender as an argument

    cout<<"The probability is "<<probability*100<<"%\n";
    //final ouput statement about the probability calculated

    return 0;
}