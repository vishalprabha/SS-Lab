/*
**************************
@Lab: System Software Lab
Code from Kavya GY
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Pass_two_assembler.cpp
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

map<string,string> optab,symtab;
map<string,string>::iterator iter;

void read_tables(string symfile,string opfile)
{
    string mnemonic,opcode;
    fstream f(opfile.c_str(),ios::in);
    while(f >> mnemonic >>opcode )
    {
        optab[mnemonic] = opcode;
    }
    f.close();
    f.open(symfile.c_str(),ios::in);
    while(f >> mnemonic >>opcode )
    {
        symtab[mnemonic] = opcode;
    }
    f.close();
}

void tokenize(string line,string &lo,string &la,string &m,string &o)
{
    stringstream tokens(line);
    getline(tokens,lo,'\t');
    getline(tokens,la,'\t');
    getline(tokens,m,'\t');
    getline(tokens,o,'\n');
}

string generate(string loc,string lab,string mne, string op);
void pass2a(string ifile,string ofile);

int main()
{
    read_tables("symtab.txt","optab.txt");
    pass2a("Pass_one_output.txt","Pass_two_output.txt");
}

int first = -1;

void pass2a(string ifile,string ofile)
{
    //to generate object codes, open in/out files, store lineno, tokens
    fstream infile(ifile.c_str(),ios::in);
    int lineno=0,loc = 0,len=0,flag=0;
    fstream outfile(ofile.c_str(),ios::out),objfile("Object_program.txt",ios::out);
    string line,objcode,locctr,lab,mne,op;
    stringstream temp,textrecord("");
    while(getline(infile,line))
    {
        lineno++;
        //if comment, skip
        if(line[0] == '.')
        {
            outfile<<line<<endl;
            continue;
        }
        tokenize(line,locctr,lab,mne,op);
        if(mne == "START")
        {
            temp.str(op);temp.clear();
            temp>>hex>>loc;
            //write out header record
            temp.str(symtab.find("END")->second);
            temp.clear();
            temp>>hex>>len;
            len=len-loc;
            objfile<<"H"<<left<<setfill(' ')<<setw(6)<<lab<<right<<setfill('0')<<setw(6)<<uppercase<<hex<<loc<<setfill('0')<<setw(6)<<uppercase<<hex<<len<<endl;

            //initialise first text record
            textrecord<<"T"<<setfill('0')<<setw(6)<<uppercase<<hex<<loc<<"LN";
            continue;
        }

        if(mne == "END")
        {
            string trec = textrecord.str();
            int len = trec.size()-9;
            len = len%2==0? len/2 : (len+1)/2;
            temp.str("");temp.clear();
            temp<<setw(2)<<setfill('0')<<uppercase<<hex<<len;
            trec.replace(trec.find("LN"),2,temp.str());
            objfile<<trec<<endl;
            temp.str("");
            temp.clear();
            temp<<"E"<<setfill('0')<<setw(6)<<uppercase<<hex<<first<<endl;
            objfile<<temp.str()<<endl;
            break;
        }

        //generate object code for given line
        objcode = generate(locctr,lab,mne,op);
        if(objcode == "ERROR"){ cout<<"ERROR at line"<<lineno<<endl;break;}
        else if(objcode.size()!=0)
        {
            if(textrecord.str().size()+objcode.size()>69||flag==1){
                string trec = textrecord.str();
                int len = (trec.size()-9)/2;
                temp.str("");temp.clear();
                temp<<setw(2)<<setfill('0')<<uppercase<<hex<<len;
                trec.replace(trec.find("LN"),2,temp.str());
                objfile<<trec<<endl;
                //initialise new text record;
                textrecord.clear();
                textrecord.str("");
                textrecord<<"T"<<setfill('0')<<setw(6)<<uppercase<<hex<<locctr<<"LN";  ;
                flag = flag==1?0:flag;
            }
            textrecord<<objcode;
        }
        else
        {
            flag=1;
        }
        //pass2a output
        outfile<<line<<"\t"<<objcode<<"\n";

    }

    infile.close();
    outfile.close();
    objfile.close();
}

string generate(string loc,string lab,string mne, string op)
{
    bool index = false;
    string objcode= "";
    stringstream temp("");

    iter = optab.find(mne);

    if(iter->second != "*") //normal instruction - not data
    {
        if(first==-1){
            stringstream s(loc);
            s>>hex>>first;
        }
        objcode = iter->second;
        if(op.size()==0) // like rsub
        {
            temp<<objcode<<setfill('0')<<setw(4)<<hex<<0;
        }
        else
        {
            if(op.find(",X")!=string::npos)
            {
                //it contains ,X - so lets get the original symbol
                op.replace(op.find(",X"),2,"");
                if(symtab.find(op)==symtab.end()){
                    return "ERROR";
                }
                index=true;
            }
            stringstream temp2(symtab.find(op)->second);
            int addr;
            temp2>>hex>>addr;
            if(index)addr^=0x8000;
            temp<<objcode<<uppercase<<hex<<addr;
        }


    }
    else //data instructions
    {
        //handle RESW && RESB
        if(mne == "RESW" || mne == "RESB") return "";

        if (mne == "BYTE")
        {
            if(op[0] == 'C') index = true;
            op = op.substr(2);
            if(index)
            {    //convert ascii value of each char to hex and store it
                for(int i = 0; i < op.size()-1; i++)
                    temp << uppercase << hex << (int)op[i];

            }
            else
            {
                //append the hex values directly to obj code
                for(int i = 0; i < op.size()-1; i++)
                    temp<<op[i];
            }
        }
        else if (mne == "WORD")
        {
            stringstream temp2(op);
            int addr;
            temp2>>addr;
            temp<<setfill('0')<<setw(6)<<uppercase<<hex<<addr;
        }


    }
    objcode = temp.str();
    return objcode;
}
