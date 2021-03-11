#include <bits/stdc++.h>
#include <regex>
#include <iterator>
#define deb(x) cout<<#x<<" = "<<x<<endl

using namespace std;

map<string,string> Make_Regex_Map(){
    map<string,string> my_map {       
        { "\\;|\\{|\\}|\\(|\\)|\\,|\\#", "Special Symbol"},
        { "int|char|float|bool|cin|cout|main|using|namespace|std","Keywords"},
        { "\\include|define", "Pre-Processor Directive"},
        {"\\iostream|\\stdio|\\string","Library"},
        { "\\*|\\+|\\>>|\\<<|<|>",  "Operator"},
        { "[0-9]+" ,   "Integer" },
        { "[^include][^iostream][^int][^main][^cin][^cout][^;][^>>][^,][^[B ;cin]][a-z]+" ,   "Identifier" },
        { "[A-Z]+",    "Variable"},
        {"[ ]",""},
    };
    return my_map;
}

map<size_t,pair<string,string>> Match_Language (map<string,string> patterns,string str){

 map< size_t, pair<string,string> > lang_matches;

    for ( auto i = patterns.begin(); i != patterns.end(); ++i )
    {
        regex compare(i->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), compare );
        auto words_end   = sregex_iterator();
    //MAKING PAIRS OF [STRING OF REGEX 'compare' : 'pattern']
        for ( auto it = words_begin; it != words_end; ++it )
            lang_matches[ it->position() ] = make_pair( it->str(), i->second );
    }
    return lang_matches;
}

string tell_Lexeme(string op){
    if(op=="*") return "MUL";
    else if(op=="+") return "ADD";
    else if(op==">>") return "INS";
    else if(op=="<<") return "EXTR";
    else if(op==">") return "RSHFT";
    else if(op=="<") return "LSHFT";
}
int main()
{
    ofstream fout;
    fout.open("OutputFile");
    char c;
    fstream fin("SourceCode.txt", fstream::in);
    string str;
    //Fetching Source Code in String type 'str'
    while(fin>> noskipws>>c)
        str=str+c;

    //Making a map which which will define the regex in source code to its pattern in my language.
    map<string,string> patterns =Make_Regex_Map();

    /*DECLARING MAP 'lang_matches' from 'patterns' map which will pair up the patterns 
    from the ['Source Code':'Defined Pattern' via a Regex named 'compare'. */
    map< size_t, pair<string,string> > lang_matches = Match_Language(patterns,str);

    // Writing matches in File ignoring 'spaces' and '\n'.
    for ( auto match = lang_matches.begin(); match != lang_matches.end(); ++match ){

        if(!(match->second.first==" ")&&!(match->second.first=="//")){
            if(match->second.second=="Variable"||match->second.second=="Identifier")
            fout<<"Token (  '"<< match->second.first << "' " <<" -------> "<< match->second.second  <<" ,  POINTER TO SYMBOL TABLE )"<<endl;
            else{
                if(match->second.second=="Operator"){
                string op=tell_Lexeme(match->second.first);
                fout<<"Token (  "<< match->second.first << " " <<" -------> "<< match->second.second<<" , "<<op<<"  )"  <<endl;    
                }
                else
                fout<<"Token (  "<< match->second.first << " " <<" -------> "<< match->second.second<<"  )"  <<endl;
            } 
        }
    }
    return 0;
}