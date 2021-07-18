# Lexical Analyzer in C++.

This repository contains the source code for Lexical Analyzer for C++ Language.

While designing the lexical analyser for a a substet of (C++), I have assumed the following assumptions.

**Note: My language L1 will ignore all single line comments ‘//’ ,’whitespaces’ and ‘\n’ while reading the tokens.**

#### ASSUMPTIONS of Subset in C++.
- [x] **Special Symbol**: ; { } ( ) , #
- [x] **Keyword**: int, char, float, bool, cin, cout, main
- [x] **Pre-processor Directives**: include, define
- [x] **Library**: iostream, studio, string
- [x] **Operators**: *, +, >>, <<,>,<
- [x] **Numbers/Integers**: All numbers Values from 0-9.
- [x] **Identifies/ Variables**: All alphabetic strings except the keywords, numbers, Pre-processor directive and library strings.
