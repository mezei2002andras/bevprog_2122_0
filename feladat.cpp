#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

//province;agegrp5;sex;no_reinf;reinf;total
struct Demo
{
    string province;
    string agegrp5;
    string sex;
    int no_reinf;
    int reinf;
    int total;

};
//"date","inc_1","inc_2"
struct Ts
{
    string date;
    int inc_1;
    int inc_2;
};

int main()
{
    vector<Demo> demo;
    vector<Ts> ts;
    ifstream file_ts("ts.csv");
    if(file_ts.is_open())
    {
        string line;
        getline(file_ts,line);
        while(getline(file_ts, line))
        {
            stringstream ss(line);
            string field;
            Ts tsdata;
            getline(ss, tsdata.date, ',');
            ss >> tsdata.inc_1;
            ss.ignore(1, ',');
            ss >> tsdata.inc_2;
            ss.ignore(1, ',');

            ts.push_back(tsdata);
        }
    }
    else
    {
        cout << "NEm lehet megnyitni" << endl;
        return 1;
    }

    ifstream file_demo("demo.csv");
    if(file_demo.is_open())
    {
        string line;
        getline(file_demo,line);
        while(getline(file_demo, line))
        {
            stringstream ss(line);
            string field;
            Demo demodata;
            getline(ss, demodata.province, ';');
            getline(ss, demodata.agegrp5, ';');
            getline(ss, demodata.sex, ';');
            ss >> demodata.no_reinf;
            ss.ignore(1, ';');
            ss >> demodata.reinf;
            ss.ignore(1, ';');
            ss >> demodata.total;
            ss.ignore(1, ';');

            demo.push_back(demodata);
        }
    }
    else
    {
        cout << "NEm lehet megnyitni" << endl;
        return 1;
    }
    //cout << ts[1].date << "\t" << ts[1].inc_1 << "\t" << ts[1].inc_2 << endl;
    //cout << demo[1].province << "\t" << demo[1].agegrp5 << "\t" << demo[1].sex << endl;
    //A a)
    int szum_ferto = 0;
    for (int i = 0; i < demo.size(); i++)
    {
        //cout << demo[i].province << endl;
        if(demo[i].province == "LIMPOPO")
        {
            //cout << demo[i].province << endl;
            if(demo[i].agegrp5 == "(20,25]" || demo[i].agegrp5 == "(25,30]" || demo[i].agegrp5 == "(30,35]" || demo[i].agegrp5 == "(35,40]")
            {
                szum_ferto += demo[i].reinf;
            }
        }
    }
    cout << szum_ferto << endl;

    bool van_e = true;
    for ( int i = 0 ; i < ts.size(); i++)
    {
        string honap = ts[i].date.substr(5, 2);
        if(honap == "02") 
        {
            for (int j = 1; j <= 28; j++)
            {
                string nap = ts[i].date.substr(8, 2);
                if(j == stoi(nap))
                {
                    van_e = false;
                    //cout << j << "\t" << ts[i].date << endl;
                    
                }
            }
            
        }
        if(honap == "04" || honap == "06" || honap == "09" || honap == "11" ) 
        {
            for (int j = 1; j <= 30; j++)
            {
                string nap = ts[i].date.substr(8, 2);
                if(j == stoi(nap))
                {
                    van_e = false;
                    //cout << j << "\t" << ts[i].date << endl;
                }
            }
            
        }
        if(honap == "01" || honap == "03" || honap == "05" || honap == "07" || honap == "08" || honap == "10" || honap == "12" ) 
        {
            for (int j = 1; j <= 31; j++)
            {
                string nap = ts[i].date.substr(8, 2);
                if(j == stoi(nap))
                {
                    van_e = false;
                    //cout << j << "\t" << ts[i].date << endl;
                }
            }
            
        }
    }
    cout << van_e << endl;
    return 0;
}