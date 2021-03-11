# Lexical Analyzer in C++.
This repository contains the source code for Lexical Analyzer for C++ Language.
While designing the lexical analyser for a language L1, I have assumed the following assumptions.
**Note: My language L1 will ignore all single line comments ‘//’ ,’whitespaces’ and ‘\n’ while reading the tokens.**

//------------------ASSUMPTIONS-----------------
**Special Symbol**: ; { } ( ) , #
**Keyword**: int, char, float, bool, cin, cout, main
**Pre-processor Directives**: include, define
**Library**: iostream, studio, string
**Operators**: *, +, >>, <<,>,<
**Numbers/Integers**: All numbers Values from 0-9.
**Identifies/ Variables**: All alphabetic strings except the keywords, numbers, Pre-processor directive and library strings.
