/* Copyright (c) 2012 the authors listed at the following URL, and/or
the authors of referenced articles or incorporated external code:
http://en.literateprograms.org/Finite_automaton_string_search_algorithm_(C_Plus_Plus)?action=history&offset=20110413050702

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Finite_automaton_string_search_algorithm_(C_Plus_Plus)?oldid=17102
*/

#include <set>
#include <map>
#include <vector>

#include <string>

#include <string>
#include <iostream>

using std::set;
using std::map;
using std::vector;

using std::string;
using std::cout;
using std::endl;

typedef int string_pos;
typedef int state_num;

const int NUM_CHARS = 256;


// Maps the set of string positions a state represents to the state number
map< set<string_pos>, state_num > state_map;
// Maps a state number to its set of string positions
vector< set<string_pos> > states;

vector< vector<state_num> > transition_table;
vector<bool> final;


state_num get_state(set<string_pos>& s)
{
    static int next_state_num = 0;
    map< set<string_pos>, state_num >::iterator iter =
        state_map.find(s);
    if (iter == state_map.end())
    {
        state_map[s] = next_state_num;
        states.push_back(s);
        transition_table.push_back(vector<state_num>(NUM_CHARS));
    final.push_back(false);

        next_state_num++;
        return next_state_num - 1;
    }
    else
    {
        return iter->second;
    }
        
}
void fill_transition_table_entry(string pattern, int state, char c_next)
{
    set<string_pos> new_state;
    new_state.insert(0);
    set<string_pos>::iterator iter = states[state].begin();
    for( ; iter != states[state].end(); iter++)
    {
        if (pattern[*iter] == c_next)
        {
            new_state.insert(*iter + 1);
        }
    }
    state_num temp = get_state(new_state); // fix concurrent modification bug
    transition_table[state][c_next] = temp;
    #if TRACE
        cout << "Adding edge " << state << " -" << c_next << "-> "
             << transition_table[state][c_next] << endl;
    #endif
}

void fill_transition_table(string pattern)
{
    set<string_pos> initial_pos;
    initial_pos.insert(0);
    get_state(initial_pos);
    for (unsigned int state=0; state < states.size(); state++)
    {
    repeat_inner_loop:
        set<string_pos>::iterator iter = states[state].begin();
        for( ; iter != states[state].end(); iter++)
        {
            if (*iter == (string_pos)pattern.length())
        {
            final[state] = true;
            continue;
        }
            char c_next = pattern[*iter];
            if (transition_table[state][c_next] == 0) {
                fill_transition_table_entry(pattern, state, c_next);
                goto repeat_inner_loop;
            }
        }
    }
    state_map.clear();
    states.clear();
}

int dfa_string_search(string search_for, string search_in)
{
    state_num cur_state = 0;
    string_pos cur_pos = 0;
    while (cur_pos < (string_pos)search_in.length() && !final[cur_state])
    {
        cur_state = transition_table[cur_state][search_in[cur_pos]];
        cur_pos++;
    }
    if (final[cur_state])
        return cur_pos - search_for.length();
    else
        return -1;
}
int main(int argc, char* argv[])
{
    fill_transition_table(argv[1]);
    int result = dfa_string_search(argv[1], argv[2]);
    if (result == -1)
        cout << "No match found." << endl;
    else
        cout << "Matched at position " << result << ":" << endl
             << string(argv[2]).substr(0, result) << "|"
             << string(argv[2]).substr(result) << endl;
    return 0;
}

