#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;


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
int main()
{
    string dataset_name = "data.csv";//"sample.csv";
    int rows = 7/*200*/, cols= 6;
    vector < vector < int > > matrix (rows, vector <int> (cols));
    read_record( dataset_name, matrix ) ;
    view_matrix(matrix);
    return 0;
}